#ifndef ALBUMLISTWIDGET_H
#define ALBUMLISTWIDGET_H

#include <QWidget>

#include <QItemSelectionModel>

namespace Ui {
class AlbumListWidget;
}

class AlbumModel;

class AlbumListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlbumListWidget(QWidget *parent_ = 0);
    ~AlbumListWidget();

    void setModel(AlbumModel* model_);
    void setSelectionModel(QItemSelectionModel* selectionModel_);

private slots:
    void createAlbum();

private:
    Ui::AlbumListWidget* _ui;
    AlbumModel*          _mAlbumModel;
};


#endif // ALBUMLISTWIDGET_H
