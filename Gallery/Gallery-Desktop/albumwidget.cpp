#include "albumwidget.h"
#include "ui_albumwidget.h"

#include <QInputDialog>
#include <QFileDialog>

#include "albummodel.h"
#include "picturemodel.h"

AlbumWidget::AlbumWidget(QWidget *parent_) :
    QWidget(parent_),
    _ui(new Ui::AlbumWidget),
    _mAlbumModel(nullptr),
    _mAlbumSelectionModel(nullptr),
    _mPictureModel(nullptr),
    _mPictureSelectionModel(nullptr)
{
    _ui->setupUi(this);
    clearUi();

    _ui->thumbnailListView->setSpacing(5);
    _ui->thumbnailListView->setResizeMode(QListView::Adjust);
    _ui->thumbnailListView->setFlow(QListView::LeftToRight);
    _ui->thumbnailListView->setWrapping(true);

    connect(_ui->thumbnailListView, &QListView::doubleClicked,
            this, &AlbumWidget::pictureActivated);

    connect(_ui->deleteButton, &QPushButton::clicked,
            this, &AlbumWidget::deleteAlbum);

    connect(_ui->editButton, &QPushButton::clicked,
            this, &AlbumWidget::editAlbum);

    connect(_ui->addPicturesButton, &QPushButton::clicked,
            this, &AlbumWidget::addPictures);

    _ui->thumbnailListView->setItemDelegate(
                new PictureDelegate(this));
}

AlbumWidget::~AlbumWidget()
{
    delete _ui;
}

void AlbumWidget::setAlbumModel(AlbumModel *albumModel_)
{
    _mAlbumModel = albumModel_;

       connect(_mAlbumModel, &QAbstractItemModel::dataChanged,
           [this] (const QModelIndex &topLeft) {
               if (topLeft == _mAlbumSelectionModel->currentIndex()) {
                   loadAlbum(topLeft);
               }
       });
}

void AlbumWidget::setAlbumSelectionModel(QItemSelectionModel *albumSelectionModel_)
{
    _mAlbumSelectionModel = albumSelectionModel_;

        connect(_mAlbumSelectionModel,
                &QItemSelectionModel::selectionChanged,
                [this] (const QItemSelection &selected) {
                    if (selected.isEmpty()) {
                        clearUi();
                        return;
                    }
                    loadAlbum(selected.indexes().first());
        });
}

void AlbumWidget::setPictureModel(ThumbnailProxyModel *pictureModel_)
{
    _mPictureModel = pictureModel_;
    _ui->thumbnailListView->setModel(mPictureModel_);
}

void AlbumWidget::setPictureSelectionModel(QItemSelectionModel *selectionModel_)
{
    _ui->thumbnailListView->setSelectionModel(selectionModel_);
}

void AlbumWidget::deleteAlbum()
{
    if (_mAlbumSelectionModel->selectedIndexes().isEmpty()) {
            return;
        }
        int row = _mAlbumSelectionModel->currentIndex().row();
        _mAlbumModel->removeRow(row);

        // Try to select the previous album
        QModelIndex previousModelIndex = _mAlbumModel->index(row - 1,
            0);
        if(previousModelIndex.isValid()) {
            _mAlbumSelectionModel->setCurrentIndex(previousModelIndex,
                 QItemSelectionModel::SelectCurrent);
            return;
        }

        // Try to select the next album
        QModelIndex nextModelIndex = _mAlbumModel->index(row, 0);
        if(nextModelIndex.isValid()) {
            _mAlbumSelectionModel->setCurrentIndex(nextModelIndex,
                QItemSelectionModel::SelectCurrent);
            return;
        }
}

void AlbumWidget::editAlbum()
{
    if (_mAlbumSelectionModel->selectedIndexes().isEmpty()) {
            return;
        }

        QModelIndex currentAlbumIndex =
            _mAlbumSelectionModel->selectedIndexes().first();

        QString oldAlbumName = _mAlbumModel->data(currentAlbumIndex,
            AlbumModel::Roles::NameRole).toString();

        bool ok;
        QString newName = QInputDialog::getText(this,
                                                "Album's name",
                                                "Change Album name",
                                                QLineEdit::Normal,
                                                oldAlbumName,
                                                &ok);

        if (ok && !newName.isEmpty()) {
            _mAlbumModel->setData(currentAlbumIndex,
                                 newName,
                                 AlbumModel::Roles::NameRole);
        }
}

void AlbumWidget::addPictures()
{
    QStringList filenames =
            QFileDialog::getOpenFileNames(this,
                "Add pictures",
                 QDir::homePath(),
                "Picture files (*.jpg *.png)");

        if (!filenames.isEmpty()) {
            QModelIndex lastModelIndex;
            for (auto filename : filenames) {
                Picture picture(filename);
                lastModelIndex = _mPictureModel->pictureModel()->addPicture(picture);
            }
            _ui->thumbnailListView->setCurrentIndex(lastModelIndex);
        }
}

void AlbumWidget::clearUi()
{
    _ui->albumName->setText("");
    _ui->deleteButton->setVisible(false);
    _ui->editButton->setVisible(false);
    _ui->addPicturesButton->setVisible(false);
}

void AlbumWidget::loadAlbum(const QModelIndex &albumIndex_)
{
    _mPictureModel->pictureModel()->setAlbumId(mAlbumModel->data(albumIndex_,
            AlbumModel::Roles::IdRole).toInt());

    _ui->albumName->setText(_mAlbumModel->data(albumIndex_,
            Qt::DisplayRole).toString());

    _ui->deleteButton->setVisible(true);
    _ui->editButton->setVisible(true);
    _ui->addPicturesButton->setVisible(true);
}
