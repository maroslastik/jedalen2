#include "jedalen.h"
#include "prihlasokno.h"

#include <QFileDialog>
#include <QMessagebox>
#include <QInputDialog>
#include <string>

jedalen::jedalen(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	nacitaj_uzivatelov();
	nacitaj_jedla();
	otvor_po();
}

// nieco ako main pre prihlasovacie okno
void jedalen::otvor_po()
{
	this->hide();
	po = new prihlasokno();
	po->show();
	vypis_uziv(pracovnici, stravnici);
	connect(po->ui.prihlasit_sa, &QPushButton::pressed, this, &jedalen::zatvor_po);
}

void jedalen::zatvor_po()
{
	if (najdi_uziv(po->ui.zoz_uziv->currentItem()->text())->Heslo() == po->ui.heslo->text())
	{
		prihlaseny = najdi_uziv(po->ui.zoz_uziv->currentItem()->text());
		this->show();
		po->hide();
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText(QString("Nespravne meno alebo heslo."));
		msgBox.exec();
	}
}

void jedalen::vypis_uziv(QList<pracovnik>& pracovnici, QList<stravnik>& stravnici)
{
	po->ui.zoz_uziv->blockSignals(true);

	for (size_t i = 0; i < pracovnici.size(); i++)
	{
		QString productLine = QString("%1").arg(pracovnici[i].u_meno);

		QListWidgetItem* item = new QListWidgetItem(productLine);
		po->ui.zoz_uziv->addItem(item);
	}

	for (size_t i = 0; i < stravnici.size(); i++)
	{
		QString productLine = QString("%1").arg(stravnici[i].u_meno);

		QListWidgetItem* item = new QListWidgetItem(productLine);
		po->ui.zoz_uziv->addItem(item);
	}

	po->ui.zoz_uziv->blockSignals(false);
	po->ui.zoz_uziv->setCurrentRow(0);
}

void jedalen::nacitaj_jedla()
{
	// okno na vyber suboru
	QMessageBox msgBox;
	msgBox.setText(QString("Vyber subor s jedlami."));
	msgBox.exec();
	QString jedla = QFileDialog::getOpenFileName(this, tr("Vyber subor s jedlami"), "C:\\Users\\PC\\Desktop\\cpp\\jedalen\\databazy", tr("Image Files (*.csv)"));

	// otvorenie a overenie otvorenia suboru
	QFile subor(jedla);

	if (!subor.open(QFile::ReadOnly | QFile::Text))
	{
		QMessageBox::warning(this, "Chyba", "subor sa neotvoril");
		return;
	}

	// precitanie suboru a zavretie suboru
	for (int i = 0; i < 7; i++)
		menu[i].clear();

	QTextStream in(&subor);

	in.readLine();	// preskocenie 1 vysvetlovacieho riadku

	QStringList x = in.readLine().split(",");

	while (x.length() == 3)
	{
		if (x[0] == "Pondelok")		menu[0].append(Jedlo(x));
		else if (x[0] == "Utorok")	menu[1].append(Jedlo(x));
		else if (x[0] == "Streda")	menu[2].append(Jedlo(x));
		else if (x[0] == "Stvrtok")	menu[3].append(Jedlo(x));
		else if (x[0] == "Piatok")	menu[4].append(Jedlo(x));
		else if (x[0] == "Sobota")	menu[5].append(Jedlo(x));
		else if (x[0] == "Nedela")	menu[6].append(Jedlo(x));

		x = in.readLine().split(",");
	}

	subor.close();
}

void jedalen::nacitaj_uzivatelov()
{
	// otvorenie a overenie otvorenia suboru
	QFile subor("C:\\Users\\PC\\Desktop\\cpp\\jedalen\\databazy\\uzivatelia.csv");

	if (!subor.open(QFile::ReadOnly | QFile::Text))
	{
		QMessageBox::warning(this, "Chyba", "subor sa neotvoril");
		return;
	}

	// precitanie suboru, vycistenie povodnych zoznamov stravnik. a pracov.

	pracovnici.clear();
	stravnici.clear();

	QTextStream in(&subor);

	in.readLine();	// preskocenie 1 vysvetlovacieho riadku

	QStringList uzivatel = in.readLine().split(",");

	while (uzivatel.length() == 10)
	{
		if (uzivatel[0] == "pracovnik")
		{
			if (uzivatel[1] == "pokladnik")
				pracovnici.append(pokladnik(uzivatel));
			if (uzivatel[1] == "kuchar")
				pracovnici.append(kuchar(uzivatel));
			if (uzivatel[1] == "pomoc_personal")
				pracovnici.append(pomoc_personal(uzivatel));
			if (uzivatel[1] == "admin")
				pracovnici.append(admin(uzivatel));
		}
		if (uzivatel[0] == "stravnik")
		{
			stravnici.append(stravnik(uzivatel));
		}

		uzivatel = in.readLine().split(",");
	}

	subor.close();
}

uzivatel* jedalen::najdi_uziv(QString u_meno)
{
	qDebug() << u_meno;
	for (QList<pracovnik>::iterator i = pracovnici.begin(); i != pracovnici.end(); i++)
	{
		if (i->U_meno() == u_meno)
			return i;
	}

	for (QList<stravnik>::iterator i = stravnici.begin(); i != stravnici.end(); i++)
	{
		if (i->U_meno() == u_meno)
			return i;
	}
	return nullptr;
}

