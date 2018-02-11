#pragma once

#include <QtWidgets/QWidget>
#include "ui_PID_uppermonitor.h"

class PID_uppermonitor : public QWidget
{
	Q_OBJECT

public:
	PID_uppermonitor(QWidget *parent = Q_NULLPTR);

private:
	Ui::PID_uppermonitorClass ui;
};
