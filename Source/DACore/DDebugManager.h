#pragma once
#include "DObject.h"

class DDebugManager :
	public DObject
{
	DClass(DDebugManager)
private:
	void DebugPrint(const wchar_t* Sender, const wchar_t* Level, const wchar_t* Detail);
	void ClassPrint(const DObject* Sender, const wchar_t* Level, const wchar_t* Detail);
public:
	DDebugManager();
	~DDebugManager();

	template<class ExceptionType> void ThrowError(const DObject* Sender, const wchar_t* Detail)
	{
		this->Error(Sender, Detail);
		throw ExceptionType(Detail);
	}

	void Error(const DObject* Sender, const wchar_t* Detail);
	void Log(const DObject* Sender, const wchar_t* Detail);
};

