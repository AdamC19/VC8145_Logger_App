#include "vc8145.h"
#include <QSerialPort>

VC8145::VC8145(QObject *parent) : QObject(parent), serial(parent)
{

}

bool VC8145::connect(QString comport){
    serial.setPortName(comport);
    serial.setBaudRate(VC8145_DEFAULT_BAUD_RATE);
    return true;
}
