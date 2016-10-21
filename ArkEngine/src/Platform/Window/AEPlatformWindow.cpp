#include <ArkEngine/Platform/Window/AEPlatformWindow.h>
#include <ArkEngine/Platform/AEPlatform.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

AF_DECLARE_INTERNAL_IMPLEMENT(ArkEngine::Platform::Window::AEPlatformWindow,
{
	HWND _hwnd;
	static LRESULT __stdcall WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT OnWindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
});

LRESULT AF_INTERNAL_IMPLEMENT(ArkEngine::Platform::Window::AEPlatformWindow)::OnWindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(_hwnd, uMsg, wParam, lParam);
}

LRESULT AF_INTERNAL_IMPLEMENT(ArkEngine::Platform::Window::AEPlatformWindow)::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_CLOSE)
	{
		PostMessage(hwnd, WM_QUIT, 0, 0);
		return 0;
	}

	auto platformWindow = reinterpret_cast<ArkEngine::Platform::Window::AEPlatformWindow*>(GetWindowLongPtr(hwnd, 0));
	if (platformWindow != nullptr)
		return AFGetImplement(platformWindow)->OnWindowProc(uMsg, wParam, lParam);

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void ArkEngine::Platform::Window::AEPlatformWindow::Init(std::wstring title, int width, int height)
{
	auto impl = GetImplement(this);

	auto hInstance = static_cast<HINSTANCE>(ArkEngine::Platform::AEPlatform::Get().GetAppInstance());

	WNDCLASS wndcls;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	wndcls.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndcls.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wndcls.hInstance = hInstance;
	wndcls.lpfnWndProc = AF_INTERNAL_IMPLEMENT(ArkEngine::Platform::Window::AEPlatformWindow)::WindowProc;
	wndcls.lpszClassName = TEXT("ArkEngineRenderWindow");
	wndcls.lpszMenuName = nullptr;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls);

	RECT windowRect = { 0, 0, width, height };
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, false);

	impl->_hwnd = CreateWindowW(
		L"ArkEngineRenderWindow", 
		title.c_str(),
		WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		windowRect.right-windowRect.left, 
		windowRect.bottom-windowRect.top,
		nullptr, nullptr, hInstance, nullptr);

	SetWindowLongPtr(impl->_hwnd, 0, reinterpret_cast<LONG_PTR>(this));

	ShowWindow(impl->_hwnd, SW_SHOWNORMAL);
	UpdateWindow(impl->_hwnd);
}

void* ArkEngine::Platform::Window::AEPlatformWindow::GetHandle() const
{
	return static_cast<void*>(GetImplement(this)->_hwnd);
}
