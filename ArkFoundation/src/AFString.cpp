#include <ArkFoundation/AFString.h>
#include <codecvt>

std::wstring ArkFoundation::GetWString(std::string&& str)
{
	static std::wstring_convert<std::codecvt_utf8<wchar_t>> wstringConvert;
	return wstringConvert.from_bytes((std::forward<std::string&>(str).c_str()));
}

