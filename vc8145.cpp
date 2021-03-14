#include "vc8145.h"
#include <QSerialPort>
#include <QIODevice>

VC8145::VC8145(QObject *parent) : QSerialPort(parent)
{

}

bool VC8145::connect(QString comport){
    setPortName(comport);
    setBaudRate(VC8145_DEFAULT_BAUD_RATE);
    if(!this->isOpen()){
        this->open(QIODevice::ReadWrite);
    }else{
        if(this->openMode() != QIODevice::ReadWrite){
            this->close();
            this->open(QIODevice::ReadWrite);
        }
    }
    return this->isOpen();
}


void VC8145::run(){
    while(!done){
        QThread::msleep(250);
    }
}
