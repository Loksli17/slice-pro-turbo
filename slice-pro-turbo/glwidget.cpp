#include "glwidget.h"
#include "GL/glu.h"
#include "GL/glut.h"

#include <math.h>
#include <QDebug>
#include <QFile>
#include <QMouseEvent>
#include <QTextStream>
#include <QVector3D>
#include <QVector>
#include <algorithm>

#include "vector2.h"
#include "triangle.h"
#include "delaunay.h"

//#define GridSize 2
#define maxInnerRandPoint 100

struct point{
    float X;
    float Y;
    float Z;
};

struct triangle{
    point Normal;
    point p[3];
};

struct point2D{
    float x;
    float y;
};

///Структура хранящая ограничивающий многоугольник для процесса создания ячеек вороного
struct poligone{
    QVector <point2D> StackCorners;
};

struct edge{
    point start;
    point end;
};

point2D TempBasePoint;

struct state{
    bool grid;
};

float GabariteMaxX;
float GabariteMinX;
float GabariteMaxY;
float GabariteMinY;
float GabariteMaxZ;
float GabariteMinZ;

QVector <triangle>triangleBase;
QVector <state>states;

QVector <point>pointSeparation;
QVector <int>pointSeparationID;
QVector <point>OutLineSeparation;
QVector <int>OutLineSeparationID;
QVector <QVector <point> > OutLineLoop;
QVector <QVector <int> > OutLineLoopID;
int countLoops;
QVector<QVector <point> > InnerPoints;
//QVector <point> InnerPoints;
QVector <point2D> MeabyPoint;
QVector <poligone> PoligoneBase;

float SlicerHeight;
int offsetUpForLinePerimetr = 0;
bool HideSolid = false;
float LayerHeight = 0.2;

bool showIntersectionFlag = false;
bool wireframeFlag = false;


//diagramm Voronov
QVector <QVector <poligone>> digramVoronov;

//QVector<edge> edgesForDrawing;
QVector<QVector<edge> > edgesForDrawing;


GLWidget::GLWidget(QWidget *parent)
{
    setFocusPolicy(Qt::StrongFocus);
    xRot = yRot = zRot = 0;
    yRot = 720;
    xRot = 480;
    xPos = yPos = 0;
    zoomScale = 0.05;

    fontOrigin = new QFont("Arial", 16);
    fontText = new QFont("Arial", 10);

    setXRotation(xRot);
    setYRotation(yRot);
    setZRotation(zRot);
}

/// Initialization method, initializes lighting and stuff
void GLWidget::initializeGL()
{
    glClearColor(0.45, 0.45, 0.45, 1.0);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glEnable(GL_LINE_SMOOTH);

    // Настройки глута - нужны для верного отображения
    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CW);

    // Настройка света и прозрачности
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
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

    // Отрисовка модели и сетки
    glPushMatrix();
        glScalef(zoomScale, zoomScale, zoomScale);
        drawGrid();

        // Отображение множетсва слоев после слайсинга модели (зеленый)
        glDisable(GL_LIGHTING);
        glLineWidth(1);
        for (int j = 0; j < OutLineLoop.size(); j++) {
            glBegin(GL_LINES);
                glColor4f(0.0, 1.0, 0.0, 1.0);
                glNormal3f(0.0, 0.0, 1.0);
                for (int i = 0; i < OutLineLoop.at(j).size() - 1; i++) {
                    if (OutLineLoopID.at(j).at(i+1) == OutLineLoopID.at(j).at(i)){
                        glVertex3f(OutLineLoop.at(j).at(i).X, OutLineLoop.at(j).at(i).Y,OutLineLoop.at(j).at(i).Z);
                        glVertex3f(OutLineLoop.at(j).at(i + 1).X, OutLineLoop.at(j).at(i + 1).Y,OutLineLoop.at(j).at(i + 1).Z);
                    }
                }
            glEnd();
        }
        glEnable(GL_LIGHTING);

        // Нужен вектор векторов внутренних точек слоя
       // glDisable(GL_LIGHTING);
