#pragma once

class DUtil
{
private:
	static std::wstring_convert<std::codecvt_utf16<wchar_t>> converter;
public:
	DUtil();
	virtual ~DUtil() = 0;

	static std::wstring StringAtoW(const std::string &Origin);
	static std::string StringWtoA(const std::wstring &Origin);

	static std::wstring ANSIToUnicode(const std::string& str);
	static std::string UnicodeToANSI(const std::wstring& str);
};

