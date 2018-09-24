#include "main.h"

namespace mtd
{

class CentralWidget : public QWidget
{
public:
    CentralWidget(QWidget *parent=nullptr) : QWidget(parent) {
        auto main_lbl = new QLabel("Hello, world!");
        main_lbl->setAlignment(Qt::AlignCenter);

        auto cancel_btn = new QPushButton("Cancel");
        auto accept_btn = new QPushButton("Accept");

        connect(
            cancel_btn, &QPushButton::clicked
            , this, &CentralWidget::handle_cancel
        );

        connect(
            accept_btn, &QPushButton::clicked
            , this, &CentralWidget::handle_accept
        );

        auto hlayout = new QHBoxLayout();

        hlayout->addWidget(cancel_btn);
        hlayout->addWidget(accept_btn);

        auto vlayout = new QVBoxLayout();
        vlayout->addWidget(main_lbl);
        vlayout->addLayout(hlayout);

        this->setLayout(vlayout);
    }

    void handle_cancel() {
        std::cerr << "handle cancel" << std::endl;
    }

    void handle_accept() {
        std::cerr << "handle accept" << std::endl;
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