//        glPointSize(4);
//        for (int i = 0; i < InnerPoints.size(); i++) {
//            glBegin(GL_POINTS);
//                glColor4f(1.0, 0.0, 1.0, 1.0);
//                QVector<point> temp = InnerPoints[i];
//                for (int j = 0; j < temp.size(); j++) {
//                    glVertex3f(temp[j].X, temp[j].Y, temp[j].Z);
//                }
//            glEnd();
//        }
       // glEnable(GL_LIGHTING);

        glDisable(GL_LIGHTING);
        glLineWidth(1);
        glColor4f(0.9, 0.9, 0.9, 1);
        for (int i = 0; i < edgesForDrawing.size(); i++) {
            for (int j = 0; j < edgesForDrawing[i].size(); j++) {
                glBegin(GL_LINES);
                    glVertex3f(edgesForDrawing[i][j].start.X, edgesForDrawing[i][j].start.Y, edgesForDrawing[i][j].start.Z);
                    glVertex3f(edgesForDrawing[i][j].end.X, edgesForDrawing[i][j].end.Y, edgesForDrawing[i][j].end.Z);
                glEnd();
            }
        }
        glEnable(GL_LIGHTING);




        if (wireframeFlag) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        } else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }

        glDepthMask(false);
        //Отображение плоскости слайсинга
        glColor4f(0.1, 0.1, 0.5, 0.3);
        glDisable(GL_CULL_FACE);
        glBegin(GL_POLYGON);
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3f(GabariteMinX - 1, GabariteMinY - 1, SlicerHeight);
        glVertex3f(GabariteMaxX + 1, GabariteMinY - 1, SlicerHeight);
        glVertex3f(GabariteMaxX + 1, GabariteMaxY + 1, SlicerHeight);
        glVertex3f(GabariteMinX - 1, GabariteMaxY + 1, SlicerHeight);
        glEnd();
        glEnable(GL_CULL_FACE);




        //строим модель
        if (showModel) {

            glBegin(GL_TRIANGLES);
            glColor4f(0.8, 0.8, 0.1, 0.8);
            for (int i = 0; i < triangleBase.size(); i++){
                glNormal3f(triangleBase[i].Normal.X, triangleBase[i].Normal.Y, triangleBase[i].Normal.Z);
                glVertex3f(triangleBase[i].p[0].X,   triangleBase[i].p[0].Y,   triangleBase[i].p[0].Z);
                glVertex3f(triangleBase[i].p[1].X,   triangleBase[i].p[1].Y,   triangleBase[i].p[1].Z);
                glVertex3f(triangleBase[i].p[2].X,   triangleBase[i].p[2].Y,   triangleBase[i].p[2].Z);
            }
            glEnd();

        }
        glDepthMask(true);

        if (wireframeFlag) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        glDisable(GL_LIGHTING);
        if(showIntersectionFlag){
            glClear(GL_DEPTH_BUFFER_BIT);
            glLineWidth(4.5);
            glBegin(GL_LINES);
            glColor4f(1.0, 0.0, 0.0, 1.0);
            glNormal3f(0.0, 0.0, 1.0);
            for (int i = 0; i < offsetUpForLinePerimetr - 1;i++){
                if (OutLineSeparationID[i + 1] == OutLineSeparationID[i]){
                    glVertex3f(OutLineSeparation[i].X,OutLineSeparation[i].Y,OutLineSeparation[i].Z);
                    glVertex3f(OutLineSeparation[i + 1].X,OutLineSeparation[i + 1].Y,OutLineSeparation[i + 1].Z);
                }
            }
            glEnd();
        }
        glEnable(GL_LIGHTING);

    glPopMatrix();


    // Отрисовка оси координат поверх всего
    drawOrigin();

    if (wireframeFlag) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glColor4f(0.0, 0.0, 0.0, 0.5);
    renderText(3.5, 0.2, 0.0, "X", *fontOrigin);
    renderText(0.0, 3.5, 0.2, "Y", *fontOrigin);
    renderText(0.2, 0.0, 3.5, "Z", *fontOrigin);

    glLineWidth(1);

    QString cameraRot = "Camera angle: x: " + QString::number(xRot)
                        + ", y:  " + QString::number(yRot) + ", z: " + QString::number(zRot);

    QString cameraPos = "Camera position: x: " + QString::number(xPos)
                        + ", y:  " + QString::number(yPos);

    QString zoom = "Zoom: " + QString::number(zoomScale);
    QString triangles = "Triangles: " + QString::number(triangleBase.size());

    renderText(5, 15, cameraRot, *fontText);
    renderText(5, 30, cameraPos, *fontText);
    renderText(5, 45, zoom,      *fontText);
    renderText(5, 60, triangles, *fontText);
}


/// Window resize handler
void GLWidget::resizeGL(int w, int h)
{
//    int side = qMin(w, h);
//    glViewport((w - 2.0 * side) / 2, (h - 2.0 * side) / 2, 2.0 * side, 2.0 * side);

//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//#ifdef QT_OPENGL_ES_1
//    glOrthof(-2.0, +2.0, -2.0, +2.0, 4.0, 15.0);
//#else
//    glOrtho(-2.0, +2.0, -2.0, +2.0, 4.0, 15.0);
//#endif
//    glMatrixMode(GL_MODELVIEW);

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GLWidget::drawOrigin()
{
    glClear(GL_DEPTH_BUFFER_BIT);
    glDisable(GL_LIGHTING);
    glLineWidth(4);
    glBegin(GL_LINES);
        glNormal3f(0, 0, 1);
        // X
        glColor4f(  1.0, 0.0, 0.0, 0.2);
        glVertex3f(-4.0, 0.0, 0.0);
        glVertex3f( 4.0, 0.0, 0.0);
        // Y
        glColor4f( 0.0,  1.0, 0.0, 0.5);
        glVertex3f(0.0, -4.0, 0.0);
        glVertex3f(0.0,  4.0, 0.0);
        // Z
        glColor4f(  0.0, 0.0,  1.0, 0.5);
        glVertex3f( 0.0, 0.0, -4.0);
        glVertex3f( 0.0, 0.0,  4.0);
    glEnd();
    glEnable(GL_LIGHTING);
}


void GLWidget::drawGrid()
{
    glDisable(GL_LIGHTING);
    glColor4f(0.0, 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
        for (GLfloat i = -30.0; i <= 30.0; i += 2.0) {
            glVertex3f(i, 0, 30.0); glVertex3f( i, 0, -30.0);
            glVertex3f(30.0, 0, i); glVertex3f( -30.0, 0, i);
        }
    glEnd();
    glEnable(GL_LIGHTING);
}


void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}


void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() == Qt::LeftButton) {
        setXRotation(xRot + 16 * dy);
        setYRotation(yRot + 16 * dx);
    } else if (event->buttons() == Qt::RightButton) {
        setXRotation(xRot + 16 * dy);
        setZRotation(zRot + 16 * dx);
    } else if (event->buttons() == Qt::MiddleButton) {
        xPos += (10.0 * dx) / ((double)width());
        yPos -= (8.0  * dy) / ((double)height());
    }

    lastPos = event->pos();
    update();
}



