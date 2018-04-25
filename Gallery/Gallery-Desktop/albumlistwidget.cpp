#include "albumlistwidget.h"
#include "ui_albumlistwidget.h"

#include <QInputDialog>

#include "albummodel.h"

AlbumListWidget::AlbumListWidget(QWidget *parent_) :
    QWidget(parent_),
    _ui(new Ui::AlbumListWidget),
    _mAlbumModel(nullptr)
{
    _ui->setupUi(this);

    connect(_ui->createAlbumButton, &QPushButton::clicked,
            this, &AlbumListWidget::createAlbum);
}

AlbumListWidget::~AlbumListWidget()
{
    delete _ui;
}

void AlbumListWidget::setModel(AlbumModel* model_)
{
    _mAlbumModel = model_;
    _ui->albumList->setModel(_mAlbumModel);
}

void AlbumListWidget::setSelectionModel(QItemSelectionModel* selectionModel_)
{
    _ui->albumList->setSelectionModel(selectionModel_);
}

void AlbumListWidget::createAlbum()
{
    if(!_mAlbumModel) {
            return;
        }

        bool ok;
        QString albumName = QInputDialog::getText(this,
                                "Create a new Album",
                                "Choose an name",
                                QLineEdit::Normal,
                                "New album",
                                &ok);

        if (ok && !albumName.isEmpty()) {
            Album album(albumName);
            QModelIndex createdIndex = mAlbumModel->addAlbum(album);
            _ui->albumList->setCurrentIndex(createdIndex);
        }
}
