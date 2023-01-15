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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
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
    QAction *odhlasit_sa;
    QAction *sprava_uzivatelov;
    QAction *vycistit_system;
    QAction *zobrazit_obj;
    QAction *ulozit_obj;
    QAction *novy_subor_jedal;
    QAction *actionObjednavky;
    QAction *actionVycistit_system;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *udaje_uzi;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *uz_meno;
    QLabel *label_2;
    QDoubleSpinBox *kredit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *dostupne;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *dostupne_zoz;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QComboBox *den;
    QSpacerItem *verticalSpacer;
    QGroupBox *objednane;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *objednane_zoz;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *zrusit_obj;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuUzivatel;
    QMenu *menuAdmin;
    QMenu *menuKuchar;
    QMenu *objednavky;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *jedalenClass)
    {
        if (jedalenClass->objectName().isEmpty())
            jedalenClass->setObjectName("jedalenClass");
        jedalenClass->resize(945, 605);
        odhlasit_sa = new QAction(jedalenClass);
        odhlasit_sa->setObjectName("odhlasit_sa");
        sprava_uzivatelov = new QAction(jedalenClass);
        sprava_uzivatelov->setObjectName("sprava_uzivatelov");
        vycistit_system = new QAction(jedalenClass);
        vycistit_system->setObjectName("vycistit_system");
        zobrazit_obj = new QAction(jedalenClass);
        zobrazit_obj->setObjectName("zobrazit_obj");
        ulozit_obj = new QAction(jedalenClass);
        ulozit_obj->setObjectName("ulozit_obj");
        novy_subor_jedal = new QAction(jedalenClass);
        novy_subor_jedal->setObjectName("novy_subor_jedal");
        actionObjednavky = new QAction(jedalenClass);
        actionObjednavky->setObjectName("actionObjednavky");
        actionVycistit_system = new QAction(jedalenClass);
        actionVycistit_system->setObjectName("actionVycistit_system");
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

        uz_meno = new QLineEdit(udaje_uzi);
        uz_meno->setObjectName("uz_meno");
        uz_meno->setReadOnly(true);

        horizontalLayout->addWidget(uz_meno);

        label_2 = new QLabel(udaje_uzi);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        kredit = new QDoubleSpinBox(udaje_uzi);
        kredit->setObjectName("kredit");
        kredit->setReadOnly(true);

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
        dostupne_zoz->setEnabled(true);
        dostupne_zoz->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout_2->addWidget(dostupne_zoz);

        groupBox = new QGroupBox(dostupne);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        den = new QComboBox(groupBox);
        den->addItem(QString());
        den->addItem(QString());
        den->addItem(QString());
        den->addItem(QString());
        den->addItem(QString());
        den->addItem(QString());
        den->addItem(QString());
        den->setObjectName("den");

        verticalLayout_2->addWidget(den);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(groupBox);


        verticalLayout->addWidget(dostupne);

        objednane = new QGroupBox(centralWidget);
        objednane->setObjectName("objednane");
        horizontalLayout_3 = new QHBoxLayout(objednane);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        objednane_zoz = new QTableWidget(objednane);
        objednane_zoz->setObjectName("objednane_zoz");
        objednane_zoz->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout_3->addWidget(objednane_zoz);

        groupBox_2 = new QGroupBox(objednane);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        zrusit_obj = new QPushButton(groupBox_2);
        zrusit_obj->setObjectName("zrusit_obj");

        verticalLayout_3->addWidget(zrusit_obj);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout->addWidget(objednane);

        jedalenClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(jedalenClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 945, 30));
        menuUzivatel = new QMenu(menuBar);
        menuUzivatel->setObjectName("menuUzivatel");
        menuAdmin = new QMenu(menuBar);
        menuAdmin->setObjectName("menuAdmin");
        menuKuchar = new QMenu(menuBar);
        menuKuchar->setObjectName("menuKuchar");
        objednavky = new QMenu(menuKuchar);
        objednavky->setObjectName("objednavky");
        jedalenClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(jedalenClass);
        mainToolBar->setObjectName("mainToolBar");
        jedalenClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(jedalenClass);
        statusBar->setObjectName("statusBar");
        jedalenClass->setStatusBar(statusBar);

        menuBar->addAction(menuUzivatel->menuAction());
        menuBar->addAction(menuKuchar->menuAction());
        menuBar->addAction(menuAdmin->menuAction());
        menuUzivatel->addAction(odhlasit_sa);
        menuAdmin->addAction(sprava_uzivatelov);
        menuAdmin->addAction(novy_subor_jedal);
        menuKuchar->addAction(objednavky->menuAction());
        menuKuchar->addAction(vycistit_system);
        objednavky->addAction(zobrazit_obj);
        objednavky->addAction(ulozit_obj);

        retranslateUi(jedalenClass);

        den->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(jedalenClass);
    } // setupUi

    void retranslateUi(QMainWindow *jedalenClass)
    {
        jedalenClass->setWindowTitle(QCoreApplication::translate("jedalenClass", "jedalen", nullptr));
        odhlasit_sa->setText(QCoreApplication::translate("jedalenClass", "Odlhasit sa", nullptr));
        sprava_uzivatelov->setText(QCoreApplication::translate("jedalenClass", "Sprava uzivatelov", nullptr));
        vycistit_system->setText(QCoreApplication::translate("jedalenClass", "Vycistit system", nullptr));
        zobrazit_obj->setText(QCoreApplication::translate("jedalenClass", "Zobrazit", nullptr));
        ulozit_obj->setText(QCoreApplication::translate("jedalenClass", "Ulozit", nullptr));
        novy_subor_jedal->setText(QCoreApplication::translate("jedalenClass", "Novy subor jedal", nullptr));
        actionObjednavky->setText(QCoreApplication::translate("jedalenClass", "Objednavky", nullptr));
        actionVycistit_system->setText(QCoreApplication::translate("jedalenClass", "Vycistit system", nullptr));
        udaje_uzi->setTitle(QCoreApplication::translate("jedalenClass", "Udaje uzivatela", nullptr));
        label->setText(QCoreApplication::translate("jedalenClass", "Uzivatel:", nullptr));
        label_2->setText(QCoreApplication::translate("jedalenClass", "Kredit:", nullptr));
        dostupne->setTitle(QCoreApplication::translate("jedalenClass", "Dostupne jedla:", nullptr));
        groupBox->setTitle(QString());
        den->setItemText(0, QCoreApplication::translate("jedalenClass", "Pondelok", nullptr));
        den->setItemText(1, QCoreApplication::translate("jedalenClass", "Utorok", nullptr));
        den->setItemText(2, QCoreApplication::translate("jedalenClass", "Streda", nullptr));
        den->setItemText(3, QCoreApplication::translate("jedalenClass", "Stvrtok", nullptr));
        den->setItemText(4, QCoreApplication::translate("jedalenClass", "Piatok", nullptr));
        den->setItemText(5, QCoreApplication::translate("jedalenClass", "Sobota", nullptr));
        den->setItemText(6, QCoreApplication::translate("jedalenClass", "Nedela", nullptr));

        objednane->setTitle(QCoreApplication::translate("jedalenClass", "Objednane jedla:", nullptr));
        groupBox_2->setTitle(QString());
        zrusit_obj->setText(QCoreApplication::translate("jedalenClass", "Zrusit objednavku", nullptr));
        menuUzivatel->setTitle(QCoreApplication::translate("jedalenClass", "Uzivatel", nullptr));
        menuAdmin->setTitle(QCoreApplication::translate("jedalenClass", "Admin", nullptr));
        menuKuchar->setTitle(QCoreApplication::translate("jedalenClass", "Kuchar", nullptr));
        objednavky->setTitle(QCoreApplication::translate("jedalenClass", "Objednavky", nullptr));
    } // retranslateUi

};

namespace Ui {
    class jedalenClass: public Ui_jedalenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JEDALEN_H