void GLWidget::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees = event->angleDelta();
    if (numDegrees.y() < 0) zoomScale /= 1.2;
    if (numDegrees.y() > 0) zoomScale *= 1.2;

    update();
}

/// reset all camera movements
void GLWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_R) {
        yRot = 720;
        xRot = 480;
        zRot = 0;

        xPos = yPos = 0;
        zoomScale = 0.05;

        setXRotation(xRot);
        setYRotation(yRot);
        setZRotation(zRot);
    }
    if (event->key() == Qt::Key_X) {
        showModel = !showModel;
    }
    update();
}

void GLWidget::resetSliceState()
{
    resetState();
    update();
}

void GLWidget::rotateBody(int axis)
{
    if (triangleBase.size() == 0) {
        emit showMessage("No model loaded");
        return;
    }

    OutLineLoop.clear();
    OutLineLoopID.clear();
    pointSeparation.clear();
    pointSeparationID.clear();
    OutLineSeparation.clear();
    OutLineSeparationID.clear();
    edgesForDrawing.clear();
    InnerPoints.clear();

    float
        NewNormalX,
        NewNormalY,
        NewNormalZ;
    float
        NewPointX,
        NewPointY,
        NewPointZ;
    float PointMidleX, PointMidleY, PointMidleZ;

    float angle = M_PI / 4;

    //Определение центра модели
    PointMidleX = ((GabariteMaxX - GabariteMinX) / 2) + GabariteMinX;
    PointMidleY = ((GabariteMaxY - GabariteMinY) / 2) + GabariteMinY;
    PointMidleZ = ((GabariteMaxZ - GabariteMinZ) / 2) + GabariteMinZ;

    //Цикл сдвижки кадой точки через матрицу поворота в 3D пространстве
    for (int i = 0; i < triangleBase.size(); i++) {
        if (axis == 0){
            NewNormalX =  triangleBase[i].Normal.X;
            NewNormalY = triangleBase[i].Normal.Y * cos(angle)
                         + triangleBase[i].Normal.Z * sin(angle);
            NewNormalZ = - triangleBase[i].Normal.Y * sin(angle)
                         + triangleBase[i].Normal.Z * cos(angle);
        } else if (axis == 1){
            NewNormalX = triangleBase[i].Normal.X * cos(angle)
                         + triangleBase[i].Normal.Z * sin(angle);
            NewNormalY =  triangleBase[i].Normal.Y;
            NewNormalZ = -triangleBase[i].Normal.X * sin(angle)
                         + triangleBase[i].Normal.Z * cos(angle);
        } else if (axis == 2){
            NewNormalX = triangleBase[i].Normal.X * cos(angle)
                         - triangleBase[i].Normal.Y * sin(angle);
            NewNormalY = triangleBase[i].Normal.X * sin(angle)
                         + triangleBase[i].Normal.Y * cos(angle);
            NewNormalZ =  triangleBase[i].Normal.Z;
        }
        //=/Дополнительное смещение нормалей модели для верного вычисления освещения модели
        triangleBase[i].Normal.X = NewNormalX;
        triangleBase[i].Normal.Y = NewNormalY;
        triangleBase[i].Normal.Z = NewNormalZ;
        for (int j = 0; j < 3; j++){
            if (axis == 0){
                NewPointX = triangleBase[i].p[j].X;
                NewPointY = ((triangleBase[i].p[j].Y - PointMidleY) * cos(angle) + (triangleBase[i].p[j].Z - PointMidleZ) * sin(angle));
                NewPointZ = (-1 * (triangleBase[i].p[j].Y - PointMidleY) * sin(angle) + (triangleBase[i].p[j].Z - PointMidleZ) * cos(angle));
            }
            if (axis == 1){
                NewPointX = ((triangleBase[i].p[j].X - PointMidleX) * cos(angle) + (triangleBase[i].p[j].Z - PointMidleZ) * sin(angle));
                NewPointY = triangleBase[i].p[j].Y;
                NewPointZ = (-1 * (triangleBase[i].p[j].X - PointMidleY) * sin(angle) + (triangleBase[i].p[j].Z - PointMidleZ) * cos(angle));
            }
            if (axis == 2) {
                NewPointX = ((triangleBase[i].p[j].X - PointMidleX) * cos(angle) - (triangleBase[i].p[j].Y - PointMidleY) * sin(angle));
                NewPointY = ((triangleBase[i].p[j].X - PointMidleY) * sin(angle) + (triangleBase[i].p[j].Y - PointMidleY) * cos(angle));
                NewPointZ = triangleBase[i].p[j].Z;
            }
            triangleBase[i].p[j].X = NewPointX;
            triangleBase[i].p[j].Y = NewPointY;
            triangleBase[i].p[j].Z = NewPointZ;
        }
    }
    findGabarite();
    intersectionDraw();
}

