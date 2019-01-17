// 客户端.cpp 
#include"mysocket.h"
#include "global.h" // 全局配置：如服务器ip 端口号
using namespace std;
#pragma comment(lib, "ws2_32.lib")

char Global::ip[] = "127.0.0.1";


int main()
{
	MySocket* m = new MySocket;
	m->run();
	// exit 退出
	m->release();
	delete m;
	return 0;
}


