#pragma once
#include "DException.h"
class DIOException :
	public DException
{
public:
	DIOException(const wchar_t* Detail);
	~DIOException();
};

