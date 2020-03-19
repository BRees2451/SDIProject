/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new matDisplay(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(260, 30, 521, 381));
        ZoomInButton = new QPushButton(centralwidget);
        ZoomInButton->setObjectName(QStringLiteral("ZoomInButton"));
        ZoomInButton->setGeometry(QRect(560, 420, 101, 31));
        ZoomOutButton = new QPushButton(centralwidget);
        ZoomOutButton->setObjectName(QStringLiteral("ZoomOutButton"));
        ZoomOutButton->setGeometry(QRect(670, 420, 101, 31));
        DrawTriangleButton = new QPushButton(centralwidget);
        DrawTriangleButton->setObjectName(QStringLiteral("DrawTriangleButton"));
        DrawTriangleButton->setGeometry(QRect(20, 340, 101, 31));
        DrawRectButton = new QPushButton(centralwidget);
        DrawRectButton->setObjectName(QStringLiteral("DrawRectButton"));
        DrawRectButton->setGeometry(QRect(130, 340, 101, 31));
        DrawTrapButton = new QPushButton(centralwidget);
        DrawTrapButton->setObjectName(QStringLiteral("DrawTrapButton"));
        DrawTrapButton->setGeometry(QRect(20, 380, 101, 31));
        DrawHexButton = new QPushButton(centralwidget);
        DrawHexButton->setObjectName(QStringLiteral("DrawHexButton"));
        DrawHexButton->setGeometry(QRect(130, 380, 101, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(260, 10, 111, 16));
        RotateLButton = new QPushButton(centralwidget);
        RotateLButton->setObjectName(QStringLiteral("RotateLButton"));
        RotateLButton->setGeometry(QRect(270, 420, 101, 31));
        RotateRButton = new QPushButton(centralwidget);
        RotateRButton->setObjectName(QStringLiteral("RotateRButton"));
        RotateRButton->setGeometry(QRect(380, 420, 101, 31));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 231, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ImagesLabel = new QLabel(verticalLayoutWidget);
        ImagesLabel->setObjectName(QStringLiteral("ImagesLabel"));

        verticalLayout->addWidget(ImagesLabel);

        ImagesWindow = new QListWidget(verticalLayoutWidget);
        ImagesWindow->setObjectName(QStringLiteral("ImagesWindow"));

        verticalLayout->addWidget(ImagesWindow);

        AddImageButton = new QPushButton(verticalLayoutWidget);
        AddImageButton->setObjectName(QStringLiteral("AddImageButton"));

        verticalLayout->addWidget(AddImageButton);

        ClassLabel = new QLabel(verticalLayoutWidget);
        ClassLabel->setObjectName(QStringLiteral("ClassLabel"));

        verticalLayout->addWidget(ClassLabel);

        ClassWindow = new QListWidget(verticalLayoutWidget);
        ClassWindow->setObjectName(QStringLiteral("ClassWindow"));

        verticalLayout->addWidget(ClassWindow);

        AddClassButton = new QPushButton(verticalLayoutWidget);
        AddClassButton->setObjectName(QStringLiteral("AddClassButton"));

        verticalLayout->addWidget(AddClassButton);

        mouse_position_label = new QLabel(centralwidget);
        mouse_position_label->setObjectName(QStringLiteral("mouse_position_label"));
        mouse_position_label->setGeometry(QRect(590, 470, 181, 61));
        mouse_position_label->setStyleSheet(QStringLiteral("background-color: rgb(216, 216, 216);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", Q_NULLPTR));
        ZoomInButton->setText(QApplication::translate("MainWindow", "Zoom In", Q_NULLPTR));
        ZoomOutButton->setText(QApplication::translate("MainWindow", "Zoom Out", Q_NULLPTR));
        DrawTriangleButton->setText(QApplication::translate("MainWindow", "Draw Triangle", Q_NULLPTR));
        DrawRectButton->setText(QApplication::translate("MainWindow", "Draw Rectangle", Q_NULLPTR));
        DrawTrapButton->setText(QApplication::translate("MainWindow", "Draw Trapezium", Q_NULLPTR));
        DrawHexButton->setText(QApplication::translate("MainWindow", "Draw Polygon", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Image Pane", Q_NULLPTR));
        RotateLButton->setText(QApplication::translate("MainWindow", "Rotate Left", Q_NULLPTR));
        RotateRButton->setText(QApplication::translate("MainWindow", "Rotate Right", Q_NULLPTR));
        ImagesLabel->setText(QApplication::translate("MainWindow", "Images", Q_NULLPTR));
        AddImageButton->setText(QApplication::translate("MainWindow", "Add Image", Q_NULLPTR));
        ClassLabel->setText(QApplication::translate("MainWindow", "Classifier Path", Q_NULLPTR));
        AddClassButton->setText(QApplication::translate("MainWindow", "Add Class", Q_NULLPTR));
        mouse_position_label->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
