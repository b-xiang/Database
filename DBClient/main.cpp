// �ͻ���.cpp 
#include"mysocket.h"
#include "global.h" // ȫ�����ã��������ip �˿ں�
using namespace std;
#pragma comment(lib, "ws2_32.lib")

char Global::ip[] = "127.0.0.1";


int main()
{
	//select id,name, height from player where money>100 and gender='male';
	//SELECT id,name,money from table1,table2 where table1.height>160;
	MySocket* m = new MySocket;
	m->run();
	// exit �˳�
	m->release();
	delete m;
	return 0;
}


