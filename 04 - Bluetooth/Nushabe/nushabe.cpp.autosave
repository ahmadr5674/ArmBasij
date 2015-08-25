#include "nushabe.h"
#include "ui_nushabe.h"

Nushabe::Nushabe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nushabe)
{
    ui->setupUi(this);
    QVBoxLayout* layout 	= new QVBoxLayout();
    QWidget* centralWidget 	= new QWidget();

    dial 			= new QDial();
    progressbar = new QProgressBar();


    layout->addWidget(dial);
    layout->addWidget(progressbar);

    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);
    resize(200, 300);



    connect(dial,SIGNAL(sliderMoved(int)),this,SLOT(valueChangedSlot(int)));

}

Nushabe::~Nushabe()
{
    delete ui;
}

void Nushabe::valueChangedSlot(int value){
     progressbar->setValue(value);
}
