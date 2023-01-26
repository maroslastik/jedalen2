#pragma once

#include <QMainWindow>

#include "ui_sprava_uzivatelov.h"

class sprava_uzivatelov : public QMainWindow
{
	friend class jedalen;
	Q_OBJECT

public:
	sprava_uzivatelov(QWidget *parent = nullptr);
	~sprava_uzivatelov(){}

private:
	Ui::sprava_uzivatelovClass su_ui;
};
