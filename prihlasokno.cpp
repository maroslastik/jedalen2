#include "prihlasokno.h"

#include <QFileDialog>
#include <QMessagebox>
#include <QInputDialog>
#include <string>

prihlasokno::prihlasokno(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	jed = new jedalen();
	nacitaj_uzivatelov();
	
	nacitaj_jedla();
	vypis_uziv(pracovnici, stravnici);
}

prihlasokno::~prihlasokno()
{}

void prihlasokno::vypis_uziv(QList<pracovnik>&pracovnici,QList<stravnik>& stravnici)
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
}

void prihlasokno::nacitaj_jedla()
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

void prihlasokno::nacitaj_uzivatelov()
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

// zbytocna funkcia
char prihlasokno::prihlasenie()
{
	bool cancel = false;
	QString u_meno = QInputDialog::getText(NULL, "Prihlasovacie meno", "Prihlasovacie meno:", QLineEdit::Normal, "", &cancel);

	if (!cancel)
	{
		prihlaseny = nullptr;
		return 'f';
	}

	while (najdi_uziv(u_meno) == nullptr)
	{
		u_meno = QInputDialog::getText(NULL, "Nespravne prihlasovacie meno", "Prihlasovacie meno:", QLineEdit::Normal, "", &cancel);
		if (!cancel)
		{
			prihlaseny = nullptr;
			return 'f';
		}
	}

	prihlaseny = najdi_uziv(u_meno);

	qDebug() << prihlaseny->heslo;
	QString heslo = QInputDialog::getText(NULL, "Heslo", "Heslo:", QLineEdit::Password, "", &cancel);

	if (!cancel)
	{
		prihlaseny = nullptr;
		return 'f';
	}

	while (prihlaseny->heslo != heslo)
	{
		u_meno = QInputDialog::getText(NULL, "Nespravne heslo", "heslo:", QLineEdit::Password, "", &cancel);
		if (!cancel)
		{
			prihlaseny = nullptr;
			return 'f';
		}
	}
	return 't';
}

uzivatel* prihlasokno::najdi_uziv(QString u_meno)
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

void prihlasokno::on_prihlasit_sa_released()
{
	if(najdi_uziv(ui.zoz_uziv->currentItem()->text())->Heslo() == ui.heslo->text())
	{
		prihlaseny = najdi_uziv(ui.zoz_uziv->currentItem()->text());
		jed->show();
		this->hide();
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText(QString("Nespravne meno alebo heslo."));
		msgBox.exec();
	}
}
