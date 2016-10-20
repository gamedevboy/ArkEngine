#include <ArkEngine/Platform/AEPlatform.h>
#include <ArkEngine/AEModuleManager.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

AF_DECLARE_INTERNAL_IMPLEMENT(ArkEngine::Platform::AEPlatform,
{
	void Init();
});

void AF_INTERNAL_IMPLEMENT(ArkEngine::Platform::AEPlatform)::Init()
{
	
}

ArkEngine::Platform::AEPlatform ArkEngine::Platform::AEPlatform::Platform;


ArkEngine::Platform::AEPlatform::AEPlatform()
{
}

void ArkEngine::Platform::AEPlatform::DoMainLoop()
{
}

void ArkEngine::Platform::AEPlatform::Init()
{
}

void ArkEngine::Platform::AEPlatform::Shutdown()
{
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmd, int nCmdShow)
{
	ArkEngine::AEModuleManager::Get().Initialize();

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
			ArkEngine::Platform::AEPlatform::Platform.DoMainLoop();
		}
	}

	ArkEngine::AEModuleManager::Get().Shutdown();
	
	return msg.wParam;
}
