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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sprava_uzivatelovClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QTableWidget *zoz_uzivatelov;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *odstran_uz;
    QPushButton *pridaj_uz;
    QSpacerItem *verticalSpacer;
    QPushButton *uloz_zmeny;
    QPushButton *ukonci;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *sprava_uzivatelovClass)
    {
        if (sprava_uzivatelovClass->objectName().isEmpty())
            sprava_uzivatelovClass->setObjectName("sprava_uzivatelovClass");
        sprava_uzivatelovClass->resize(797, 400);
        centralWidget = new QWidget(sprava_uzivatelovClass);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName("groupBox_3");
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(groupBox_3);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");

        horizontalLayout_2->addWidget(label_5);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");

        horizontalLayout_2->addWidget(label_6);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");

        horizontalLayout_2->addWidget(label_7);


        verticalLayout_3->addWidget(groupBox_3);

        zoz_uzivatelov = new QTableWidget(groupBox_2);
        zoz_uzivatelov->setObjectName("zoz_uzivatelov");

        verticalLayout_3->addWidget(zoz_uzivatelov);


        horizontalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        odstran_uz = new QPushButton(groupBox);
        odstran_uz->setObjectName("odstran_uz");

        verticalLayout->addWidget(odstran_uz);

        pridaj_uz = new QPushButton(groupBox);
        pridaj_uz->setObjectName("pridaj_uz");

        verticalLayout->addWidget(pridaj_uz);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        uloz_zmeny = new QPushButton(groupBox);
        uloz_zmeny->setObjectName("uloz_zmeny");

        verticalLayout->addWidget(uloz_zmeny);

        ukonci = new QPushButton(groupBox);
        ukonci->setObjectName("ukonci");

        verticalLayout->addWidget(ukonci);


        horizontalLayout->addWidget(groupBox);

        sprava_uzivatelovClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(sprava_uzivatelovClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 797, 30));
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
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        label->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Pozicia", nullptr));
        label_2->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Meno", nullptr));
        label_3->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Priezvisko", nullptr));
        label_4->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Uzivatelske meno", nullptr));
        label_5->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Heslo", nullptr));
        label_6->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Kredit", nullptr));
        label_7->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Zlava", nullptr));
        groupBox->setTitle(QString());
        odstran_uz->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Odstran uzivatela", nullptr));
        pridaj_uz->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Pridaj uzivatela", nullptr));
        uloz_zmeny->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Uloz zmeny uzivatelov", nullptr));
        ukonci->setText(QCoreApplication::translate("sprava_uzivatelovClass", "Ukonci", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sprava_uzivatelovClass: public Ui_sprava_uzivatelovClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRAVA_UZIVATELOV_H
