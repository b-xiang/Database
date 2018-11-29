#ifndef CONVERTOR_H
#define CONVERTOR_H
#include <string>
using namespace std;

//10进制和x进制的换算
class Conv64
{
private:
	Conv64() {}
	virtual ~Conv64() {}

public:
	static int sti(const string& strValue);
	static string its(int nValue);
	static string to_64(const string& src10, const int nMinLen = 0);
	//10进制转化成的x进制长度，不足nMinLen长度的话高位补0
	static string to_64(const int src10, int nMinLen = 0);
	//x进制转为10进制
	static string to_10(const string& srcx, int nMinLen = 0);
protected:
	static string convMinLen(const string& src, int nMinLen);
	//初始化，设置字符集
	void init(const char * charSet);
private:
	static char m_charSet[128];
	static int m_nDigital;
};

#endif // !CONVERTOR_H

