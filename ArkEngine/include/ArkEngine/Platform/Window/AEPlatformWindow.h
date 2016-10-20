#pragma once

#include <ArkFoundation/AFInternalImplType.h>

#include <ArkFoundation/Runtime/AFRuntimeType.h>
#include <ArkFoundation/Runtime/AFRuntimeObject.h>

namespace ArkEngine
{
	namespace Platform
	{
		namespace Window
		{
			class AF_RUNTIME_TYPE(AEPlatformWindow, ArkFoundation::Runtime::AFRuntimeObject, public ArkFoundation::AFInternalImplementType<AEPlatformWindow>)
			{
			public:
				void Init(std::wstring Title, int width, int height);
				void* GetHandle() const;
			};
		}
	}
}
