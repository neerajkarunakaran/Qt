#ifndef PICTUREDAO_H
#define PICTUREDAO_H

#include <memory>
#include <vector>

class QSqlDatabase;
class Picture;

class PictureDao
{
public:
    explicit PictureDao(QSqlDatabase& database_);
    void init() const;

    void addPictureInAlbum(int albumId_, Picture& picture_) const;
    void removePicture(int id_) const;
    void removePicturesForAlbum(int albumId_) const;
    std::unique_ptr<std::vector<std::unique_ptr<Picture>>> picturesForAlbum(int albumId_) const;

private:
    QSqlDatabase& _mDatabase;
};


#endif // PICTUREDAO_H
