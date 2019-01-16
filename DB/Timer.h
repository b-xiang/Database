#ifndef TIMER_H
#define TIMER_H
#include <map>
#include <string>
#include <time.h>
using namespace std;

class Timer
{
private:
	static map<string, pair<clock_t, clock_t>> reg;
public:
	static void start(string mission = "default");	//开始mission的定时器
	static void end(string mission = "default");	//结束mission的定时器
	static string outputInterval(string mission = "default");	//输出经过的时间
	static clock_t getInterval(string mission = "default");	//获取经过的时间
	static string getCurTime();	//获取当前时间的字符串
};

#endif // !TIMER_H