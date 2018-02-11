#include "PID_uppermonitor.h"

PID_uppermonitor::PID_uppermonitor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	foreach(const QSerialPortInfo &Info, QSerialPortInfo::availablePorts())//��ȡ������Ϣ
	{
		qDebug() << "portName    :" << Info.portName();//����ʱ���Կ��Ĵ�����Ϣ
		qDebug() << "Description   :" << Info.description();//�豸��Ϣ

		QSerialPort serial;
		serial.setPort(Info);

		if (serial.open(QIODevice::ReadWrite))//��������ǿ��Զ�д��ʽ�򿪵�
		{
			ui.comboBox_portName->addItem(Info.portName());//��comboBox����Ӵ��ں�
			serial.close();//Ȼ���Զ��رյȴ���Ϊ������ͨ���Ǹ��򿪴��ڵ�PushButton��
		}
	}
	ui.pushButton_switch->setText(tr(u8"�����豸"));
	//����ѡbuttonѡ����Բ�ͬ�豸
	btnGroupDevice = new QButtonGroup(this);
	btnGroupDevice->addButton(ui.radioButton_0, 0);
	btnGroupDevice->addButton(ui.radioButton_1, 1);
	btnGroupDevice->addButton(ui.radioButton_2, 2);
	btnGroupDevice->addButton(ui.radioButton_3, 3);
	btnGroupDevice->addButton(ui.radioButton_4, 4);
	btnGroupDevice->addButton(ui.radioButton_5, 5);
	btnGroupDevice->addButton(ui.radioButton_6, 6);
	btnGroupDevice->addButton(ui.radioButton_7, 7);
	connect(ui.radioButton_0, SIGNAL(clicked()), this, SLOT(onRadioClickDevice()));
	connect(ui.radioButton_1, SIGNAL(clicked()), this, SLOT(onRadioClickDevice()));
	connect(ui.radioButton_2, SIGNAL(clicked()), this, SLOT(onRadioClickDevice()));
	connect(ui.radioButton_3, SIGNAL(clicked()), this, SLOT(onRadioClickDevice()));
	connect(ui.radioButton_4, SIGNAL(clicked()), this, SLOT(onRadioClickDevice()));
	connect(ui.radioButton_5, SIGNAL(clicked()), this, SLOT(onRadioClickDevice()));
	connect(ui.radioButton_6, SIGNAL(clicked()), this, SLOT(onRadioClickDevice()));
	connect(ui.radioButton_7, SIGNAL(clicked()), this, SLOT(onRadioClickDevice()));
	ui.radioButton_0->setChecked(true);
}
PID_uppermonitor::~PID_uppermonitor()
{
}


void PID_uppermonitor::on_pushButton_switch_clicked()
{
	if (ui.pushButton_switch->text() == tr(u8"�����豸"))
	{
		my_serialPort = new QSerialPort;
		my_serialPort->setPortName(ui.comboBox_portName->currentText());//���ô�����
		my_serialPort->open(QIODevice::ReadWrite);//�򿪴���
		my_serialPort->setBaudRate(ui.comboBox_baudRate->currentText().toInt());//s���ò�����
		my_serialPort->setDataBits(QSerialPort::Data8);//��������λ��
		my_serialPort->setParity(QSerialPort::NoParity);//������żУ��
		my_serialPort->setStopBits(QSerialPort::OneStop);//����ֹͣλ
		my_serialPort->setFlowControl(QSerialPort::NoFlowControl);//����������

		ui.comboBox_baudRate->setEnabled(false);
		ui.comboBox_portName->setEnabled(false);

		ui.pushButton_switch->setText(tr(u8"�Ͽ�����"));
	}
	else if(ui.pushButton_switch->text() == tr(u8"�Ͽ�����"))
	{
		my_serialPort->clear();
		my_serialPort->close();
		my_serialPort->deleteLater();
		ui.comboBox_baudRate->setEnabled(true);
		ui.comboBox_portName->setEnabled(true);
		ui.pushButton_switch->setText(tr(u8"�����豸"));
	}
}

void PID_uppermonitor::on_pushButton_outloopWrite_clicked()
{
	QString str = "@#";
	str += QString("%1").arg(DeviceNumber);
	my_serialPort->write(str.toLocal8Bit());
}


void PID_uppermonitor::onRadioClickDevice()
{
	DeviceNumber = btnGroupDevice->checkedId();
}