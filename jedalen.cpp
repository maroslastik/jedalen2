#include "jedalen.h"
#include "prihlasokno.h"

#include <QFileDialog>
#include <QMessagebox>
#include <QInputDialog>
#include <QtCore/QtCore>

#include <iostream>
#include <string>

jedalen::jedalen(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	nacitaj_uzivatelov();
	nacitaj_jedla();
	qDebug() << "idem na objednavky";
	nacitaj_objednavky();
	qDebug() << "dal som objednavky";
	otvor_po();
	connect(po, &QWidget::destroyed, this, &jedalen::prihlasenie);
}


// obsluha prihlasovacieho okna
	// otvor_po a zatvor_po obsluhuju prihlasovacie okno
void jedalen::otvor_po()
{
	this->hide();
	po = new prihlasokno();
	po->show();
	vypis_uziv(pracovnici, stravnici);
	connect(po->ui.prihlasit_sa, &QPushButton::clicked, this, &jedalen::zatvor_po);
}

void jedalen::zatvor_po()
{
	if (najdi_uziv(po->ui.zoz_uziv->currentItem()->text())->Heslo() == po->ui.heslo->text())
	{
		prihlaseny = najdi_uziv(po->ui.zoz_uziv->currentItem()->text());
		this->show();
		po->deleteLater();
		prihlasenie();
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText(QString("Nespravne meno alebo heslo."));
		msgBox.exec();
	}
}

	// nacitaj_... ukladaju data z databaz do widgetu

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

	// preskocenie 1 vysvetlovacieho riadku
	
	QStringList x = in.readLine().split(",");
	
	while (!in.atEnd())
	{
		x = in.readLine().split(",");
		if (x[0] == "Pondelok")		menu[0].append(Jedlo(x[0], x[1], x[2].toDouble(), x[3].toInt()));
		else if (x[0] == "Utorok")	menu[1].append(Jedlo(x[0], x[1], x[2].toDouble(), x[3].toInt()));
		else if (x[0] == "Streda")	menu[2].append(Jedlo(x[0], x[1], x[2].toDouble(), x[3].toInt()));
		else if (x[0] == "Stvrtok")	menu[3].append(Jedlo(x[0], x[1], x[2].toDouble(), x[3].toInt()));
		else if (x[0] == "Piatok")	menu[4].append(Jedlo(x[0], x[1], x[2].toDouble(), x[3].toInt()));
		else if (x[0] == "Sobota")	menu[5].append(Jedlo(x[0], x[1], x[2].toDouble(), x[3].toInt()));
		else if (x[0] == "Nedela")	menu[6].append(Jedlo(x[0], x[1], x[2].toDouble(), x[3].toInt()));
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

	// preskocenie 1 vysvetlovacieho riadku

	QStringList uzivatel = in.readLine().split(",");

	while (!in.atEnd())
	{
		uzivatel = in.readLine().split(",");
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

		
	}

	subor.close();
}

void jedalen::nacitaj_objednavky()
{
	QFile subor("C:\\Users\\PC\\Desktop\\cpp\\jedalen\\databazy\\objednavky.csv");

	if (!subor.open(QFile::ReadOnly | QFile::Text))
	{
		QMessageBox::warning(this, "Chyba", "Subor sa neotvoril");
		return;
	}

	QTextStream in(&subor);
		// preskocenie 1 vysvetlovacieho riadku

	QStringList riadok = in.readLine().split(",");
	uzivatel* zakaznik = najdi_uziv(riadok[0]);
	int iden = (riadok[1].toInt() / 100) % 10 - 1;
	
	while (!in.atEnd())
	{
		riadok = in.readLine().split(",");
		zakaznik = najdi_uziv(riadok[0]);
		iden = (riadok[1].toInt() / 100) % 10 - 1;
		if (skontroluj_id(riadok[1].toInt()) and zakaznik != nullptr)
		{
			zakaznik->objednane[iden].append(Jedlo(najdi_jedlo(riadok[1].toInt())));
			zakaznik = nullptr;
		}
	}
	subor.close();
}
	
	// pomocne funkcie

