#include "stdafx.h"
#include "DNetworkException.h"


DNetworkException::DNetworkException(const wchar_t* Detail)
	: DException(Detail)
{
}


DNetworkException::~DNetworkException()
{
}
