/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *FileName;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *ResetButton;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *messageLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *SliceAuto;
    QPushButton *SliceAdaptive;
    QPushButton *drawGrid;
    QPushButton *saveGCode;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *RotateX;
    QPushButton *RotateY;
    QPushButton *RotateZ;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *intersection;
    QCheckBox *checkBox;
    QDoubleSpinBox *SliceAdaptiveSpinBox;
    QPushButton *HelpAction;
    QHBoxLayout *horizontalLayout;
    GLWidget *widget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1192, 823);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/image/logo-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setStyleSheet(QString::fromUtf8("QWidget#Widget {\n"
"	background-color: #FAFAFA;\n"
"}"));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 9, 9, 9);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        FileName = new QLabel(Widget);
        FileName->setObjectName(QString::fromUtf8("FileName"));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto Light"));
        font.setPointSize(18);
        FileName->setFont(font);
        FileName->setStyleSheet(QString::fromUtf8("QLabel#FileName {\n"
"	margin-left: 90px;\n"
"	padding-bottom: 12px;\n"
"}"));

        horizontalLayout_4->addWidget(FileName);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto Light"));
        font1.setPointSize(12);
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_2 {\n"
"	margin-bottom: 12px;\n"
"	padding-top: 8px;\n"
"	padding-bottom: 8px;\n"
"	border-radius: 6px;\n"
"	background-color: #DEDEDE;\n"
"}\n"
"\n"
"QPushButton#pushButton_2:hover {\n"
"	background-color: #6584ED;\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_2);

        ResetButton = new QPushButton(Widget);
        ResetButton->setObjectName(QString::fromUtf8("ResetButton"));
        ResetButton->setFont(font1);
        ResetButton->setStyleSheet(QString::fromUtf8("QPushButton#ResetButton {\n"
"	margin-bottom: 12px;\n"
"	padding-top: 8px;\n"
"	padding-bottom: 8px;\n"
"	border-radius: 6px;\n"
"	background-color: #DEDEDE;\n"
"}\n"
"\n"
"QPushButton#ResetButton:hover {\n"
"	background-color: #6584ED;\n"
"}"));

        horizontalLayout_3->addWidget(ResetButton);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton#pushButton {\n"
"	margin-bottom: 12px;\n"
"	padding-top: 8px;\n"
"	padding-bottom: 8px;\n"
"	border-radius: 6px;\n"
"	background-color: #DEDEDE;\n"
"}\n"
"\n"
"QPushButton#pushButton:hover {\n"
"	background-color: #6584ED;\n"
"}"));

        horizontalLayout_3->addWidget(pushButton);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        messageLayout = new QVBoxLayout();
        messageLayout->setObjectName(QString::fromUtf8("messageLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 338));
        groupBox_2->setMaximumSize(QSize(16777215, 348));
        groupBox_2->setFont(font1);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox#groupBox_2 {\n"
"	border: none;\n"
"	padding-top: 16px;\n"
"}\n"
""));
        groupBox_2->setAlignment(Qt::AlignCenter);
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        SliceAuto = new QPushButton(groupBox_2);
        SliceAuto->setObjectName(QString::fromUtf8("SliceAuto"));
        SliceAuto->setEnabled(true);
        SliceAuto->setMinimumSize(QSize(64, 64));
        SliceAuto->setMaximumSize(QSize(64, 64));
        SliceAuto->setStyleSheet(QString::fromUtf8("QPushButton#SliceAuto {\n"
"	border-radius: 6px;\n"
"	background-color: #DEDEDE;\n"
"}\n"
"\n"
"QPushButton#SliceAuto:hover {\n"
"	background-color: #6584ED;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/image/slice.png"), QSize(), QIcon::Normal, QIcon::Off);
        SliceAuto->setIcon(icon1);
        SliceAuto->setIconSize(QSize(42, 42));

        verticalLayout_3->addWidget(SliceAuto);

        SliceAdaptive = new QPushButton(groupBox_2);
        SliceAdaptive->setObjectName(QString::fromUtf8("SliceAdaptive"));
        SliceAdaptive->setEnabled(true);
        SliceAdaptive->setMinimumSize(QSize(64, 64));
        SliceAdaptive->setMaximumSize(QSize(64, 64));
        SliceAdaptive->setStyleSheet(QString::fromUtf8("QPushButton#SliceAdaptive {\n"
"	border-radius: 6px;\n"
"	background-color: #DEDEDE;\n"
"}\n"
"\n"
"QPushButton#SliceAdaptive:hover {\n"
"	background-color: #6584ED;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/image/aslice.png"), QSize(), QIcon::Normal, QIcon::Off);
        SliceAdaptive->setIcon(icon2);
        SliceAdaptive->setIconSize(QSize(42, 42));

        verticalLayout_3->addWidget(SliceAdaptive);

        drawGrid = new QPushButton(groupBox_2);
        drawGrid->setObjectName(QString::fromUtf8("drawGrid"));
        drawGrid->setEnabled(true);
        drawGrid->setMinimumSize(QSize(64, 64));
        drawGrid->setMaximumSize(QSize(64, 64));
        drawGrid->setStyleSheet(QString::fromUtf8("QPushButton#drawGrid {\n"
"	border-radius: 6px;\n"
"	background-color: #DEDEDE;\n"
"}\n"
"\n"
"QPushButton#drawGrid:hover {\n"
"	background-color: #6584ED;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/image/voronov.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawGrid->setIcon(icon3);
        drawGrid->setIconSize(QSize(42, 42));

        verticalLayout_3->addWidget(drawGrid);

        saveGCode = new QPushButton(groupBox_2);
        saveGCode->setObjectName(QString::fromUtf8("saveGCode"));
        saveGCode->setEnabled(true);
        saveGCode->setMinimumSize(QSize(64, 64));
        saveGCode->setMaximumSize(QSize(64, 64));
        saveGCode->setStyleSheet(QString::fromUtf8("QPushButton#saveGCode {\n"
"	border-radius: 6px;\n"
"	background-color: #DEDEDE;\n"
"}\n"
"\n"
"QPushButton#saveGCode:hover {\n"
"	background-color: #6584ED;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/image/gcode.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveGCode->setIcon(icon4);
        saveGCode->setIconSize(QSize(42, 42));

        verticalLayout_3->addWidget(saveGCode);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 238));
        groupBox->setMaximumSize(QSize(16777215, 250));
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox#groupBox {\n"
"	border: none;\n"
"	padding-top: 16px;\n"
"}\n"
""));
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        RotateX = new QPushButton(groupBox);
        RotateX->setObjectName(QString::fromUtf8("RotateX"));
        RotateX->setEnabled(true);
        RotateX->setMinimumSize(QSize(64, 64));
        RotateX->setMaximumSize(QSize(64, 64));
        RotateX->setStyleSheet(QString::fromUtf8("QPushButton#RotateX {\n"
"	border-radius: 6px;\n"
"	background-color: #DEDEDE;\n"
"}\n"
"\n"
"QPushButton#RotateX:hover {\n"
"	background-color: #6584ED;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/image/x.png"), QSize(), QIcon::Normal, QIcon::Off);
        RotateX->setIcon(icon5);
        RotateX->setIconSize(QSize(42, 42));

        verticalLayout_2->addWidget(RotateX);

        RotateY = new QPushButton(groupBox);
        RotateY->setObjectName(QString::fromUtf8("RotateY"));
        RotateY->setEnabled(true);
        RotateY->setMinimumSize(QSize(64, 64));
        RotateY->setMaximumSize(QSize(64, 64));
        RotateY->setStyleSheet(QString::fromUtf8("QPushButton#RotateY {\n"
"	border-radius: 6px;\n"
"	background-color: #DEDEDE;\n"
"}\n"
"\n"
"QPushButton#RotateY:hover {\n"
"	background-color: #6584ED;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/image/y.png"), QSize(), QIcon::Normal, QIcon::Off);
        RotateY->setIcon(icon6);
        RotateY->setIconSize(QSize(42, 42));

        verticalLayout_2->addWidget(RotateY);

        RotateZ = new QPushButton(groupBox);
        RotateZ->setObjectName(QString::fromUtf8("RotateZ"));
        RotateZ->setEnabled(true);
        RotateZ->setMinimumSize(QSize(64, 64));
        RotateZ->setMaximumSize(QSize(64, 64));
        RotateZ->setStyleSheet(QString::fromUtf8("QPushButton#RotateZ {\n"
"	border-radius: 6px;\n"
"	background-color: #DEDEDE;\n"
"}\n"
"\n"
"QPushButton#RotateZ:hover {\n"
"	background-color: #6584ED;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/image/z.png"), QSize(), QIcon::Normal, QIcon::Off);
        RotateZ->setIcon(icon7);
        RotateZ->setIconSize(QSize(42, 42));

        verticalLayout_2->addWidget(RotateZ);


        verticalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 152));
        groupBox_3->setMaximumSize(QSize(16777215, 164));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox#groupBox_3 {\n"
