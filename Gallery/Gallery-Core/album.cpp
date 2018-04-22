#include "album.h"


Album::Album(const QString &name_)
    :_mId(-1)
    , _mName(name_)
{

}

int Album::id() const
{
    return _mId;
}

void Album::setId(const int &id_)
{
    _mId = id_;
}

QString Album::name() const
{
    return _mName;
}

void Album::setName(const QString &name)
{
    _mName = name_;
}
