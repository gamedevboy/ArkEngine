#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ArkEngine/include/ArkEngine/AEModuleManager.h"
#include "../ArkEngine/include/ArkEngine/gfx/AEGFXDevice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArkEngineTest
{		
	TEST_CLASS(ArkEngineTest)
	{
	public:
		
		TEST_METHOD(ModuleTest)
		{
			ArkEngine::GFX::AEGFXDevice device;

			ArkEngine::AEModuleManager::Get()->Initialize();
		}

	};
}