void GLWidget::setXRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
    }
}

void GLWidget::setYRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
    }
}

void GLWidget::setZRotation(int angle)
{
    normalizeAngle(&angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
    }
}

void GLWidget::resetState()
{
    showIntersectionFlag = false;
    emit disableIntersection();

    edgesForDrawing.clear();
    triangleBase.clear();
    OutLineLoop.clear();
    OutLineLoopID.clear();
    pointSeparation.clear();
    pointSeparationID.clear();
    OutLineSeparation.clear();
    OutLineSeparationID.clear();
    InnerPoints.clear();
    MeabyPoint.clear();
    PoligoneBase.clear();

    emit removeFileName();
}

//полученние данных с файла и отрисовка модели
void GLWidget::getStl(QFile* file)
{
    resetState();

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

    findGabarite();

    qDebug() << "triangles: " << triangleBase.size();

    update();
}

void GLWidget::toggleWireframe(bool show)
{
    wireframe(show);
}

void GLWidget::normalizeAngle(int *angle)
{
    while (*angle < 0)
        *angle += 360 * 16;
    while (*angle > 360 * 16)
        *angle -= 360 * 16;
}

void GLWidget::wireframe(bool show)
{
    wireframeFlag = show;
    update();
}

void GLWidget::findGabarite()
{
    float minX = triangleBase[0].p[0].X;
    float maxX = triangleBase[0].p[0].X;
    float minY = triangleBase[0].p[0].Y;
    float maxY = triangleBase[0].p[0].Y;
    float minZ = triangleBase[0].p[0].Z;
    float maxZ = triangleBase[0].p[0].Z;

    for (int i = 0; i < triangleBase.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (triangleBase[i].p[j].X > maxX) maxX = triangleBase[i].p[j].X;
            if (triangleBase[i].p[j].Y > maxY) maxY = triangleBase[i].p[j].Y;
            if (triangleBase[i].p[j].Z > maxZ) maxZ = triangleBase[i].p[j].Z;
            if (triangleBase[i].p[j].X < minX) minX = triangleBase[i].p[j].X;
            if (triangleBase[i].p[j].Y < minY) minY = triangleBase[i].p[j].Y;
            if (triangleBase[i].p[j].Z < minZ) minZ = triangleBase[i].p[j].Z;
        }
    }

    GabariteMaxX = maxX;
    GabariteMinX = minX;
    GabariteMaxY = maxY;
    GabariteMinY = minY;
    GabariteMaxZ = maxZ;
    GabariteMinZ = minZ;
}

void GLWidget::findSeparatePoint()
{
    int vert2;
    pointSeparation.clear();
    pointSeparationID.clear();

    ///Основной цикл прохода по всем треугольниками модели
    for (int trianN = 0; trianN < triangleBase.size(); trianN++) {
        ///Преобразование с определением к какой грани относится та или иная точка на трегуольнике
        for (int vert1 = 0; vert1 < 3; vert1++) {
            if (vert1 == 0) vert2 = 1;
            if (vert1 == 1) vert2 = 2;
            if (vert1 == 2) vert2 = 0;
            ///Оплетка для проверки факта парарельности треугольника секущей плоскости
            if (triangleBase[trianN].p[vert1].Z == SlicerHeight) {
//                    cout<<"Danger triangle pararell slisser plane "<<trianN<<endl;
                pointSeparation.clear();
                pointSeparationID.clear();
                return;
            }

            ///Определение факта того что плоскость пересекает треугольник (она должна пересекать точно 2 грани, не может быть 1 или 3)
            if ((triangleBase[trianN].p[vert1].Z < SlicerHeight  && triangleBase[trianN].p[vert2].Z > SlicerHeight)
                || (triangleBase[trianN].p[vert1].Z > SlicerHeight && triangleBase[trianN].p[vert2].Z < SlicerHeight)) {
                float difX = triangleBase[trianN].p[vert2].X - triangleBase[trianN].p[vert1].X;
                float difY = triangleBase[trianN].p[vert2].Y - triangleBase[trianN].p[vert1].Y;
                float difZ = triangleBase[trianN].p[vert2].Z - triangleBase[trianN].p[vert1].Z;
                float t = (SlicerHeight - triangleBase[trianN].p[vert1].Z) / (difZ);

                if (pointSeparationID.size() > 0) {
                    if (pointSeparationID[pointSeparationID.size() - 1] == trianN
                        && (fabs(pointSeparation[pointSeparation.size() - 1].X
                                 - (triangleBase[trianN].p[vert1].X + difX * t)))
                               < 0.001
                        && (fabs(pointSeparation[pointSeparation.size() - 1].Y
                                 - (triangleBase[trianN].p[vert1].Y + difY * t)))
                               < 0.001) {
                        pointSeparation.pop_back();
                        pointSeparationID.pop_back();
                        continue;
                    }
                }
                point temp;
                temp.X = triangleBase[trianN].p[vert1].X + difX * t;
                temp.Y = triangleBase[trianN].p[vert1].Y + difY * t;
                temp.Z = triangleBase[trianN].p[vert1].Z + difZ * t;
                pointSeparation.push_back(temp);
                pointSeparationID.push_back(trianN);
            }
        }
    }
}

