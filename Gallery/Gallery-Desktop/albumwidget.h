#ifndef ALBUMWIDGET_H
#define ALBUMWIDGET_H

#include <QWidget>
#include <QModelIndex>

namespace Ui {
class AlbumWidget;
}

class AlbumModel;
class PictureModel;
class QItemSelectionModel;
class ThumbnailProxyModel;

class AlbumWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlbumWidget(QWidget *parent_ = 0);
    ~AlbumWidget();

    void setAlbumModel(AlbumModel* albumModel_);
    void setAlbumSelectionModel(QItemSelectionModel* albumSelectionModel_);
    void setPictureModel(ThumbnailProxyModel* pictureModel_);
    void setPictureSelectionModel(QItemSelectionModel* selectionModel_);

signals:
    void pictureActivated(const QModelIndex& index_);

private slots:
    void deleteAlbum();
    void editAlbum();
    void addPictures();

private:
    void clearUi();
    void loadAlbum(const QModelIndex& albumIndex_);

private:
    Ui::AlbumWidget* _ui;
    AlbumModel* _mAlbumModel;
    QItemSelectionModel* _mAlbumSelectionModel;

    ThumbnailProxyModel* _mPictureModel;
    QItemSelectionModel* _mPictureSelectionModel;
};

#endif // ALBUMWIDGET_H
