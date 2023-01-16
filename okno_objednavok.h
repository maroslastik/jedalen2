#pragma once

#include <QMainWindow>
#include "ui_okno_objednavok.h"

#include "jedalen.h"

class okno_objednavok : public QMainWindow
{
	friend class jedalen;
	Q_OBJECT

public:
	okno_objednavok(QWidget *parent = nullptr);
	~okno_objednavok() {}

private:
	Ui::objednavkyClass ob_ui;
};
