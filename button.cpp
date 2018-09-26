#include "button.h"

namespace mtd
{

PushButton::PushButton(QWidget *parent) : QPushButton(parent) {}

PushButton::PushButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent) {}

PushButton::PushButton(
    const QIcon &icon, const QString &text, QWidget *parent
) : QPushButton(icon, text, parent) {}

void PushButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);

    QBrush brush(Qt::red, Qt::SolidPattern);

    painter.setOpacity(1);
    painter.setBrush(brush);
    painter.drawRect(this->rect());

    painter.setPen(Qt::black);
    painter.drawText(this->rect(), Qt::AlignCenter, this->text());

    // QPushButton::paintEvent(event);
}

} // namespace mtd
