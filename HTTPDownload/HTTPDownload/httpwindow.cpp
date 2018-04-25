#include "httpwindow.h"
#include "ui_httpwindow.h"

HttpWindow::HttpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HttpWindow)
{
    ui->setupUi(this);
}

HttpWindow::~HttpWindow()
{
    delete ui;
}
