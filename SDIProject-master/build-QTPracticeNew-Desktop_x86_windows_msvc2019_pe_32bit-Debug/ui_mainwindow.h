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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QLineEdit *ImageSearchLine;
    QPushButton *ImageSearchButton;
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
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(865, 719);
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
        graphicsView->setGeometry(QRect(330, 40, 521, 381));
        ZoomInButton = new QPushButton(centralwidget);
        ZoomInButton->setObjectName(QStringLiteral("ZoomInButton"));
        ZoomInButton->setGeometry(QRect(630, 430, 101, 31));
        ZoomOutButton = new QPushButton(centralwidget);
        ZoomOutButton->setObjectName(QStringLiteral("ZoomOutButton"));
        ZoomOutButton->setGeometry(QRect(740, 430, 101, 31));
        DrawTriangleButton = new QPushButton(centralwidget);
        DrawTriangleButton->setObjectName(QStringLiteral("DrawTriangleButton"));
        DrawTriangleButton->setGeometry(QRect(20, 460, 101, 31));
        DrawTriangleButton->setCheckable(true);
        DrawRectButton = new QPushButton(centralwidget);
        DrawRectButton->setObjectName(QStringLiteral("DrawRectButton"));
        DrawRectButton->setGeometry(QRect(130, 460, 101, 31));
        DrawRectButton->setCheckable(true);
        DrawTrapButton = new QPushButton(centralwidget);
        DrawTrapButton->setObjectName(QStringLiteral("DrawTrapButton"));
        DrawTrapButton->setGeometry(QRect(20, 500, 101, 31));
        DrawTrapButton->setCheckable(true);
        DrawPolyButton = new QPushButton(centralwidget);
        DrawPolyButton->setObjectName(QStringLiteral("DrawPolyButton"));
        DrawPolyButton->setGeometry(QRect(130, 500, 101, 31));
        DrawPolyButton->setCheckable(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(330, 10, 111, 16));
        RotateLButton = new QPushButton(centralwidget);
        RotateLButton->setObjectName(QStringLiteral("RotateLButton"));
        RotateLButton->setGeometry(QRect(340, 430, 101, 31));
        RotateRButton = new QPushButton(centralwidget);
        RotateRButton->setObjectName(QStringLiteral("RotateRButton"));
        RotateRButton->setGeometry(QRect(450, 430, 101, 31));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 311, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        newClassLayout_3 = new QHBoxLayout();
        newClassLayout_3->setObjectName(QStringLiteral("newClassLayout_3"));
        newClass_3 = new QLabel(verticalLayoutWidget);
        newClass_3->setObjectName(QStringLiteral("newClass_3"));
        newClass_3->setEnabled(true);

        newClassLayout_3->addWidget(newClass_3);

        ImageSearchLine = new QLineEdit(verticalLayoutWidget);
        ImageSearchLine->setObjectName(QStringLiteral("ImageSearchLine"));

        newClassLayout_3->addWidget(ImageSearchLine);

        ImageSearchButton = new QPushButton(verticalLayoutWidget);
        ImageSearchButton->setObjectName(QStringLiteral("ImageSearchButton"));

        newClassLayout_3->addWidget(ImageSearchButton);


        verticalLayout->addLayout(newClassLayout_3);

        ImagesLabel = new QLabel(verticalLayoutWidget);
        ImagesLabel->setObjectName(QStringLiteral("ImagesLabel"));

        verticalLayout->addWidget(ImagesLabel);

        ImagesWindow = new QListWidget(verticalLayoutWidget);
        ImagesWindow->setObjectName(QStringLiteral("ImagesWindow"));

        verticalLayout->addWidget(ImagesWindow);

        sortImageBy = new QComboBox(verticalLayoutWidget);
        sortImageBy->setObjectName(QStringLiteral("sortImageBy"));

        verticalLayout->addWidget(sortImageBy);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 5);
        AddImageButton = new QPushButton(verticalLayoutWidget);
        AddImageButton->setObjectName(QStringLiteral("AddImageButton"));

        horizontalLayout->addWidget(AddImageButton);

        selectImage = new QPushButton(verticalLayoutWidget);
        selectImage->setObjectName(QStringLiteral("selectImage"));

        horizontalLayout->addWidget(selectImage);


        verticalLayout->addLayout(horizontalLayout);

        ClassLabel = new QLabel(verticalLayoutWidget);
        ClassLabel->setObjectName(QStringLiteral("ClassLabel"));

        verticalLayout->addWidget(ClassLabel);

        ClassWindow = new QListWidget(verticalLayoutWidget);
        ClassWindow->setObjectName(QStringLiteral("ClassWindow"));

        verticalLayout->addWidget(ClassWindow);

        sortClassBy = new QComboBox(verticalLayoutWidget);
        sortClassBy->setObjectName(QStringLiteral("sortClassBy"));

        verticalLayout->addWidget(sortClassBy);

        newClassLayout = new QHBoxLayout();
        newClassLayout->setObjectName(QStringLiteral("newClassLayout"));
        newClass = new QLabel(verticalLayoutWidget);
        newClass->setObjectName(QStringLiteral("newClass"));
        newClass->setEnabled(true);

        newClassLayout->addWidget(newClass);

        newClassLineEdit = new QLineEdit(verticalLayoutWidget);
        newClassLineEdit->setObjectName(QStringLiteral("newClassLineEdit"));
        newClassLineEdit->setEnabled(false);

        newClassLayout->addWidget(newClassLineEdit);


        verticalLayout->addLayout(newClassLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        addClassButton = new QPushButton(verticalLayoutWidget);
        addClassButton->setObjectName(QStringLiteral("addClassButton"));

        horizontalLayout_2->addWidget(addClassButton);

        selectClassButton = new QPushButton(verticalLayoutWidget);
        selectClassButton->setObjectName(QStringLiteral("selectClassButton"));

        horizontalLayout_2->addWidget(selectClassButton);


        verticalLayout->addLayout(horizontalLayout_2);

        mouse_position_label = new QLabel(centralwidget);
        mouse_position_label->setObjectName(QStringLiteral("mouse_position_label"));
        mouse_position_label->setGeometry(QRect(660, 480, 181, 61));
        mouse_position_label->setStyleSheet(QStringLiteral("background-color: rgb(216, 216, 216);"));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 580, 82, 17));
        pasteShape = new QPushButton(centralwidget);
        pasteShape->setObjectName(QStringLiteral("pasteShape"));
        pasteShape->setGeometry(QRect(130, 570, 75, 23));
        copyShape = new QPushButton(centralwidget);
        copyShape->setObjectName(QStringLiteral("copyShape"));
        copyShape->setGeometry(QRect(130, 540, 75, 23));
        deleteShape = new QPushButton(centralwidget);
        deleteShape->setObjectName(QStringLiteral("deleteShape"));
        deleteShape->setGeometry(QRect(130, 600, 75, 23));
        resizeShape = new QPushButton(centralwidget);
        resizeShape->setObjectName(QStringLiteral("resizeShape"));
        resizeShape->setGeometry(QRect(130, 630, 75, 23));
        shapeTypeLabel = new QLabel(centralwidget);
        shapeTypeLabel->setObjectName(QStringLiteral("shapeTypeLabel"));
        shapeTypeLabel->setGeometry(QRect(706, 10, 141, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 865, 21));
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
        DrawPolyButton->setText(QApplication::translate("MainWindow", "Draw Polygon", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Image Pane", Q_NULLPTR));
        RotateLButton->setText(QApplication::translate("MainWindow", "Rotate Left", Q_NULLPTR));
        RotateRButton->setText(QApplication::translate("MainWindow", "Rotate Right", Q_NULLPTR));
        newClass_3->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        ImageSearchButton->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        ImagesLabel->setText(QApplication::translate("MainWindow", "Images", Q_NULLPTR));
        sortImageBy->clear();
        sortImageBy->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Name (Asc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Name (Desc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Date (Asc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Date (Desc)", Q_NULLPTR)
        );
        AddImageButton->setText(QApplication::translate("MainWindow", "Add Image", Q_NULLPTR));
        selectImage->setText(QApplication::translate("MainWindow", "Select Image", Q_NULLPTR));
        ClassLabel->setText(QApplication::translate("MainWindow", "Classifier Path", Q_NULLPTR));
        sortClassBy->clear();
        sortClassBy->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Name (Asc)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Name (Desc)", Q_NULLPTR)
        );
        newClass->setText(QApplication::translate("MainWindow", "New Object:", Q_NULLPTR));
        addClassButton->setText(QApplication::translate("MainWindow", "Add Object", Q_NULLPTR));
        selectClassButton->setText(QApplication::translate("MainWindow", "Select Object", Q_NULLPTR));
        mouse_position_label->setText(QString());
        radioButton->setText(QApplication::translate("MainWindow", "Select Shape", Q_NULLPTR));
        pasteShape->setText(QApplication::translate("MainWindow", "Paste", Q_NULLPTR));
        copyShape->setText(QApplication::translate("MainWindow", "Copy", Q_NULLPTR));
        deleteShape->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        resizeShape->setText(QApplication::translate("MainWindow", "Resize", Q_NULLPTR));
        shapeTypeLabel->setText(QApplication::translate("MainWindow", "Shape Type: None", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
