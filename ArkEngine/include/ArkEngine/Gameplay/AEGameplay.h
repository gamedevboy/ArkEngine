#pragma once
#include <ArkFoundation/AFInternalImplType.h>

namespace ArkEngine
{
	namespace Gameplay
	{
		class AEGameplay : public ArkFoundation::AFInternalImplementType<AEGameplay>
		{
		public:
			AEGameplay();

			virtual void Init();
			virtual void Shutdown();
			virtual void OnAdvanceTime();

			void DoMainLoop();

			static AEGameplay* GetGameplay();
		};
	}
}
