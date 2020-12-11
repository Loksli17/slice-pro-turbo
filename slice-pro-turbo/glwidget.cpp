#include "glwidget.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <QDebug>
#include <QMouseEvent>
#include <QFile>
#include <QTextStream>
#include <QVector>

//struct triangle{
//    point Normal;
//    point p[3];
//};

GLWidget::GLWidget(QWidget *parent)
{
    setFocusPolicy(Qt::StrongFocus);
    xRot = yRot = zRot = 0;
    yRot = 720;
    xRot = 480;
    xPos = yPos = 0;
    zoomScale = 0.5;

    setXRotation(xRot);
    setYRotation(yRot);
    setZRotation(zRot);
}

/// Initialization method, initializes lighting and stuff
void GLWidget::initializeGL()
{
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // Настройки глута - нужны для верного отображения
    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CW);

    // Настройка света и прозрачности
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
//    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

/// Render method, everything gets rendered here
void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslated(xPos, yPos, -10.0);

    glRotated(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotated(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotated(zRot / 16.0, 0.0, 0.0, 1.0);


//    gluLookAt(xPos, yPos, 0.0, 0.0, 0.0, -10.0, 0.0, 1.0, 0.0);

    // Отрисовка модели и сетки
    glPushMatrix();
        glScalef(zoomScale, zoomScale, zoomScale);
        drawGrid();

        glutSolidTeapot(1.0);
    glPopMatrix();

    // Отрисовка оси координат поверх всего
    drawOrigin();

    glLineWidth(1);
}

/// Window resize handler
void GLWidget::resizeGL(int w, int h)
{
    int side = qMin(w, h);
    glViewport((w - 2.0 * side) / 2, (h - 2.0 * side) / 2, 2.0 * side, 2.0 * side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2.0, +2.0, -2.0, +2.0, 4.0, 15.0);
#else
    glOrtho(-2.0, +2.0, -2.0, +2.0, 4.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);

//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45, (float)w/h, 0.01, 100.0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(
//                0, 0, 5,
//                0, 0, 0,
//                0, 1, 0
//                    );
}

void GLWidget::drawOrigin()
{
    glClear(GL_DEPTH_BUFFER_BIT);
    glDisable(GL_LIGHTING);
    glLineWidth(4);
    glBegin(GL_LINES);
        glNormal3f(0, 0, 1);
        // X
        glColor4f(1.0, 0.0, 0.0, 0.2);
        glVertex3f(-5.0,  0.0,  0.0);
        glVertex3f( 5.0,  0.0,  0.0);
        // Y
        glColor4f(0.0, 1.0, 0.0, 0.5);
        glVertex3f( 0.0, -5.0, 0.0);
        glVertex3f( 0.0,  5.0, 0.0);
        // Z
        glColor4f(0.0, 0.0, 1.0, 0.5);
        glVertex3f( 0.0,  0.0, -5.0);
        glVertex3f( 0.0,  0.0,  5.0);
    glEnd();
    glEnable(GL_LIGHTING);
}

void GLWidget::drawGrid()
{
    glColor4f(0.5, 0.5, 0.5, 1.0);
    glBegin(GL_LINES);
    for (GLfloat i = -2.5; i <= 2.5; i += 0.25) {
        glVertex3f(i, 0, 2.5); glVertex3f(i, 0, -2.5);
        glVertex3f(2.5, 0, i); glVertex3f(-2.5, 0, i);
    }
    glEnd();
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
//    setFocus();
    lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
//    setFocus();
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() == Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() == Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    } else if (event->buttons() == Qt::MiddleButton) {
        xPos += dx / ((double)width() / 3.0);
        yPos -= dy / ((double)height() / 2.0);
    }

    lastPos = event->pos();
    updateGL();
}

/// reset all camera movements
void GLWidget::wheelEvent(QWheelEvent *event)
{
//    setFocus();
    QPoint numDegrees = event->angleDelta();
    if (numDegrees.y() < 0) zoomScale = zoomScale / 1.5;
    if (numDegrees.y() > 0) zoomScale = zoomScale * 1.5;

    updateGL();
}

void GLWidget::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_R) {
        yRot = 720;
        xRot = 480;
        zRot = 0;

        xPos = yPos = 0;
        zoomScale = 0.5;

        setXRotation(xRot);
        setYRotation(yRot);
        setZRotation(zRot);
    } else if (event->key() == Qt::Key_W) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else if (event->key() == Qt::Key_E) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    updateGL();
}

void GLWidget::setXRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
//        updateGL();
    }
}

void GLWidget::setYRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
//        updateGL();
    }
}


void GLWidget::setZRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
//        updateGL();
    }
}


void GLWidget::getStl(QFile* file)
{

    struct point{
        float X;
        float Y;
        float Z;
    };

    struct triangle{
        point Normal;
        point p[3];
    };

    QVector <triangle>triangleBase;

    int
        state       = 0,
        type        = 0,
        countCoords = 0;
    float points[3];
    triangle form;

    QTextStream in(file);
    QString text      = in.readAll();
    QStringList words = text.split(" ");
    file->close();

    for(int i = 0; i < words.size(); i++){
        QString word = words[i];

        if(word != ""){
            if(state == 1){
                countCoords--;
                points[countCoords] = word.toFloat();

                if(!countCoords){
                  if(type == 1){
                      form.Normal.X = points[2];
                      form.Normal.Y = points[1];
                      form.Normal.Z = points[0];
                      triangleBase.push_back(form);
                      qDebug() << triangleBase[triangleBase.size() - 1].p[type - 2].X;
                      qDebug() << triangleBase[triangleBase.size() - 1].p[type - 2].X;
                      qDebug() << triangleBase[triangleBase.size() - 1].p[type - 2].X;
                  }else if(type > 1){
                      triangleBase[triangleBase.size() - 1].p[type - 2].X = points[2];
                      triangleBase[triangleBase.size() - 1].p[type - 2].Y = points[1];
                      triangleBase[triangleBase.size() - 1].p[type - 2].Z = points[0];
                  }
                  state = 0;
                }
            }else if(state == 0){
                if(word == "normal"){
                  state       = 1;
                  countCoords = 3;
                  type        = 1;
                }else if(word == "vertex"){
                  state       = 1;
                  countCoords = 3;
                  type        = type + 1;
                }
            }
        }
    }

    qDebug() << triangleBase.size();
}


void GLWidget::normalizeAngle(int *angle)
{
    while (*angle < 0)
        *angle += 360 * 16;
    while (*angle > 360 * 16)
        *angle -= 360 * 16;
}
