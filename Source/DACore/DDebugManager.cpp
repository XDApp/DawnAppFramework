#include "stdafx.h"
#include "DDebugManager.h"


DDebugManager::DDebugManager()
{
}


DDebugManager::~DDebugManager()
{
}

void DDebugManager::DebugPrint(const wchar_t* Sender, const wchar_t* Level, const wchar_t* Detail)
{
	std::wstring TargetStr = L"";

	TargetStr.append(L"[");
	TargetStr.append(Level);
	TargetStr.append(L"]");
	TargetStr.append(Sender);
	TargetStr.append(L": ");
	TargetStr.append(Detail);

	std::wcout << TargetStr << std::endl;

	OutputDebugString(TargetStr.c_str());
}

void DDebugManager::Error(const DObject* Sender, const wchar_t* Detail)
{
	this->ClassPrint(Sender, L"Error", Detail);
}


void DDebugManager::Log(const DObject* Sender, const wchar_t* Detail)
{
	this->ClassPrint(Sender, L"Log", Detail);
}

void DDebugManager::ClassPrint(const DObject* Sender, const wchar_t* Level, const wchar_t* Detail)
{
	this->DebugPrint(Sender == nullptr ? L"Unknown" : Sender->ClassName_W(), Level, Detail);
}
