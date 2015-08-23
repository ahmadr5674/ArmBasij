#ifndef NUSHABE_H
#define NUSHABE_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QDial>
#include <QtGui>
#include"QVBoxLayout"

namespace Ui {
class Nushabe;
}

class Nushabe : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nushabe(QWidget *parent = 0);
    QDial* dial;
    QProgressBar* progressbar;
    ~Nushabe();
public:
    Ui::Nushabe *ui;
public slots:
    void valueChangedSlot(int value);

};

#endif // NUSHABE_H
