#include "PID_uppermonitor.h"

PID_uppermonitor::PID_uppermonitor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	foreach(const QSerialPortInfo &Info, QSerialPortInfo::availablePorts())//读取串口信息
	{
		qDebug() << "portName    :" << Info.portName();//调试时可以看的串口信息
		qDebug() << "Description   :" << Info.description();//设备信息

		QSerialPort serial;
		serial.setPort(Info);

		if (serial.open(QIODevice::ReadWrite))//如果串口是可以读写方式打开的
		{
			ui.comboBox_portName->addItem(Info.portName());//在comboBox那添加串口号
			serial.close();//然后自动关闭等待人为开启（通过那个打开串口的PushButton）
		}
	}
	ui.pushButton_switch->setText(tr(u8"连接设备"));
	//处理单选button选择调试不同设备
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
	if (ui.pushButton_switch->text() == tr(u8"连接设备"))
	{
		my_serialPort = new QSerialPort;
		my_serialPort->setPortName(ui.comboBox_portName->currentText());//设置串口名
		my_serialPort->open(QIODevice::ReadWrite);//打开串口
		my_serialPort->setBaudRate(ui.comboBox_baudRate->currentText().toInt());//s设置波特率
		my_serialPort->setDataBits(QSerialPort::Data8);//设置数据位数
		my_serialPort->setParity(QSerialPort::NoParity);//设置奇偶校验
		my_serialPort->setStopBits(QSerialPort::OneStop);//设置停止位
		my_serialPort->setFlowControl(QSerialPort::NoFlowControl);//设置流控制

		ui.comboBox_baudRate->setEnabled(false);
		ui.comboBox_portName->setEnabled(false);

		ui.pushButton_switch->setText(tr(u8"断开连接"));
	}
	else if(ui.pushButton_switch->text() == tr(u8"断开连接"))
	{
		my_serialPort->clear();
		my_serialPort->close();
		my_serialPort->deleteLater();
		ui.comboBox_baudRate->setEnabled(true);
		ui.comboBox_portName->setEnabled(true);
		ui.pushButton_switch->setText(tr(u8"连接设备"));
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