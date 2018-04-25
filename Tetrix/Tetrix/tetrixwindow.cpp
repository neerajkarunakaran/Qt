#include "tetrixwindow.h"
#include "ui_tetrixwindow.h"

TetrixWindow::TetrixWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TetrixWindow)
{
    ui->setupUi(this);
}

TetrixWindow::~TetrixWindow()
{
    delete ui;
}
