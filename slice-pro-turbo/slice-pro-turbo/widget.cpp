#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    ui->label->setText("Здравствуйте Александр Андреевич, Хорошего Вам Дня !!! <3");
}


void Widget::on_openStlAction_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открытый файл", QDir::homePath());
    QFile   file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "Файл не был открыт");
    }

    QMessageBox::information(this, "../", "Файл: " + fileName + " был открыт");

    QTextStream in(&file);
    QString text = in.readAll();
    file.close();

    //text parser here

    qDebug() << text;
}
