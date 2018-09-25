#include "button.h"

mtd::PushButton::PushButton(QWidget *parent) : QPushButton(parent) {}

mtd::PushButton::PushButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent) {}

mtd::PushButton::PushButton(
    const QIcon &icon, const QString &text, QWidget *parent
) : QPushButton(icon, text, parent) {}
