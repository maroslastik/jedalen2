#pragma once

#include <QMainWindow>

#include "ui_prihlasokno.h"

class prihlasokno : public QMainWindow
{
	friend class jedalen;
	Q_OBJECT

public:
	prihlasokno(QWidget* parent = nullptr);
	~prihlasokno(){}

private:
	Ui::prihlasoknoClass po_ui;
};



