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
	changePIDvalue_O();
	QString str = "@",temp = "";
	str += DeviceNumber_String;
	str += "O";//�⻷
	str += ",";//ʱ��
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
	str += "I";//�⻷
	str += ",";//ʱ��
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