#pragma once
#include <iostream>
//#include <windows.h>
#include <Winsock2.h>	// �����Ŀ�
#include<WS2tcpip.h>
// #include <thread>
#include <mutex>
#include <string>
#include <map>
#include <process.h>
#include "global.h"
#pragma comment(lib,"ws2_32.lib")

using namespace std;

class ServerSocket // ������׽���
{
private:


	SOCKET Listen_Sock;
	// SOCKET sockConn;
	static int thread_num; // �̺߳�
	static DWORD WINAPI createThread(const LPVOID arg);
	static void getAndUse();
	static string recv_buf;// �յ������Կͻ��˵�SQL
	static string send_buf;// ���͵��ͻ���������ʾ������
	static void put_in_buf(const char str[]);
	static void put_in_buf(string& str); // ��str������׷�ӵ�send_buf��
public:
	ServerSocket();
	void run();
	void release();
};