void GLWidget::findSeparateLayerOutline()
{
    //Строчки для поготовки к работе, очистка, создание базовой точки т т.д.
    OutLineSeparation.clear();
    OutLineSeparationID.clear();
    point tempPoint;
    int tempID;
    int thisIDLine;
    //qDebug() << pointSeparation.size() << "SIZE";
    tempPoint.X = pointSeparation[0].X;
    tempPoint.Y = pointSeparation[0].Y;
    tempPoint.Z = pointSeparation[0].Z;
    tempID = 0;
    thisIDLine = 0;
    OutLineSeparation.push_back(tempPoint);
    OutLineSeparationID.push_back(thisIDLine);

    //Бесконечный цикл прохода по всем точкам пересечения плоскости с моделью
    while (pointSeparationID.size() > 0){
        for (int i = 0; i < pointSeparation.size(); i++) {
            if (fabs(pointSeparation[i].X-tempPoint.X)<0.001 &&
                fabs(pointSeparation[i].Y-tempPoint.Y)<0.001 &&
                fabs(pointSeparation[i].Z-tempPoint.Z)<0.001){
                    for (int j=0;j<pointSeparation.size();j++){
                        if ((pointSeparation[j].X!=pointSeparation[i].X ||
                            pointSeparation[j].Y!=pointSeparation[i].Y ||
                            pointSeparation[j].Z!=pointSeparation[i].Z) &&
                            pointSeparationID[j]==pointSeparationID[i]){
                                tempPoint.X=pointSeparation[j].X;
                                tempPoint.Y=pointSeparation[j].Y;
                                tempPoint.Z=pointSeparation[j].Z;
                                OutLineSeparation.push_back(tempPoint);
                                OutLineSeparationID.push_back(thisIDLine);
                                tempID=pointSeparationID[i];

                                ///Фильтрация получившегося констра на совпадение ID
                                for (int k = 0; k < pointSeparationID.size(); k++) {
                                    if (pointSeparationID[k] == tempID) {
                                        pointSeparation.erase(pointSeparation.begin()+k,pointSeparation.begin()+k+1);
                                        pointSeparationID.erase(pointSeparationID.begin()+k,pointSeparationID.begin()+k+1);
                                        break;
                                    }
                                }
                                for (int k = 0; k < pointSeparationID.size(); k++) {
                                    if (pointSeparationID[k] == tempID) {
                                        pointSeparation.erase(pointSeparation.begin() + k, pointSeparation.begin() + k + 1);
                                        pointSeparationID.erase(pointSeparationID.begin() + k,pointSeparationID.begin() + k + 1);
                                        break;
                                    }
                                }

                                break;
                        }
                    }
                    break;
            }
            ///Оплетка поиска количества контуров
            if (i == pointSeparation.size() - 1) {
                tempPoint.X = pointSeparation[0].X;
                tempPoint.Y = pointSeparation[0].Y;
                tempPoint.Z = pointSeparation[0].Z;
                tempID = 0;
                OutLineSeparation.push_back(tempPoint);
                OutLineSeparationID.push_back(thisIDLine + 1);
                thisIDLine++;
            }
        }
    }

    //Дополнительная фильтрация массива контура для удаления лишних вершин в узле которой линия не изгибается
    int thisPointStartLine = 0;
    while (thisPointStartLine < OutLineSeparation.size() - 2) {
        if (OutLineSeparationID[thisPointStartLine] != OutLineSeparationID[thisPointStartLine + 2]) {
            thisPointStartLine += 2;
        }
        float dx1 = fabs(OutLineSeparation[thisPointStartLine].X - OutLineSeparation[thisPointStartLine + 1].X);
        float dy1 = fabs(OutLineSeparation[thisPointStartLine].Y - OutLineSeparation[thisPointStartLine + 1].Y);
        float dx2 = fabs(OutLineSeparation[thisPointStartLine + 1].X - OutLineSeparation[thisPointStartLine + 2].X);
        float dy2 = fabs(OutLineSeparation[thisPointStartLine + 1].Y - OutLineSeparation[thisPointStartLine + 2].Y);

        if ((dx1 / dy1) == (dx2 / dy2)){
            OutLineSeparation[thisPointStartLine + 1].X = OutLineSeparation[thisPointStartLine + 2].X;
            OutLineSeparation[thisPointStartLine + 1].Y = OutLineSeparation[thisPointStartLine + 2].Y;
            OutLineSeparation[thisPointStartLine + 1].Z = OutLineSeparation[thisPointStartLine + 2].Z;
            OutLineSeparation.erase(OutLineSeparation.begin() + thisPointStartLine + 2, OutLineSeparation.begin() + thisPointStartLine + 3);
            OutLineSeparationID.erase(OutLineSeparationID.begin() + thisPointStartLine + 2, OutLineSeparationID.begin() + thisPointStartLine + 3);
            thisPointStartLine = 0;
        } else thisPointStartLine += 1;
    }

    offsetUpForLinePerimetr = OutLineSeparation.size();
    countLoops = thisIDLine + 1;
}

