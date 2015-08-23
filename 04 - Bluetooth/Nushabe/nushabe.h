#ifndef NUSHABE_H
#define NUSHABE_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QDial>
namespace Ui {
class Nushabe;
}

class Nushabe : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nushabe(QWidget *parent = 0);
    ~Nushabe();
    int percentage;
private:
    Ui::Nushabe *ui;
private slots:
    void increase_light();
    void deccrease_light();
};

#endif // NUSHABE_H
