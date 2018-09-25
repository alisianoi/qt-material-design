#ifndef BUTTON_H
#define BUTTON_H

#include <QtWidgets>

namespace mtd
{

class PushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButton(QWidget *parent=nullptr);
    explicit PushButton(const QString &text, QWidget *parent=nullptr);
    explicit PushButton(
        const QIcon &icon, const QString &text, QWidget *parent=nullptr
    );
};

} // namespace mtd

#endif // BUTTON_H
