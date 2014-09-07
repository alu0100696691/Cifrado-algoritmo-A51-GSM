/********************************************************************************
** Form generated from reading UI file 'gsm.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GSM_H
#define UI_GSM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GSM
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QTextEdit *pass;
    QLabel *label_2;
    QTextEdit *text;
    QLabel *label_3;
    QTextEdit *res;
    QPushButton *ejecutar;
    QPushButton *salir;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GSM)
    {
        if (GSM->objectName().isEmpty())
            GSM->setObjectName(QStringLiteral("GSM"));
        GSM->resize(971, 583);
        centralWidget = new QWidget(GSM);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 71, 17));
        pass = new QTextEdit(centralWidget);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setGeometry(QRect(110, 20, 661, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 90, 67, 17));
        text = new QTextEdit(centralWidget);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(110, 80, 661, 121));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 250, 71, 17));
        res = new QTextEdit(centralWidget);
        res->setObjectName(QStringLiteral("res"));
        res->setGeometry(QRect(110, 240, 661, 121));
        ejecutar = new QPushButton(centralWidget);
        ejecutar->setObjectName(QStringLiteral("ejecutar"));
        ejecutar->setGeometry(QRect(618, 420, 151, 27));
        salir = new QPushButton(centralWidget);
        salir->setObjectName(QStringLiteral("salir"));
        salir->setGeometry(QRect(618, 470, 151, 27));
        GSM->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GSM);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 971, 25));
        GSM->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GSM);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GSM->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GSM);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GSM->setStatusBar(statusBar);

        retranslateUi(GSM);

        QMetaObject::connectSlotsByName(GSM);
    } // setupUi

    void retranslateUi(QMainWindow *GSM)
    {
        GSM->setWindowTitle(QApplication::translate("GSM", "GSM", 0));
        label->setText(QApplication::translate("GSM", "SEMILLA:", 0));
        pass->setHtml(QApplication::translate("GSM", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1001000100011010001010110011110001001101010111100110111100001111</p></body></html>", 0));
        label_2->setText(QApplication::translate("GSM", "TEXTO:", 0));
        label_3->setText(QApplication::translate("GSM", "CIFRADO:", 0));
        ejecutar->setText(QApplication::translate("GSM", "EJECUTAR", 0));
        salir->setText(QApplication::translate("GSM", "SALIR", 0));
    } // retranslateUi

};

namespace Ui {
    class GSM: public Ui_GSM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GSM_H
