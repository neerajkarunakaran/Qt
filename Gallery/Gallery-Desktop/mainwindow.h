#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

namespace Ui {
class MainWindow;
}

class GalleryWidget;
class PictureWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent_ = 0);
    ~MainWindow();

public slots:
    void displayGallery();
    void displayPicture(const QModelIndex& index_);

private:
    Ui::MainWindow *_ui;
    GalleryWidget* _mGalleryWidget;
    PictureWidget* _mPictureWidget;
    QStackedWidget* _mStackedWidget;
};


#endif // MAINWINDOW_H
