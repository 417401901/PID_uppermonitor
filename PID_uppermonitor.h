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
	int DeviceNumber = 0;
private slots:
	void on_pushButton_switch_clicked();
	void on_pushButton_outloopWrite_clicked();
	void onRadioClickDevice();
};
