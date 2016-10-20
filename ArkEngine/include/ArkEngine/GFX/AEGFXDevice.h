#pragma once

#include <ArkEngine/AEModule.h>

namespace ArkEngine
{
	namespace GFX
	{
		class AF_RUNTIME_TYPE(AEGFXDevice, AEModule, public ArkFoundation::AFInternalImplementType<AEGFXDevice>)
		{
		public:
			AEGFXDevice();
		protected:
			void Init() override;
			void Shutdown() override;
		};
	}
}