uzivatel* jedalen::najdi_uziv(QString u_meno)
{
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

QStringList jedalen::najdi_jedlo(int id)
{
	QStringList je;
	je.resize(4);

	for (int i = 0; i < 7; i++)
	{
		for (QList<Jedlo>::iterator j = menu[i].begin(); j != menu[i].end(); j++)
		{
			if (j->Id() == id)
			{
				je[0] = j->Den();
				je[1] = j->Nazov();
				je[2] = QString::number(j->Cena());
				je[3] = QString::number(j->Id());
			}
		}
	}
	return je;
}

void jedalen::vypis_uziv(QList<pracovnik>& pracovnici, QList<stravnik>& stravnici)
{
	po->ui.zoz_uziv->blockSignals(true);

	for (size_t i = 0; i < pracovnici.size(); i++)
	{
		QString uz = QString("%1").arg(pracovnici[i].U_meno());

		QListWidgetItem* item = new QListWidgetItem(uz);
		po->ui.zoz_uziv->addItem(item);
	}

	for (size_t i = 0; i < stravnici.size(); i++)
	{
		QString uz = QString("%1").arg(stravnici[i].U_meno());

		QListWidgetItem* item = new QListWidgetItem(uz);
		po->ui.zoz_uziv->addItem(item);
	}

	po->ui.zoz_uziv->blockSignals(false);
	po->ui.zoz_uziv->setCurrentRow(0);
}


// obsluha hlavneho okna

// fcia nastavi hlavne okno vzdy po prihlaseni
void jedalen::nastav_okno()
{
	ui.uz_meno->setText(prihlaseny->Meno());
	ui.kredit->setValue(prihlaseny->Kredit());
	on_den_currentIndexChanged();
	vypis_objednavky();
}

// slot meni dostupne jedla podla dna
void jedalen::on_den_currentIndexChanged()
{
	int index = ui.den->currentIndex();
	ui.dostupne_zoz->setRowCount(0);
	ui.dostupne_zoz->setColumnCount(2);

	for (size_t i = 0; i < menu[index].size(); i++)
	{
		ui.dostupne_zoz->insertRow(i);
		QTableWidgetItem* nazov = new QTableWidgetItem(QString("%1").arg(menu[index][i].Nazov()));
		QTableWidgetItem* cena = new QTableWidgetItem(QString("%1").arg(menu[index][i].Cena()));

		ui.dostupne_zoz->setItem(i, 0, nazov);
		ui.dostupne_zoz->setItem(i, 1, cena);
	}
}

// fcia sa vykona vzdy po prihlaseni - momentalne zbytocna, mozno na citanie suboru objednavok
void jedalen::prihlasenie()
{
	nastav_okno();
	prepis_subor_objednavok();
}

// slot odhlasi uzivatela, ulozi jeho objednavky a otvori prihlasovacie okno
void jedalen::on_odhlasit_sa_triggered()
{
	zapis_objednavky();
	otvor_po();
	this->close();
	prihlaseny = nullptr;
}

// slot po 2kliku prida objednavku, ak je dost kreditu
void jedalen::on_dostupne_zoz_itemDoubleClicked()
{
	int iden = ui.den->currentIndex(),
		ijedlo = ui.dostupne_zoz->currentItem()->row();
	
	if (prihlaseny->ZnizKredit(menu[iden][ijedlo].Cena()) < 0)
	{
		prihlaseny->ZvysKredit(menu[iden][ijedlo].Cena());
		QMessageBox msgBox;
		msgBox.setText(QString("Nedostatocny kredit."));
		msgBox.exec();
		return;
	}

	ui.kredit->setValue(prihlaseny->Kredit());
	
	int objednanych = prihlaseny->objednane[iden].size();
	prihlaseny->objednane[iden].append(menu[iden][ijedlo]);

	ui.objednane_zoz->insertRow(objednanych);

	QTableWidgetItem* nazov = new QTableWidgetItem(QString("%1").arg(menu[iden][ijedlo].Nazov()));
	QTableWidgetItem* cena = new QTableWidgetItem(QString("%1").arg(menu[iden][ijedlo].Cena()));
	QTableWidgetItem* den = new QTableWidgetItem(QString("%1").arg(menu[iden][ijedlo].Den()));

	ui.objednane_zoz->setItem(objednanych, 0, nazov);
	ui.objednane_zoz->setItem(objednanych, 1, cena);
	ui.objednane_zoz->setItem(objednanych, 2, den);
}

// slot zrusi kliknutu objednavku
void jedalen::on_zrusit_obj_clicked()
{
	// kontrola ci si uzivael nieco vybral
	if (ui.objednane_zoz->selectedItems().isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setText(QString("Nebolo vybrate ziadne jedlo."));
		msgBox.exec();
		return;
	}

	int iden = index_dna(ui.objednane_zoz->item(ui.objednane_zoz->currentItem()->row(), 2)->text()),
		ijedlo = ui.objednane_zoz->currentItem()->row();

	prihlaseny->ZvysKredit(prihlaseny->objednane[iden][ijedlo].Cena());
	prihlaseny->objednane[iden].removeAt(ijedlo);

	ui.objednane_zoz->removeRow(ijedlo);
	ui.kredit->setValue(prihlaseny->Kredit());
}

// funckia vypise objednavky uzivatela po prihlaseni
void jedalen::vypis_objednavky()
{
	ui.objednane_zoz->setRowCount(0);
	ui.objednane_zoz->setColumnCount(3);
	for (size_t iden = 0; iden < 7; iden++)
	{
		for (size_t ijedlo = 0; ijedlo < prihlaseny->objednane[iden].size(); ijedlo++)
		{
			ui.objednane_zoz->insertRow(iden+ijedlo-1);
			QTableWidgetItem* nazov = new QTableWidgetItem(QString("%1").arg(prihlaseny->objednane[iden][ijedlo].Nazov()));
			QTableWidgetItem* cena	= new QTableWidgetItem(QString("%1").arg(prihlaseny->objednane[iden][ijedlo].Cena()));
			QTableWidgetItem* den	= new QTableWidgetItem(QString("%1").arg(prihlaseny->objednane[iden][ijedlo].Den()));

			ui.objednane_zoz->setItem(iden+ijedlo-1, 0, nazov);
			ui.objednane_zoz->setItem(iden+ijedlo-1, 1, cena);
			ui.objednane_zoz->setItem(iden+ijedlo-1, 2, den);
		}
	}
}

// fcia skontroluje, ci existuje jedlo s id
bool jedalen::skontroluj_id(int kontrol_id)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < menu[i].size(); j++)
		{
			if (kontrol_id == menu[i][j].Id())
				return true;
		}
	}
	return false;
}

