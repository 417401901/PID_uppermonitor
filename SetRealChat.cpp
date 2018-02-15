#include "SetRealChat.h"
#include "qdebug.h"


SetRealChat::SetRealChat()
{
	LinesReal = new QSplineSeries;
	LinesSet = new QSplineSeries;
	this->legend()->hide();  // ����ͼ��
	this->addSeries(LinesSet);  // ���趨ֵ�������ͼ����
	this->addSeries(LinesReal);  // ��ʵ��ֵ�������ͼ����
	this->createDefaultAxes();  // ��������ӵ�ͼ��� series ��������
	this->axisY()->setRange(y_min, y_max);
    this->axisX()->setRange(0, max_count);
}


SetRealChat::~SetRealChat()
{
}

void SetRealChat::changeValue(int Set, int Real)
{
    qDebug()<<"Set:"<<Set<<"Real:"<<Real;
    count ++;
	if (count > max_count)
	{
		dataSet.pop_front();
		dataSet << Set;
		LinesSet->clear();

		dataReal.pop_front();
		dataReal << Real;
		LinesReal->clear();

		for (int i = 0; i < max_count; i++)
		{
			LinesSet->append(i, dataSet.at(i));
			LinesReal->append(i, dataReal.at(i));
		}
	}
	else
	{
		dataSet << Set;
		dataReal << Real;
		LinesSet->clear();
		LinesReal->clear();
		for (int i = 0; i<count; i++)
		{
			LinesSet->append(max_count - i, dataSet.at(count - i - 1));
			LinesReal->append(max_count - i, dataReal.at(count - i - 1));
		}
	}
}
