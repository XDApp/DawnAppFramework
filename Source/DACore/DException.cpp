#include "stdafx.h"
#include "DException.h"


DException::DException(const wchar_t* Detail)
	: ExceptionDetail(Detail)
{
}


DException::~DException()
{
}

const wchar_t* DException::GetDetail() const
{
	return this->ExceptionDetail;
}