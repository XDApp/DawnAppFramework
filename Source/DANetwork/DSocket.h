#pragma once

#include "DSocketAddrIn.h"

class DSocket
	: public DObject
{
	DClass(DSocket)
protected:
	SOCKET sock;
public:
	DSocket();
	virtual ~DSocket() = 0;
	void Send(const char* buf, int length, const DSocketAddrIn &addr);
	int Recv(char* buf, int length, DSocketAddrIn &addr);
	void Bind(const DSocketAddrIn &addr);
};