/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *imageList;
    QProgressBar *progressBar;
    QPushButton *startButton;
    QTextBrowser *outputLog;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTextEdit *inputFilePath;
    QPushButton *inputButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioOrtho;
    QPushButton *buttonSetPara;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QTextEdit *outputFilePath;
    QPushButton *outputButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(523, 617);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        imageList = new QListWidget(centralWidget);
        imageList->setObjectName(QStringLiteral("imageList"));
        imageList->setGeometry(QRect(20, 70, 471, 192));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 400, 471, 16));
        progressBar->setValue(24);
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(190, 430, 105, 31));
        outputLog = new QTextBrowser(centralWidget);
        outputLog->setObjectName(QStringLiteral("outputLog"));
        outputLog->setGeometry(QRect(20, 470, 471, 192));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 471, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        inputFilePath = new QTextEdit(layoutWidget);
        inputFilePath->setObjectName(QStringLiteral("inputFilePath"));

        horizontalLayout->addWidget(inputFilePath);

        inputButton = new QPushButton(layoutWidget);
        inputButton->setObjectName(QStringLiteral("inputButton"));

        horizontalLayout->addWidget(inputButton);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(27, 290, 190, 35));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioOrtho = new QRadioButton(layoutWidget1);
        radioOrtho->setObjectName(QStringLiteral("radioOrtho"));
        radioOrtho->setChecked(true);

        horizontalLayout_2->addWidget(radioOrtho);

        buttonSetPara = new QPushButton(layoutWidget1);
        buttonSetPara->setObjectName(QStringLiteral("buttonSetPara"));

        horizontalLayout_2->addWidget(buttonSetPara);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 340, 471, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        outputFilePath = new QTextEdit(layoutWidget2);
        outputFilePath->setObjectName(QStringLiteral("outputFilePath"));

        horizontalLayout_3->addWidget(outputFilePath);

        outputButton = new QPushButton(layoutWidget2);
        outputButton->setObjectName(QStringLiteral("outputButton"));

        horizontalLayout_3->addWidget(outputButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 523, 35));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        startButton->setText(QApplication::translate("MainWindow", "start", 0));
        label->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266\345\244\271\357\274\232", 0));
        inputButton->setText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251", 0));
        radioOrtho->setText(QApplication::translate("MainWindow", "\346\255\243\345\260\204\345\275\261\345\203\217", 0));
        buttonSetPara->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        label_2->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\347\233\256\345\275\225\357\274\232", 0));
        outputButton->setText(QApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
