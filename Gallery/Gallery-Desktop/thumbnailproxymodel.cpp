#include "thumbnailproxymodel.h"


const unsigned int THUMBNAIL_SIZE = 350;

ThumbnailProxyModel::ThumbnailProxyModel()
{

}

QVariant ThumbnailProxyModel::data(const QModelIndex &index_, int role_) const
{
    if (role_ != Qt::DecorationRole) {
            return QIdentityProxyModel::data(index_, role_);
        }

        QString filepath = sourceModel()->data(index_,
                                     PictureModel::Roles::FilePathRole).toString();
        return *mThumbnails[filepath];
}

void ThumbnailProxyModel::setSourceModel(QAbstractItemModel *sourceModel_)
{
    QIdentityProxyModel::setSourceModel(sourceModel_);
        if (!sourceModel_) {
            return;
        }

        connect(sourceModel_, &QAbstractItemModel::modelReset,
                      [this] {
            reloadThumbnails();
        });

        connect(sourceModel_, &QAbstractItemModel::rowsInserted,
                     [this] (const QModelIndex& parent, int first, int last) {
            generateThumbnails(index(first, 0), last - first + 1);
        });
}

PictureModel *ThumbnailProxyModel::pictureModel() const
{
    return static_cast<PictureModel*>(sourceModel());
}

void ThumbnailProxyModel::generateThumbnails(const QModelIndex &startIndex_, int count_)
{
    if (!startIndex.isValid()) {
           return;
       }

       const QAbstractItemModel* model = startIndex.model();
       int lastIndex = startIndex.row() + count;
       for(int row = startIndex.row(); row < lastIndex; row++) {
           QString filepath = model->data(model->index(row, 0),
                                                      PictureModel::Roles::FilePathRole).toString();
           QPixmap pixmap(filepath);
           auto thumbnail = new QPixmap(pixmap
                                        .scaled(THUMBNAIL_SIZE, THUMBNAIL_SIZE,
                                                Qt::KeepAspectRatio,
                                                Qt::SmoothTransformation));
           mThumbnails.insert(filepath, thumbnail);
       }
}

void ThumbnailProxyModel::reloadThumbnails()
{
    qDeleteAll(_mThumbnails);
    _mThumbnails.clear();
    generateThumbnails(index(0, 0), rowCount());
}
