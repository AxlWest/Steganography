#ifndef EXTRACTWINDOW_H
#define EXTRACTWINDOW_H

#include <QDialog>

namespace Ui {
class ExtractWindow;
}

class ExtractWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ExtractWindow(QWidget *parent = 0);
    ~ExtractWindow();

private:
    Ui::ExtractWindow *ui;
};

#endif // EXTRACTWINDOW_H
