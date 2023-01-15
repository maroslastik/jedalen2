/********************************************************************************
** Form generated from reading UI file 'sprava_uzivatelov.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRAVA_UZIVATELOV_H
#define UI_SPRAVA_UZIVATELOV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sprava_uzivatelovClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *zoz_uziv;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pridaj_uz;
    QSpacerItem *verticalSpacer;
    QPushButton *ukonci;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *sprava_uzivatelovClass)
    {
        if (sprava_uzivatelovClass->objectName().isEmpty())
            sprava_uzivatelovClass->setObjectName("sprava_uzivatelovClass");
        sprava_uzivatelovClass->resize(600, 400);
        centralWidget = new QWidget(sprava_uzivatelovClass);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        zoz_uziv = new QListWidget(centralWidget);
        zoz_uziv->setObjectName("zoz_uziv");

        horizontalLayout->addWidget(zoz_uziv);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);

        pridaj_uz = new QPushButton(groupBox);
        pridaj_uz->setObjectName("pridaj_uz");

        verticalLayout->addWidget(pridaj_uz);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        ukonci = new QPushButton(groupBox);
        ukonci->setObjectName("ukonci");

        verticalLayout->addWidget(ukonci);


        horizontalLayout->addWidget(groupBox);

        sprava_uzivatelovClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(sprava_uzivatelovClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 30));
        sprava_uzivatelovClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(sprava_uzivatelovClass);
        mainToolBar->setObjectName("mainToolBar");
        sprava_uzivatelovClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(sprava_uzivatelovClass);
        statusBar->setObjectName("statusBar");
        sprava_uzivatelovClass->setStatusBar(statusBar);

        retranslateUi(sprava_uzivatelovClass);

        QMetaObject::connectSlotsByName(sprava_uzivatelovClass);
    } // setupUi

    void retranslateUi(QMainWindow *sprava_uzivatelovClass)
    {
        sprava_uzivatelovClass->setWindowTitle(QCoreApplication::translate("sprava_uzivatelovClass", "sprava_uzivatelov", nullptr));
        groupBox->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Odstran uzivatela", nullptr));
        pushButton_4->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Uprav uzivatela", nullptr));
        pridaj_uz->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Pridaj uzivatela", nullptr));
        ukonci->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Ukonci", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sprava_uzivatelovClass: public Ui_sprava_uzivatelovClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRAVA_UZIVATELOV_H