// fcia zapise subor objednavok bez prihlaseneho uz., jeho udaje sa appendnu po odhlaseni
void jedalen::prepis_subor_objednavok()
{
	QFile stary_subor("C:\\Users\\PC\\Desktop\\cpp\\jedalen\\databazy\\objednavky.csv");
	QFile novy_subor("C:\\Users\\PC\\Desktop\\cpp\\jedalen\\databazy\\objednavky_tmp.csv");

	if (!stary_subor.open(QFile::ReadOnly | QFile::Text))
	{
		QMessageBox::warning(this, "Chyba", "Stary subor sa neotvoril");
		return;
	}

	if (!novy_subor.open(QFile::WriteOnly | QFile::Text))
	{
		QMessageBox::warning(this, "Chyba", "Novy subor sa neotvoril");
		return;
	}

	QTextStream in(&stary_subor);
	QTextStream out(&novy_subor);

	QStringList riadok = in.readLine().split(",");
	out << "uzivatelske_meno,id\n";

	while (!in.atEnd())
	{
		riadok = in.readLine().split(",");
		if (riadok[0] == prihlaseny->U_meno())
			continue;
		out << riadok[0] << "," << riadok[1] << "\n";
	}

	stary_subor.remove();
	if (!novy_subor.rename("C:\\Users\\PC\\Desktop\\cpp\\jedalen\\databazy\\objednavky.csv"))
	{
		QMessageBox::warning(this, "Chyba", "Subor sa neprepisal");
		return;
	}
	novy_subor.close();
}

// fcia appendne objednavky prave odhlaseneho uzivatela
void jedalen::zapis_objednavky()
{
	QFile subor("C:\\Users\\PC\\Desktop\\cpp\\jedalen\\databazy\\objednavky.csv");

	if (!subor.open(QFile::WriteOnly | QIODevice::Append |QFile::Text))
	{
		QMessageBox::warning(this, "Chyba", "Subor sa neotvoril");
		return;
	}

	QTextStream out(&subor);

	for (size_t iden = 0; iden < 7; iden++)
	{
		for (size_t ijedlo = 0; ijedlo < prihlaseny->objednane[iden].size(); ijedlo++)
		{
			out << prihlaseny->U_meno() << "," << prihlaseny->objednane[iden][ijedlo].Id() << "\n";
		}
	}

	subor.close();
}