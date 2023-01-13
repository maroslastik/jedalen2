#include "jedalen.h"
#include "prihlasokno.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    jedalen w;
    prihlasokno p;
    p.show();   // toto okno automaticky otvori jedalen ak sa uzivatel uspesne pruhalsi vo funckii on_prihlasit_sa_released()
    return a.exec();
}
