QT       += widgets core gui opengl

LIBS += -lglu32 -lopengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    delaunay.cpp \
    edge.cpp \
    glwidget.cpp \
    main.cpp \
    triangle.cpp \
    vector2.cpp \
    widget.cpp

HEADERS += \
    delaunay.h \
    edge.h \
    glwidget.h \
    numeric.h \
    triangle.h \
    vector2.h \
    widget.h

FORMS += \
    widget.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    res.qrc

win32:CONFIG(release, debug|release): LIBS += -LC:/Qt/5.15.2/mingw81_64/lib/ -lfreeglut
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/Qt/5.15.2/mingw81_64/lib/ -lfreeglut

INCLUDEPATH += C:/Qt/5.15.2/mingw81_64/include
DEPENDPATH += C:/Qt/5.15.2/mingw81_64/include
