#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_jedalen.h"

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
    jedalen(QWidget *parent = nullptr);
    ~jedalen() {}

    uzivatel* prihlaseny;
    QList<pracovnik> pracovnici;
    QList<stravnik> stravnici;
    QList<Jedlo> menu[7];

    prihlasokno* po;

    void nacitaj_jedla();
    void nacitaj_uzivatelov();
    void prihlasenie();
    uzivatel* najdi_uziv(QString u_meno);
    bool prihlas() { if (prihlaseny == nullptr) return false; return true; }

    void vypis_uziv(QList<pracovnik>& pracovnici, QList<stravnik>& stravnici);
    void otvor_po();
    void zatvor_po();

private slots:

private:
    Ui::jedalenClass ui;
};


class uzivatel
{
protected:

public:
    uzivatel(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString nkredit) :
        meno(nmeno), priezvisko(npriezvisko), u_meno(nu_meno), heslo(nheslo), kredit(nkredit) {}
    ~uzivatel() {}
    QString meno, priezvisko, u_meno, heslo, kredit;
    QString Meno() { return meno; }
    QString Priezvisko() { return priezvisko; }
    QString U_meno() { return u_meno; }
    QString Heslo() { return heslo; }
};

class pracovnik : public uzivatel
{
protected:
    QString pozicia;
public:
    pracovnik(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString npozicia, QString nkredit) :
        uzivatel(nmeno, npriezvisko, nu_meno, nheslo, nkredit), pozicia(npozicia) {}
    pracovnik(QStringList uz) :
        uzivatel(uz[2], uz[3], uz[4], uz[5], uz[8]) {}
    ~pracovnik() {}
    QString Pozicia() { return pozicia; }
};

class pokladnik : public pracovnik
{
public:
    pokladnik(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString npozicia, QString nkredit) :
        pracovnik(nmeno, npriezvisko, nu_meno, nheslo, npozicia, nkredit) {}
    pokladnik(QStringList uz) :
        pracovnik(uz[2], uz[3], uz[4], uz[5], uz[1], uz[8]) {}
    ~pokladnik() {}
};

class kuchar : public pracovnik
{
public:
    kuchar(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString npozicia, QString nkredit) :
        pracovnik(nmeno, npriezvisko, nu_meno, nheslo, npozicia, nkredit) {}
    kuchar(QStringList uz) :
        pracovnik(uz[2], uz[3], uz[4], uz[5], uz[8], uz[1]) {}
    ~kuchar() {}
};

class pomoc_personal : public pracovnik
{
public:
    pomoc_personal(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString npozicia, QString nkredit) :
        pracovnik(nmeno, npriezvisko, nu_meno, nheslo, npozicia, nkredit) {}
    pomoc_personal(QStringList uz) :
        pracovnik(uz[2], uz[3], uz[4], uz[5], uz[8], uz[1]) {}
    ~pomoc_personal() {}
};

class admin : public pracovnik
{
public:
    admin(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString npozicia, QString nkredit) :
        pracovnik(nmeno, npriezvisko, nu_meno, nheslo, npozicia, nkredit) {}
    admin(QStringList uz) :
        pracovnik(uz[2], uz[3], uz[4], uz[5], uz[8], uz[1]) {}
    ~admin() {}
};

class stravnik : public uzivatel
{
public:
    stravnik(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString nkredit) :
        uzivatel(nmeno, npriezvisko, nu_meno, nheslo, nkredit) {}
    stravnik(QStringList uz) :
        uzivatel(uz[2], uz[3], uz[4], uz[5], uz[8]) {}
    ~stravnik() {}
};

class student : public stravnik
{
protected:
    QString odbor, zlava;
public:
    student(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString nodbor, QString nkredit) :
        stravnik(nmeno, npriezvisko, nu_meno, nheslo, nkredit), odbor(nodbor) {}
    student(QStringList uz) :
        stravnik(uz[2], uz[3], uz[4], uz[5], uz[8]), odbor(uz[7]), zlava(uz[9]) {}
    ~student() {}
    QString Odbor() { return odbor; }
};

class zamestnanec : public stravnik
{
protected:
    QString oddelenie;
public:
    zamestnanec(QString nmeno, QString npriezvisko, QString nu_meno, QString nheslo, QString noddelenie, QString nkredit) :
        stravnik(nmeno, npriezvisko, nu_meno, nheslo, nkredit), oddelenie(noddelenie) {}
    zamestnanec(QStringList uz) :
        stravnik(uz[2], uz[3], uz[4], uz[5], uz[8]), oddelenie(uz[6]) {}
    ~zamestnanec() {}
};

class Jedlo
{
public:
    QString den, nazov, cena;
    Jedlo(QString nden, QString nnazov, QString ncena) { den = nden; nazov = nnazov; cena = ncena; }
    Jedlo(QStringList je) :
        den(je[0]), nazov(je[1]), cena(je[2]) {}
    ~Jedlo() {}
    QString Den() { return den; }
    QString Nazov() { return nazov; }
    QString Cena() { return cena; }
};