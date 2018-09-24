#include "main.h"

MyMainWidget::MyMainWidget(QWidget *parent) : QWidget(parent)
{
    auto main_lbl = new QLabel("Hello, world!");

    auto cancel_btn = new QPushButton("Cancel");
    auto accept_btn = new QPushButton("Accept");
    auto hlayout = new QHBoxLayout();

    hlayout->addWidget(cancel_btn);
    hlayout->addWidget(accept_btn);

    auto vlayout = new QVBoxLayout();
    vlayout->addWidget(main_lbl);
    vlayout->addLayout(hlayout);

    this->setLayout(vlayout);
}

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    auto window = new MyMainWidget();
    window->resize(320, 240);
    window->show();
    window->setWindowTitle("Hello, world!");
    return app.exec();
}
