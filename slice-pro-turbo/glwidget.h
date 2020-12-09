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
    void wheelEvent(QWheelEvent *event);

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
    float zoomScale;
    QPoint lastPos;

    // lighting
    const GLfloat light_ambient[4]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat light_diffuse[4]  = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_position[4] = { 2.0f, 5.0f, 5.0f, 0.0f };

    const GLfloat mat_ambient[4]    = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[4]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[1] = { 100.0f };
};

#endif // GLWIDGET_H
