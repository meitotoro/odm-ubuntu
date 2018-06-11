#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "replytimeout.h"
#include <QFileDialog>
#include <QDebug>
#include <QStringList>
#include <QProcess>
#include <QMessageBox>
#include <QDialog>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFileInfoList>
#include <QFileInfo>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    num(5)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputButton_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory(this, tr("Open Image"), "../",
                                                         QFileDialog::ShowDirsOnly
                                                         | QFileDialog::DontResolveSymlinks);
    input_path=filePath;
    ui->inputFilePath->setText(filePath);
    QDir dir(filePath);
    file_number=dir.count();

    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.bmp";
    QStringList list=dir.entryList(filters);
    ui->imageList->addItems(list);
    QFileInfoList absoluteList=dir.entryInfoList(filters);
    for(int i=0;i<absoluteList.size();i++){
        fileList.append(absoluteList.at(i).filePath());
    }



}

void MainWindow::httpRequest(QString batchName, QStringList fileList, int step){
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    int file_count=0;
    int map_count=fileList.size();
    QSemaphore num_map(0);
    QObject::connect(manager, QNetworkAccessManager::finished,
                     [&](QNetworkReply* reply){
        QByteArray rep=reply->readAll();
        map[QString::fromUtf8(rep)]=true;
        num.release();
        num_map.release();
        file_count++;
    });

    for(int i=0;i<fileList.size();i++){
        auto file_fullpath = fileList[i];
        QFileInfo info = QFileInfo(file_fullpath);
        QString file_name = info.fileName();
        map[file_name]=false;
        QUrlQuery params;
        params.addQueryItem("addr", batchName);
        params.addQueryItem("name", file_name);
        QUrl url("http://192.168.188.10:9000/transformap?"+params.query());
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));

        QFile file(file_fullpath);
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        file.close();

        num.acquire();
        auto reply = manager->post(request, ba);
        connect(reply, static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error), [](QNetworkReply::NetworkError code) {
            qDebug() << "error: " << code;
        });
//        QObject::connect(reply, QNetworkReply::uploadProgress,
//                         [&](qint64 bytesSent, qint64 bytesTotal){
//            if(bytesSent==bytesTotal){
//                map[file_name]=true;
//                num.release();
//                num_map.release();
//                file_count++;
//            }
//        });
        ReplyTimeout *pTimeout = new ReplyTimeout(reply, 60000);
        // 超时进一步处理
        connect(pTimeout, &ReplyTimeout::timeout, [=]() {
            qDebug() << "Timeout";
            reply->abort();
        });
    }
    num_map.acquire(map_count);

//    if(file_count==map.size())
//    {
//        num_map.release();
//        QMessageBox::information(this,"提示","传输完成",QMessageBox::Ok);

//    }



}


void MainWindow::on_startButton_clicked()
{
    QString address=ui->lineEdit->text();
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd");
    QString batchName=address+"-"+current_date;
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(file_number);
    ui->progressBar->setValue(0);
    const int step=0;
    httpRequest(batchName,fileList,step);
}
