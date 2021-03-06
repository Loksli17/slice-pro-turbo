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
    ui->messageLayout->addWidget(bar);
    glWidget = new GLWidget();
    connect(this, SIGNAL(stlOpened(QFile *)),       glWidget, SLOT(getStl(QFile *)));
    connect(this, SIGNAL(toggleWireframe(bool)),    glWidget, SLOT(toggleWireframe(bool)));
    connect(this, SIGNAL(sliceAuto()),              glWidget, SLOT(sliceAuto()));
    connect(this, SIGNAL(sliceAdaptive(double)),    glWidget, SLOT(sliceAdaptive(double)));
    connect(this, SIGNAL(createGCodeFile(QString)), glWidget, SLOT(createGCodeFile(QString)));
    connect(this, SIGNAL(resetSlicing()),           glWidget, SLOT(resetSliceState()));
    connect(this, SIGNAL(rotateBody(int)),          glWidget, SLOT(rotateBody(int)));
    connect(this, SIGNAL(intersection(bool)),       glWidget, SLOT(intersection(bool)));
    connect(this, SIGNAL(setGridInIntersection()),  glWidget, SLOT(setInnerPointsGrid()));
    connect(this, SIGNAL(createDiagramVoronov()),   glWidget, SLOT(createDiagramVoronov()));
    //    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), glWidget, SLOT(getInt(int)));

    connect(glWidget, SIGNAL(showMessage(QString)),  this, SLOT(showMessage(QString)));
    connect(glWidget, SIGNAL(removeFileName()),  this, SLOT(removeFileName()));
    connect(glWidget, SIGNAL(disableIntersection()), this, SLOT(disableIntersection()));
    connect(glWidget, SIGNAL(showStatusBarMessage(QString)), this, SLOT(showStatusBarMessage(QString)));

    ui->groupBox->setDisabled(true);
    ui->groupBox_2->setDisabled(true);
    ui->SliceAdaptiveSpinBox->setDisabled(true);
    ui->checkBox->setDisabled(true);
    ui->intersection->setDisabled(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Открытый файл", QDir::homePath(), tr("STL-files (*.stl)"));
    QFile   file(filePath);

    QStringList lst = filePath.split('/');
    fileName = lst[lst.count() - 1];

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Ошибка", "Файл не был открыт");
        return;
    } else QMessageBox::information(this, "Успех", "Файл: " + fileName + " был открыт");

    ui->widget->setFocus();
    emit stlOpened(&file);

    bar->showMessage(fileName + " was opened successfully", 2000);
    ui->FileName->setText(fileName);

    ui->groupBox->setDisabled(false);
    ui->groupBox_2->setDisabled(false);
//    ui->groupBox_3->setDisabled(false);
    ui->SliceAdaptiveSpinBox->setDisabled(false);
    ui->checkBox->setDisabled(false);
    ui->intersection->setDisabled(false);
}


void Widget::on_checkBox_toggled(bool checked)
{
    ui->widget->setFocus();
    emit toggleWireframe(checked);
}


void Widget::on_SliceAuto_clicked()
{
    ui->widget->setFocus();
    emit sliceAuto();
}


void Widget::on_saveGCode_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               QDir::homePath(),
                               tr("GcodeFiles (*.gcode)"));
    qDebug() << fileName;

    emit createGCodeFile(fileName);

    bar->showMessage(fileName + " was created successfully", 2000);
}

void Widget::on_ResetButton_clicked()
{
    ui->widget->setFocus();
    emit resetSlicing();
}

void Widget::on_RotateX_clicked()
{
    ui->widget->setFocus();
    emit rotateBody(0);
}

void Widget::on_RotateY_clicked()
{
    ui->widget->setFocus();
    emit rotateBody(1);
}

void Widget::on_RotateZ_clicked()
{
    ui->widget->setFocus();
    emit rotateBody(2);
}

void Widget::on_SliceAdaptive_clicked()
{
    ui->widget->setFocus();
    double val = ui->SliceAdaptiveSpinBox->value();
    emit sliceAdaptive(val);
}

void Widget::on_intersection_toggled(bool checked)
{
    ui->widget->setFocus();
    emit intersection(checked);
}

void Widget::removeFileName()
{
    ui->FileName->setText("File not open");
    ui->groupBox->setDisabled(true);
    ui->groupBox_2->setDisabled(true);
//    ui->groupBox_3->setDisabled(true);
    ui->SliceAdaptiveSpinBox->setDisabled(true);
    ui->checkBox->setDisabled(true);
    ui->intersection->setDisabled(true);
}

//void Widget::on_pushButton_3_clicked()
//{
//    ui->widget->setFocus();
//    emit setGridInIntersection();
//}

void Widget::disableIntersection()
{
    ui->intersection->setChecked(false);
}

void Widget::showMessage(QString text)
{
    QMessageBox::warning(this, "Ошибка", text);
}

void Widget::showStatusBarMessage(QString text)
{
    bar->showMessage(text, 2000);
}

void Widget::on_drawGrid_clicked()
{
    ui->widget->setFocus();
    emit createDiagramVoronov();
}
