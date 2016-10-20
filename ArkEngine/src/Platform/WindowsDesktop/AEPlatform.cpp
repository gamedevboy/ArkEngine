#include <ArkEngine/Platform/AEPlatform.h>
#include <ArkEngine/AEModuleManager.h>
#include <ArkEngine/Gameplay/AEGameplay.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

AF_DECLARE_INTERNAL_IMPLEMENT(ArkEngine::Platform::AEPlatform,
{
	HINSTANCE _hInstance;

	void Init();
	
});

void AF_INTERNAL_IMPLEMENT(ArkEngine::Platform::AEPlatform)::Init()
{
	
}

ArkEngine::Platform::AEPlatform thePlatform;

ArkEngine::Platform::AEPlatform::AEPlatform()
{
}

ArkEngine::Platform::AEPlatform& ArkEngine::Platform::AEPlatform::Get()
{
	return thePlatform;
}

void* ArkEngine::Platform::AEPlatform::GetAppInstance() const
{
	auto impl = AFGetImplement(this);
	return static_cast<void*>(impl->_hInstance);
}

void ArkEngine::Platform::AEPlatform::Init()
{
}

void ArkEngine::Platform::AEPlatform::Shutdown()
{
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmd, int nCmdShow)
{
	auto gameplay = ArkEngine::Gameplay::AEGameplay::GetGameplay();
	if (gameplay == nullptr)
		return -1;

	AFGetImplement(&ArkEngine::Platform::AEPlatform::Get())->_hInstance = hInstance;

	ArkEngine::AEModuleManager::Get().Initialize();

	gameplay->Init();

	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			gameplay->DoMainLoop();
		}
	}

	gameplay->Shutdown();

	ArkEngine::AEModuleManager::Get().Shutdown();
	
	return static_cast<int>(msg.wParam);
}
