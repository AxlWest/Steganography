#include "ExtractWindow.h"
#include "ui_ExtractWindow.h"
#include "Bitmap.h"
#include "ImageFile.h"
#include "LSB.h"
#include "LSB_1_2_3.h"
#include "LSB_1_3_4.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>

#include <stdio.h>

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

void ExtractWindow::on_StegoPushButton_clicked()
{
    QString fileName ;
    fileName = QFileDialog::getOpenFileName(this, tr("Open File") , "/home" , tr("Images (*.bmp)")) ;

    if(fileName != NULL)
    {
        ui->StegoLineEdit->setText(fileName) ;
    }
}

void ExtractWindow::on_SavePushButton_clicked()
{
    QString dir ;
    dir = QFileDialog::getExistingDirectory(this , tr("Open Directory") , "/home" , QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks) ;

    if(dir != NULL)
    {
        ui->SaveLineEdit->setText(dir) ;
    }
}

void ExtractWindow::on_buttonBox_accepted()
{
    QMessageBox msgBox ;

    switch(ui->StegoComboBox->currentIndex())
    {
        case 0 :

            msgBox.setText("Extraction failed: Did not select type of steganography.") ;
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
                    if(ui->SaveLineEdit->text() != NULL)
                    {
                        if(ui->NameLineEdit->text() != NULL)
                        {
                            ImageFile* imageFile ;
                            Bitmap bitmap ;
                            LSB lsb ;

                            imageFile = new ImageFile() ;

                            imageFile = bitmap.bitmapFileLoader(ui->StegoLineEdit->text().toStdString().c_str()) ;

                            char* temp ;

                            temp = (char*)malloc((strlen(ui->SaveLineEdit->text().toStdString().c_str()) + strlen(ui->NameLineEdit->text().toStdString().c_str()) + (sizeof(char) * 6))) ;

                            strcpy(temp , ui->SaveLineEdit->text().toStdString().c_str()) ;
                            strcat(temp , "/") ;
                            strcat(temp , ui->NameLineEdit->text().toStdString().c_str()) ;
                            strcat(temp , ".txt") ;

                            lsb.extractSteganography(imageFile , temp) ;


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

                            char* temp ;

                            temp = (char*)malloc((strlen(ui->SaveLineEdit->text().toStdString().c_str()) + (sizeof(char) * 6))) ;

                            strcpy(temp , ui->SaveLineEdit->text().toStdString().c_str()) ;
                            strcat(temp , "/ExtractedText.txt") ;

                            lsb.extractSteganography(imageFile , temp) ;

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
                        if(ui->NameLineEdit->text() != NULL)
                        {
                            ImageFile* imageFile ;
                            Bitmap bitmap ;
                            LSB lsb ;

                            imageFile = new ImageFile() ;

                            imageFile = bitmap.bitmapFileLoader(ui->StegoLineEdit->text().toStdString().c_str()) ;

                            char* temp ;

                            temp = (char*)malloc((strlen(ui->NameLineEdit->text().toStdString().c_str()) + (sizeof(char) * 6))) ;

                            strcat(temp , ui->NameLineEdit->text().toStdString().c_str()) ;
                            strcat(temp , ".txt") ;

                            lsb.extractSteganography(imageFile , temp) ;


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

                            lsb.extractSteganography(imageFile , "ExtractedTect.txt") ;

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
                    msgBox.setText("Steganography failed: Unsupported image file type\nSupported types: .bmp.") ;
                    msgBox.setIcon(QMessageBox::Warning);
                    msgBox.exec() ;
                }
            }
            else
            {
                msgBox.setText("Steganography failed: No image sellected.") ;
                msgBox.setIcon(QMessageBox::Warning);
                msgBox.exec() ;
            }

            break ;

        case 2 :

            if(ui->StegoLineEdit->text() != NULL)
            {
                QFileInfo fi(ui->StegoLineEdit->text()) ;
                QString ext = fi.completeSuffix() ;

                if(ext == "bmp")
                {
                    if(ui->SaveLineEdit->text() != NULL)
                    {
                        if(ui->NameLineEdit->text() != NULL)
                        {
                            ImageFile* imageFile ;
                            Bitmap bitmap ;
                            LSB_1_2_3 lsb ;

                            imageFile = new ImageFile() ;

                            imageFile = bitmap.bitmapFileLoader(ui->StegoLineEdit->text().toStdString().c_str()) ;

                            char* temp ;

                            temp = (char*)malloc((strlen(ui->SaveLineEdit->text().toStdString().c_str()) + strlen(ui->NameLineEdit->text().toStdString().c_str()) + (sizeof(char) * 6))) ;

                            strcpy(temp , ui->SaveLineEdit->text().toStdString().c_str()) ;
                            strcat(temp , "/") ;
                            strcat(temp , ui->NameLineEdit->text().toStdString().c_str()) ;
                            strcat(temp , ".txt") ;

                            lsb.extractSteganography(imageFile , temp) ;


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

                            char* temp ;

                            temp = (char*)malloc((strlen(ui->SaveLineEdit->text().toStdString().c_str()) + (sizeof(char) * 6))) ;

                            strcpy(temp , ui->SaveLineEdit->text().toStdString().c_str()) ;
                            strcat(temp , "/ExtractedText.txt") ;

                            lsb.extractSteganography(imageFile , temp) ;

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
                        if(ui->NameLineEdit->text() != NULL)
                        {
                            ImageFile* imageFile ;
                            Bitmap bitmap ;
                            LSB lsb ;

                            imageFile = new ImageFile() ;

                            imageFile = bitmap.bitmapFileLoader(ui->StegoLineEdit->text().toStdString().c_str()) ;

                            char* temp ;

                            temp = (char*)malloc((strlen(ui->NameLineEdit->text().toStdString().c_str()) + (sizeof(char) * 6))) ;

                            strcat(temp , ui->NameLineEdit->text().toStdString().c_str()) ;
                            strcat(temp , ".txt") ;

                            lsb.extractSteganography(imageFile , temp) ;


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

                            lsb.extractSteganography(imageFile , "ExtractedTect.txt") ;

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
                    msgBox.setText("Steganography failed: Unsupported image file type\nSupported types: .bmp.") ;
                    msgBox.setIcon(QMessageBox::Warning);
                    msgBox.exec() ;
                }
            }
            else
            {
                msgBox.setText("Steganography failed: No image sellected.") ;
                msgBox.setIcon(QMessageBox::Warning);
                msgBox.exec() ;
            }

            break ;

        case 3 :

            if(ui->StegoLineEdit->text() != NULL)
            {
                QFileInfo fi(ui->StegoLineEdit->text()) ;
                QString ext = fi.completeSuffix() ;

                if(ext == "bmp")
                {
                    if(ui->SaveLineEdit->text() != NULL)
                    {
                        if(ui->NameLineEdit->text() != NULL)
                        {
                            ImageFile* imageFile ;
                            Bitmap bitmap ;
                            LSB_1_3_4 lsb ;

                            imageFile = new ImageFile() ;

                            imageFile = bitmap.bitmapFileLoader(ui->StegoLineEdit->text().toStdString().c_str()) ;

                            char* temp ;

                            temp = (char*)malloc((strlen(ui->SaveLineEdit->text().toStdString().c_str()) + strlen(ui->NameLineEdit->text().toStdString().c_str()) + (sizeof(char) * 6))) ;

                            strcpy(temp , ui->SaveLineEdit->text().toStdString().c_str()) ;
                            strcat(temp , "/") ;
                            strcat(temp , ui->NameLineEdit->text().toStdString().c_str()) ;
                            strcat(temp , ".txt") ;

                            lsb.extractSteganography(imageFile , temp) ;


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

                            char* temp ;

                            temp = (char*)malloc((strlen(ui->SaveLineEdit->text().toStdString().c_str()) + (sizeof(char) * 6))) ;

                            strcpy(temp , ui->SaveLineEdit->text().toStdString().c_str()) ;
                            strcat(temp , "/ExtractedText.txt") ;

                            lsb.extractSteganography(imageFile , temp) ;

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
                        if(ui->NameLineEdit->text() != NULL)
                        {
                            ImageFile* imageFile ;
                            Bitmap bitmap ;
                            LSB lsb ;

                            imageFile = new ImageFile() ;

                            imageFile = bitmap.bitmapFileLoader(ui->StegoLineEdit->text().toStdString().c_str()) ;

                            char* temp ;

                            temp = (char*)malloc((strlen(ui->NameLineEdit->text().toStdString().c_str()) + (sizeof(char) * 6))) ;

                            strcat(temp , ui->NameLineEdit->text().toStdString().c_str()) ;
                            strcat(temp , ".txt") ;

                            lsb.extractSteganography(imageFile , temp) ;


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

                            lsb.extractSteganography(imageFile , "ExtractedTect.txt") ;

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
                    msgBox.setText("Steganography failed: Unsupported image file type\nSupported types: .bmp.") ;
                    msgBox.setIcon(QMessageBox::Warning);
                    msgBox.exec() ;
                }
            }
            else
            {
                msgBox.setText("Steganography failed: No image sellected.") ;
                msgBox.setIcon(QMessageBox::Warning);
                msgBox.exec() ;
            }

            break ;

        default :

            msgBox.setText("Program error 2.") ;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec() ;

            break ;
    }
}
