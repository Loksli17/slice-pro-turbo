#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QObject>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

private:
    void normalizeAngle(int *angle);

    int xRot;
    int yRot;
    int zRot;

    QPoint lastPos;
};

#endif // GLWIDGET_H
