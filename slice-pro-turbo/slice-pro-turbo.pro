QT       += widgets core gui opengl


LIBS += -lglu32 -lopengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    glwidget.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    glwidget.h \
    widget.h

FORMS += \
    widget.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L"C:/Qt/5.15.2/mingw81_32/lib/" -lglut32
else:win32:CONFIG(debug, debug|release): LIBS += -L"C:/Qt/5.15.2/mingw81_32/lib/" -lglut32

INCLUDEPATH += C:/Qt/5.15.2/mingw81_32/include
DEPENDPATH += C:/Qt/5.15.2/mingw81_32/include
