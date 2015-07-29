// networl-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include <process.h>
#include <string.h>

#pragma comment(lib,"Ws2_32.lib")


#define MaxSize 65570
#define HTTP_PORT 80

struct HttpHeader{
	char method[4];
	char url[1024];
	char host[1024];
	char cookie[1024 * 10];
	HttpHeader(){
		ZeroMemory(this, sizeof(HttpHeader));
	}
};

BOOL InitSocket();
int ParseHttpHead(char * buffer, HttpHeader* httpHeader);
BOOL ConnectToServer(SOCKET *serverSocket, char*host);
unsigned int _stdcall ProxyThread(LPVOID IpParameter);

SOCKET ProxyServer;
sockaddr_in ProxyServerAddr;
const int ProxyPort = 10240;

struct ProxyParam{
	SOCKET clientSocket;
	SOCKET serverSocket;

};

int _tmain(int argc, char * argv[])
{
	printf("代理服务器启动\n");
	printf("init\n");
	if (!InitSocket())
	{
		printf("init fail\n");
		return -1;

	}

	printf("代理服务器正在运行，监听端口%d.\n", ProxyPort);
	SOCKET acceptSocket = INVALID_SOCKET;
	ProxyParam *IpProxyParam;
	HANDLE hThread;
	DWORD dwThreadID;
	while (true){
		acceptSocket = accept(ProxyServer, NULL, NULL);
		IpProxyParam = new ProxyParam;
		if (IpProxyParam == NULL)
		{
			continue;

		}
		IpProxyParam->clientSocket = acceptSocket;
		hThread = (HANDLE)_beginthreadex(NULL, 0, &ProxyThread, (LPVOID)IpProxyParam, 0, 0);
		CloseHandle(hThread);
		Sleep(200);
	}
	closesocket(ProxyServer);
	WSACleanup();
	return 0;
}

BOOL InitSocket(){
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		printf("fail,%d\n", WSAGetLastError());
		return FALSE;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		printf("wrong version\n");
		WSACleanup();
		return FALSE;

	}
	ProxyServer = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == ProxyServer)
	{
		printf("build socket fail,%d\n", WSAGetLastError());
		return FALSE;
	}
	ProxyServerAddr.sin_family = AF_INET;
	ProxyServerAddr.sin_port = htons(ProxyPort);
	ProxyServerAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(ProxyServer, (SOCKADDR*)&ProxyServerAddr, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		printf("fail\n");
		return FALSE;
	}
	if (listen(ProxyServer, SOMAXCONN) == SOCKET_ERROR)
	{
		printf("监听端口%dFAIL\n", ProxyPort);
		return FALSE;

	}
	return TRUE;

}

unsigned int _stdcall ProxyThread(LPVOID IpParameter)
{
	char Buffer[MaxSize];
	char *CacheBuffer;
	ZeroMemory(Buffer, MaxSize);
	SOCKADDR_IN clientAddr;
	int length = sizeof(SOCKADDR_IN);
	int recvSize;
	int ret;
	recvSize = recv(((ProxyParam*)IpParameter)->clientSocket, Buffer, MaxSize, 0);
	if (recvSize <= 0)
	{
		goto error;

	}
	HttpHeader*httpHeader = new HttpHeader();
	CacheBuffer = new char[recvSize + 1];
	ZeroMemory(CacheBuffer, recvSize + 1);
	memcpy(CacheBuffer, Buffer, recvSize);
	int t=ParseHttpHead(CacheBuffer, httpHeader);
	
	delete CacheBuffer;
	if (t == 0)
	{
		goto error;
	}
	if (t == 2)
	{
		return 0;
	}
	if (!ConnectToServer(&((ProxyParam*)IpParameter)->serverSocket, httpHeader->host))
	{
		goto error;
	}
	printf("代理连接主机%ssuccess\n", httpHeader->host);
	ret = send(((ProxyParam*)IpParameter)->serverSocket, Buffer, strlen(Buffer) + 1, 0);
	recvSize = recv(((ProxyParam*)IpParameter)->serverSocket, Buffer, MaxSize, 0);
	if (recvSize <= 0)
	{
		goto error;
	}
	ret = send(((ProxyParam*)IpParameter)->clientSocket, Buffer, sizeof(Buffer)+1, 0);
error:
	printf("close socket\n");
	Sleep(200);
	closesocket(((ProxyParam*)IpParameter)->clientSocket);
	closesocket(((ProxyParam*)IpParameter)->serverSocket);
	delete IpParameter;
	_endthreadex(0);
	return 0;
}

int ParseHttpHead(char * buffer, HttpHeader* httpHeader)
{
	char *p;
	char *ptr;
	const char* delim = "\r\n";
	p = strtok_s(buffer, delim, &ptr);
	printf("%s\n", p);
	if (p[0] == 'G'){
		memcpy(httpHeader->method, "GET", 3);
		memcpy(httpHeader->url, &p[4], strlen(p) - 13);
		

	}
	else if (p[0] == 'P')
	{
		memcpy(httpHeader->method, "POST", 4);
		memcpy(httpHeader->url, &p[5], strlen(p) - 14);
	}
	printf("%s\n", httpHeader->url);
	char temp[1024];
	//printf("Please input the url you want to forbian");
	strcpy_s(temp,"http://www.tudou.com/");
	if (!strcmp(httpHeader->url , temp))
	{
		printf("The url is forbiddened!\n");
		return 2;
	}
	p = strtok_s(NULL, delim, &ptr);
	while (p)
	{
		switch (p[0]){
		case'H':
			memcpy(httpHeader->host, &p[6], strlen(p) - 6);
			break;
		case'C':
			if (strlen(p) > 8)
			{
				char header[8];
				ZeroMemory(header, sizeof(header));
				memcpy(header, p, 6);
				if (!strcmp(header, "Cookie")){
					memcpy(httpHeader->cookie, &p[8], strlen(p) - 8);
				}
			}
			break;
		default:
			break;
		}
		p = strtok_s(NULL, delim, &ptr);
	}
	return 1;
}

BOOL ConnectToServer(SOCKET* serverSocket, char* host)
{
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(HTTP_PORT);
	HOSTENT * hostnet = gethostbyname(host);
	if (!hostnet)
	{
		return FALSE;

	}
	in_addr Inaddr = *((in_addr*)*hostnet->h_addr_list);
	serverAddr.sin_addr.S_un.S_addr = inet_addr(inet_ntoa(Inaddr));
	*serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (*serverSocket == INVALID_SOCKET)
	{
		return FALSE;

	}
	if (connect(*serverSocket, (SOCKADDR *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		closesocket(*serverSocket);
		return FALSE;
	}
	return true;
}


