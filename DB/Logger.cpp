#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

#include "Logger.h"

using namespace std;

Logger* Logger::logger = NULL;
Logger* Logger::getLogger() {
	if (logger == NULL) {
		logger = new Logger;
	}
	return logger;
}

void  Logger::releaseLogger() {
	delete logger;
	logger = NULL;
}

string Logger::Get_Current_Date() {
	time_t nowtime;
	nowtime = time(NULL); //获取日历时间   
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&nowtime));
	return tmp;
}

void Logger::logToFile(string str) {
	FILE* f1=fopen("test.txt","a+");
	fprintf(f1,"%s %s",Get_Current_Date().c_str(),str.c_str());
	fprintf(f1,"\n");
	fclose(f1);
	
	/*
	// 将当前日期以 20** - ** - ** 格式输出
	cout << Get_Current_Date().c_str() << endl;
	*/
}


