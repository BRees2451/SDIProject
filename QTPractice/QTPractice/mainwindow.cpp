#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    painter.setBrush(Qt::BDiagPattern);

    QPen pen;
    pen.setColor(Qt::green);
    pen.setWidth(5);

    painter.setPen(pen);
    painter.drawRect(QRect(80,120,200,100));

}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText("Clicked");
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionOpen_triggered()
{
    //Create File Dialog
    QString fileName = QFileDialog::getSaveFileName(this, "Open A File","C://");
    ui->textEdit->setText(fileName);
}

//void MainWindow::on_pushButton_2_clicked()
//{
//    QPainter painter(this);
//    painter.drawRect(QRect(200,240,300,200));

//}
