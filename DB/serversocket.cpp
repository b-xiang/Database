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
		//��֤�û������Ϣ
		char recvbuf[1000 + 5];
		recv(sockConn, recvbuf, 1000, 0);
		if (recv_buf == "exit") 
			return 0;
		username = recvbuf;
		recv(sockConn, recvbuf, 1000, 0);
		if (recv_buf == "exit")
			return 0;
		password = recvbuf;
		if (true)//�û���Ϣ��֤//////////////////////////////////////////
		{
			curUserList[n] = username;
			send_buf.clear();
			put_in_buf("pass");
			::send(sockConn, send_buf.c_str(), send_buf.size() + 1, 0);
			cout << Timer::getCurTime() << ": �û�" << curUserList[n] << "������" << endl;
			break;
		}
		else {
			send_buf.clear();
			put_in_buf("Incorrect username or password. \n");
			::send(sockConn, send_buf.c_str(), send_buf.size() + 1, 0);
		}
	}


	while (1) {
		// ������
		char recvbuf[1000 + 5];
		recv(sockConn, recvbuf, 1000, 0);
		recv_buf = recvbuf;
		cout << Timer::getCurTime() <<": �����û�" << curUserList[n] << "������ : ";
		cout << recv_buf << endl;

		if (recv_buf == "exit") {
			cout << Timer::getCurTime() << ": �û�" << curUserList[n] << "�˳� " << endl;
			curUserList.erase(n);
			break;// Ӧ���ǿͻ��˽��� ������˳��߳�
		}
			
		send_buf.clear();

		getAndUse(curUserList[n]);

		// ������
		
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
	// ����1 �����׽��ֿ�
	WSADATA wsa;
	/*��ʼ��socket��Դ*/
	WORD sockVersion = MAKEWORD(2, 2);
	if (WSAStartup(sockVersion, &wsa) != 0)
	{
		return;  // ����ʧ��
	}
	// ����2 ����SOCKET
	Listen_Sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	// ����3 ��IP��˿�
	sockaddr_in serverAddr;
	// ZeroMemory((char *)&serverAddr, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(server_my_port);
	// serverAddr.sin_addr.s_addr = htonl(server_my_ip);
	serverAddr.sin_addr.S_un.S_addr = INADDR_ANY; /*��IP*/
	// ����4 ��Socket
	::bind(Listen_Sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
}

void ServerSocket::run()
{
	HANDLE hThread[20];
	// ����5 ����  (����Ӧ����socket�Լ��Ƕ��߳�)
	if (listen(Listen_Sock, max_thread_num) == SOCKET_ERROR)  //��listen���� ����ǰ��󶨺õ�slisten�׽���
	{
		printf("listen error !");
		return;
	}
	else {
		std::cout <<Timer::getCurTime() <<": socket�ѽ��������ڼ�����socket��ţ� " << (int)Listen_Sock << std::endl;
	}
	std::cout << Timer::getCurTime() << ": �������ȴ�������" << std::endl;
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
	std::cout << "����" << std::endl;
	closesocket(Listen_Sock);
	// �ͷ�socket��
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
	put_in_buf("�����������صĽ��\n");
}