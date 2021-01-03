#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QObject>
#include <QString>
#include <QFile>


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void drawOrigin();
    void drawGrid();

    bool findPointInLoop(float inX, float inY);
    float atanTrueDegree(float x, float y);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    void keyPressEvent(QKeyEvent *event);

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

    void getStl(QFile* file);
    void toggleWireframe(bool show);
    void sliceAuto();
    void sliceAdaptive(double width);
    void createGCodeFile(QString fileName);
    void resetSliceState();
    void rotateBody(int axis);
    void intersection(bool checked);

    void setInnerPointsGrid();

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

    void disableIntersection();
    void showMessage(QString text);

private:
    void normalizeAngle(int *angle);
    void wireframe(bool show);
    void findGabarite();

    void findSeparatePoint();
    void findSeparateLayerOutline();

    void intersectionDraw();
    void setInnerPointsGridDraw();

    void resetState();


    int xRot;
    int yRot;
    int zRot;
    double xPos;
    double yPos;
    double zoomScale;
    QPoint lastPos;

    //Fonts
    QFont *fontText;
    QFont *fontOrigin;

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
