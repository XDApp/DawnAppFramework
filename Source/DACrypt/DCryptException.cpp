#include "stdafx.h"
#include "DCryptException.h"


DCryptException::DCryptException(const wchar_t* Detail)
	: DException(Detail)
{
}


DCryptException::~DCryptException()
{
}
