#include "jedalen.h"
#include "prihlasokno.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    jedalen w;
    return a.exec();
}
