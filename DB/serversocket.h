#pragma once
#include <iostream>
//#include <windows.h>
#include <Winsock2.h>	// 依赖的库
#include<WS2tcpip.h>
// #include <thread>
#include <mutex>
#include <string>
#include <map>
#include <process.h>
#include "global.h"
#pragma comment(lib,"ws2_32.lib")

using namespace std;

class ServerSocket // 服务端套接字
{
private:


	SOCKET Listen_Sock;
	// SOCKET sockConn;
	static int thread_num; // 线程号
	static DWORD WINAPI createThread(const LPVOID arg);
	static void getAndUse();
	static string recv_buf;// 收到的来自客户端的SQL
	static string send_buf;// 发送到客户端让其显示的内容
	static void put_in_buf(const char str[]);
	static void put_in_buf(string& str); // 将str的内容追加到send_buf中
public:
	ServerSocket();
	void run();
	void release();
};