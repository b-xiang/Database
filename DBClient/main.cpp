// �ͻ���.cpp 
#include"mysocket.h"
#include "global.h" // ȫ�����ã��������ip �˿ں�
using namespace std;
#pragma comment(lib, "ws2_32.lib")

char Global::ip[] = "127.0.0.1";


int main()
{
	MySocket* m = new MySocket;
	m->run();
	// exit �˳�
	m->release();
	delete m;
	return 0;
}


