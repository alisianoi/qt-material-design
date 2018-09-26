#ifndef BUTTON_H
#define BUTTON_H

#include <QtWidgets>

#include "button_p.h"

namespace mtd
{

class PushButton : public QPushButton
{
    Q_OBJECT
public:
    PushButton(QWidget *parent=nullptr);
    PushButton(const QString &text, QWidget *parent=nullptr);
    PushButton(const QIcon &icon, const QString &text, QWidget *parent=nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Q_DISABLE_COPY(PushButton)
    Q_DECLARE_PRIVATE(PushButton)
};

} // namespace mtd

#endif // BUTTON_H
