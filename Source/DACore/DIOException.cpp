#include "stdafx.h"
#include "DIOException.h"


DIOException::DIOException(const wchar_t* Detail)
	: DException(Detail)
{
}


DIOException::~DIOException()
{
}
