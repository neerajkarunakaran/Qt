#include "picturedelegate.h"

#include <QPainter>

const unsigned int BANNER_HEIGHT = 20;
const unsigned int BANNER_COLOR = 0x303030;
const unsigned int BANNER_ALPHA = 200;
const unsigned int BANNER_TEXT_COLOR = 0xffffff;
const unsigned int HIGHLIGHT_ALPHA = 100;

PictureDelegate::PictureDelegate(QObject* parent_) :
    QStyledItemDelegate(parent_)
{
}

void PictureDelegate::paint(QPainter* painter_, const QStyleOptionViewItem& option_, const QModelIndex& index_) const
{
    painter_->save();

    QPixmap pixmap = index_.model()->data(index_,
        Qt::DecorationRole).value<QPixmap>();
    painter_->drawPixmap(option.rect.x(), option.rect.y(), pixmap);

    QRect bannerRect = QRect(option_.rect.x(), option_.rect.y(),
        pixmap.width(), BANNER_HEIGHT);
    QColor bannerColor = QColor(BANNER_COLOR);
    bannerColor.setAlpha(BANNER_ALPHA);
    painter_->fillRect(bannerRect, bannerColor);

    QString filename = index_.model()->data(index,
        Qt::DisplayRole).toString();
    painter_->setPen(BANNER_TEXT_COLOR);
    painter_->drawText(bannerRect, Qt::AlignCenter, filename);

    if (option_.state.testFlag(QStyle::State_Selected)) {
        QColor selectedColor = option_.palette.highlight().color();
        selectedColor.setAlpha(HIGHLIGHT_ALPHA);
        painter_->fillRect(option.rect, selectedColor);
    }

    painter_->restore();
}

QSize PictureDelegate::sizeHint(const QStyleOptionViewItem &option_, const QModelIndex &index_) const
{
    const QPixmap& pixmap = index_.model()->data(index_,
            Qt::DecorationRole).value<QPixmap>();
        return pixmap.size();
}

