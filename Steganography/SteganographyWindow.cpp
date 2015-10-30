#include "SteganographyWindow.h"
#include "ui_SteganographyWindow.h"
#include "Bitmap.h"
#include "ImageFile.h"
#include <string.h>
#include <stdlib.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>

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

void SteganographyWindow::on_StegoBrowseButton_clicked()
{
    QString fileName ;
    fileName = QFileDialog::getOpenFileName(this, tr("Open File") , "/home" , tr("Images (*.bmp)")) ;

    if(fileName != NULL)
    {
        ui->StegoLineEdit->setText(fileName) ;
    }
}

void SteganographyWindow::on_TextBrowseButton_clicked()
{
    QString fileName ;
    fileName = QFileDialog::getOpenFileName(this, tr("Open File") , "/home" , tr("Text files (*.txt)")) ;

    if(fileName != NULL)
    {
        ui->TextLineEdit->setText(fileName) ;
    }
}

void SteganographyWindow::on_pushButton_clicked()
{
    QString dir ;
    dir = QFileDialog::getExistingDirectory(this , tr("Open Directory") , "/home" , QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks) ;

    if(dir != NULL)
    {
        ui->SaveLineEdit->setText(dir) ;
    }
}

void SteganographyWindow::on_buttonBox_accepted()
{
    QMessageBox msgBox ;

    switch(ui->StegoComboBox->currentIndex())
    {
        case 0 :

            msgBox.setText("Steganography failed: Did not select type of steganography.") ;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec() ;

            break ;

        case 1 :

            if(ui->StegoLineEdit->text() != NULL)
            {
                QFileInfo fi(ui->StegoLineEdit->text()) ;
                QString ext = fi.completeSuffix() ;

                if(ext == "bmp")
                {
                    if(ui->TextLineEdit->text() != NULL)
                    {
                        QFileInfo fi(ui->TextLineEdit->text()) ;
                        QString ext = fi.completeSuffix() ;

                        if(ext == "txt")
                        {
                            if(ui->SaveLineEdit->text() != NULL)
                            {
                                if(ui->SaveNameLineEdit->text() != NULL)
                                {
                                    ImageFile* imageFile ;
                                    Bitmap bitmap ;
                                    LSB lsb ;

                                    imageFile = new ImageFile() ;

                                    imageFile = bitmap.bitmapFileLoader(ui->StegoLineEdit->text().toStdString().c_str()) ;
                                    lsb.proformSteganography(imageFile , ui->TextLineEdit->text().toStdString().c_str()) ;

                                    char* temp ;

                                    temp = (char*)malloc((strlen(ui->SaveLineEdit->text().toStdString().c_str()) + strlen(ui->SaveNameLineEdit->text().toStdString().c_str()) + (sizeof(char) * 6))) ;

                                    strcpy(temp , ui->SaveLineEdit->text().toStdString().c_str()) ;
                                    strcat(temp , "/") ;
                                    strcat(temp , ui->SaveNameLineEdit->text().toStdString().c_str()) ;
                                    strcat(temp , ".bmp") ;

                                    bitmap.bitmapFileSaver(temp , imageFile->getWidth() , imageFile->getHeight() , imageFile->getImage()) ;

                                    if(imageFile != NULL)
                                    {
                                        delete imageFile ;
                                        imageFile = NULL ;
                                    }

                                    if(temp != NULL)
                                    {
                                        free(temp) ;
                                        temp = NULL ;
                                    }
                                }
                                else
                                {
                                    ImageFile* imageFile ;
                                    Bitmap bitmap ;
                                    LSB lsb ;

                                    imageFile = new ImageFile() ;

                                    imageFile = bitmap.bitmapFileLoader(ui->StegoLineEdit->text().toStdString().c_str()) ;
                                    lsb.proformSteganography(imageFile , ui->TextLineEdit->text().toStdString().c_str()) ;

                                    char* temp = NULL ;
                                    temp = (char*)malloc(strlen(ui->SaveLineEdit->text().toStdString().c_str()) + (sizeof(char) * 6)) ;
                                    strcat(temp , ui->SaveLineEdit->text().toStdString().c_str()) ;
                                    strcat(temp , "/") ;
                                    strcat(temp , "StegoImage.bmp") ;

                                    bitmap.bitmapFileSaver(temp , imageFile->getWidth() , imageFile->getHeight() , imageFile->getImage()) ;

                                    if(imageFile != NULL)
                                    {
                                        delete imageFile ;
                                        imageFile = NULL ;
                                    }

                                    if(temp != NULL)
                                    {
                                        free(temp) ;
                                        temp = NULL ;
                                    }
                                }
                            }
                            else
                            {
                                if(ui->SaveNameLineEdit->text() != NULL)
                                {
                                    ImageFile* imageFile ;
                                    Bitmap bitmap ;
                                    LSB lsb ;

                                    imageFile = new ImageFile() ;

                                    imageFile = bitmap.bitmapFileLoader(ui->StegoLineEdit->text().toStdString().c_str()) ;
                                    lsb.proformSteganography(imageFile , ui->TextLineEdit->text().toStdString().c_str()) ;

                                    char* temp = NULL ;
                                    temp = (char*)malloc(((strlen(ui->SaveLineEdit->text().toStdString().c_str()) + (sizeof(char) * 6)))) ;
                                    strcat(temp , ui->SaveLineEdit->text().toStdString().c_str()) ;
                                    strcat(temp , "/") ;
                                    strcat(temp , "StegoImage.bmp") ;

                                    bitmap.bitmapFileSaver(temp , imageFile->getWidth() , imageFile->getHeight() , imageFile->getImage()) ;

                                    if(imageFile != NULL)
                                    {
                                        delete imageFile ;
                                        imageFile = NULL ;
                                    }
                                }
                                else
                                {
                                    ImageFile* imageFile ;
                                    Bitmap bitmap ;
                                    LSB lsb ;

                                    imageFile = new ImageFile() ;

                                    imageFile = bitmap.bitmapFileLoader(ui->StegoLineEdit->text().toStdString().c_str()) ;
                                    lsb.proformSteganography(imageFile , ui->TextLineEdit->text().toStdString().c_str()) ;

                                    bitmap.bitmapFileSaver("StegoImage.bmp" , imageFile->getWidth() , imageFile->getHeight() , imageFile->getImage()) ;

                                    if(imageFile != NULL)
                                    {
                                        delete imageFile ;
                                        imageFile = NULL ;
                                    }
                                }
                            }
                        }
                        else
                        {
                            msgBox.setText("Steganography failed: Unsupported text file type\nSupported types: .txt.") ;
                            msgBox.setIcon(QMessageBox::Warning);
                            msgBox.exec() ;
                        }
                    }
                    else
                    {
                        msgBox.setText("Steganography failed: Did not select a text file.") ;
                        msgBox.setIcon(QMessageBox::Warning);
                        msgBox.exec() ;
                    }
                }
                else
                {
                    msgBox.setText("Steganography failed: Unsupported image file type\nSupported types: .bmp.") ;
                    msgBox.setIcon(QMessageBox::Warning);
                    msgBox.exec() ;
                }
            }
            else
            {
                msgBox.setText("Steganography failed: Did not select an image.") ;
                msgBox.setIcon(QMessageBox::Warning);
                msgBox.exec() ;
            }

            break ;

        default :

            msgBox.setText("Program error 1.") ;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec() ;

            break ;
    }
}
