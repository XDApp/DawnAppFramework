#pragma once
#include "DObject.h"
class DException :
	public DObject
{
	DClass(DException)
private:
	const wchar_t* ExceptionDetail;
public:
	DException(const wchar_t* Detail);
	const wchar_t* GetDetail() const;
	~DException();
};

