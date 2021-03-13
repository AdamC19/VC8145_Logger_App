#ifndef VC8145_H
#define VC8145_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

#define VC8145_DEFAULT_BAUD_RATE QSerialPort::Baud9600

class VC8145 : public QObject
{
    Q_OBJECT
private:
    QSerialPort serial;
public:
    explicit VC8145(QObject *parent = nullptr);
    bool connect(QString comport);
signals:

};

#endif // VC8145_H
