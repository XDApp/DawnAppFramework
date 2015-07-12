#pragma once
#include "DObject.h"
class DIOStream :
	public DObject
{
	DClass(DIOStream)
public:
	DIOStream();
	~DIOStream();

	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual void Buffer() = 0;
};

