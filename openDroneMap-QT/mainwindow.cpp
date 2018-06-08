#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QStringList>
#include <QProcess>
#include<QMessageBox>
#include <QMessageBox>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
    QStringList filters;
    filters << "*.png" << "*.jpg" << "*.bmp";
    QStringList fileList=dir.entryList(filters);
    ui->imageList->addItems(fileList);


}

void MainWindow::on_outputButton_clicked()
{
    QString filePath = QFileDialog::getExistingDirectory(this, tr("Output file"), "../",
                                                         QFileDialog::ShowDirsOnly
                                                         | QFileDialog::DontResolveSymlinks);
    ui->outputFilePath->setText(filePath);
    Output_path=filePath;
    
}
void MainWindow::runShell(QString inputPath,int step){
    QProcess *proc = new QProcess;
    QDir dir(inputPath);
    dir.cdUp();
    QString outpath_orthophoto=dir.path()+"/odm_orthophoto";
    QString outpath_texturing=dir.path()+"/odm_texturing";
    QString command = "unbuffer docker run -i --rm -v "+ inputPath+":/code/images -v "+ outpath_orthophoto+":/code/odm_orthophoto -v "+outpath_texturing+":/code/odm_texturing opendronemap/opendronemap";
    qDebug()<<command;
    connect(proc,&QProcess::errorOccurred,
            [](QProcess::ProcessError e){
        qDebug() << e;
    }
    );
    QString logPath=dir.path()+"/log.txt";

    QFile file(logPath);
    //方式：Append为追加，WriteOnly，ReadOnly
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QMessageBox::critical(NULL, "提示", "无法创建文件");
        return;
    }
    QTextStream out(&file);

    connect(proc,&QProcess::readyReadStandardOutput,
            [&](){
        QByteArray procOutput;
        procOutput=proc->readAllStandardOutput();
        qDebug() << procOutput.data();
        out<<procOutput<<endl;
        QString str = QString(QLatin1String(procOutput.data()));
        if(str.indexOf("running PYTHONPATH")>0){
            step=step+10;
            ui->progressBar->setValue(step);
        }
        if(str.indexOf("OpenDroneMap app finished")>0){
            ui->progressBar->setValue(100);
            QMessageBox::information(this,"tishi","finished!",QMessageBox::Ok);

        }
    }
    );
    proc->start(command);


    // 等待进程启动
    if (!proc->waitForStarted())
    {
        qDebug() << "启动失败\n";
        return;
    }
    // 关闭写通道,因为没有向进程写数据,没用到
    proc->closeWriteChannel();

    // 用于保存进程的控制台输出
    QByteArray procOutput;
    // 等待进程结束
    while (false == proc->waitForFinished())
    {
        ;
    }
    // 读取进程输出到控制台的数据
    procOutput = proc->readAllStandardError();
    // 输出读到的数据
    qDebug() << procOutput.data();

}



void MainWindow::on_startButton_clicked()
{
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    const int step=0;
    runShell(input_path,step);
}
