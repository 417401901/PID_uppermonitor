#include "PID_uppermonitor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PID_uppermonitor w;
	w.setWindowIcon(QIcon(":/new/prefix1/logo"));
	w.show();
	return a.exec();
}
