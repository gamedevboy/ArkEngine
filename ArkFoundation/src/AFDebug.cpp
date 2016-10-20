#include <ArkFoundation/AFDebug.h>
#include <cstdarg>
#include <iostream>

#if _WINDOWS_DESKTOP
#include <windows.h>
#endif

void ArkFoundation::AFLog(std::wstring text, ...)
{
	wchar_t buffer[1024];
	std::va_list args;
	va_start(args, text);
	
	_vsnwprintf_s(buffer, sizeof(buffer), text.c_str(), args);

	std::cout << buffer << std::endl;

#if _WINDOWS_DESKTOP
	::OutputDebugStringW(buffer);
#endif
}