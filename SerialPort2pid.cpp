#include "SerialPort2pid.h"
#include "qt_windows.h"


SerialPort2pid::SerialPort2pid()
{
	qRegisterMetaType<QVariant>("QVariant");
}


SerialPort2pid::~SerialPort2pid()
{
}
//打开串口
void SerialPort2pid::SerialPort_Open(QString name, int baudrate)
{
	my_serialPort = new QSerialPort;
	my_serialPort->setPortName(name);//设置串口名
	my_serialPort->open(QIODevice::ReadWrite);//打开串口
	my_serialPort->setBaudRate(baudrate);//设置波特率
	my_serialPort->setDataBits(QSerialPort::Data8);//设置数据位数
	my_serialPort->setParity(QSerialPort::NoParity);//设置奇偶校验
	my_serialPort->setStopBits(QSerialPort::OneStop);//设置停止位
	my_serialPort->setFlowControl(QSerialPort::NoFlowControl);//设置流控制
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(freshenUIdate_end()));
	timer->start(10);

	qDebug() << name << tr(u8"打开成功");
}
//关闭串口
void SerialPort2pid::SerialPort_Close()
{
	delete timer;
	my_serialPort->clear();//清理串口
	my_serialPort->close();//关闭串口
	my_serialPort->deleteLater();
	qDebug() << tr(u8"串口已经关闭");
}
//串口发送字符串
void SerialPort2pid::write(const QByteArray &date)
{
	my_serialPort->write(date);
	qDebug() << u8"发送数据：   " << date;
}
//下位机->串口读取->UI
void SerialPort2pid::freshenUIdate_end()
{
	MyStruct askData;
	QByteArray buf;
	QString temp;
    int num;
	buf = my_serialPort->readAll();
	//为了实现槽函数传递结构体作为参数
	QVariant DataVar;

	if (!buf.isEmpty())
	{
        qDebug() <<"ReciveData:   "<< buf;
		if(buf.at(0) == '@')
		{
			buf.remove(0, 1);
			qDebug() << buf;
			while (buf.at(0) != ';')
			{
				memset(&askData, 0, sizeof(MyStruct));
				buf.remove(0, 1);
				num = buf.left(1).toInt();
				buf.remove(0, 2);
				askData.Itime = buf.left(3).toInt();
				buf.remove(0, 4);
				askData.inP = buf.left(5).toDouble();
				buf.remove(0, 6);
				askData.inI = buf.left(5).toDouble();
				buf.remove(0, 6);
				askData.inD = buf.left(5).toDouble();
				buf.remove(0, 5);
				qDebug() << buf;
				if (buf.at(0) == '#' || buf.at(0) == ';')
				{
					DataVar.setValue(askData);
					emit freshenUIdate_Sender(num, DataVar);
					continue;
				}
				else
				{
					buf.remove(0, 1);
					askData.Otime = buf.left(3).toInt();
					buf.remove(0, 4);
					askData.outP = buf.left(5).toDouble();
					buf.remove(0, 6);
					askData.outI = buf.left(5).toDouble();
					buf.remove(0, 6);
					askData.outD = buf.left(5).toDouble();
					buf.remove(0, 5);
					DataVar.setValue(askData);
					emit freshenUIdate_Sender(num, DataVar);
				}
			}
		}
		else if (buf.at(0) == 'I')
		{
			buf.remove(0, 1);
			while (buf.at(0) != ',')
			{
                temp += buf.at(0);
				buf.remove(0, 1);
			}
			int Set = temp.toInt();
			temp = "";
			buf.remove(0, 1);
			while (buf.at(0) != ';')
			{
				temp += buf.at(0);
				buf.remove(0, 1);
			}
			int Real = temp.toInt();
			temp = "";
			emit setSetRealI(Set, Real);
		}
		else if (buf.at(0) == 'O')
		{
			buf.remove(0, 1);
			while (buf.at(0) != ',')
			{
				temp += buf.at(0);
				buf.remove(0, 1);
			}
			int Set = temp.toInt();
			temp = "";
			buf.remove(0, 1);
			while (buf.at(0) != ';')
			{
				temp += buf.at(0);
				buf.remove(0, 1);
			}
			int Real = temp.toInt();
			temp = "";
			emit setSetRealO(Set, Real);
		}
	}

	
}
