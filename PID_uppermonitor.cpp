#include "PID_uppermonitor.h"

PID_uppermonitor::PID_uppermonitor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	qRegisterMetaType<QVariant>("QVariant");
	//———————————————————获取串口信息函数————————————————————————
	foreach(const QSerialPortInfo &Info, QSerialPortInfo::availablePorts())//读取串口信息
	{
		qDebug() << "portName    :" << Info.portName();//调试时可以看的串口信息
		qDebug() << "Description :" << Info.description();//设备信息

		QSerialPort serial;//声明串口
		serial.setPort(Info);

	//	if (serial.open(QIODevice::ReadWrite))//如果串口是可以读写方式打开的
		{
			ui.comboBox_portName->addItem(Info.portName());//在comboBox那添加串口号
			serial.setDataTerminalReady(true);
			serial.close();//然后自动关闭等待人为开启（通过那个打开串口的PushButton）
		}
	}
	//————————————————————————————————————————————————————————
	Serialobj = new SerialPort2pid; //创建一个自己写的串口对象
	RSPthread = new ReadSerialPortThread;
    SRCthread = new QThread;
	Chat_I = new SetRealChat;
	Chat_O = new SetRealChat;
    QChartView *chartViewI = new QChartView(Chat_I);
    chartViewI->setRenderHint(QPainter::Antialiasing);
    QChartView *chartViewO = new QChartView(Chat_O);
    chartViewO->setRenderHint(QPainter::Antialiasing);
    ui.horizontalLayout_Charts->addWidget(chartViewO);
    ui.horizontalLayout_Charts->addWidget(chartViewI);

//	Serialobj->moveToThread(RSPthread);
//  chartViewI->moveToThread(SRCthread);
//    Chat_I->moveToThread(SRCthread);
//    chartViewO->moveToThread(SRCthread);
//    Chat_O->moveToThread(SRCthread);

    RSPthread->start();
    SRCthread->start();
	PID_uppermonitor::btnGroupDeviceConnect();//单选设备按钮分组
	//连接ui打开按钮和串口功能打开
	connect(this, &PID_uppermonitor::OpenTheSerialPort, Serialobj, &SerialPort2pid::SerialPort_Open);
	connect(this, &PID_uppermonitor::CloseTheSerialPort, Serialobj, &SerialPort2pid::SerialPort_Close);
	connect(this, &PID_uppermonitor::serialportWrite, Serialobj, &SerialPort2pid::write);
	connect(Serialobj, &SerialPort2pid::bytesWritten, Serialobj, &SerialPort2pid::freshenUIdate_end);
//	connect(this, &PID_uppermonitor::freshenUIdate_begin, Serialobj, &SerialPort2pid::freshenUIdate_end);
	connect(Serialobj, &SerialPort2pid::freshenUIdate_Sender, this, &PID_uppermonitor::freshenUIdate_Reciver);
	//图表更新
	connect(Serialobj, &SerialPort2pid::setSetRealI, Chat_I, &SetRealChat::changeValue);
	connect(Serialobj, &SerialPort2pid::setSetRealO, Chat_O, &SetRealChat::changeValue);
	
}
PID_uppermonitor::~PID_uppermonitor()
{
}


void PID_uppermonitor::on_pushButton_switch_clicked()
{
	if (ui.pushButton_switch->text() == tr(u8"连接设备"))
	{
		emit OpenTheSerialPort(ui.comboBox_portName->currentText(), \
							   ui.comboBox_baudRate->currentText().toInt());
		//串口和波特率不可修改状态
		ui.comboBox_baudRate->setEnabled(false);
		ui.comboBox_portName->setEnabled(false);
		//改变串口开关按钮状态
		ui.pushButton_switch->setText(tr(u8"断开连接"));
	}
	else if(ui.pushButton_switch->text() == tr(u8"断开连接"))
	{
		emit CloseTheSerialPort();
	//	RSPthread->wait();
		//串口和波特率可修改状态
		ui.comboBox_baudRate->setEnabled(true);
		ui.comboBox_portName->setEnabled(true);
		//改变串口开关按钮状态
		ui.pushButton_switch->setText(tr(u8"连接设备"));
	}
}
//外环数据写入函数，写入当前选中设备
void PID_uppermonitor::on_pushButton_outloopWrite_clicked()
{
	changePIDvalue_O();
	if (ui.pushButton_switch->text() == tr(u8"断开连接"))
	{
		QString str = "@", temp = "";
		str += DeviceNumber_String;
		str += "O";//外环
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
		serialportWrite(str.toLocal8Bit());
	}
	else
	{
		showInfomation(tr(u8"无法写入"));
	}
}
//内环数据写入函数，写入当前选中设备
void PID_uppermonitor::on_pushButton_inloopWrite_clicked()
{
	changePIDvalue_I();
	if (ui.pushButton_switch->text() == tr(u8"断开连接") )
	{
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
		serialportWrite(str.toLocal8Bit());
	}
	else
	{
		showInfomation(tr(u8"无法写入"));
	}
}
//刷新数据按钮，使上位机所显示参数与下位机相同
void PID_uppermonitor::on_pushButton_freshen_clicked()
{
	if (ui.pushButton_switch->text() == tr(u8"断开连接"))
	{
		QString str = "@#?";
		qDebug() << str;
		serialportWrite(str.toLocal8Bit());
//		emit freshenUIdate_begin();
	}
	else
	{
		showInfomation(tr(u8"无法获取信息"));
	}
}
//刷新UI的槽函数实现
void PID_uppermonitor::freshenUIdate_Reciver(int num, QVariant dataVar)
{
	Date[num] = dataVar.value<MyStruct>();
	if (num == DeviceNumber_Int)
	{
		changePIDvalue_O_Inv();
		changePIDvalue_I_Inv();
	}
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

void PID_uppermonitor::showInfomation(QString str)
{
	QMessageBox::information(this, str, tr(u8"请连接设备"));
	return;
//	Information(this, tr(u8"请连接设备并打开串口"， tr(u8""));
}
void PID_uppermonitor::btnGroupDeviceConnect()
{
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
