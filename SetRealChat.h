#pragma once
#ifndef SETREALCHART
#define SETREALCHART

#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCore/QTimer>
#include <QList>
#include <QtCharts/QChartGlobal>
#include <QChartView>
QT_CHARTS_USE_NAMESPACE

class SetRealChat : public QChart
{
public:
	SetRealChat();
	~SetRealChat();
public slots:
	void changeValue(int Set, int Real);
private:
	QList<int>  dataSet,dataReal;
	QSplineSeries *LinesSet;
	QSplineSeries *LinesReal;
	int count = 0;
	int y_max = 1000;
	int y_min = -1000;
	const int max_count = 100;
};

#endif // !SETREALCHART
