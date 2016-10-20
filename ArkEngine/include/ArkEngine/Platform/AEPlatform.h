#pragma once

#include <ArkEngine/AEModule.h>

namespace ArkEngine
{
	namespace Platform
	{
		class AF_RUNTIME_TYPE(AEPlatform, AEModule, ArkFoundation::AFInternalImplementType<AEPlatform>)
		{
		public:
			static AEPlatform Platform;

			AEPlatform();
			void DoMainLoop();
		protected:
			void Init() override;
			void Shutdown() override;
		};
	}
}
