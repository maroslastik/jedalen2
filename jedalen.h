#pragma once

#include <QtWidgets/QMainWindow>

#include "prihlasokno.h"
#include "ui_jedalen.h"

class Jedlo;

class jedalen : public QMainWindow
{
    friend class prihlasokno;
    Q_OBJECT

public:
    jedalen(QWidget *parent = nullptr);
    ~jedalen();

    //void vypis_menu(QList<Jedlo>& menu[7]);
private:
    Ui::jedalenClass ui;
};
