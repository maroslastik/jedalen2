/********************************************************************************
** Form generated from reading UI file 'okno_objednavok.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNO_OBJEDNAVOK_H
#define UI_OKNO_OBJEDNAVOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_objednavkyClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *objednavky_zoz;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *ob_ukonci;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *objednavkyClass)
    {
        if (objednavkyClass->objectName().isEmpty())
            objednavkyClass->setObjectName("objednavkyClass");
        objednavkyClass->resize(600, 400);
        centralWidget = new QWidget(objednavkyClass);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        objednavky_zoz = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        objednavky_zoz->setHeaderItem(__qtreewidgetitem);
        objednavky_zoz->setObjectName("objednavky_zoz");

        horizontalLayout->addWidget(objednavky_zoz);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        ob_ukonci = new QPushButton(groupBox);
        ob_ukonci->setObjectName("ob_ukonci");

        verticalLayout->addWidget(ob_ukonci);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(groupBox);

        objednavkyClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(objednavkyClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 30));
        objednavkyClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(objednavkyClass);
        mainToolBar->setObjectName("mainToolBar");
        objednavkyClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(objednavkyClass);
        statusBar->setObjectName("statusBar");
        objednavkyClass->setStatusBar(statusBar);

        retranslateUi(objednavkyClass);

        QMetaObject::connectSlotsByName(objednavkyClass);
    } // setupUi

    void retranslateUi(QMainWindow *objednavkyClass)
    {
        objednavkyClass->setWindowTitle(QCoreApplication::translate("objednavkyClass", "objednavky", nullptr));
        groupBox->setTitle(QString());
        ob_ukonci->setText(QCoreApplication::translate("objednavkyClass", "Ukonci", nullptr));
    } // retranslateUi

};

namespace Ui {
    class objednavkyClass: public Ui_objednavkyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNO_OBJEDNAVOK_H
