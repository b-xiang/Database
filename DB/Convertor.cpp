#include "Convertor.h"
#include <sstream>
#include <string>
using namespace std;

char Conv64::m_charSet[128] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int Conv64::m_nDigital = strlen(m_charSet);


int Conv64::sti(const string & strValue)
{
#ifdef WIN32
	return _atoi64(strValue.c_str());
#else
	return atoll(strValue.c_str());
#endif

}

string Conv64::its(int nValue)
{
	stringstream ss;
	ss << nValue;
	return ss.str();
}

string Conv64::to_64(const string & src10, const int nMinLen)
{
	string dst;
	int src = sti(src10);
	if (src == 0) {
		char szTmp[2];
		szTmp[0] = m_charSet[0];
		szTmp[1] = 0;
		dst.append(szTmp);
	}
	while (src != 0) {
		int nMod = src % m_nDigital;
		char szTmp[2];
		szTmp[0] = m_charSet[nMod];
		szTmp[1] = 0;
		dst.append(szTmp);

		src = src / m_nDigital;
	}

	reverse(dst.begin(), dst.end());
	string str = convMinLen(dst, nMinLen);
	return str;
}

string Conv64::to_64(int src10, int nMinLen)
{
	return to_64(its(src10), nMinLen);
}

string Conv64::to_10(const string & srcx, int nMinLen)
{
	int dst = 0L;
	for (int i = 0; i < srcx.length(); i++)
	{
		char c = srcx[i];
		for (int j = 0; j < strlen(m_charSet); j++)
		{
			if (c == m_charSet[j])
			{
				dst = (dst * m_nDigital) + j;
				break;
			}
		}
	}

	string str = convMinLen(its(dst), nMinLen);
	return str;
}

string Conv64::convMinLen(const string & src, int nMinLen)
{
	int nAddLen = nMinLen - src.length();
	stringstream strTmp;
	for (int i = 0; i < nAddLen; i++)
	{
		strTmp << "A";
	}
	strTmp << src;
	return strTmp.str();
}

void Conv64::init(const char * charSet)
{
	strcpy(m_charSet, charSet);
	m_nDigital = strlen(m_charSet);
}