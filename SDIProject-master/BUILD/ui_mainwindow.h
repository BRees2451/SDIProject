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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QPushButton *DrawPolyButton;
    QLabel *label_3;
    QPushButton *RotateLButton;
    QPushButton *RotateRButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *newClassLayout_3;
    QLabel *newClass_3;
    QLineEdit *newClassLineEdit_3;
    QLabel *ImagesLabel;
    QListWidget *ImagesWindow;
    QComboBox *sortImageBy;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddImageButton;
    QPushButton *selectImage;
    QLabel *ClassLabel;
    QListWidget *ClassWindow;
    QComboBox *sortClassBy;
    QHBoxLayout *newClassLayout;
    QLabel *newClass;
    QLineEdit *newClassLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addClassButton;
    QPushButton *selectClassButton;
    QLabel *mouse_position_label;
    QRadioButton *radioButton;
    QPushButton *pasteShape;
    QPushButton *copyShape;
    QPushButton *deleteShape;
    QPushButton *resizeShape;
    QLabel *shapeTypeLabel;
    QLineEdit *ImageSearchLine;
    QLabel *ImageSearchLabel;
    QPushButton *ImageSearchButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(865, 719);
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
        graphicsView->setGeometry(QRect(330, 40, 521, 381));
        ZoomInButton = new QPushButton(centralwidget);
        ZoomInButton->setObjectName(QString::fromUtf8("ZoomInButton"));
        ZoomInButton->setGeometry(QRect(630, 430, 101, 31));
        ZoomOutButton = new QPushButton(centralwidget);
        ZoomOutButton->setObjectName(QString::fromUtf8("ZoomOutButton"));
        ZoomOutButton->setGeometry(QRect(740, 430, 101, 31));
        DrawTriangleButton = new QPushButton(centralwidget);
        DrawTriangleButton->setObjectName(QString::fromUtf8("DrawTriangleButton"));
        DrawTriangleButton->setGeometry(QRect(20, 460, 101, 31));
        DrawRectButton = new QPushButton(centralwidget);
        DrawRectButton->setObjectName(QString::fromUtf8("DrawRectButton"));
        DrawRectButton->setGeometry(QRect(130, 460, 101, 31));
        DrawTrapButton = new QPushButton(centralwidget);
        DrawTrapButton->setObjectName(QString::fromUtf8("DrawTrapButton"));
        DrawTrapButton->setGeometry(QRect(20, 500, 101, 31));
        DrawPolyButton = new QPushButton(centralwidget);
        DrawPolyButton->setObjectName(QString::fromUtf8("DrawPolyButton"));
        DrawPolyButton->setGeometry(QRect(130, 500, 101, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 10, 111, 16));
        RotateLButton = new QPushButton(centralwidget);
        RotateLButton->setObjectName(QString::fromUtf8("RotateLButton"));
        RotateLButton->setGeometry(QRect(340, 430, 101, 31));
        RotateRButton = new QPushButton(centralwidget);
        RotateRButton->setObjectName(QString::fromUtf8("RotateRButton"));
        RotateRButton->setGeometry(QRect(450, 430, 101, 31));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 311, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        newClassLayout_3 = new QHBoxLayout();
        newClassLayout_3->setObjectName(QString::fromUtf8("newClassLayout_3"));
        newClass_3 = new QLabel(verticalLayoutWidget);
        newClass_3->setObjectName(QString::fromUtf8("newClass_3"));
        newClass_3->setEnabled(true);

        newClassLayout_3->addWidget(newClass_3);

        newClassLineEdit_3 = new QLineEdit(verticalLayoutWidget);
        newClassLineEdit_3->setObjectName(QString::fromUtf8("newClassLineEdit_3"));
        newClassLineEdit_3->setEnabled(false);

        newClassLayout_3->addWidget(newClassLineEdit_3);


        verticalLayout->addLayout(newClassLayout_3);

        ImagesLabel = new QLabel(verticalLayoutWidget);
        ImagesLabel->setObjectName(QString::fromUtf8("ImagesLabel"));

        verticalLayout->addWidget(ImagesLabel);

        ImagesWindow = new QListWidget(verticalLayoutWidget);
        ImagesWindow->setObjectName(QString::fromUtf8("ImagesWindow"));

        verticalLayout->addWidget(ImagesWindow);

        sortImageBy = new QComboBox(verticalLayoutWidget);
        sortImageBy->addItem(QString());
        sortImageBy->addItem(QString());
        sortImageBy->addItem(QString());
        sortImageBy->addItem(QString());
        sortImageBy->setObjectName(QString::fromUtf8("sortImageBy"));

        verticalLayout->addWidget(sortImageBy);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 5);
        AddImageButton = new QPushButton(verticalLayoutWidget);
        AddImageButton->setObjectName(QString::fromUtf8("AddImageButton"));

        horizontalLayout->addWidget(AddImageButton);

        selectImage = new QPushButton(verticalLayoutWidget);
        selectImage->setObjectName(QString::fromUtf8("selectImage"));

        horizontalLayout->addWidget(selectImage);


        verticalLayout->addLayout(horizontalLayout);

        ClassLabel = new QLabel(verticalLayoutWidget);
        ClassLabel->setObjectName(QString::fromUtf8("ClassLabel"));

        verticalLayout->addWidget(ClassLabel);

        ClassWindow = new QListWidget(verticalLayoutWidget);
        ClassWindow->setObjectName(QString::fromUtf8("ClassWindow"));

        verticalLayout->addWidget(ClassWindow);

        sortClassBy = new QComboBox(verticalLayoutWidget);
        sortClassBy->addItem(QString());
        sortClassBy->addItem(QString());
        sortClassBy->setObjectName(QString::fromUtf8("sortClassBy"));

        verticalLayout->addWidget(sortClassBy);

        newClassLayout = new QHBoxLayout();
        newClassLayout->setObjectName(QString::fromUtf8("newClassLayout"));
        newClass = new QLabel(verticalLayoutWidget);
        newClass->setObjectName(QString::fromUtf8("newClass"));
        newClass->setEnabled(true);

        newClassLayout->addWidget(newClass);

        newClassLineEdit = new QLineEdit(verticalLayoutWidget);
        newClassLineEdit->setObjectName(QString::fromUtf8("newClassLineEdit"));
        newClassLineEdit->setEnabled(false);

        newClassLayout->addWidget(newClassLineEdit);


        verticalLayout->addLayout(newClassLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        addClassButton = new QPushButton(verticalLayoutWidget);
        addClassButton->setObjectName(QString::fromUtf8("addClassButton"));

        horizontalLayout_2->addWidget(addClassButton);

        selectClassButton = new QPushButton(verticalLayoutWidget);
        selectClassButton->setObjectName(QString::fromUtf8("selectClassButton"));

        horizontalLayout_2->addWidget(selectClassButton);


        verticalLayout->addLayout(horizontalLayout_2);

        mouse_position_label = new QLabel(centralwidget);
        mouse_position_label->setObjectName(QString::fromUtf8("mouse_position_label"));
        mouse_position_label->setGeometry(QRect(660, 480, 181, 61));
        mouse_position_label->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 216, 216);"));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(30, 580, 82, 17));
        pasteShape = new QPushButton(centralwidget);
        pasteShape->setObjectName(QString::fromUtf8("pasteShape"));
        pasteShape->setGeometry(QRect(130, 570, 75, 23));
        copyShape = new QPushButton(centralwidget);
        copyShape->setObjectName(QString::fromUtf8("copyShape"));
        copyShape->setGeometry(QRect(130, 540, 75, 23));
        deleteShape = new QPushButton(centralwidget);
        deleteShape->setObjectName(QString::fromUtf8("deleteShape"));
        deleteShape->setGeometry(QRect(130, 600, 75, 23));
        resizeShape = new QPushButton(centralwidget);
        resizeShape->setObjectName(QString::fromUtf8("resizeShape"));
        resizeShape->setGeometry(QRect(130, 630, 75, 23));
        shapeTypeLabel = new QLabel(centralwidget);
        shapeTypeLabel->setObjectName(QString::fromUtf8("shapeTypeLabel"));
        shapeTypeLabel->setGeometry(QRect(706, 10, 141, 20));
        ImageSearchLine = new QLineEdit(centralwidget);
        ImageSearchLine->setObjectName(QString::fromUtf8("ImageSearchLine"));
        ImageSearchLine->setGeometry(QRect(420, 570, 113, 20));
        ImageSearchLabel = new QLabel(centralwidget);
        ImageSearchLabel->setObjectName(QString::fromUtf8("ImageSearchLabel"));
        ImageSearchLabel->setGeometry(QRect(340, 570, 71, 20));
        ImageSearchButton = new QPushButton(centralwidget);
        ImageSearchButton->setObjectName(QString::fromUtf8("ImageSearchButton"));
        ImageSearchButton->setGeometry(QRect(540, 570, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 865, 21));
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
        DrawPolyButton->setText(QCoreApplication::translate("MainWindow", "Draw Polygon", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Image Pane", nullptr));
        RotateLButton->setText(QCoreApplication::translate("MainWindow", "Rotate Left", nullptr));
        RotateRButton->setText(QCoreApplication::translate("MainWindow", "Rotate Right", nullptr));
        newClass_3->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        ImagesLabel->setText(QCoreApplication::translate("MainWindow", "Images", nullptr));
        sortImageBy->setItemText(0, QCoreApplication::translate("MainWindow", "Name (Asc)", nullptr));
        sortImageBy->setItemText(1, QCoreApplication::translate("MainWindow", "Name (Desc)", nullptr));
        sortImageBy->setItemText(2, QCoreApplication::translate("MainWindow", "Date (Asc)", nullptr));
        sortImageBy->setItemText(3, QCoreApplication::translate("MainWindow", "Date (Desc)", nullptr));

        AddImageButton->setText(QCoreApplication::translate("MainWindow", "Add Image", nullptr));
        selectImage->setText(QCoreApplication::translate("MainWindow", "Select Image", nullptr));
        ClassLabel->setText(QCoreApplication::translate("MainWindow", "Classifier Path", nullptr));
        sortClassBy->setItemText(0, QCoreApplication::translate("MainWindow", "Name (Asc)", nullptr));
        sortClassBy->setItemText(1, QCoreApplication::translate("MainWindow", "Name (Desc)", nullptr));

        newClass->setText(QCoreApplication::translate("MainWindow", "New Object:", nullptr));
        addClassButton->setText(QCoreApplication::translate("MainWindow", "Add Object", nullptr));
        selectClassButton->setText(QCoreApplication::translate("MainWindow", "Select Object", nullptr));
        mouse_position_label->setText(QString());
        radioButton->setText(QCoreApplication::translate("MainWindow", "Select Shape", nullptr));
        pasteShape->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        copyShape->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        deleteShape->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        resizeShape->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        shapeTypeLabel->setText(QCoreApplication::translate("MainWindow", "Shape Type: None", nullptr));
        ImageSearchLabel->setText(QCoreApplication::translate("MainWindow", "Image Search:", nullptr));
        ImageSearchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
