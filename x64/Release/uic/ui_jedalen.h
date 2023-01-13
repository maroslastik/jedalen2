/********************************************************************************
** Form generated from reading UI file 'jedalen.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JEDALEN_H
#define UI_JEDALEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_jedalenClass
{
public:
    QAction *odlhasit_sa;
    QAction *sprava_uzivatelov;
    QAction *vycistit_system;
    QAction *zobrazit_obj;
    QAction *ulozit_obj;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *udaje_uzi;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *uzivatel;
    QLabel *label_2;
    QLineEdit *kredit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *dostupne;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *dostupne_zoz;
    QGroupBox *objednane;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *objednane_zoz;
    QPushButton *zrusit_obj;
    QMenuBar *menuBar;
    QMenu *menuUzivatel;
    QMenu *menuAdmin;
    QMenu *menuZamestnanec;
    QMenu *objednavky;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *jedalenClass)
    {
        if (jedalenClass->objectName().isEmpty())
            jedalenClass->setObjectName("jedalenClass");
        jedalenClass->resize(600, 513);
        odlhasit_sa = new QAction(jedalenClass);
        odlhasit_sa->setObjectName("odlhasit_sa");
        sprava_uzivatelov = new QAction(jedalenClass);
        sprava_uzivatelov->setObjectName("sprava_uzivatelov");
        vycistit_system = new QAction(jedalenClass);
        vycistit_system->setObjectName("vycistit_system");
        zobrazit_obj = new QAction(jedalenClass);
        zobrazit_obj->setObjectName("zobrazit_obj");
        ulozit_obj = new QAction(jedalenClass);
        ulozit_obj->setObjectName("ulozit_obj");
        centralWidget = new QWidget(jedalenClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        udaje_uzi = new QGroupBox(centralWidget);
        udaje_uzi->setObjectName("udaje_uzi");
        horizontalLayout = new QHBoxLayout(udaje_uzi);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(udaje_uzi);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        uzivatel = new QLineEdit(udaje_uzi);
        uzivatel->setObjectName("uzivatel");

        horizontalLayout->addWidget(uzivatel);

        label_2 = new QLabel(udaje_uzi);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        kredit = new QLineEdit(udaje_uzi);
        kredit->setObjectName("kredit");

        horizontalLayout->addWidget(kredit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(udaje_uzi);

        dostupne = new QGroupBox(centralWidget);
        dostupne->setObjectName("dostupne");
        horizontalLayout_2 = new QHBoxLayout(dostupne);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        dostupne_zoz = new QTableWidget(dostupne);
        dostupne_zoz->setObjectName("dostupne_zoz");

        horizontalLayout_2->addWidget(dostupne_zoz);


        verticalLayout->addWidget(dostupne);

        objednane = new QGroupBox(centralWidget);
        objednane->setObjectName("objednane");
        horizontalLayout_3 = new QHBoxLayout(objednane);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        objednane_zoz = new QTableWidget(objednane);
        objednane_zoz->setObjectName("objednane_zoz");

        horizontalLayout_3->addWidget(objednane_zoz);

        zrusit_obj = new QPushButton(objednane);
        zrusit_obj->setObjectName("zrusit_obj");

        horizontalLayout_3->addWidget(zrusit_obj);


        verticalLayout->addWidget(objednane);

        jedalenClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(jedalenClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 30));
        menuUzivatel = new QMenu(menuBar);
        menuUzivatel->setObjectName("menuUzivatel");
        menuAdmin = new QMenu(menuBar);
        menuAdmin->setObjectName("menuAdmin");
        menuZamestnanec = new QMenu(menuBar);
        menuZamestnanec->setObjectName("menuZamestnanec");
        objednavky = new QMenu(menuZamestnanec);
        objednavky->setObjectName("objednavky");
        jedalenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(jedalenClass);
        mainToolBar->setObjectName("mainToolBar");
        jedalenClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(jedalenClass);
        statusBar->setObjectName("statusBar");
        jedalenClass->setStatusBar(statusBar);

        menuBar->addAction(menuUzivatel->menuAction());
        menuBar->addAction(menuZamestnanec->menuAction());
        menuBar->addAction(menuAdmin->menuAction());
        menuUzivatel->addAction(odlhasit_sa);
        menuAdmin->addAction(sprava_uzivatelov);
        menuZamestnanec->addAction(objednavky->menuAction());
        menuZamestnanec->addAction(vycistit_system);
        objednavky->addAction(zobrazit_obj);
        objednavky->addAction(ulozit_obj);

        retranslateUi(jedalenClass);

        QMetaObject::connectSlotsByName(jedalenClass);
    } // setupUi

    void retranslateUi(QMainWindow *jedalenClass)
    {
        jedalenClass->setWindowTitle(QCoreApplication::translate("jedalenClass", "jedalen", nullptr));
        odlhasit_sa->setText(QCoreApplication::translate("jedalenClass", "Odlhasit sa", nullptr));
        sprava_uzivatelov->setText(QCoreApplication::translate("jedalenClass", "Sprava uzivatelov", nullptr));
        vycistit_system->setText(QCoreApplication::translate("jedalenClass", "Vycistit system", nullptr));
        zobrazit_obj->setText(QCoreApplication::translate("jedalenClass", "Zobrazit", nullptr));
        ulozit_obj->setText(QCoreApplication::translate("jedalenClass", "Ulozit", nullptr));
        udaje_uzi->setTitle(QCoreApplication::translate("jedalenClass", "Udaje uzivatela", nullptr));
        label->setText(QCoreApplication::translate("jedalenClass", "Uzivatel:", nullptr));
        label_2->setText(QCoreApplication::translate("jedalenClass", "Kredit:", nullptr));
        dostupne->setTitle(QCoreApplication::translate("jedalenClass", "Dostupne jedla:", nullptr));
        objednane->setTitle(QCoreApplication::translate("jedalenClass", "Objednane jedla:", nullptr));
        zrusit_obj->setText(QCoreApplication::translate("jedalenClass", "Zrusit objednavku", nullptr));
        menuUzivatel->setTitle(QCoreApplication::translate("jedalenClass", "Uzivatel", nullptr));
        menuAdmin->setTitle(QCoreApplication::translate("jedalenClass", "Admin", nullptr));
        menuZamestnanec->setTitle(QCoreApplication::translate("jedalenClass", "Zamestnanec", nullptr));
        objednavky->setTitle(QCoreApplication::translate("jedalenClass", "Objednavky", nullptr));
    } // retranslateUi

};

namespace Ui {
    class jedalenClass: public Ui_jedalenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JEDALEN_H
