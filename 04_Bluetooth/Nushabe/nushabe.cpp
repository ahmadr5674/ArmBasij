#include "nushabe.h"
#include "ui_nushabe.h"

Nushabe::Nushabe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nushabe)
{
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
    dev_list.push_back(device);
    //qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')' << "UUID: "
    //         << device.deviceUuid();
    if(device.address().toString() == "98:D3:31:60:30:DF"){
        rfcommServer = new QBluetoothServer(QBluetoothServiceInfo::RfcommProtocol, this);
        connect(rfcommServer, SIGNAL(newConnection()), this, SLOT(startClient()));
        bool result = rfcommServer->listen(localDevice.address());
        if(result)
            qDebug() << "connected to " << device.name();
    }
}

void Nushabe::startClient()
{
    //rfcommServer->serverType();
    if (socket)
        return;
    QString uuid("00001101-0000-1000-8000-00805F9B34FB");
    QBluetoothSocket* socket=new QBluetoothSocket();
    socket->connectToService(QBluetoothAddress("98:D3:31:60:30:DF"),QBluetoothUuid(uuid));


    // Connection is ready to be used
    qDebug("Connected");
    connect(socket, SIGNAL(disconnected()), this,SLOT(bt_disconnected()) );
    connect(socket, SIGNAL(connected()), this, SLOT(bt_connected()));
    qDebug() << "Create socket";
    socket->connectToService(dev_list.at(0).address(),dev_list.at(0).deviceUuid());
    qDebug() << "ConnectToService done";

    connect(socket, SIGNAL(readyRead()), this, SLOT(readSocket()));
}


void Nushabe :: bt_connected()
{

}

void Nushabe :: bt_disconnected()
{

}
