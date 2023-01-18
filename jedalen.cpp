#include "jedalen.h"

#include <QFileDialog>
#include <QMessagebox>
#include <QInputDialog>
#include <QtCore/QtCore>

jedalen::jedalen(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	nacitaj_uzivatelov();
	otvor_po();
}

jedalen::~jedalen()
{
	zapis_uzivatelov();
}

// obsluha hlavneho okna

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
	nacitane_jedla = true;
	nacitaj_objednavky(); // daju sa citat len ak su nacitane jedla
	on_den_currentIndexChanged();
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
			else if (uzivatel[1] == "kuchar")
				pracovnici.append(kuchar(uzivatel));
			else if (uzivatel[1] == "pomoc_personal")
				pracovnici.append(pomoc_personal(uzivatel));
			else if (uzivatel[1] == "admin")
				pracovnici.append(admin(uzivatel));
		}
		else if (uzivatel[0] == "stravnik")
		{
			if (uzivatel[1] == "zamestnanec")
				stravnici.append(zamestnanec(uzivatel));
			else if (uzivatel[1] == "student")
				stravnici.append(student(uzivatel));
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
	Jedlo* pridaj = najdi_jedlo(riadok[1].toInt());
	int iden = (riadok[1].toInt() / 100) % 10 - 1;
	
	while (!in.atEnd())
	{
		riadok = in.readLine().split(",");
		zakaznik = najdi_uziv(riadok[0]);
		pridaj = najdi_jedlo(riadok[1].toInt());
		iden = (riadok[1].toInt() / 100) % 10 - 1;
		if (skontroluj_id(riadok[1].toInt()) and zakaznik != nullptr)
		{
			zakaznik->objednane[iden].append(*pridaj);
			zakaznik = nullptr;
		}
	}

	subor.close();
}


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

Jedlo* jedalen::najdi_jedlo(int id)
{
	for (int iden = 0; iden < 7; iden++)
	{
		for (QList<Jedlo>::iterator ijedlo = menu[iden].begin(); ijedlo != menu[iden].end(); ijedlo++)
		{
			if (ijedlo->Id() == id)
				return ijedlo;
		}
	}
	return nullptr;
}

// obsluha hlavneho okna

void jedalen::prihlasenie()
{
	nastav_okno();
	if (!nacitane_jedla)
		return;
	prepis_subor_objednavok();
}

void jedalen::nastav_okno()
{
	ui.uz_meno->setText(prihlaseny->U_meno());
	ui.kredit->setValue(prihlaseny->Kredit());
	ui.menuKuchar->setEnabled(false);
	ui.menuAdmin->setEnabled(false);

	if (prihlaseny->Pozicia() == "kuchar" or prihlaseny->Pozicia() == "admin")
		ui.menuKuchar->setEnabled(true);
	if (prihlaseny->Pozicia() == "admin")
	{
		ui.menuAdmin->setEnabled(true);
		if (!nacitane_jedla)
			nacitaj_jedla();
	}

	if (!nacitane_jedla)
		QMessageBox::warning(this, "Chyba", "Admin este nenacital subor s jedlami");

	on_den_currentIndexChanged();
	vypis_dostupne(0);
}

void jedalen::vypis_dostupne(int index_dna)
{
	ui.objednane_zoz->setRowCount(0);
	ui.objednane_zoz->setColumnCount(3);
	for (size_t ijedlo = 0; ijedlo < prihlaseny->objednane[index_dna].size(); ijedlo++)
	{
		ui.objednane_zoz->insertRow(index_dna + ijedlo);
		QTableWidgetItem* nazov = new QTableWidgetItem(QString("%1").arg(prihlaseny->objednane[index_dna][ijedlo].Nazov()));
		QTableWidgetItem* cena = new QTableWidgetItem(QString("%1").arg(prihlaseny->objednane[index_dna][ijedlo].Cena()));
		QTableWidgetItem* den = new QTableWidgetItem(QString("%1").arg(prihlaseny->objednane[index_dna][ijedlo].Den()));

		ui.objednane_zoz->setItem(index_dna + ijedlo, 0, nazov);
		ui.objednane_zoz->setItem(index_dna + ijedlo, 1, cena);
		ui.objednane_zoz->setItem(index_dna + ijedlo, 2, den);
	}
	ui.objednane_zoz->resizeColumnsToContents();
}

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

