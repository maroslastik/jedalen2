#include "jedalen.h"

#include <QFileDialog>
#include <QMessagebox>
#include <QInputDialog>
#include <string>

jedalen::jedalen(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	ui.uzivatel->setText(prihlasokno().);
		//prihlaseny->Meno());
	// nastav kredit
}

jedalen::~jedalen()
{}
/*
void jedalen::vypis_menu(QList<Jedllo>& menu[7])
{
	ui.zoz_uziv->blockSignals(true);

	for (size_t i = 0; i < pracovnici.size(); i++)
	{
		QString productLine = QString("%1").arg(pracovnici[i].u_meno);

		QListWidgetItem* item = new QListWidgetItem(productLine);
		ui.zoz_uziv->addItem(item);
	}

	for (size_t i = 0; i < stravnici.size(); i++)
	{
		QString productLine = QString("%1").arg(stravnici[i].u_meno);

		QListWidgetItem* item = new QListWidgetItem(productLine);
		ui.zoz_uziv->addItem(item);
	}

	ui.zoz_uziv->blockSignals(false);
	ui.zoz_uziv->setCurrentRow(0);
}*/