void GLWidget::sliceAuto()
{
    if (triangleBase.size() == 0) {
        emit showMessage("No model loaded");
        return;
    }

    emit disableIntersection();

    //Подготовка к слайсингу и определение параметров слайсинга
    if (OutLineSeparation.size() > 0) {
        //        cout<<"Count vertex = "<<OutLineSeparation.size()<<endl;
    }

    InnerPoints.clear();
    edgesForDrawing.clear();
    LayerHeight = 0.2;

    ///Отчистка слоев и запоминание текущей высоты слайсинга
    float tempSliceHight = SlicerHeight;
    QVector <point> tempLoop;
    QVector <int> tempLoopID;

    OutLineLoop.clear();
    OutLineLoopID.clear();

    //Цикл слайсинга с использованием базовой фунции слайсинга слоя
    for (float height = LayerHeight / 2; height < GabariteMaxZ; height += LayerHeight){
        SlicerHeight = height;

        //findSeparatePoint
        findSeparatePoint();

        //findSeparateLayerOutline
        findSeparateLayerOutline();

        // making inner points on each layer
        setInnerPointsGridDraw();

        tempLoop = OutLineSeparation;
        tempLoopID = OutLineSeparationID;
        OutLineLoop.push_back(tempLoop);
        OutLineLoopID.push_back(tempLoopID);
    }

    OutLineSeparation.clear();
    OutLineSeparationID.clear();

    SlicerHeight = tempSliceHight;

    emit showStatusBarMessage("Model was sliced successfully");

    update();
}

float OffsetByLine(point P1, point P2, point O){
    float h = ((P2.X - P1.X) * (O.Y - P1.Y) - (P2.Y - P1.Y) * (O.X - P1.X)) / (float) sqrt((float) pow((P2.X - P1.X) + (P2.Y - P1.Y), 2));
    return h < 0 ? -h : h;
}

void GLWidget::sliceAdaptive(double width)
{
    if (triangleBase.size() == 0) {
        emit showMessage("No model loaded");
        return;
    }

    emit disableIntersection();

    InnerPoints.clear();
    edgesForDrawing.clear();
    LayerHeight = width;

    ///Подготовка к слайсингу и определение параметров слайсинга
    if (OutLineSeparation.size()>0){
        qDebug() << "Count vertex = "<<OutLineSeparation.size();
    }

    ///Создание временных подслоев для определения их степени похожести
    float tempSliceHight = SlicerHeight;
    QVector <point> tempLoop;
    QVector <int> tempLoopID;

    QVector <point> tempLoop2;
    QVector <int> tempLoopID2;

    OutLineLoop.clear();
    OutLineLoopID.clear();

    ///Цикл слайсинга с использованием базовой фунции слайсинга слоя
    for (float height = LayerHeight / 2; height < GabariteMaxZ - LayerHeight; height += LayerHeight) {
        ///Создание подслоев для определения их степени похожести. ПОдслайсинг слоев
        SlicerHeight = height;
        findSeparatePoint();
        findSeparateLayerOutline();

        // making inner points on each layer
//        setInnerPointsGridDraw();

        tempLoop = OutLineSeparation;
        tempLoopID = OutLineSeparationID;

        SlicerHeight = height + LayerHeight;
        findSeparatePoint();
        findSeparateLayerOutline();

        // huh
        //setInnerPointsGridDraw();

        tempLoop2 = OutLineSeparation;
        tempLoopID2 = OutLineSeparationID;

        ///Цикл поиска степени похожести
        float minDeltaOnLoop = 300;
        for (int i = 0; i < tempLoop2.size(); i++) {
            float minDelta = 300;
            for (int j = 0; j < tempLoop.size() - 1; j++) {
                if (tempLoopID[j + 1] == tempLoopID[j]) {
                    if (OffsetByLine(tempLoop[j], tempLoop[j + 1], tempLoop2[i]) < minDelta) {
                        //На кадом этапе определяется переменная - MinDelta - по сути после поиска по всем вершинам - это макисмальное из минимальных для каждой точки значение отклонения точек от исходных линий
                        minDelta = OffsetByLine(tempLoop[j], tempLoop[j + 1], tempLoop2[i]);
                    }
                }
            }
            if (minDelta < minDeltaOnLoop) minDeltaOnLoop = minDelta;
        }

        //qDebug() << "Adaptive = "<<minDeltaOnLoop;

        //Собственно тут принимается решение когда делать слой одинаковым. Если величина отклооения меньше 0.001 мм. То делать слой в 2 раза больше
        if (minDeltaOnLoop <= 0.00001) {
            height += LayerHeight;
            OutLineLoop.push_back(tempLoop2);
            OutLineLoopID.push_back(tempLoopID2);
            //supsees=true;
            GridSize = BIG_GRID;
        } else {
            OutLineLoop.push_back(tempLoop);
            OutLineLoopID.push_back(tempLoopID);
            GridSize = SMALL_GRID;
        }

        setInnerPointsGridDraw();
    }

    OutLineSeparation.clear();
    OutLineSeparationID.clear();

    SlicerHeight = tempSliceHight;

    emit showStatusBarMessage("Model was sliced successfully");
}


