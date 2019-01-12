#include "serversocket.h"
#include "SQLParser.h"
#include "SQLParserResult.h"
#include "Dict.h"
#include "Timer.h"
using namespace hsql;

map<int, string> ServerSocket::curUserList;
int ServerSocket::thread_num = 0;
string ServerSocket::recv_buf;
string ServerSocket::send_buf;
DWORD __stdcall ServerSocket::createThread(const LPVOID arg)
{
	string username;
	string password;
	int n = thread_num++;
	
	F *temp = (F*)arg;
	SOCKET sockConn = temp->sockConn;
	recv_buf.clear();

	while (1) {
		//验证用户身份信息
		char recvbuf[1000 + 5];
		recv(sockConn, recvbuf, 1000, 0);
		if (recv_buf == "exit") 
			return 0;
		username = recvbuf;
		recv(sockConn, recvbuf, 1000, 0);
		if (recv_buf == "exit")
			return 0;
		password = recvbuf;
		if (true)//用户信息验证//////////////////////////////////////////
		{
			curUserList[n] = username;
			send_buf.clear();
			put_in_buf("pass");
			::send(sockConn, send_buf.c_str(), send_buf.size() + 1, 0);
			cout << Timer::getCurTime() << ": 用户" << curUserList[n] << "已连接" << endl;
			break;
		}
		else {
			send_buf.clear();
			put_in_buf("Incorrect username or password. \n");
			::send(sockConn, send_buf.c_str(), send_buf.size() + 1, 0);
		}
	}


	while (1) {
		// 收数据
		char recvbuf[1000 + 5];
		recv(sockConn, recvbuf, 1000, 0);
		recv_buf = recvbuf;
		cout << Timer::getCurTime() <<": 来自用户" << curUserList[n] << "的请求 : ";
		cout << recv_buf << endl;

		if (recv_buf == "exit") {
			cout << Timer::getCurTime() << ": 用户" << curUserList[n] << "退出 " << endl;
			curUserList.erase(n);
			break;// 应该是客户端结束 服务端退出线程
		}
			
		send_buf.clear();

		getAndUse(curUserList[n]);

		// 发数据
		
		::send(sockConn, send_buf.c_str(), send_buf.size() + 1, 0);
	}

	return 0;
}





void ServerSocket::put_in_buf(string & str)
{
	send_buf.append(str);
}

void ServerSocket::put_in_buf(const char str[])
{
	send_buf.append(str);
}

ServerSocket::ServerSocket()
{
	thread_num = 0;
	// 步骤1 加载套接字库
	WSADATA wsa;
	/*初始化socket资源*/
	WORD sockVersion = MAKEWORD(2, 2);
	if (WSAStartup(sockVersion, &wsa) != 0)
	{
		return;  // 连接失败
	}
	// 步骤2 构造SOCKET
	Listen_Sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	// 步骤3 绑定IP与端口
	sockaddr_in serverAddr;
	// ZeroMemory((char *)&serverAddr, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(server_my_port);
	// serverAddr.sin_addr.s_addr = htonl(server_my_ip);
	serverAddr.sin_addr.S_un.S_addr = INADDR_ANY; /*有IP*/
	// 步骤4 绑定Socket
	::bind(Listen_Sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
}

void ServerSocket::run()
{
	HANDLE hThread[20];
	// 步骤5 监听  (这里应该是socket自己是多线程)
	if (listen(Listen_Sock, max_thread_num) == SOCKET_ERROR)  //用listen（） 监听前面绑定好的slisten套接字
	{
		printf("listen error !");
		return;
	}
	else {
		std::cout <<Timer::getCurTime() <<": socket已建立，正在监听。socket编号： " << (int)Listen_Sock << std::endl;
	}
	std::cout << Timer::getCurTime() << ": 服务器等待连接中" << std::endl;
	for (int i = 0; i < max_thread_num; i++)
	{
		sockaddr_in addrClient;
		int len = sizeof(SOCKADDR);
		SOCKET sockConn;
		sockConn = accept(Listen_Sock, (SOCKADDR*)&addrClient, &len);
		F* temp = new F;
		temp->sockConn = sockConn;
		hThread[i] = CreateThread(NULL, 0, &ServerSocket::createThread, temp, 0, NULL);
	}

	WaitForMultipleObjects(20, hThread, TRUE, INFINITE);


	release();
}

void ServerSocket::release()
{
	std::cout << "结束" << std::endl;
	closesocket(Listen_Sock);
	// 释放socket库
	WSACleanup();
}


void ServerSocket::getAndUse(string username)
{
	SQLParserResult res;
	SQLParser::parse(string(recv_buf), &res);
	if (!res.isValid()) {
		cout << res.errorMsg() << endl;
		put_in_buf(res.errorMsg());
		put_in_buf("\n");
		return;
	}
	for (auto stm : res.getStatements()) {
		stm->execute(username);
	}
	put_in_buf("服务器处理返回的结果\n");
}