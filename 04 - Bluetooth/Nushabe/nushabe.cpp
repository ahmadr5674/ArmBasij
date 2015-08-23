#include "nushabe.h"
#include "ui_nushabe.h"

Nushabe::Nushabe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nushabe)
{
    percentage = 50;
    ui->setupUi(this);
    QPushButton* up = new QPushButton("up");
    QPushButton* down = new QPushButton("down");
    QProgressBar* prog = new QProgressBar();

}

Nushabe::~Nushabe()
{
    delete ui;
}

void Nushabe::increase_light()
{
    percentage = percentage + 10;
}

void Nushabe::decrease_light()
{
    percentage = percentage - 10;
}
