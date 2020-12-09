#include "glwidget.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <QDebug>
#include <QMouseEvent>

GLWidget::GLWidget(QWidget *parent)
{
    xRot = yRot = zRot = 0;
    xPos = yPos = 0;
    zoomScale = 1;
}

/// Initialization method, initializes lighting and stuff
void GLWidget::initializeGL()
{
    setFocus();
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

    glPushMatrix();
    glScalef(zoomScale, zoomScale, zoomScale);
    glutSolidTeapot(1.0);
    glPopMatrix();

    // Отрисовка оси координат
    glClear(GL_DEPTH_BUFFER_BIT);

    glDisable(GL_LIGHTING);
    glLineWidth(4);
    glBegin(GL_LINES);
        glNormal3f(0, 0, 1);

        glColor4f(1.0, 0.0, 0.0, 0.2);
        glVertex3f(-5.0,  0.0,  0.0);
        glVertex3f( 5.0,  0.0,  0.0);

        glColor4f(0.0, 1.0, 0.0, 0.5);
        glVertex3f( 0.0, -5.0, 0.0);
        glVertex3f( 0.0,  5.0, 0.0);

        glColor4f(0.0, 0.0, 1.0, 0.5);
        glVertex3f( 0.0,  0.0, -5.0);
        glVertex3f( 0.0,  0.0,  5.0);
    glEnd();
    glEnable(GL_LIGHTING);
    // Конец отрисовки оси координат

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
//    gluPerspective(45, (float)w/h, 0.01, 10.0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(
//                0, 0, 5,
//                0, 0, 0,
//                0, 1, 0
//                );
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
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
        updateGL();
    }

    lastPos = event->pos();
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
    setFocusPolicy(Qt::StrongFocus);
    if (event->key() == Qt::Key_R) {
        xPos = yPos = 0;
        xRot = yRot = zRot = 0;
        zoomScale = 1;
        updateGL();
    }
}

void GLWidget::setXRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setYRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::setZRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void GLWidget::normalizeAngle(int *angle)
{
    while (*angle < 0)
        *angle += 360 * 16;
    while (*angle > 360 * 16)
        *angle -= 360 * 16;
}