float LenghtOfLine(point a, point b){
    return sqrt(pow((a.X - b.X), 2) + pow((a.Y - b.Y), 2));
}


void GLWidget::createGCodeFile(QString fileName)
{
    if (triangleBase.size() == 0) {
        emit showMessage("No model loaded");
        return;
    }
    QFile gcodeFile(fileName);
    gcodeFile.open(QIODevice::WriteOnly);

    //write file.gcode
    QTextStream out(&gcodeFile);
    out << "M140 S50.000000" << Qt::endl
        << "M109 T0 S190.000000" << Qt::endl
        << "T0" << Qt::endl
        << "M190 S50.000000" << Qt::endl
        << "G21        ;metric values" << Qt::endl
        << "G90        ;absolute positioning" << Qt::endl
        << "M83        ;set extruder to absolute mode" << Qt::endl
        << "M107       ;start with the fan off" << Qt::endl
        << "G28 X0 Y0  ;move X/Y to min endstops" << Qt::endl
        << "G28 Z0     ;move Z to min endstops" << Qt::endl
        << "G1 Z15.0 F9000 ;move the platform down 15mm" << Qt::endl
        << "G92 E0                  ;zero the extruded length" << Qt::endl
        << "G1 F200 E3              ;extrude 3mm of feed stock" << Qt::endl
        << "G92 E0                  ;zero the extruded length again" << Qt::endl
        << "G1 F9000" << Qt::endl
        << "M107" << Qt::endl;

    float centX = 92.22;
    float centY = 86.75;

    for (int j = 0; j < OutLineLoop.size(); j++){
        out << ";LAYER:" << j << Qt::endl;
        out << "G0 F9000 X" << OutLineLoop.at(j).at(0).X + centX << " Y" << OutLineLoop.at(j).at(0).Y + centY << " Z" << OutLineLoop.at(j).at(0).Z << Qt::endl;
        out << ";TYPE:WALL-OUTER" << Qt::endl;

        for (int i = 1; i < OutLineLoop.at(j).size() - 1; i++){
            if (OutLineLoopID.at(j).at(i - 1)==OutLineLoopID.at(j).at(i)){
                out << "G1 F1200 X" << OutLineLoop.at(j).at(i).X + centX << " Y" << OutLineLoop.at(j).at(i).Y + centY << " E" << (LenghtOfLine(OutLineLoop.at(j).at(i), OutLineLoop.at(j).at(i - 1)) / 63.697) << Qt::endl;
            }
        }

        out << "G1 F1200 X" << OutLineLoop.at(j).at(OutLineLoop.at(j).size() - 1).X + centX << " Y" <<OutLineLoop.at(j).at(OutLineLoop.at(j).size() - 1).Y+centY << " E0.1" << Qt::endl;

        out << ";TYPE:INNER-FILLING" << Qt::endl;
        for (int i = 0; i < edgesForDrawing[j].size(); i++) {
            out << "G0 X" << edgesForDrawing[j][i].start.X + centX << " Y" << edgesForDrawing[j][i].start.Y + centY << Qt::endl;
            out << "G1 F1200 X" << edgesForDrawing[j][i].end.X + centX << " Y" << edgesForDrawing[j][i].end.Y + centY << " E0.1" << Qt::endl;
        }
    }

    gcodeFile.close();
}


void GLWidget::intersection(bool checked)
{
    if (triangleBase.size() == 0) {
        emit showMessage("No model loaded");
        return;
    }

    showIntersectionFlag = checked;

    SlicerHeight = LayerHeight / 2;

    intersectionDraw();
}

void GLWidget::intersectionDraw()
{
    if(showIntersectionFlag){
        findSeparatePoint();
        findSeparateLayerOutline();
        InnerPoints.clear();
        edgesForDrawing.clear();
    }
}

