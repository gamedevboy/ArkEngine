#include <ArkEngine/gfx/AEGFXDevice.h>

#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <ArkFoundation/AFDebug.h>

#pragma comment(lib, "libEGL.lib")
#pragma comment(lib, "libGLESv2.lib")


AF_DECLARE_INTERNAL_IMPLEMENT(ArkEngine::GFX::AEGFXDevice,
{
	EGLDisplay _eglDisplay;
	EGLConfig _eglConfig;
});

ArkEngine::GFX::AEGFXDevice::AEGFXDevice()
{

}

void ArkEngine::GFX::AEGFXDevice::Init()
{
	auto impl = AFGetImplement(this);

	impl->_eglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
	AF_ASSERT(impl->_eglDisplay != EGL_NO_DISPLAY);

	EGLint majorVersion, minorVersion;
	AF_ASSERT(!eglInitialize(impl->_eglDisplay, &majorVersion, &minorVersion));

	ArkFoundation::AFLog(L"eglInitialize Version %d.%d", majorVersion, minorVersion);

	EGLint numConfigs;
	AF_ASSERT(eglGetConfigs(impl->_eglDisplay, nullptr, 0, &numConfigs));
	
	EGLint attributes[] =
	{
		EGL_RENDERABLE_TYPE, 0,
		EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
		EGL_RED_SIZE, 8,
		EGL_GREEN_SIZE, 8,
		EGL_BLUE_SIZE, 8,
		EGL_NONE
	};

	EGLConfig eglConfig;
	AF_ASSERT(eglChooseConfig(impl->_eglDisplay, attributes, &eglConfig, 1, &numConfigs));

	//// Create a surface
	//auto surface = eglCreateWindowSurface(eglDisplay, eglConfig, (EGLNativeWindowType)nullptr, nullptr);
	//AF_ASSERT(surface != EGL_NO_SURFACE);
/*
	EGLint context_attributes[] = { EGL_CONTEXT_MAJOR_VERSION, 3,
		EGL_CONTEXT_MINOR_VERSION, 1,
		EGL_NONE };

	

	auto context = eglCreateContext(eglDisplay, configs[0], EGL_NO_CONTEXT,
		context_attributes);*/
}

void ArkEngine::GFX::AEGFXDevice::Shutdown()
{
}
