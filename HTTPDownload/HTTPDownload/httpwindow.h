#ifndef HTTPWINDOW_H
#define HTTPWINDOW_H

#include <QDialog>

namespace Ui {
class HttpWindow;
}

class HttpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HttpWindow(QWidget *parent = 0);
    ~HttpWindow();

private:
    Ui::HttpWindow *ui;
};

#endif // HTTPWINDOW_H
