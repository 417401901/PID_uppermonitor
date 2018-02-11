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
	QSerialPort *my_serialPort;//(实例化一个指向串口的指针，可以用于访问串口)
	QByteArray requestData;//（用于存储从串口那读取的数据）
	QButtonGroup *btnGroupDevice;//设备单选按钮组
	int DeviceNumber = 0;
private slots:
	void on_pushButton_switch_clicked();
	void on_pushButton_outloopWrite_clicked();
	void onRadioClickDevice();
};
