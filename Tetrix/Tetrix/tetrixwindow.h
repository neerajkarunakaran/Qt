#ifndef TETRIXWINDOW_H
#define TETRIXWINDOW_H

#include <QMainWindow>

namespace Ui {
class TetrixWindow;
}

class TetrixWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TetrixWindow(QWidget *parent = 0);
    ~TetrixWindow();

private:
    Ui::TetrixWindow *ui;
};

#endif // TETRIXWINDOW_H
