#include "stdafx.h"
#include "DDgramSocket.h"
#include "DNetworkException.h"

DDgramSocket::DDgramSocket()
{
	this->sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (this->sock == INVALID_SOCKET)
	{
		GlobalDF->DebugManager->ThrowError<DNetworkException>(this, L"Invalid Socket");
	}
	int iMode = 1;
}


DDgramSocket::~DDgramSocket()
{
	closesocket(this->sock);
}