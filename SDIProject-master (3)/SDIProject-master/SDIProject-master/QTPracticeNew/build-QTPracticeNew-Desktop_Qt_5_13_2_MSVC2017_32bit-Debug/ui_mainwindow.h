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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
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
    QPushButton *DrawPentButton;
    QPushButton *DrawHexButton;
    QPushButton *DrawSeptButton;
    QLabel *label_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *ImagesWindow;
    QLabel *label_2;
    QListWidget *ClassWindow;
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
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(285, 40, 461, 371));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 420, 75, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 420, 75, 23));
        DrawTriangleButton = new QPushButton(centralwidget);
        DrawTriangleButton->setObjectName(QString::fromUtf8("DrawTriangleButton"));
        DrawTriangleButton->setGeometry(QRect(10, 270, 91, 23));
        DrawRectButton = new QPushButton(centralwidget);
        DrawRectButton->setObjectName(QString::fromUtf8("DrawRectButton"));
        DrawRectButton->setGeometry(QRect(10, 300, 91, 23));
        DrawPentButton = new QPushButton(centralwidget);
        DrawPentButton->setObjectName(QString::fromUtf8("DrawPentButton"));
        DrawPentButton->setGeometry(QRect(10, 330, 91, 23));
        DrawHexButton = new QPushButton(centralwidget);
        DrawHexButton->setObjectName(QString::fromUtf8("DrawHexButton"));
        DrawHexButton->setGeometry(QRect(10, 360, 91, 23));
        DrawSeptButton = new QPushButton(centralwidget);
        DrawSeptButton->setObjectName(QString::fromUtf8("DrawSeptButton"));
        DrawSeptButton->setGeometry(QRect(10, 390, 91, 23));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(450, 10, 111, 16));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(290, 10, 75, 23));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(660, 10, 75, 23));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 251, 250));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        ImagesWindow = new QListWidget(verticalLayoutWidget);
        ImagesWindow->setObjectName(QString::fromUtf8("ImagesWindow"));

        verticalLayout->addWidget(ImagesWindow);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        ClassWindow = new QListWidget(verticalLayoutWidget);
        ClassWindow->setObjectName(QString::fromUtf8("ClassWindow"));

        verticalLayout->addWidget(ClassWindow);

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
        pushButton->setText(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Zoom Out", nullptr));
        DrawTriangleButton->setText(QCoreApplication::translate("MainWindow", "Draw Triangle", nullptr));
        DrawRectButton->setText(QCoreApplication::translate("MainWindow", "Draw Rectangle", nullptr));
        DrawPentButton->setText(QCoreApplication::translate("MainWindow", "Draw Pentagon", nullptr));
        DrawHexButton->setText(QCoreApplication::translate("MainWindow", "DrawHexButton", nullptr));
        DrawSeptButton->setText(QCoreApplication::translate("MainWindow", "Draw Septagon", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Image Pane", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Rotate Left", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Rotate Right", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Images", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Classifier Path", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
