#pragma once
#include "DObject.h"

class DDebugManager :
	public DObject
{
	DClass(DDebugManager)
private:
	void DebugPrint(const wchar_t* Sender, const wchar_t* Level, const wchar_t* Detail);
	void ClassPrint(const DObject* Sender, const wchar_t* Level, const wchar_t* Detail);

	std::wstring_convert<std::codecvt_utf16<wchar_t>> converter;
public:
	DDebugManager();
	~DDebugManager();

	void Error(const DObject* Sender, const wchar_t* Detail);
	void Log(const DObject* Sender, const wchar_t* Detail);
};

