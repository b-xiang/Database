#pragma once
// ��������socket
#include<WINSOCK2.H>  
#include<STDIO.H>  
#include<iostream>  
#include<cstring>  
#include <string>
#include<WS2tcpip.h>


class MySocket
{
public:
	MySocket(); // ��ʼ��
	void run();
	void release();
private:
	SOCKET sclient;
};