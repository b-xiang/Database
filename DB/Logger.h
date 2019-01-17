#pragma once
#include <string>
using namespace std;

class Logger{
public:
	static Logger * getLogger();
	static void  releaseLogger();
private:
	Logger() {}
	Logger(const Logger&);
	Logger& operator=(const Logger&); 
	string Get_Current_Date();
public:
	~Logger(){}
public:
	void logToFile(string str);
private:
	static Logger* logger;
}; 

