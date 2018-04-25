#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H

#include <QWidget>
#include <QItemSelection>

namespace Ui {
class PictureWidget;
}

class PictureModel;
class QItemSelectionModel;
class ThumbnailProxyModel;

class PictureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PictureWidget(QWidget *parent_ = 0);
    ~PictureWidget();
    void setModel(ThumbnailProxyModel* model_);
    void setSelectionModel(QItemSelectionModel* selectionModel_);

signals:
    void backToGallery();

protected:
    void resizeEvent(QResizeEvent* event_) override;

private slots:
    void deletePicture();
    void loadPicture(const QItemSelection& selected_);

private:
    void updatePicturePixmap();

private:
    Ui::PictureWidget* _ui;
    ThumbnailProxyModel* _mModel;
    QItemSelectionModel* _mSelectionModel;
    QPixmap _mPixmap;
};

#endif // PICTUREWIDGET_H
