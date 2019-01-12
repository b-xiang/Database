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

	sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //�ͻ����׽���
	if (sclient == INVALID_SOCKET)
	{
		std::cout << "invalid socket!" << std::endl;
		return ;
	}

	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(Global::port);
	inet_pton(AF_INET,Global::ip, (void*)&serAddr.sin_addr.S_un.S_addr);
	if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR) //��ָ��IP��ַ�Ͷ˿ڵķ��������
	{
		cout << "connect error !" << endl;
		closesocket(sclient);
		exit(1);
	}
}

void MySocket::run()
{
	//�����ͻ����׽���
	while (1) {//�����Ϣ��֤
		printf("username:");
		string data;
		getline(cin, data);
		const char * sendData2;
		sendData2 = data.c_str(); //stringתconst char*
		send(sclient, sendData2, strlen(sendData2) + 1, 0);
		printf("password:");
		getline(cin, data);
		sendData2 = data.c_str(); //stringתconst char*
		send(sclient, sendData2, strlen(sendData2) + 1, 0);

		char recData[Global::recv_buf_size + 5];
		int ret = recv(sclient, recData, Global::recv_buf_size, 0);
		if (ret > 0) {
			recData[ret] = 0x00;
			if (string(recData)=="pass")
				break;
			else
				printf(recData);
		}
	}
	while (1)
	{
		// ����exit�˳�
		printf(">");
		string data;
		//cin >> data;
		getline(cin, data);
		
		const char * sendData2;
		sendData2 = data.c_str(); //stringתconst char*
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
