#include <ArkEngine/GFX/AEGFXDevice.h>
#include "ArkEngine/AEModuleManager.h"
//
//struct m
//{
//	
//};
//
//using p = ArkFoundation::Runtime::AFRuntimeProperty<ArkEngine::AEModule, int, &ArkEngine::AEModule::cc, m>;

#include <iostream>
#include "ArkFoundation/Runtime/AERuntimeProperty.h"

/**
 * \brief 
 * --------------------------------------
 * SpiderMonkey
 * Bridge.Net
 * LZ4
 * Vec
 * Assimp
 * FreeType2
 * webP
 * libpng
 * libjpeg
 * zlib (zstand)
 * --------------------------------------
 * midi lib 
 */
void main()
{
	//auto c = p::PropertyInstance;
	ArkEngine::GFX::AEGFXDevice device;
	ArkEngine::AEModuleManager::Get().Initialize();


	auto& type = device.GetType();
	std::wcout << type.GetName() << std::endl;

	auto& atype = ArkFoundation::Runtime::AFTypeOf<ArkEngine::AEModule>();
	std::wcout << atype.GetName() << std::endl;

	ArkFoundation::Runtime::AFRuntimeProperty::Register(&ArkEngine::GFX::AEGFXDevice::Version, L"", L"", L"");

	ArkEngine::AEModuleManager::Get().Shutdown();
}
