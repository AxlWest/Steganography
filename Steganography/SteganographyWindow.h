#ifndef STEGANOGRAPHYWINDOW_H
#define STEGANOGRAPHYWINDOW_H

#include <QDialog>
#include "LSB.h"
#include "LSB_1_0_0.h"
#include "LSB_1_2_3.h"
#include "LSB_1_3_4.h"
#include "LSB_2_0_0.h"
#include "LSB_3_0_0.h"
#include "LSB_4_0_0.h"
#include "LSB_0_1_0.h"
#include "LSB_0_2_0.h"
#include "LSB_0_3_0.h"
#include "LSB_0_4_0.h"
#include "LSB_0_0_1.h"
#include "LSB_0_0_2.h"
#include "LSB_0_0_3.h"
#include "LSB_0_0_4.h"
#include "LSB_2_2_2.h"
#include "LSB_3_3_3.h"
#include "LSB_4_4_4.h"

namespace Ui {
class SteganographyWindow;
}

class SteganographyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SteganographyWindow(QWidget *parent = 0);
    ~SteganographyWindow();

private slots:
    void on_StegoBrowseButton_clicked();

    void on_TextBrowseButton_clicked();

    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::SteganographyWindow *ui;
};

#endif // STEGANOGRAPHYWINDOW_H