"	border: none;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        intersection = new QCheckBox(groupBox_3);
        intersection->setObjectName(QString::fromUtf8("intersection"));
        intersection->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/image/intersection.png"), QSize(), QIcon::Normal, QIcon::Off);
        intersection->setIcon(icon8);
        intersection->setCheckable(true);

        verticalLayout_5->addWidget(intersection);

        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(true);
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox:checkBox::indicator {\n"
"	width: 16px;\n"
"	height: 16px;\n"
"	border: 2px;\n"
"	border-color: #DEDEDE;\n"
"}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/image/wireframe.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox->setIcon(icon9);
        checkBox->setIconSize(QSize(16, 16));

        verticalLayout_5->addWidget(checkBox);

        SliceAdaptiveSpinBox = new QDoubleSpinBox(groupBox_3);
        SliceAdaptiveSpinBox->setObjectName(QString::fromUtf8("SliceAdaptiveSpinBox"));
        SliceAdaptiveSpinBox->setEnabled(true);
        SliceAdaptiveSpinBox->setMaximumSize(QSize(64, 16777215));
        SliceAdaptiveSpinBox->setFont(font1);
        SliceAdaptiveSpinBox->setStyleSheet(QString::fromUtf8("QDoubleSpinBox#SliceAdaptiveSpinBox {\n"
"	border-radius: 4px;\n"
"	border-width: 3;\n"
"	border-color: #DEDEDE;\n"
"}\n"
"\n"
"QDoubleSpinBox#SliceAdaptiveSpinBox::up-button {\n"
"    border: 0px;\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"}\n"
"\n"
"QDoubleSpinBox#SliceAdaptiveSpinBox::down-button {\n"
"    border: 0px;\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"}\n"
"\n"
"QDoubleSpinBox#SliceAdaptiveSpinBox::up-arrow {\n"
"	image: url(:/img/image/arrow-up.png);\n"
"    width: 6px;\n"
"    height: 6px;\n"
"}\n"
"\n"
"QDoubleSpinBox#SliceAdaptiveSpinBox::down-arrow {\n"
"	image: url(:/img/image/arrow-down.png);\n"
"    width: 6px;\n"
"    height: 6px;\n"
"}\n"
"\n"
"QDoubleSpinBox#SliceAdaptiveSpinBox::up-button:hover {\n"
"	background-color: rgba(0, 0, 0, .5);\n"
"}\n"
"\n"
"QDoubleSpinBox#SliceAdaptiveSpinBox::down-button:hover {\n"
"	background-color: rgba(0, 0, 0, .5);\n"
"}"));
        SliceAdaptiveSpinBox->setMinimum(0.500000000000000);
        SliceAdaptiveSpinBox->setMaximum(1.000000000000000);
        SliceAdaptiveSpinBox->setSingleStep(0.050000000000000);
        SliceAdaptiveSpinBox->setValue(0.500000000000000);

        verticalLayout_5->addWidget(SliceAdaptiveSpinBox);

        HelpAction = new QPushButton(groupBox_3);
        HelpAction->setObjectName(QString::fromUtf8("HelpAction"));
        HelpAction->setMinimumSize(QSize(64, 64));
        HelpAction->setMaximumSize(QSize(64, 64));
        HelpAction->setLayoutDirection(Qt::LeftToRight);
        HelpAction->setStyleSheet(QString::fromUtf8("QPushButton#HelpAction {\n"
"	border-radius: 6px;\n"
"	background-color: #6584ED;\n"
"}\n"
"\n"
"QPushButton#HelpAction:hover {\n"
"	background-color: #B5C4F8;\n"
"}"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/image/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        HelpAction->setIcon(icon10);
        HelpAction->setIconSize(QSize(42, 42));

        verticalLayout_5->addWidget(HelpAction);


        verticalLayout->addWidget(groupBox_3);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new GLWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(widget);


        horizontalLayout_2->addLayout(horizontalLayout);


        messageLayout->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(messageLayout);


        gridLayout->addLayout(verticalLayout_4, 1, 0, 1, 1);


        retranslateUi(Widget);
        QObject::connect(pushButton, SIGNAL(clicked()), Widget, SLOT(close()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Vlice", nullptr));
        FileName->setText(QCoreApplication::translate("Widget", "File not open", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "Open file", nullptr));
        ResetButton->setText(QCoreApplication::translate("Widget", "Reset", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Quit", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "tools", nullptr));
        SliceAuto->setText(QString());
        SliceAdaptive->setText(QString());
        drawGrid->setText(QString());
#if QT_CONFIG(tooltip)
        saveGCode->setToolTip(QCoreApplication::translate("Widget", "Create g-code", nullptr));
#endif // QT_CONFIG(tooltip)
        saveGCode->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("Widget", "rotate", nullptr));
        RotateX->setText(QString());
        RotateY->setText(QString());
        RotateZ->setText(QString());
        groupBox_3->setTitle(QString());
        intersection->setText(QString());
        checkBox->setText(QString());
        HelpAction->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
