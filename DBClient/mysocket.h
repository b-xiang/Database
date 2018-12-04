#pragma once
// 面向对象的socket
#include<WINSOCK2.H>  
#include<STDIO.H>  
#include<iostream>  
#include<cstring>  
#include <string>
#include<WS2tcpip.h>


class MySocket
{
public:
	MySocket(); // 初始化
	void run();
	void release();
private:
	SOCKET sclient;
};