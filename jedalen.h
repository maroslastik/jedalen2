#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_jedalen.h"
#include "pomocne_fcie.h"

class prihlasokno;
class uzivatel;
class pracovnik;
class pokladnik;
class kuchar;
class pomoc_personal;
class admin;
class stravnik;
class student;
class zamestnanec;
class Jedlo;

class jedalen : public QMainWindow
{
    friend class prihlasokno;
    Q_OBJECT

public:
    jedalen(QWidget* parent = nullptr);
    ~jedalen() {}

    uzivatel* prihlaseny;
    QList<pracovnik> pracovnici;
    QList<stravnik> stravnici;
    QList<Jedlo> menu[7];

    // obsluha prihlasovacieho okna
    prihlasokno* po;
    void otvor_po();
    void zatvor_po();
    void nacitaj_jedla();
    void nacitaj_uzivatelov();
    uzivatel* najdi_uziv(QString u_meno);
    void vypis_uziv(QList<pracovnik>& pracovnici, QList<stravnik>& stravnici);

    // obsluha hlavneho okna
    void prihlasenie();
    void nastav_okno();
    void vypis_objednavky();

private slots:
    void on_den_currentIndexChanged();
    void on_odhlasit_sa_triggered();
    void on_dostupne_zoz_itemDoubleClicked();
    void on_zrusit_obj_clicked();


private:
    Ui::jedalenClass ui;
};

class uzivatel
{
protected:
    QString meno, priezvisko, u_meno, heslo;
        double kredit;
public:
    uzivatel(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, double nkredit) :
        meno(nmeno), priezvisko(npriezvisko), u_meno(nu_meno), heslo(nheslo), kredit(nkredit) {}
    ~uzivatel() {}
    
    QString Meno() { return meno; }
    QString Priezvisko() { return priezvisko; }
    QString U_meno() { return u_meno; }
    QString Heslo() { return heslo; }
    double Kredit() { return kredit; }

    double ZnizKredit(double mensitel) { return kredit -= mensitel; }
    double ZvysKredit(double scitanec) { return kredit += scitanec; }

    QList<Jedlo> objednane[7];
};

class pracovnik : public uzivatel
{
protected:
    QString pozicia;
public:
    pracovnik(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString npozicia, double nkredit) :
        uzivatel(nmeno, npriezvisko, nu_meno, nheslo, nkredit), pozicia(npozicia) {}
    pracovnik(QStringList uz) :
        uzivatel(uz[2], uz[3], uz[4], uz[5], uz[8].toDouble()) {}
    ~pracovnik() {}
    QString Pozicia() { return pozicia; }
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
    stravnik(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, double nkredit) :
        uzivatel(nmeno, npriezvisko, nu_meno, nheslo, nkredit) {}
    stravnik(QStringList uz) :
        uzivatel(uz[2], uz[3], uz[4], uz[5], uz[8].toDouble()) {}
    ~stravnik() {}
};

class student : public stravnik
{
protected:
    QString odbor;
    double zlava;
public:
    student(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString nodbor, double nkredit, double nzlava) :
        stravnik(nmeno, npriezvisko, nu_meno, nheslo, nkredit), odbor(nodbor) ,zlava(nzlava) {}
    student(QStringList uz) :
        stravnik(uz[2], uz[3], uz[4], uz[5], uz[8].toDouble()), odbor(uz[7]), zlava(uz[9].toDouble()) {}
    ~student() {}
    QString Odbor() { return odbor; }
};

class zamestnanec : public stravnik
{
protected:
    QString oddelenie;
public:
    zamestnanec(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString noddelenie, double nkredit) :
        stravnik(nmeno, npriezvisko, nu_meno, nheslo, nkredit), oddelenie(noddelenie) {}
    zamestnanec(QStringList uz) :
        stravnik(uz[2], uz[3], uz[4], uz[5], uz[8].toDouble()), oddelenie(uz[6]) {}
    ~zamestnanec() {}
};

class Jedlo
{
public:
    QString den, nazov;
    double cena;
    Jedlo(QString nden, QString nnazov, double ncena) { den = nden; nazov = nnazov; cena = ncena; }
    Jedlo(QStringList je) :
        den(je[0]), nazov(je[1]), cena(je[2].toDouble()) {}
    ~Jedlo() {}
    QString Den() { return den; }
    QString Nazov() { return nazov; }
    double Cena() { return cena; }
};
