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
	static void start(string mission = "default");	//��ʼmission�Ķ�ʱ��
	static void end(string mission = "default");	//����mission�Ķ�ʱ��
	static string outputInterval(string mission = "default");	//���������ʱ��
	static clock_t getInterval(string mission = "default");	//��ȡ������ʱ��
	static string getCurTime();	//��ȡ��ǰʱ����ַ���
};

#endif // !TIMER_H