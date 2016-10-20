#pragma once

#include "AEModule.h"
#include <unordered_set>

namespace ArkEngine
{
	class AEModuleManager
	{
		std::unordered_set<AEModule*> _moduleSet;
	public:
		static AEModuleManager& Get();

		void RegisterModule(AEModule* module);

		void Initialize() const;
		void Shutdown() const;
	};
}