void GLWidget::setInnerPointsGridDraw()
{
    QVector <point> temp;
    point tmp;

//    float GridSize = 5.0f;
//    float limit    = 1.0f;

//    bool flag = false;

    for (float dx = GabariteMinX - 1.0f; dx < GabariteMaxX + 1.0f; dx += GridSize) {
//        if(!flag){
//        GridSize = 20.0f;
//        }
//        flag = false;

//        for(int i = 0; i < OutLineSeparation.size(); i++){
//            float deltaX = OutLineSeparation[i].X - dx;
//            if (fabs(deltaX) < limit){
//                GridSize = 5.0f;
//                break;
//            }

//        }

        for (float dy = GabariteMinY - 1.0f; dy < GabariteMaxY + 1.0f; dy += GridSize) {
//            GridSize = 20.0f;

//            for(int i = 0; i < OutLineSeparation.size(); i++) {
//                float deltaY = OutLineSeparation[i].Y - dy;
//                if (fabs(deltaY) < limit){
//                    GridSize = 5.0f;
//                    break;
//                }

//            }

            tmp.X = dx;
            tmp.Y = dy;
            tmp.Z = SlicerHeight;
//            qDebug() << "GridSize kek:" << GridSize;
            if (findPointInLoop(dx, dy)) temp.push_back(tmp);
        }
    }
    InnerPoints.push_back(temp);
}



float GLWidget::atanTrueDegree(float x, float y)
{
    return (atan2(y, x) * 180 / M_PI) < 0 ? ((atan2(y, x) * 180 / M_PI) + 360)
                                          : (atan2(y, x) * 180 / M_PI);
}


bool GLWidget::findPointInLoop(float inX, float inY)
{
    float dAlpha = 0;       //Временный угол к которому суммируется дельта от переходов по точкам
    int countIDInLoops = 0; //Количество контуров

    //Цикл обхода по всем точкам контура с суммированием в временный угол
    for (int i = 0; i < OutLineSeparation.size() - 1; i++) {
        if (OutLineSeparationID[i] != OutLineSeparationID[i + 1]) {
            if (fabs(dAlpha) > 0.001) countIDInLoops++;
            dAlpha = 0;
            continue;
        }
        float p1x = OutLineSeparation[i].X - inX;
        float p1y = OutLineSeparation[i].Y - inY;
        float p2x = OutLineSeparation[i + 1].X - inX;
        float p2y = OutLineSeparation[i + 1].Y - inY;

        float angle = atanTrueDegree(p1x, p1y) - atanTrueDegree(p2x, p2y);
        if (angle >  180) angle = -(360 - atanTrueDegree(p1x, p1y) + atanTrueDegree(p2x, p2y));
        if (angle < -180) angle =  (360 - atanTrueDegree(p2x, p2y) + atanTrueDegree(p1x, p1y));
        dAlpha += angle;
    }
    if (fabs(dAlpha) > 0.001) countIDInLoops++;
    if (countIDInLoops % 2 == 1) return true;
    else return false;
}


//void GLWidget::SetInnerPointsRand(){
//    InnerPoints.clear();
//    point tmp;
//    if (OutLineSeparation.size()<2) return;
//    while (InnerPoints.size()<maxInnerRandPoint){
//        tmp.X=(((float)rand()/(float)(RAND_MAX)) * fabs(GabariteMaxX-GabariteMinX))+GabariteMinX;
//        tmp.Y=(((float)rand()/(float)(RAND_MAX)) * fabs(GabariteMaxY-GabariteMinY))+GabariteMinY;
//        tmp.Z=SlicerHeight;
//        if (findPointInLoop(tmp.X,tmp.Y)) InnerPoints.push_back(tmp);
//    }
//}


void GLWidget::setInnerPointsGrid()
{
    InnerPoints.clear();
    setInnerPointsGridDraw();
}


void GLWidget::createDiagramVoronov(){
    edgesForDrawing.clear();

    if(!InnerPoints.size()){
        //qDebug() << "HA LOLKEK NO ARRAY";
        return;
    }

    for (int i = 0; i < InnerPoints.size(); i++) {
        std::vector<dt::Vector2<float>> points;

        for(int j = 0; j < InnerPoints[i].size(); j++){
            points.push_back(dt::Vector2<float>{InnerPoints[i][j].X, InnerPoints[i][j].Y});
        }

        dt::Delaunay<float> triangulation;
        const std::vector<dt::Triangle<float>> triangles = triangulation.triangulate(points);
        std::vector<dt::Edge<float>> edges = triangulation.getEdges();

        QVector<edge> temp;

        for(int j = 0; j < edges.size(); j++){
            edge tmp;

            tmp.start.X = edges[j].v->x;
            tmp.start.Y = edges[j].v->y;
            tmp.start.Z = InnerPoints[i][0].Z;

            tmp.end.X = edges[j].w->x;
            tmp.end.Y = edges[j].w->y;
            tmp.end.Z = InnerPoints[i][0].Z;

            temp.push_back(tmp);
        }
        edgesForDrawing.push_back(temp);
    }

    emit showStatusBarMessage("Inner filling generated successfully");

    update();
}

