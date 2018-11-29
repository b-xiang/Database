#ifndef CONVERTOR_H
#define CONVERTOR_H
#include <string>
using namespace std;

//10���ƺ�x���ƵĻ���
class Conv64
{
private:
	Conv64() {}
	virtual ~Conv64() {}

public:
	static int sti(const string& strValue);
	static string its(int nValue);
	static string to_64(const string& src10, const int nMinLen = 0);
	//10����ת���ɵ�x���Ƴ��ȣ�����nMinLen���ȵĻ���λ��0
	static string to_64(const int src10, int nMinLen = 0);
	//x����תΪ10����
	static string to_10(const string& srcx, int nMinLen = 0);
protected:
	static string convMinLen(const string& src, int nMinLen);
	//��ʼ���������ַ���
	void init(const char * charSet);
private:
	static char m_charSet[128];
	static int m_nDigital;
};

#endif // !CONVERTOR_H

