#include "ExtractWindow.h"
#include "ui_ExtractWindow.h"

ExtractWindow::ExtractWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExtractWindow)
{
    ui->setupUi(this);
}

ExtractWindow::~ExtractWindow()
{
    delete ui;
}
