#include "stdafx.h"
#include "DUtil.h"

std::wstring_convert<std::codecvt_utf16<wchar_t>> DUtil::converter;

DUtil::DUtil()
{
}


DUtil::~DUtil()
{
}

std::wstring DUtil::StringAtoW(const std::string &Origin)
{
	return DUtil::converter.from_bytes(Origin);
}

std::string DUtil::StringWtoA(const std::wstring &Origin)
{
	return DUtil::converter.to_bytes(Origin);
}
