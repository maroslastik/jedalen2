#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_jedalen.h"

#include "pomocne_fcie.h"
#include "prihlasokno.h"
#include "sprava_uzivatelov.h"
#include "okno_objednavok.h"

#include <iostream>
#include <string>
#include <map>

class uzivatel;
class Jedlo;
class pracovnik;
class stravnik;

class jedalen : public QMainWindow
{
    Q_OBJECT

protected:

    uzivatel* prihlaseny; // prave prihlaseny uzivatel
    QList<pracovnik*> pracovnici; // zoznam pracovnikov
    QList<stravnik*> stravnici; //zoznam stravnikov
    QList<Jedlo> menu[7]; // menu
    std::map<QString, int> pocetnost_ob[7]; // pocetnost objednavok
    bool nacitane_jedla = false; // info ci su vo widgete aktualne nahrate jedla

    prihlasokno* po;
    sprava_uzivatelov* su;
    okno_objednavok* ob;
public:

    jedalen(QWidget* parent = nullptr);
    ~jedalen();

    void nacitaj_jedla(); // nacita jedla do systemu
    void nacitaj_uzivatelov(); // nacita uzivatelov do systemu
    void nacitaj_objednavky(); // nacita objednavky do systemu

    uzivatel* najdi_uziv(QString u_meno); // najde uzivatela podla prihlasovacieho mena
    Jedlo* najdi_jedlo(int id); // najde jedlo podla id

    // obsluha hlavneho okna
    void prihlasenie(); // vykona sa vzdy po rpihlaseni novehu uzivatela
    void nastav_okno(); // nastavi hlavne okno ked treba
    void vypis_dostupne(int index_dna); // vypise dostupne jedla podla indexu dna 
    bool skontroluj_id(int kontrol_id); // skontroluje, ci existuje v systeme jedlo s id
    void prepis_subor_objednavok(); // prepise subor objednavok bez akt. prihlas uzivatela
    void zapis_objednavky(); // zapise objednavky akt. prihlas uzivatela
    void zapis_uzivatelov(); // zapise uzivatelov a ich zmeny

    // obsluha prihlasovacieho okna
    void otvor_po(); // otvori a nastavi prihlasovacie okno
    void zatvor_po(); // zatvori okno
    void po_vypis_uziv(QList<pracovnik*>& pracovnici, QList<stravnik*>& stravnici); // vypise uzivatelov do prihlas okna

    // obsluha okna spravy uzivatelov
    void otvor_su(); // otvori a nastavi okno
    void zatvor_su(); // zatvori okno
    void su_vypis_uziv(QList<pracovnik*>& pracovnici, QList<stravnik*>& stravnici); // vypise uzivatelov do spravy uzivatelov
    void odstran_uzivatela(); // odstrani zakliknuteho uzivatela
    void uloz_zmeny(); // ulozi zmeny
    void pridaj_uzivatela(); // prida uzivatela

    //obsluha okna objednavok
    void otvor_ob(); // otvori okno objednavok a nastavi
    void zatvor_ob(); // zatvori okno
    void zmapuj_objednavky(); // zrata vsetky objednavky v systeme do mapy
    void ob_vypis_objednavky(); // vypise pocety objednavok

private slots:
    void on_den_currentIndexChanged(); // zmena dna - ukaze dostupne a objednane v den
    void on_odhlasit_sa_triggered(); // odhlasenie
    void on_dostupne_zoz_itemDoubleClicked(); // objednavanie
    void on_zrusit_obj_clicked(); // zrusenie objednaneho jedla
    void on_sprava_uzivatelov_triggered(); // otvori okno srpavy uzivatelov
    void on_vycistit_system_triggered(); // vycisti system (Zachova subor jedal, uzivatelov, zmaze subor objednavok)
    void on_zobrazit_obj_triggered(); // otvori okno objednavok
    void on_ulozit_obj_triggered(); // ulozi do suboru pocetnost objednavok
    void on_novy_subor_jedal_triggered(); // umozni nahrat novy subor jedal, zaroven sa vycisti system

private:
    Ui::jedalenClass ui;
};

class uzivatel
{
    friend class jedalen;
protected:

    QString meno, priezvisko, u_meno, heslo, pozicia;
    double kredit;

    QList<Jedlo> objednane[7]; // objednane jedla kazdeho uzivatela

public:
    uzivatel() { meno = ""; priezvisko = ""; u_meno = ""; heslo = ""; kredit = 0; }
    uzivatel(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, double nkredit, QString npozicia) :
        meno(nmeno), priezvisko(npriezvisko), u_meno(nu_meno), heslo(nheslo), kredit(nkredit), pozicia(npozicia) {}
    ~uzivatel() {}
    
    QString Meno() { return meno; }
    QString Priezvisko() { return priezvisko; }
    QString U_meno() { return u_meno; }
    QString Heslo() { return heslo; }
    double Kredit() { return kredit; }
    QString Pozicia() { return pozicia; }

    void setMeno(QString n_meno) { meno = n_meno; }
    void setPriezvisko(QString n_priezvisko) { priezvisko = n_priezvisko; }
    void setU_meno(QString n_u_meno) { u_meno = n_u_meno; }
    void setHeslo(QString n_heslo) { heslo = n_heslo; }
    void setKredit(double n_kredit) { kredit = n_kredit; }
    void setPozicia(QString n_pozicia) { pozicia = n_pozicia; }

    double ZnizKredit(double mensitel) { return kredit -= mensitel; }
    double ZvysKredit(double scitanec) { return kredit += scitanec; }

