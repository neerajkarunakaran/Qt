#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent_) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);

    AlbumModel* albumModel = new AlbumModel(this);
    QItemSelectionModel* albumSelectionModel =
        new QItemSelectionModel(albumModel, this);
    _mGalleryWidget->setAlbumModel(albumModel);
    _mGalleryWidget->setAlbumSelectionModel(albumSelectionModel);

    PictureModel* pictureModel = new PictureModel(*albumModel, this);
    ThumbnailProxyModel* thumbnailModel = new ThumbnailProxyModel(this); thumbnailModel->setSourceModel(pictureModel);

    QItemSelectionModel* pictureSelectionModel = new QItemSelectionModel(pictureModel, this);

    _mGalleryWidget->setPictureModel(thumbnailModel);
    _mGalleryWidget->setPictureSelectionModel(pictureSelectionModel);
    _mPictureWidget->setModel(thumbnailModel);
    _mPictureWidget->setSelectionModel(pictureSelectionModel);

    connect(_mGalleryWidget, &GalleryWidget::pictureActivated,
            this, &MainWindow::displayPicture);

    connect(_mPictureWidget, &PictureWidget::backToGallery,
            this, &MainWindow::displayGallery);

    _mStackedWidget->addWidget(_mGalleryWidget);
    _mStackedWidget->addWidget(_mPictureWidget);
    displayGallery();

    setCentralWidget(_mStackedWidget);


}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::displayGallery()
{
    _mStackedWidget->setCurrentWidget(_mGalleryWidget);
}

void MainWindow::displayPicture(const QModelIndex &index_)
{
    _mStackedWidget->setCurrentWidget(_mPictureWidget);
}
