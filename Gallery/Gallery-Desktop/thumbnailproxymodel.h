#ifndef THUMBNAILPROXYMODEL_H
#define THUMBNAILPROXYMODEL_H


#include <QIdentityProxyModel>
#include <QHash>
#include <QPixmap>

class PictureModel;

class ThumbnailProxyModel : public QIdentityProxyModel
{
public:
    ThumbnailProxyModel(QObject* parent = 0);

    QVariant data(const QModelIndex& index_, int role_) const override;
    void setSourceModel(QAbstractItemModel* sourceModel_) override;
    PictureModel* pictureModel() const;

private:
    void generateThumbnails(const QModelIndex& startIndex_, int count_);
    void reloadThumbnails();

private:
   QHash<QString, QPixmap*> _mThumbnails;

};

#endif // THUMBNAILPROXYMODEL_H
