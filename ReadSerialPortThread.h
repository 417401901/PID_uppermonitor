#pragma once
#ifndef _READ_THREAD_
#define _READ_THREAD_
#include<qthread.h>
#include<qdebug.h>

class ReadSerialPortThread : public QThread
{
	Q_OBJECT

public:
	ReadSerialPortThread(QObject *parent = Q_NULLPTR);
	~ReadSerialPortThread();
private:

//	void run();
//signals:
//	void sendDate(int num, MyStruct);
};

#endif // !_READ_THREAD_
