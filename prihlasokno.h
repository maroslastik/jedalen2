#pragma once

#include <QMainWindow>

#include "ui_prihlasokno.h"

#include "jedalen.h"

class prihlasokno : public QMainWindow
{
	friend class jedalen;
	Q_OBJECT

public:
	prihlasokno(QWidget* parent = nullptr);
	~prihlasokno(){}

private slots:
    

private:
	Ui::prihlasoknoClass ui;
};



