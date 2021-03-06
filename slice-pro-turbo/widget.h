#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class GLWidget;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_toggled(bool checked);

    void on_SliceAuto_clicked();

    void on_saveGCode_clicked();

    void on_ResetButton_clicked();

    void on_RotateX_clicked();

    void on_RotateY_clicked();

    void on_RotateZ_clicked();

    void on_SliceAdaptive_clicked();

    void on_intersection_toggled(bool checked);

//    void on_pushButton_3_clicked();

    void removeFileName();
    void disableIntersection();
    void showMessage(QString text);
    void showStatusBarMessage(QString text);

    void on_drawGrid_clicked();

signals:
    void stlOpened(QFile* file);
    void toggleWireframe(bool show);
    void sliceAuto();
    void sliceAdaptive(double width);
    void createGCodeFile(QString file);
    void resetSlicing();
    void rotateBody(int axis);
    void intersection(bool checked);
    void setGridInIntersection();
    void createDiagramVoronov();

private:
    Ui::Widget *ui;
    QStatusBar *bar = new QStatusBar(this);
    GLWidget   *glWidget;

    QString fileName;
};
#endif // WIDGET_H
