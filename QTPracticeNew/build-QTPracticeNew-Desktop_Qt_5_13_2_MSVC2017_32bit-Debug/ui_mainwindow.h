/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <matdisplay.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionCopy;
    QAction *actionQuit;
    QAction *actionPaste;
    QWidget *centralwidget;
    matDisplay *graphicsView;
    QPushButton *ZoomInButton;
    QPushButton *ZoomOutButton;
    QPushButton *DrawTriangleButton;
    QPushButton *DrawRectButton;
    QPushButton *DrawTrapButton;
    QPushButton *DrawHexButton;
    QLabel *label_3;
    QPushButton *RotateLButton;
    QPushButton *RotateRButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *ImagesLabel;
    QListWidget *ImagesWindow;
    QPushButton *AddImageButton;
    QLabel *ClassLabel;
    QListWidget *ClassWindow;
    QPushButton *AddClassButton;
    QLabel *mouse_position_label;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new matDisplay(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(260, 30, 521, 381));
        ZoomInButton = new QPushButton(centralwidget);
        ZoomInButton->setObjectName(QString::fromUtf8("ZoomInButton"));
        ZoomInButton->setGeometry(QRect(560, 420, 101, 31));
        ZoomOutButton = new QPushButton(centralwidget);
        ZoomOutButton->setObjectName(QString::fromUtf8("ZoomOutButton"));
        ZoomOutButton->setGeometry(QRect(670, 420, 101, 31));
        DrawTriangleButton = new QPushButton(centralwidget);
        DrawTriangleButton->setObjectName(QString::fromUtf8("DrawTriangleButton"));
        DrawTriangleButton->setGeometry(QRect(20, 340, 101, 31));
        DrawRectButton = new QPushButton(centralwidget);
        DrawRectButton->setObjectName(QString::fromUtf8("DrawRectButton"));
        DrawRectButton->setGeometry(QRect(130, 340, 101, 31));
        DrawTrapButton = new QPushButton(centralwidget);
        DrawTrapButton->setObjectName(QString::fromUtf8("DrawTrapButton"));
        DrawTrapButton->setGeometry(QRect(20, 380, 101, 31));
        DrawHexButton = new QPushButton(centralwidget);
        DrawHexButton->setObjectName(QString::fromUtf8("DrawHexButton"));
        DrawHexButton->setGeometry(QRect(130, 380, 101, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 10, 111, 16));
        RotateLButton = new QPushButton(centralwidget);
        RotateLButton->setObjectName(QString::fromUtf8("RotateLButton"));
        RotateLButton->setGeometry(QRect(270, 420, 101, 31));
        RotateRButton = new QPushButton(centralwidget);
        RotateRButton->setObjectName(QString::fromUtf8("RotateRButton"));
        RotateRButton->setGeometry(QRect(380, 420, 101, 31));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 231, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ImagesLabel = new QLabel(verticalLayoutWidget);
        ImagesLabel->setObjectName(QString::fromUtf8("ImagesLabel"));

        verticalLayout->addWidget(ImagesLabel);

        ImagesWindow = new QListWidget(verticalLayoutWidget);
        ImagesWindow->setObjectName(QString::fromUtf8("ImagesWindow"));

        verticalLayout->addWidget(ImagesWindow);

        AddImageButton = new QPushButton(verticalLayoutWidget);
        AddImageButton->setObjectName(QString::fromUtf8("AddImageButton"));

        verticalLayout->addWidget(AddImageButton);

        ClassLabel = new QLabel(verticalLayoutWidget);
        ClassLabel->setObjectName(QString::fromUtf8("ClassLabel"));

        verticalLayout->addWidget(ClassLabel);

        ClassWindow = new QListWidget(verticalLayoutWidget);
        ClassWindow->setObjectName(QString::fromUtf8("ClassWindow"));

        verticalLayout->addWidget(ClassWindow);

        AddClassButton = new QPushButton(verticalLayoutWidget);
        AddClassButton->setObjectName(QString::fromUtf8("AddClassButton"));

        verticalLayout->addWidget(AddClassButton);

        mouse_position_label = new QLabel(centralwidget);
        mouse_position_label->setObjectName(QString::fromUtf8("mouse_position_label"));
        mouse_position_label->setGeometry(QRect(590, 470, 181, 61));
        mouse_position_label->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 216, 216);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        ZoomInButton->setText(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
        ZoomOutButton->setText(QCoreApplication::translate("MainWindow", "Zoom Out", nullptr));
        DrawTriangleButton->setText(QCoreApplication::translate("MainWindow", "Draw Triangle", nullptr));
        DrawRectButton->setText(QCoreApplication::translate("MainWindow", "Draw Rectangle", nullptr));
        DrawTrapButton->setText(QCoreApplication::translate("MainWindow", "Draw Trapezium", nullptr));
        DrawHexButton->setText(QCoreApplication::translate("MainWindow", "Draw Polygon", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Image Pane", nullptr));
        RotateLButton->setText(QCoreApplication::translate("MainWindow", "Rotate Left", nullptr));
        RotateRButton->setText(QCoreApplication::translate("MainWindow", "Rotate Right", nullptr));
        ImagesLabel->setText(QCoreApplication::translate("MainWindow", "Images", nullptr));
        AddImageButton->setText(QCoreApplication::translate("MainWindow", "Add Image", nullptr));
        ClassLabel->setText(QCoreApplication::translate("MainWindow", "Classifier Path", nullptr));
        AddClassButton->setText(QCoreApplication::translate("MainWindow", "Add Class", nullptr));
        mouse_position_label->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
