#ifndef PICTUREMODEL_H
#define PICTUREMODEL_H

#include <memory>
#include <vector>

#include <QAbstractListModel>

#include "gallery-core_global.h"
#include "album.h"
#include "databasemanager.h"
#include "albummodel.h"
#include "picture.h"


class GALLERYCORESHARED_EXPORT PictureModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum PictureRole {
        FilePathRole = Qt::UserRole + 1
    };
    PictureModel(const AlbumModel& albumModel_, QObject* parent_ = 0);

    QModelIndex addPicture(const Picture& picture_);

    int rowCount(const QModelIndex& parent_ = QModelIndex()) const override;
    QVariant data(const QModelIndex& index_, int role_) const override;
    bool removeRows(int row_, int count_, const QModelIndex& parent_) override;

    void setAlbumId(int albumId_);
    void clearAlbum();

public slots:
    void deletePicturesForAlbum();

private:
    void loadPictures(int albumId_);
    bool isIndexValid(const QModelIndex& index_) const;

private:
    DatabaseManager& _mDb;
    int _mAlbumId;
    std::unique_ptr<std::vector<std::unique_ptr<Picture>>> _mPictures;
};


#endif // PICTUREMODEL_H
