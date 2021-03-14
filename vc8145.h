#ifndef VC8145_H
#define VC8145_H

#include <QObject>
#include <QSerialPort>

#define VC8145_DEFAULT_BAUD_RATE QSerialPort::Baud9600

class MultimeterData : public QObject
{
    Q_OBJECT
public:
    double value = 0.0;
    QString units = "";
    MultimeterData(double value, QString units);
};

class VC8145 : public QSerialPort
{
    Q_OBJECT
private:
    bool done = false;
public:
    explicit VC8145(QObject *parent = nullptr);
    bool connect(QString comport);
    void run();
signals:
    void meterData(MultimeterData &data);
};

#endif // VC8145_H
