#include "widget.h"
#include "glwidget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    glWidget = new GLWidget();
    connect(this, SIGNAL(stlOpened(QFile*)), glWidget, SLOT(getStl(QFile*)));
    connect(this, SIGNAL(toggleWireframe(bool)), glWidget, SLOT(toggleWireframe(bool)));
//    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), glWidget, SLOT(getInt(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открытый файл", QDir::homePath());
    QFile   file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "Файл не был открыт");
        return;
    } else QMessageBox::information(this, "../", "Файл: " + fileName + " был открыт");

    ui->widget->setFocus();
    emit stlOpened(&file);
}


void Widget::on_checkBox_toggled(bool checked)
{
    ui->widget->setFocus();
    emit toggleWireframe(checked);
}
