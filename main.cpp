#include "main.h"

namespace mtd
{

class CentralWidget : public QWidget
{
    QStateMachine *machine;

    PushButton *reject_btn;
    PushButton *accept_btn;

public:
    CentralWidget(QWidget *parent=nullptr) : QWidget(parent) {
        auto main_lbl = new QLabel("Hello, world!");
        main_lbl->setAlignment(Qt::AlignCenter);

        reject_btn = new PushButton("Cancel");
        accept_btn = new PushButton("Accept");

        connect(
            reject_btn, &QPushButton::clicked
            , this, &CentralWidget::handle_reject
        );

        connect(
            accept_btn, &QPushButton::clicked
            , this, &CentralWidget::handle_accept
        );

        machine = new QStateMachine();

        auto proposed = new QState();
        auto rejected = new QState();
        auto accepted = new QState();

        proposed->assignProperty(machine, "state", "proposed");
        rejected->assignProperty(machine, "state", "rejected");
        accepted->assignProperty(machine, "state", "accepted");

        machine->addState(proposed);
        machine->addState(rejected);
        machine->addState(accepted);

        proposed->addTransition(reject_btn, &QPushButton::clicked, rejected);
        proposed->addTransition(accept_btn, &QPushButton::clicked, accepted);

        machine->setInitialState(proposed);
        qDebug() << machine->property("state").toString();
        machine->start();
        qDebug() << machine->property("state").toString();

        auto hlayout = new QHBoxLayout();

        hlayout->addWidget(reject_btn);
        hlayout->addWidget(accept_btn);

        auto vlayout = new QVBoxLayout();
        vlayout->addWidget(main_lbl);
        vlayout->addLayout(hlayout);

        this->setLayout(vlayout);
    }

    void handle_reject() const {
        std::cerr << "handle cancel" << std::endl;
        qDebug() << machine->property("state").toString();
        qDebug() << reject_btn->rect();
        qDebug() << reject_btn->pos();
        qDebug() << rect();
    }

    void handle_accept() const {
        std::cerr << "handle accept" << std::endl;
        qDebug() << machine->property("state").toString();
        qDebug() << accept_btn->rect();
        qDebug() << accept_btn->pos();
        qDebug() << rect();
    }
};

class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent=nullptr) : QMainWindow(parent) {
        this->setCentralWidget(new CentralWidget);
    }
};

} // namespace mtd

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    auto window = new mtd::MainWindow();

    window->resize(320, 240);
    window->show();
    window->setWindowTitle("Hello, world!");

    return app.exec();
}
