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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

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
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *DrawTriangleButton;
    QPushButton *DrawRectButton;
    QListWidget *listWidget;
    QLabel *label;
    QLabel *label_2;
    QListWidget *listWidget_2;
    QPushButton *DrawPentButton;
    QPushButton *DrawHexButton;
    QPushButton *DrawSeptButton;
    QLabel *label_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
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
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(285, 40, 461, 371));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 420, 75, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 420, 75, 23));
        DrawTriangleButton = new QPushButton(centralwidget);
        DrawTriangleButton->setObjectName(QStringLiteral("DrawTriangleButton"));
        DrawTriangleButton->setGeometry(QRect(10, 260, 91, 23));
        DrawRectButton = new QPushButton(centralwidget);
        DrawRectButton->setObjectName(QStringLiteral("DrawRectButton"));
        DrawRectButton->setGeometry(QRect(10, 290, 91, 23));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 50, 251, 91));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 47, 13));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 150, 91, 16));
        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(10, 170, 251, 71));
        DrawPentButton = new QPushButton(centralwidget);
        DrawPentButton->setObjectName(QStringLiteral("DrawPentButton"));
        DrawPentButton->setGeometry(QRect(10, 320, 91, 23));
        DrawHexButton = new QPushButton(centralwidget);
        DrawHexButton->setObjectName(QStringLiteral("DrawHexButton"));
        DrawHexButton->setGeometry(QRect(10, 350, 91, 23));
        DrawSeptButton = new QPushButton(centralwidget);
        DrawSeptButton->setObjectName(QStringLiteral("DrawSeptButton"));
        DrawSeptButton->setGeometry(QRect(10, 380, 91, 23));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(450, 10, 111, 16));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(290, 10, 75, 23));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(660, 10, 75, 23));
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
        pushButton->setText(QApplication::translate("MainWindow", "Zoom In", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Zoom Out", Q_NULLPTR));
        DrawTriangleButton->setText(QApplication::translate("MainWindow", "Draw Triangle", Q_NULLPTR));
        DrawRectButton->setText(QApplication::translate("MainWindow", "Draw Rectangle", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Images", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Classifier Path", Q_NULLPTR));
        DrawPentButton->setText(QApplication::translate("MainWindow", "Draw Pentagon", Q_NULLPTR));
        DrawHexButton->setText(QApplication::translate("MainWindow", "DrawHexButton", Q_NULLPTR));
        DrawSeptButton->setText(QApplication::translate("MainWindow", "Draw Septagon", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Image Pane", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "Rotate Left", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "Rotate Right", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
