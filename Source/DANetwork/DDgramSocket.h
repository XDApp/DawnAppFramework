#pragma once
#include "DSocket.h"

class DDgramSocket :
	public DSocket
{
	DClass(DDgramSocket)
public:
	DDgramSocket();
	~DDgramSocket();
};