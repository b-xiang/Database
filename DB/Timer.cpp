#include "Timer.h"
#include <iostream>
#include <sstream>
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

string Timer::outputInterval(string mission)
{
	stringstream ss;
	ss <<"done. consumes " <<(reg[mission].second - reg[mission].first) << " ms" <<endl<< endl;
	return ss.str();
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
