/********************************************************************************
** Form generated from reading UI file 'prihlasokno.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIHLASOKNO_H
#define UI_PRIHLASOKNO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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

class Ui_prihlasoknoClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QListWidget *zoz_uziv;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *heslo;
    QSpacerItem *horizontalSpacer;
    QPushButton *prihlasit_sa;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *prihlasoknoClass)
    {
        if (prihlasoknoClass->objectName().isEmpty())
            prihlasoknoClass->setObjectName("prihlasoknoClass");
        prihlasoknoClass->resize(600, 400);
        centralWidget = new QWidget(prihlasoknoClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        zoz_uziv = new QListWidget(groupBox);
        zoz_uziv->setObjectName("zoz_uziv");

        verticalLayout_2->addWidget(zoz_uziv);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox_2);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        heslo = new QLineEdit(groupBox_2);
        heslo->setObjectName("heslo");
        heslo->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(heslo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        prihlasit_sa = new QPushButton(groupBox_2);
        prihlasit_sa->setObjectName("prihlasit_sa");

        horizontalLayout->addWidget(prihlasit_sa);


        verticalLayout->addWidget(groupBox_2);

        prihlasoknoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(prihlasoknoClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 30));
        prihlasoknoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(prihlasoknoClass);
        mainToolBar->setObjectName("mainToolBar");
        prihlasoknoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(prihlasoknoClass);
        statusBar->setObjectName("statusBar");
        prihlasoknoClass->setStatusBar(statusBar);

        retranslateUi(prihlasoknoClass);

        QMetaObject::connectSlotsByName(prihlasoknoClass);
    } // setupUi

    void retranslateUi(QMainWindow *prihlasoknoClass)
    {
        prihlasoknoClass->setWindowTitle(QCoreApplication::translate("prihlasoknoClass", "prihlasokno", nullptr));
        groupBox->setTitle(QCoreApplication::translate("prihlasoknoClass", "Uzivatelia:", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("prihlasoknoClass", "Heslo:", nullptr));
        prihlasit_sa->setText(QCoreApplication::translate("prihlasoknoClass", "Prihlasit sa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class prihlasoknoClass: public Ui_prihlasoknoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIHLASOKNO_H
