#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SteganographyWindow.h"
#include "ExtractWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    SteganographyWindow stegoWindow ;
    stegoWindow.setModal(true) ;
    stegoWindow.exec() ;
}

void MainWindow::on_pushButton_2_clicked()
{
    SteganographyWindow extraWindow ;
    extraWindow.setModal(true) ;
    extraWindow.exec() ;
}
