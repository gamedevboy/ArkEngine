#pragma once

#include <cassert>
#include <exception>

#if _DEBUG
#define AF_ASSERT(p) assert(p)
#else
#define AF_ASSERT(p) if(!(p)) throw std::exception(#p)
#endif