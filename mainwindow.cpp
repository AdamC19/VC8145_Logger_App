#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    meter = new VC8145(this);
    ui->statusbar->showMessage("Starting application...");

    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    for(QSerialPortInfo info : ports){
        ui->comportComboBox->addItem(info.portName());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comportComboBox_activated(const QString &arg1)
{

}

void MainWindow::on_comportComboBox_highlighted(const QString &arg1)
{
    // refresh device list
    ui->statusbar->showMessage("Refreshing Devices list...");
}

void MainWindow::on_comportComboBox_currentTextChanged(const QString &arg1)
{

}

void MainWindow::on_connectButton_clicked()
{
    QString device = ui->comportComboBox->currentText();
    ui->statusbar->showMessage("Connecting meter at " + device);
    meter->connect(device);
}
