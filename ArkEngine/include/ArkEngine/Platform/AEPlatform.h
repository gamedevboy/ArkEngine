#pragma once

#include <ArkEngine/AEModule.h>

namespace ArkEngine
{
	namespace Platform
	{
		class AF_RUNTIME_TYPE(AEPlatform, AEModule, public ArkFoundation::AFInternalImplementType<AEPlatform>)
		{
		public:
			AEPlatform();
			static AEPlatform& Get();
			void* GetAppInstance() const;
		protected:
			void Init() override;
			void Shutdown() override;
		};
	}
}
