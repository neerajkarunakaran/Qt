#ifndef ALBUM_H
#define ALBUM_H

#include <QString>

#include "gallery-core_global.h"

class GALLERYCORESHARED_EXPORT Album
{

public:
    explicit Album(const QString & name_ = "");

    int id()const;
    void setId(const int & id_);
    QString name()const;
    void setName(const QString & name_);

private:
    int       _mId;
    QString   _mName;
};

#endif // ALBUM_H
