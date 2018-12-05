#include "Timer.h"
#include <iostream>
using namespace std;

map<string, pair<clock_t, clock_t>> Timer::reg;
void Timer::start(string mission)
{
	clock_t s = clock();
	reg[mission] = make_pair(s,s);
}

void Timer::end(string mission)
{
	reg[mission].second = clock();
}

void Timer::outputInterval(string mission)
{
	cout << reg[mission].second - reg[mission].first<<" ms";
}

clock_t Timer::getInterval(string mission)
{
	return reg[mission].second - reg[mission].first;
}

string Timer::getCurTime()
{
	time_t nowtime;
	nowtime = time(NULL); //获取日历时间   
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&nowtime));
	return tmp;
}