void jedalen::prepis_subor_objednavok()
{
	if (!nacitane_jedla) return;

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

void jedalen::zapis_objednavky()
{
	QFile subor("C:\\Users\\PC\\Desktop\\cpp\\jedalen\\databazy\\objednavky.csv");

	if (!subor.open(QFile::WriteOnly | QIODevice::Append | QFile::Text))
	{
		QMessageBox::warning(this, "Chyba", "Subor sa neotvoril");
		return;
	}

	QTextStream out(&subor);
	for (size_t iden = 0; iden < 7; iden++)
	{
		for (size_t ijedlo = 0; ijedlo < prihlaseny->objednane[iden].size(); ijedlo++)
		{
			if (skontroluj_id(prihlaseny->objednane[iden][ijedlo].Id()))
			{
				out << prihlaseny->U_meno() << "," << prihlaseny->objednane[iden][ijedlo].Id() << "\n";
			}
		}
	}

	subor.close();
}

void jedalen::zapis_uzivatelov()
{
	QFile subor("C:\\Users\\PC\\Desktop\\cpp\\jedalen\\databazy\\uzivatelia.csv");
	subor.remove();
	if (!subor.open(QFile::WriteOnly | QFile::Text))
	{
		QMessageBox::warning(this, "Chyba", "Subor sa neotvoril");
		return;
	}

	QTextStream out(&subor);
	out << "typ,pozicia,meno,priezvisko,u_meno,heslo,oddelenie,odbor,kredit,zlava\n";

	for (size_t iuz = 0; iuz < pracovnici.size(); iuz++)
	{
		out << "pracovnik," << pracovnici[iuz].Pozicia() << "," << pracovnici[iuz].Meno() << "," << pracovnici[iuz].Priezvisko()
			<< "," << pracovnici[iuz].U_meno() << "," << pracovnici[iuz].Heslo() << "," << pracovnici[iuz].Oddelenie()
			<< "," << pracovnici[iuz].Odbor() << "," << pracovnici[iuz].Kredit() << "," << pracovnici[iuz].Zlava() << "\n";
	}

	for (size_t iuz = 0; iuz < stravnici.size(); iuz++)
	{
		out << "stravnik," << stravnici[iuz].Pozicia() << "," << stravnici[iuz].Meno() << "," << stravnici[iuz].Priezvisko()
			<< "," << stravnici[iuz].U_meno() << "," << stravnici[iuz].Heslo() << "," << stravnici[iuz].Oddelenie()
			<< "," << stravnici[iuz].Odbor() << "," << stravnici[iuz].Kredit() << "," << stravnici[iuz].Zlava() << "\n";
	}

	subor.close();
}

// obsluha prihlasovacieho okna

void jedalen::otvor_po()
{
	this->hide();
	po = new prihlasokno();
	po->show();
	po_vypis_uziv(pracovnici, stravnici);
	connect(po->po_ui.prihlasit_sa, &QPushButton::clicked, this, &jedalen::zatvor_po);
}

void jedalen::zatvor_po()
{
	if (najdi_uziv(po->po_ui.zoz_uziv->currentItem()->text())->Heslo() == po->po_ui.heslo->text())
	{
		prihlaseny = najdi_uziv(po->po_ui.zoz_uziv->currentItem()->text());
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

void jedalen::po_vypis_uziv(QList<pracovnik>& pracovnici, QList<stravnik>& stravnici)
{
	po->po_ui.zoz_uziv->blockSignals(true);

	for (size_t i = 0; i < pracovnici.size(); i++)
	{
		QString uz = QString("%1").arg(pracovnici[i].U_meno());

		QListWidgetItem* item = new QListWidgetItem(uz);
		po->po_ui.zoz_uziv->addItem(item);
	}

	for (size_t i = 0; i < stravnici.size(); i++)
	{
		QString uz = QString("%1").arg(stravnici[i].U_meno());

		QListWidgetItem* item = new QListWidgetItem(uz);
		po->po_ui.zoz_uziv->addItem(item);
	}
	po->po_ui.zoz_uziv->blockSignals(false);
	po->po_ui.zoz_uziv->setCurrentRow(0);
}

// obsluha okna spravy uzivatelov

void jedalen::otvor_su()
{
	this->hide();
	su = new sprava_uzivatelov();
	su->show();
	su_vypis_uziv(pracovnici, stravnici);
	connect(su->su_ui.ukonci, &QPushButton::clicked, this, &jedalen::zatvor_su);
	connect(su->su_ui.odstran_uz, &QPushButton::clicked, this, &jedalen::odstran_uzivatela);
	connect(su->su_ui.uloz_zmeny, &QPushButton::clicked, this, &jedalen::uloz_zmeny);
	connect(su->su_ui.pridaj_uz, &QPushButton::clicked, this, &jedalen::pridaj_uzivatela);
}

void jedalen::zatvor_su()
{
	this->show();
	su->deleteLater();
}

void jedalen::su_vypis_uziv(QList<pracovnik>& pracovnici, QList<stravnik>& stravnici) // tu chcem tabulku, nie zoznam - problem s dedicnostou
{
	su->su_ui.zoz_uzivatelov->setRowCount(0);
	su->su_ui.zoz_uzivatelov->setColumnCount(7);
	size_t i = 0;
	for (; i < pracovnici.size(); i++)
	{
		su->su_ui.zoz_uzivatelov->insertRow(i);
		QTableWidgetItem* pozicia = new QTableWidgetItem(QString("%1").arg(pracovnici[i].Pozicia()));
		QTableWidgetItem* meno = new QTableWidgetItem(QString("%1").arg(pracovnici[i].Meno()));
		QTableWidgetItem* priezvisko = new QTableWidgetItem(QString("%1").arg(pracovnici[i].Priezvisko()));
		QTableWidgetItem* u_meno = new QTableWidgetItem(QString("%1").arg(pracovnici[i].U_meno()));
		QTableWidgetItem* heslo = new QTableWidgetItem(QString("%1").arg(pracovnici[i].Heslo()));
		QTableWidgetItem* kredit = new QTableWidgetItem(QString("%1").arg(pracovnici[i].Kredit()));
		QTableWidgetItem* zlava = new QTableWidgetItem(QString("%1").arg(pracovnici[i].Zlava()));

		su->su_ui.zoz_uzivatelov->setItem(i, 0, pozicia);
		su->su_ui.zoz_uzivatelov->setItem(i, 1, meno);
		su->su_ui.zoz_uzivatelov->setItem(i, 2, priezvisko);
		su->su_ui.zoz_uzivatelov->setItem(i, 3, u_meno);
		su->su_ui.zoz_uzivatelov->setItem(i, 4, heslo);
		su->su_ui.zoz_uzivatelov->setItem(i, 5, kredit);
		su->su_ui.zoz_uzivatelov->setItem(i, 6, zlava);
	}

	for (size_t j = 0; j < stravnici.size(); j++)
	{
		su->su_ui.zoz_uzivatelov->insertRow(i + j);
		QTableWidgetItem* pozicia = new QTableWidgetItem(QString("%1").arg(stravnici[j].Pozicia()));
		QTableWidgetItem* meno = new QTableWidgetItem(QString("%1").arg(stravnici[j].Meno()));
		QTableWidgetItem* priezvisko = new QTableWidgetItem(QString("%1").arg(stravnici[j].Priezvisko()));
		QTableWidgetItem* u_meno = new QTableWidgetItem(QString("%1").arg(stravnici[j].U_meno()));
		QTableWidgetItem* heslo = new QTableWidgetItem(QString("%1").arg(stravnici[j].Heslo()));
		QTableWidgetItem* kredit = new QTableWidgetItem(QString("%1").arg(stravnici[j].Kredit()));
		QTableWidgetItem* zlava = new QTableWidgetItem(QString("%1").arg(stravnici[j].Zlava()));

		su->su_ui.zoz_uzivatelov->setItem(i + j, 0, pozicia);
		su->su_ui.zoz_uzivatelov->setItem(i + j, 1, meno);
		su->su_ui.zoz_uzivatelov->setItem(i + j, 2, priezvisko);
		su->su_ui.zoz_uzivatelov->setItem(i + j, 3, u_meno);
		su->su_ui.zoz_uzivatelov->setItem(i + j, 4, heslo);
		su->su_ui.zoz_uzivatelov->setItem(i + j, 5, kredit);
		su->su_ui.zoz_uzivatelov->setItem(i + j, 6, zlava);
	}
	su->su_ui.zoz_uzivatelov->resizeColumnsToContents();
}

void jedalen::odstran_uzivatela()
{
	if (su->su_ui.zoz_uzivatelov->selectedItems().isEmpty())
	{
		QMessageBox msgBox;
		msgBox.setText(QString("Nebol vybraty ziadny uzivatel."));
		msgBox.exec();
		return;
	}

	int iuziv = su->su_ui.zoz_uzivatelov->currentItem()->row();

	if (su->su_ui.zoz_uzivatelov->item(iuziv, 0)->text() == "admin")
	{
		QMessageBox msgBox;
		msgBox.setText(QString("Admin nemoze vymazat ineho admina"));
		msgBox.exec();
		return;
	}
	else if (su->su_ui.zoz_uzivatelov->item(iuziv, 0)->text() == "")
	{
		stravnici.removeAt(iuziv - pracovnici.size());
	}
	else
	{
		pracovnici.removeAt(iuziv);
	}

	su->su_ui.zoz_uzivatelov->removeRow(iuziv);
}

void jedalen::uloz_zmeny()
{
	int i = 0;

	for (; i < pracovnici.size(); i++) {
		pracovnici[i].setPozicia(su->su_ui.zoz_uzivatelov->item(i, 0)->text());
		pracovnici[i].setMeno(su->su_ui.zoz_uzivatelov->item(i, 1)->text());
		pracovnici[i].setPriezvisko(su->su_ui.zoz_uzivatelov->item(i, 2)->text());
		pracovnici[i].setU_meno(su->su_ui.zoz_uzivatelov->item(i, 3)->text());
		pracovnici[i].setHeslo(su->su_ui.zoz_uzivatelov->item(i, 4)->text());
		pracovnici[i].setKredit(su->su_ui.zoz_uzivatelov->item(i, 5)->text().toDouble());
		pracovnici[i].setZlava(su->su_ui.zoz_uzivatelov->item(i, 6)->text().toDouble());
	}

	for (int j = 0; j < stravnici.size(); j++) {
		stravnici[j].setPozicia(su->su_ui.zoz_uzivatelov->item(i + j, 0)->text());
		stravnici[j].setMeno(su->su_ui.zoz_uzivatelov->item(i + j, 1)->text());
		stravnici[j].setPriezvisko(su->su_ui.zoz_uzivatelov->item(i + j, 2)->text());
		stravnici[j].setU_meno(su->su_ui.zoz_uzivatelov->item(i + j, 3)->text());
		stravnici[j].setHeslo(su->su_ui.zoz_uzivatelov->item(i + j, 4)->text());
		stravnici[j].setKredit(su->su_ui.zoz_uzivatelov->item(i + j, 5)->text().toDouble());
		stravnici[j].setZlava(su->su_ui.zoz_uzivatelov->item(i + j, 6)->text().toDouble());
	}
	su_vypis_uziv(pracovnici, stravnici);
}

void jedalen::pridaj_uzivatela()
{
	int riadok = su->su_ui.zoz_uzivatelov->rowCount();
	QStringList pozicie;
	pozicie << "pokladnik" << "kuchar" << "pomoc_personal" << "admin" << "zamestnanec" << "student";
	QString pozicia = QInputDialog::getItem(this, "Vyber poziciu", "Vyber poziciu:", pozicie, 5, false);
	QString meno = QInputDialog::getText(this, "Zadaj meno", "Zadaj meno:");
	QString priezvisko = QInputDialog::getText(this, "Zadaj priezvisko", "Zadaj priezvisko:");
	QString u_meno = QInputDialog::getText(this, "Zadaj uzivatelske meno", "Zadaj uzivatelske meno:");
	QString heslo = QInputDialog::getText(this, "Zadaj heslo", "Zadaj heslo:");
	double kredit = QInputDialog::getDouble(this, "Zadaj kredit", "Zadaj kredit:", 0.0, 0.0, 2147483647, 2);
	double zlava = QInputDialog::getDouble(this, "Zadaj zlavu", "Zadaj zlavu:", 0.0, 0.0, 100.0, 2);

	if (pozicia == "student")
	{
		pozicia = "student";
		QString odbor = QInputDialog::getText(this, "Zadaj odbor", "Zadaj odbor:");
		stravnici.append(student(meno, priezvisko, u_meno, heslo, odbor, kredit, zlava, pozicia));
	}
	else if (pozicia == "zamestnanec")
	{
		pozicia = "zamestnanec";
		QString oddelenie = QInputDialog::getText(this, "Zadaj oddelenie", "Zadaj oddelenie:");
		stravnici.append(zamestnanec(meno, priezvisko, u_meno, heslo, oddelenie, kredit, pozicia));
	}
	else
	{
		pracovnici.append(pracovnik(meno, priezvisko, u_meno, heslo, pozicia, kredit));
	}
	su_vypis_uziv(pracovnici, stravnici);
}

// obsluha okna objednavok

void jedalen::otvor_ob()
{
	this->hide();
	ob = new okno_objednavok();
	ob->show();
	zmapuj_objednavky();
	ob_vypis_objednavky();
	connect(ob->ob_ui.ob_ukonci, &QPushButton::clicked, this, &jedalen::zatvor_ob);
}

void jedalen::zatvor_ob()
{
	this->show();
	ob->deleteLater();
}

void jedalen::zmapuj_objednavky()
{
	// inicializacia mapy
	for (size_t iden = 0; iden < 7; iden++)
	{
		for (size_t ijedlo = 0; ijedlo < menu[iden].size(); ijedlo++)
		{
			pocetnost_ob[iden][menu[iden][ijedlo].Nazov()] = 0;
		}
	}

	// iteracia cez prihlaseneho uzivatela
	for (size_t iden = 0; iden < 7; iden++)
	{
		for (QList<Jedlo>::iterator ijedlo = prihlaseny->objednane[iden].begin(); ijedlo != prihlaseny->objednane[iden].end(); ijedlo++)
		{
			pocetnost_ob[iden][ijedlo->Nazov()]++;
		}
	}

	// iteracia cez subor
	QFile subor("C:\\Users\\PC\\Desktop\\cpp\\jedalen\\databazy\\objednavky.csv");

	if (!subor.open(QFile::ReadOnly | QFile::Text))
	{
		QMessageBox::warning(this, "Chyba", "Subor sa neotvoril");
		return;
	}

	QTextStream in(&subor);
	// preskocenie 1 vysvetlovacieho riadku

	QStringList riadok = in.readLine().split(",");
	int iden = (riadok[1].toInt() / 100) % 10 - 1;

	while (!in.atEnd())
	{
		riadok = in.readLine().split(",");
		iden = (riadok[1].toInt() / 100) % 10 - 1;

		if (skontroluj_id(riadok[1].toInt()))
		{
			pocetnost_ob[iden][najdi_jedlo(riadok[1].toInt())->Nazov()]++;
		}
	}
	subor.close();
}

void jedalen::ob_vypis_objednavky()
{
	QString dni[7] = { "Pondelok", "Utorok", "Streda", "Stvrtok", "Piatok", "Sobota", "Nedela" };
	ob->ob_ui.objednavky_zoz->setColumnCount(2);
	for (int iden = 0; iden < 7; iden++)
	{
		QTreeWidgetItem* parent = new QTreeWidgetItem(ob->ob_ui.objednavky_zoz);
		parent->setText(0, dni[iden]);

		for (auto it = pocetnost_ob[iden].begin(); it != pocetnost_ob[iden].end(); it++)
		{
			QTreeWidgetItem* child = new QTreeWidgetItem();
			child->setText(0, QString("%1").arg(it->first));
			child->setText(1, QString("%1").arg(it->second));
			parent->addChild(child);
		}
		ob->ob_ui.objednavky_zoz->expandItem(parent);
	}
}

// private slots

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

	ui.dostupne_zoz->resizeColumnsToContents();
	vypis_dostupne(index);
}

void jedalen::on_odhlasit_sa_triggered()
{
	zapis_objednavky();
	otvor_po();
	this->close();
	prihlaseny = nullptr;
}

void jedalen::on_dostupne_zoz_itemDoubleClicked()
{
	int iden = ui.den->currentIndex(),
		ijedlo = ui.dostupne_zoz->currentItem()->row();
	double cenovy_obrat = menu[iden][ijedlo].Cena()- (menu[iden][ijedlo].Cena()*prihlaseny->Zlava())/100;

	if (prihlaseny->ZnizKredit(cenovy_obrat) < 0)
	{
		prihlaseny->ZvysKredit(cenovy_obrat);
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
	ui.objednane_zoz->resizeColumnsToContents();
}

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
		ijedlo = ui.objednane_zoz->currentItem()->row(); // hodnota v tabulke, nie v objednanych
	qDebug() << ijedlo << prihlaseny->objednane[iden].size() << "zvyskredit";
	prihlaseny->ZvysKredit(prihlaseny->objednane[iden][ijedlo].Cena());
	
	qDebug() << "vymaz z objednanych";
	prihlaseny->objednane[iden].removeAt(ijedlo);

	ui.objednane_zoz->removeRow(ijedlo);
	
	ui.kredit->setValue(prihlaseny->Kredit());
}

void jedalen::on_sprava_uzivatelov_triggered()
{
	otvor_su();
}

void jedalen::on_vycistit_system_triggered()
{
	int ret = QMessageBox::question(this, "Isto?", 
		"Vymaze sa vela udajov, \nodporucam najprv ulozit objednavky, chces naozaj vycistit system?", 
		QMessageBox::Yes | QMessageBox::No);

	if (ret == QMessageBox::No) 
	{
		return;
	}
	else 
	{
		for (int i = 0; i < 7; i++)
		{
			menu[i].clear();
			menu[i].resize(0);
		}

		for (int iprac = 0; iprac < pracovnici.size(); iprac++)
		{
			for (int iden = 0; iden < 7; iden++)
			{
				pracovnici[iprac].objednane[iden].clear();
				pracovnici[iprac].objednane[iden].resize(0);
			}
		}
		for (int istrav = 0; istrav < stravnici.size(); istrav++)
		{
			for (int iden = 0; iden < 7; iden++)
			{
				stravnici[istrav].objednane[iden].clear();
				stravnici[istrav].objednane[iden].resize(0);
			}
		}

		QFile subor("C:\\Users\\PC\\Desktop\\cpp\\jedalen\\databazy\\objednavky.csv");

		if (!subor.open(QFile::WriteOnly | QIODevice::Truncate))
		{
			QMessageBox::warning(this, "Chyba", "Subor sa neotvoril");
			return;
		}

		QTextStream out(&subor);

		out << "uzivatelske_meno,id\n";

		subor.close();
		nacitane_jedla = false;
	}

	nastav_okno();
}

void jedalen::on_zobrazit_obj_triggered()
{
	otvor_ob();
}

void jedalen::on_ulozit_obj_triggered()
{
	zmapuj_objednavky();
	QFile subor("C:\\Users\\PC\\Desktop\\cpp\\jedalen\\databazy\\pocetnostiobjednavok.csv");

	if (!subor.open(QFile::WriteOnly | QFile::Text))
	{
		QMessageBox::warning(this, "Chyba", "Stary subor sa neotvoril");
		return;
	}

	QTextStream out(&subor);

	out << "den\njedlo,id\n";
	for (int iden = 0; iden < 7; iden++)
	{
		out << iden << "\n";
		for (auto it = pocetnost_ob[iden].begin(); it != pocetnost_ob[iden].end(); it++)
		{
			out << it->first << "," << it->second << "\n";
		}
	}

	subor.close();
}

void jedalen::on_novy_subor_jedal_triggered()
{
	on_vycistit_system_triggered();
	nacitaj_jedla();
}
