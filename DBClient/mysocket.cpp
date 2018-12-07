#include "mysocket.h"
#include "global.h"
using namespace std;
MySocket::MySocket()
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)
	{
		return;
	}

	sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //客户端套接字
	if (sclient == INVALID_SOCKET)
	{
		std::cout << "invalid socket!" << std::endl;
		return ;
	}

	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(Global::port);
	inet_pton(AF_INET,Global::ip, (void*)&serAddr.sin_addr.S_un.S_addr);
	if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR) //与指定IP地址和端口的服务端连接
	{
		cout << "connect error !" << endl;
		closesocket(sclient);
		return;
	}
}

void MySocket::run()
{
	//创建客户端套接字
	while (1)
	{
		// 输入exit退出
		printf(">");
		string data;
		//cin >> data;
		getline(cin, data);
		
		const char * sendData2;
		sendData2 = data.c_str(); //string转const char*
		send(sclient, sendData2, strlen(sendData2) + 1, 0);

		if (data == "exit")
			break;

		char recData[Global::recv_buf_size + 5];
		int ret = recv(sclient, recData, Global::recv_buf_size, 0);
		if (ret > 0) {
			recData[ret] = 0x00;
			printf(recData);
		}


	}
	release();
}

void MySocket::release()
{
	closesocket(sclient);
	WSACleanup();
}
