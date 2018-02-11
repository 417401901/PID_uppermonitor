#pragma once

#include <QtWidgets/QWidget>
#include "ui_PID_uppermonitor.h"
#include "qserialport.h"
#include "qserialportinfo.h"
#include "qdebug.h"

class PID_uppermonitor : public QWidget
{
	Q_OBJECT

public:
	PID_uppermonitor(QWidget *parent = Q_NULLPTR);
	~PID_uppermonitor();
private:
	Ui::PID_uppermonitorClass ui;
	QSerialPort *my_serialPort;//(ʵ����һ��ָ�򴮿ڵ�ָ�룬�������ڷ��ʴ���)
	QByteArray requestData;//�����ڴ洢�Ӵ����Ƕ�ȡ�����ݣ�
	QButtonGroup *btnGroupDevice;//�豸��ѡ��ť��
	QString DeviceNumber_String = "#0";
	int DeviceNumber_Int = 0;
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
	}Date[8];
	void changePIDvalue_O();
	void changePIDvalue_I();
	void changePIDvalue_O_Inv();
	void changePIDvalue_I_Inv();
private slots:
	void on_pushButton_switch_clicked();
	void on_pushButton_outloopWrite_clicked();
	void onRadioClickDevice();
	void on_pushButton_inloopWrite_clicked();
};
