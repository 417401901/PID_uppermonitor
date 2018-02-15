#pragma once

#include <QtWidgets/QWidget>
#include <qmessagebox.h>
#include "ui_PID_uppermonitor.h"
#include "qserialport.h"
#include "qserialportinfo.h"
#include "qdebug.h"
#include "ReadSerialPortThread.h"
#include "SerialPort2pid.h"
#include "SetRealChat.h"


class PID_uppermonitor : public QWidget
{
	Q_OBJECT
public:
	PID_uppermonitor(QWidget *parent = Q_NULLPTR);
	~PID_uppermonitor();

signals:
	void OpenTheSerialPort(QString name, int baudrate);
	void CloseTheSerialPort();
	void serialportWrite(const QByteArray &date);
	void freshenUIdate_begin();
private:
	Ui::PID_uppermonitorClass ui;
	QSerialPort * my_serialPort;//(ʵ����һ��ָ�򴮿ڵ�ָ�룬�������ڷ��ʴ���)
	QByteArray requestData;//�����ڴ洢�Ӵ����Ƕ�ȡ�����ݣ�
	QButtonGroup *btnGroupDevice;//�豸��ѡ��ť��
	QString DeviceNumber_String = "#0";
	ReadSerialPortThread *RSPthread;
    QThread *SRCthread;
	SerialPort2pid *Serialobj;
	SetRealChat *Chat_I;
	SetRealChat *Chat_O;
	int DeviceNumber_Int = 0;
	MyStruct Date[8];
	void changePIDvalue_O();
	void changePIDvalue_I();
	void changePIDvalue_O_Inv();
	void changePIDvalue_I_Inv();
	void showInfomation(QString str);
	void btnGroupDeviceConnect();

private slots:
	void on_pushButton_switch_clicked();
	void on_pushButton_outloopWrite_clicked();
	void onRadioClickDevice();
	void on_pushButton_inloopWrite_clicked();
	void on_pushButton_freshen_clicked();
	void freshenUIdate_Reciver(int num, QVariant dataVar);
//	void PID_uppermonitor::changePIDvalue(int num, MyStruct);
};
