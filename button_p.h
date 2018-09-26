#ifndef BUTTON_P_H
#define BUTTON_P_H

#include <QtWidgets>

class PushButtonState : public QState
{

};

class PushButtonStateMachine : public QStateMachine
{

};

class PushButtonPrivate
{
    PushButtonStateMachine *machine;

    PushButtonState *light;
    PushButtonState *heavy;
public:
    PushButtonPrivate();
};

#endif // BUTTON_P_H
