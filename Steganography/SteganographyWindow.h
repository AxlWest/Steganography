#ifndef STEGANOGRAPHYWINDOW_H
#define STEGANOGRAPHYWINDOW_H

#include <QDialog>

namespace Ui {
class SteganographyWindow;
}

class SteganographyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SteganographyWindow(QWidget *parent = 0);
    ~SteganographyWindow();

private:
    Ui::SteganographyWindow *ui;
};

#endif // STEGANOGRAPHYWINDOW_H
