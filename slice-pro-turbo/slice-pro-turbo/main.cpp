#include "widget.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    qDebug()<<"Моя жопа";
    qDebug() << "РУКАВ ВСЕ ЕЩЕ ХУ*";
    qDebug() << "HAHAHAHA";
    qDebug() << "а у мя работает :)";
    return a.exec();
}
