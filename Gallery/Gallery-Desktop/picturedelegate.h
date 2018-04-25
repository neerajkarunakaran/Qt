#ifndef PICTUREDELEGATE_H
#define PICTUREDELEGATE_H


#include <QStyledItemDelegate>

class PictureDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    PictureDelegate(QObject* parent_ = 0);

    void paint(QPainter* painter_, const QStyleOptionViewItem&
        option_, const QModelIndex& index_) const override;

    QSize sizeHint(const QStyleOptionViewItem& option_,
        const QModelIndex& index_) const override;
};


#endif // PICTUREDELEGATE_H
