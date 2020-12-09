#include "widget.h"
#include <QApplication>
#include <QDebug>
#include "GL/glut.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
