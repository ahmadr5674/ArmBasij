#include "nushabe.h"
#include "ui_nushabe.h"

Nushabe::Nushabe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nushabe)
{
    ui->setupUi(this);
    QVBoxLayout* layout = new QVBoxLayout();
    QWidget* centralWidget= new QWidget();
    dial = new QDial();
    progressbar = new QProgressBar();
    status = new QLabel("boom");
    layout->addWidget(dial);
    layout->addWidget(progressbar);
    layout->addWidget(status);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);
    resize(200, 300);
    QBluetoothLocalDevice localDevice;
    QString localDeviceName;
    //QList<QBluetoothHostInfo> host;
    //QList<QBluetoothDeviceInfo> found_devices;
    if (localDevice.isValid()) {

        // Turn Bluetooth on
        localDevice.powerOn();
        status->setText("blue is on");
        // Read local device name
        localDeviceName = localDevice.name();
        // Make it visible to others
        localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);
    }
    startDeviceDiscovery();
    rfcommServer = new QBluetoothServer(QBluetoothServiceInfo::RfcommProtocol, this);
    connect(rfcommServer, SIGNAL(newConnection()), this, SLOT(clientConnected()));
    bool result = rfcommServer->listen(localDevice.address());
    if (!result)
    {
        qWarning() << "Cannot bind chat server to" << localDevice.name();
        return;
    }
}

Nushabe::~Nushabe()
{
    delete ui;
}

void Nushabe::valueChangedSlot(int value){
     progressbar->setValue(value);
}

void Nushabe::startDeviceDiscovery()
{

    // Create a discovery agent and connect to its signals
    QBluetoothDeviceDiscoveryAgent *discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
    discoveryAgent->start();
}


void Nushabe::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';
}

