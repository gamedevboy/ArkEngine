#pragma once

#include <cassert>
#include <exception>
#include <string>

#if _DEBUG
#define AF_ASSERT(p) assert(p)
#else
#define AF_ASSERT(p) if(!(p)) { ArkFoundation::AFLog(L#p); throw std::exception(#p); }
#endif

namespace ArkFoundation
{
	extern void AFLog(std::wstring text, ...);
}