    virtual void setOdbor(QString n_odbor) { }
    virtual void setOddelenie(QString n_oddelenie) { }
    virtual void setZlava(double n_zlava) { }

    virtual double Zlava() { return 0; }
    virtual QString Odbor() { return NULL; }
    virtual QString Oddelenie() { return NULL; }
};

class pracovnik : public uzivatel
{
public:
    pracovnik() { meno = ""; priezvisko = ""; u_meno = ""; heslo = "", kredit = 0; }
    pracovnik(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString npozicia, double nkredit) :
        uzivatel(nmeno, npriezvisko, nu_meno, nheslo, nkredit, npozicia) {}
    pracovnik(QStringList uz) :
        uzivatel(uz[2], uz[3], uz[4], uz[5], uz[8].toDouble(), uz[1]) {}
    ~pracovnik() {}
};

class pokladnik : public pracovnik
{
public:
    pokladnik(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString npozicia, double nkredit) :
        pracovnik(nmeno, npriezvisko, nu_meno, nheslo, npozicia, nkredit) {}
    pokladnik(QStringList uz) :
        pracovnik(uz[2], uz[3], uz[4], uz[5], uz[1], uz[8].toDouble()) {}
    ~pokladnik() {}
};

class kuchar : public pracovnik
{
public:
    kuchar(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString npozicia, double nkredit) :
        pracovnik(nmeno, npriezvisko, nu_meno, nheslo, npozicia, nkredit) {}
    kuchar(QStringList uz) :
        pracovnik(uz[2], uz[3], uz[4], uz[5], uz[1], uz[8].toDouble()) {}
    ~kuchar() {}
};

class pomoc_personal : public pracovnik
{
public:
    pomoc_personal(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString npozicia, double nkredit) :
        pracovnik(nmeno, npriezvisko, nu_meno, nheslo, npozicia, nkredit) {}
    pomoc_personal(QStringList uz) :
        pracovnik(uz[2], uz[3], uz[4], uz[5], uz[1], uz[8].toDouble()) {}
    ~pomoc_personal() {}
};

class admin : public pracovnik
{
public:
    admin(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString npozicia, double nkredit) :
        pracovnik(nmeno, npriezvisko, nu_meno, nheslo, npozicia, nkredit) {}
    admin(QStringList uz) :
        pracovnik(uz[2], uz[3], uz[4], uz[5], uz[1], uz[8].toDouble()) {}
    ~admin() {}
};

class stravnik : public uzivatel
{
public:
    stravnik() { meno = ""; priezvisko = ""; u_meno = ""; heslo = "", kredit = 0; }
    stravnik(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, double nkredit, QString npozicia) :
        uzivatel(nmeno, npriezvisko, nu_meno, nheslo, nkredit, npozicia) {}
    stravnik(QStringList uz) :
        uzivatel(uz[2], uz[3], uz[4], uz[5], uz[8].toDouble(), uz[1]) {}
    ~stravnik() {}

    virtual double Zlava() { return 0; }
    virtual QString Odbor() { return NULL; }
    virtual QString Oddelenie() { return NULL; }

    virtual void setOdbor(QString n_odbor) { }
    virtual void setOddelenie(QString n_oddelenie) { }
    virtual void setZlava(double n_zlava) { }
};

class student : public stravnik
{
protected: 

    QString odbor;
    double zlava;

public:

    student(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString nodbor, double nkredit, double nzlava, QString npozicia) :
        stravnik(nmeno, npriezvisko, nu_meno, nheslo, nkredit, npozicia), odbor(nodbor) ,zlava(nzlava) {}
    student(QStringList uz) :
        stravnik(uz[2], uz[3], uz[4], uz[5], uz[8].toDouble(), uz[1]), odbor(uz[7]), zlava(uz[9].toDouble()) {}
    ~student() {}

    QString Odbor() override { return odbor; }
    double Zlava() { return zlava; }

    void setOdbor(QString n_odbor) { odbor = n_odbor; }
    void setZlava(double n_zlava) { zlava = n_zlava; }
};

class zamestnanec : public stravnik
{
protected:

    QString oddelenie;

public:

    zamestnanec(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString noddelenie, double nkredit, QString npozicia) :
        stravnik(nmeno, npriezvisko, nu_meno, nheslo, nkredit, npozicia), oddelenie(noddelenie) {}
    zamestnanec(QStringList uz) :
        stravnik(uz[2], uz[3], uz[4], uz[5], uz[8].toDouble(), uz[1]), oddelenie(uz[6]) {}
    ~zamestnanec() {}

    QString Oddelenie() { return oddelenie; }
    void setOddelenie(QString n_oddelenie) { oddelenie = n_oddelenie; }
};

class Jedlo
{    
    friend jedalen;
protected:

    QString den, nazov;
    double cena;
    int ID;

public:
    
    Jedlo() { den = "Pondelok"; nazov = "Prazdny tanier"; cena = 0; ID = 0; }
    Jedlo(QString nden, QString nnazov, double ncena, int nid) { den = nden; nazov = nnazov; cena = ncena; ID = nid; }
    Jedlo(QStringList je) :
        den(je[0]), nazov(je[1]), cena(je[2].toDouble()), ID(je[3].toInt()) {}
    ~Jedlo() {}

    QString Den() { return den; }
    QString Nazov() { return nazov; }
    double Cena() { return cena; }
    int Id() { return ID; }

    void setDen(QString n_den) { den = n_den; }
    void setNazov(QString n_nazov) { nazov = n_nazov; }
    void setCena(double n_cena) { cena = n_cena; }
    void setId(int n_id) { ID = n_id; }
};
