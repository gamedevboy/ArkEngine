#pragma once

#include <ArkFoundation/Runtime/AFRuntimeType.h>
#include "ArkFoundation/AFInternalImplType.h"

namespace ArkEngine
{
	class AF_RUNTIME_TYPE(AEModule, ArkFoundation::Runtime::AFRuntimeObject, ArkFoundation::AFInternalImplementType<AEModule>)
	{
	public:
		friend class AEModuleManager;
		explicit AEModule(const AEModule* initBefore = nullptr, const AEModule* shutdownBefore = nullptr);

		bool IsInitAfter(const AEModule* module) const;
		bool IsShutdownBefore(const AEModule* module) const;

		virtual void Init();
		virtual void Shutdown();
	};
}
