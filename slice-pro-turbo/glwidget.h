#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QObject>
#include <QString>
#include <QFile>

#define BIG_GRID 8
#define SMALL_GRID 4

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
    void createDiagramVoronov();

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

    void disableIntersection();
    void showMessage(QString text);
    void showStatusBarMessage(QString text);
    void removeFileName();

private:
    void normalizeAngle(int *angle);
    void wireframe(bool show);
    void findGabarite();

    void findSeparatePoint();
    void findSeparateLayerOutline();

    void intersectionDraw();
    void setInnerPointsGridDraw();
    void SetInnerPointsRand();

    void resetState();

    int GridSize = BIG_GRID;
    int xRot;
    int yRot;
    int zRot;
    double xPos;
    double yPos;
    double zoomScale;
    QPoint lastPos;

    bool showModel = true;

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
