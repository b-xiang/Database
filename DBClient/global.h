#pragma once
// 这里存放一些global的内容
#include <string>
using namespace std;

class Global
{
public:
	// 全局设置
	static char ip[];  // 服务器IP地址
	static const int port = 5055;
	static const int recv_buf_size = 1000;
};

//char Global::ip = "10.151.135.59";
//int Global::port = 5055;
//const int Global::recv_buf_size = 1000;