#pragma once

#include<qserialport.h>
#include<qdebug.h>	
#include "qtimer.h"

struct MyStruct
{
	int Otime = 0;
	double outI = 0.00;
	double outP = 0.00;
	double outD = 0.00;
	int Itime = 0;
	double inP = 0.00;
	double inI = 0.00;
	double inD = 0.00;
};
Q_DECLARE_METATYPE(MyStruct)

class SerialPort2pid : public QSerialPort
{
	Q_OBJECT
public:
	SerialPort2pid();
	~SerialPort2pid();
signals:
	void freshenUIdate_Sender(int num, QVariant dataVar);
	void setSetRealI(int Set, int Real);
	void setSetRealO(int Set, int Real);
public slots:
	void SerialPort_Open(QString name, int baudrate);
	void SerialPort_Close();
	void write(const QByteArray &date);
	void freshenUIdate_end();
private:
	QSerialPort * my_serialPort;//(实例化一个指向串口的指针，可以用于访问串口)
	QString serialPort_name;
	QTimer *timer;
};

