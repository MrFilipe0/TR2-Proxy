/********************************************************************************
** Form generated from reading UI file 'proxyui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROXYUI_H
#define UI_PROXYUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_proxyui
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_port;
    QLineEdit *le_port;
    QPushButton *pb_start;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pb_request;
    QTextEdit *te_request;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pb_response;
    QTextEdit *te_response;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_spider;
    QLineEdit *le_spider;
    QPushButton *pb_spidergo;
    QTextEdit *te_spider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_dump;
    QLineEdit *le_dump;
    QPushButton *pb_dump;
    QMenuBar *menuBar;
    QMenu *menuServidor_Proxy;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *proxyui)
    {
        if (proxyui->objectName().isEmpty())
            proxyui->setObjectName(QString::fromUtf8("proxyui"));
        proxyui->resize(749, 652);
        centralWidget = new QWidget(proxyui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 691, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lbl_port = new QLabel(verticalLayoutWidget);
        lbl_port->setObjectName(QString::fromUtf8("lbl_port"));

        horizontalLayout_5->addWidget(lbl_port);

        le_port = new QLineEdit(verticalLayoutWidget);
        le_port->setObjectName(QString::fromUtf8("le_port"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_port->sizePolicy().hasHeightForWidth());
        le_port->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(le_port);


        verticalLayout->addLayout(horizontalLayout_5);

        pb_start = new QPushButton(verticalLayoutWidget);
        pb_start->setObjectName(QString::fromUtf8("pb_start"));

        verticalLayout->addWidget(pb_start);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pb_request = new QPushButton(verticalLayoutWidget);
        pb_request->setObjectName(QString::fromUtf8("pb_request"));

        verticalLayout_4->addWidget(pb_request);

        te_request = new QTextEdit(verticalLayoutWidget);
        te_request->setObjectName(QString::fromUtf8("te_request"));
        te_request->setReadOnly(true);

        verticalLayout_4->addWidget(te_request);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pb_response = new QPushButton(verticalLayoutWidget);
        pb_response->setObjectName(QString::fromUtf8("pb_response"));

        verticalLayout_3->addWidget(pb_response);

        te_response = new QTextEdit(verticalLayoutWidget);
        te_response->setObjectName(QString::fromUtf8("te_response"));
        te_response->setReadOnly(true);

        verticalLayout_3->addWidget(te_response);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lbl_spider = new QLabel(verticalLayoutWidget);
        lbl_spider->setObjectName(QString::fromUtf8("lbl_spider"));

        horizontalLayout_2->addWidget(lbl_spider);

        le_spider = new QLineEdit(verticalLayoutWidget);
        le_spider->setObjectName(QString::fromUtf8("le_spider"));

        horizontalLayout_2->addWidget(le_spider);


        verticalLayout->addLayout(horizontalLayout_2);

        pb_spidergo = new QPushButton(verticalLayoutWidget);
        pb_spidergo->setObjectName(QString::fromUtf8("pb_spidergo"));

        verticalLayout->addWidget(pb_spidergo);

        te_spider = new QTextEdit(verticalLayoutWidget);
        te_spider->setObjectName(QString::fromUtf8("te_spider"));
        te_spider->setReadOnly(true);

        verticalLayout->addWidget(te_spider);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lbl_dump = new QLabel(verticalLayoutWidget);
        lbl_dump->setObjectName(QString::fromUtf8("lbl_dump"));

        horizontalLayout_3->addWidget(lbl_dump);

        le_dump = new QLineEdit(verticalLayoutWidget);
        le_dump->setObjectName(QString::fromUtf8("le_dump"));

        horizontalLayout_3->addWidget(le_dump);


        verticalLayout->addLayout(horizontalLayout_3);

        pb_dump = new QPushButton(verticalLayoutWidget);
        pb_dump->setObjectName(QString::fromUtf8("pb_dump"));

        verticalLayout->addWidget(pb_dump);

        proxyui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(proxyui);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 749, 25));
        menuServidor_Proxy = new QMenu(menuBar);
        menuServidor_Proxy->setObjectName(QString::fromUtf8("menuServidor_Proxy"));
        proxyui->setMenuBar(menuBar);
        mainToolBar = new QToolBar(proxyui);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        proxyui->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(proxyui);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        proxyui->setStatusBar(statusBar);

        menuBar->addAction(menuServidor_Proxy->menuAction());

        retranslateUi(proxyui);

        QMetaObject::connectSlotsByName(proxyui);
    } // setupUi

    void retranslateUi(QMainWindow *proxyui)
    {
        proxyui->setWindowTitle(QApplication::translate("proxyui", "proxyui", 0, QApplication::UnicodeUTF8));
        lbl_port->setText(QApplication::translate("proxyui", " Digite a porta TCP:", 0, QApplication::UnicodeUTF8));
        pb_start->setText(QApplication::translate("proxyui", "Iniciar servidor proxy", 0, QApplication::UnicodeUTF8));
        pb_request->setText(QApplication::translate("proxyui", "Request", 0, QApplication::UnicodeUTF8));
        pb_response->setText(QApplication::translate("proxyui", "Response", 0, QApplication::UnicodeUTF8));
        lbl_spider->setText(QApplication::translate("proxyui", "URL:", 0, QApplication::UnicodeUTF8));
        pb_spidergo->setText(QApplication::translate("proxyui", "Spider", 0, QApplication::UnicodeUTF8));
        lbl_dump->setText(QApplication::translate("proxyui", "URL:", 0, QApplication::UnicodeUTF8));
        pb_dump->setText(QApplication::translate("proxyui", "Dump", 0, QApplication::UnicodeUTF8));
        menuServidor_Proxy->setTitle(QApplication::translate("proxyui", "Servidor_Proxy", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class proxyui: public Ui_proxyui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROXYUI_H
