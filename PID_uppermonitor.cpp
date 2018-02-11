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
	changePIDvalue_O();
	QString str = "@",temp = "";
	str += DeviceNumber_String;
	str += "O";//外环
	str += ",";//时间
	temp = QString("%1").arg(1000 + ui.spinBox_outlooptime->value() );
	str += temp.right(3);
	str += ",";//P
	temp = QString("%1").arg(QString::number((100 + ui.doubleSpinBox_outloopP->value() +0.001), 'f', 2));
	str += temp.right(5);
	str += ",";//I
	temp = QString("%1").arg(QString::number((100 + ui.doubleSpinBox_outloopI->value() + 0.001), 'f', 2));
	str += temp.right(5);
	str += ",";//D
	temp = QString("%1").arg(QString::number((100 + ui.doubleSpinBox_outloopD->value() + 0.001), 'f', 2));
	str += temp.right(5);
	str += ";";
	str += '\n';
	my_serialPort->write(str.toLocal8Bit());
}
void PID_uppermonitor::on_pushButton_inloopWrite_clicked()
{
	changePIDvalue_I();
	QString str = "@", temp = "";
	str += DeviceNumber_String;
	str += "I";//外环
	str += ",";//时间
	temp = QString("%1").arg(1000 + ui.spinBox_outlooptime->value());
	str += temp.right(3);
	str += ",";//P
	temp = QString("%1").arg(QString::number((100 + ui.doubleSpinBox_outloopP->value() + 0.001), 'f', 2));
	str += temp.right(5);
	str += ",";//I
	temp = QString("%1").arg(QString::number((100 + ui.doubleSpinBox_outloopI->value() + 0.001), 'f', 2));
	str += temp.right(5);
	str += ",";//D
	temp = QString("%1").arg(QString::number((100 + ui.doubleSpinBox_outloopD->value() + 0.001), 'f', 2));
	str += temp.right(5);
	str += ";";
	str += '\n';
	my_serialPort->write(str.toLocal8Bit());
}


void PID_uppermonitor::onRadioClickDevice()
{
	changePIDvalue_I();
	changePIDvalue_O();
	DeviceNumber_Int = btnGroupDevice->checkedId();
	DeviceNumber_String = QString("#%1").arg(DeviceNumber_Int);
	changePIDvalue_O_Inv();
	changePIDvalue_I_Inv();
}
void PID_uppermonitor::changePIDvalue_O()
{
	Date[DeviceNumber_Int].Otime = ui.spinBox_outlooptime->value();
	Date[DeviceNumber_Int].outP = ui.doubleSpinBox_outloopP->value();
	Date[DeviceNumber_Int].outI = ui.doubleSpinBox_outloopI->value();
	Date[DeviceNumber_Int].outD = ui.doubleSpinBox_outloopD->value();
}
void PID_uppermonitor::changePIDvalue_I()
{
	Date[DeviceNumber_Int].Itime = ui.spinBox_inlooptime->value();
	Date[DeviceNumber_Int].inP = ui.doubleSpinBox_inloopP->value();
	Date[DeviceNumber_Int].inI = ui.doubleSpinBox_inloopI->value();
	Date[DeviceNumber_Int].inD = ui.doubleSpinBox_inloopD->value();
}
void PID_uppermonitor::changePIDvalue_O_Inv()
{
	ui.spinBox_outlooptime->setValue(Date[DeviceNumber_Int].Otime);
	ui.doubleSpinBox_outloopP->setValue(Date[DeviceNumber_Int].outP);
	ui.doubleSpinBox_outloopI->setValue(Date[DeviceNumber_Int].outI);
	ui.doubleSpinBox_outloopD->setValue(Date[DeviceNumber_Int].outD);
}
void PID_uppermonitor::changePIDvalue_I_Inv()
{
	ui.spinBox_inlooptime->setValue(Date[DeviceNumber_Int].Itime);
	ui.doubleSpinBox_inloopP->setValue(Date[DeviceNumber_Int].inP);
	ui.doubleSpinBox_inloopI->setValue(Date[DeviceNumber_Int].inI);
	ui.doubleSpinBox_inloopD->setValue(Date[DeviceNumber_Int].inD);
}