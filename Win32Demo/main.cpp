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
#include <ArkEngine/Gameplay/AEGameplay.h>
#include <ArkEngine/Platform/Window/AEPlatformWindow.h>

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

class MyGameplay : public ArkEngine::Gameplay::AEGameplay
{
	ArkEngine::Platform::Window::AEPlatformWindow _window;
	ArkEngine::GFX::AEGFXDevice _gfxDevice;

public:
	void Init() override
	{
		_window.Init(L"hello", 800, 600);
	}
} theGameplay;
