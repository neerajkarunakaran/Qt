#include "picturewidget.h"
#include "ui_picturewidget.h"

PictureWidget::PictureWidget(QWidget *parent_) :
    QWidget(parent_),
    _ui(new Ui::PictureWidget)
{
    _ui->setupUi(this);
}

PictureWidget::~PictureWidget()
{
    delete _ui;
}

void PictureWidget::resizeEvent(QResizeEvent *event_)
{
    QWidget::resizeEvent(event_);
    updatePicturePixmap();
}

void PictureWidget::updatePicturePixmap()
{
    if (mPixmap.isNull()) {
            return;
        }
        _ui->pictureLabel->setPixmap(_mPixmap.scaled(_ui->pictureLabel->size(), Qt::KeepAspectRatio));
}
