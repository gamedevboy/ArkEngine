#pragma once

#include "ArkFoundation/Runtime/AFRuntimeType.h"
#include "ArkFoundation/Runtime/AFRuntimeObject.h"
#include "ArkFoundation/AFInternalImplType.h"

namespace ArkEngine
{
	namespace GFX
	{
		class AF_RUNTIME_TYPE(AEGFXContext, ArkFoundation::Runtime::AFRuntimeObject, public ArkFoundation::AFInternalImplementType<AEGFXContext>)
		{
			friend class AEGFXDevice;
			AEGFXContext(void* contextHandle);
		public:
			AEGFXContext();
			void MakeCurrent();
		};
	}
}
