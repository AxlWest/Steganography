#include "SteganographyWindow.h"
#include "ui_SteganographyWindow.h"

SteganographyWindow::SteganographyWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SteganographyWindow)
{
    ui->setupUi(this);
}

SteganographyWindow::~SteganographyWindow()
{
    delete ui;
}
