#pragma once
// ������һЩglobal������
#include <string>
using namespace std;

class Global
{
public:
	// ȫ������
	static char ip[];  // ������IP��ַ
	static const int port = 5055;
	static const int recv_buf_size = 1000;
};

//char Global::ip = "10.151.135.59";
//int Global::port = 5055;
//const int Global::recv_buf_size = 1000;