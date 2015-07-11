#pragma once
#include "E:\DAF\Source\DACore\DException.h"
class DNetworkException :
	public DException
{
	DClass(DNetworkException)
public:
	DNetworkException(const wchar_t* Detail);
	~DNetworkException();
};

