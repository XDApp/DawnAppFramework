#pragma once

class DCryptException :
	public DException
{
	DClass(DCryptException)
public:
	DCryptException(const wchar_t* Detail);
	~DCryptException();
};

