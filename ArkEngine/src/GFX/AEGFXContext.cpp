#include "ArkEngine/GFX/AEGFXContext.h"
#include <EGL/egl.h>

AF_DECLARE_INTERNAL_IMPLEMENT(ArkEngine::GFX::AEGFXContext,
{
	EGLConfig _eglConfig;
});

ArkEngine::GFX::AEGFXContext::AEGFXContext(void* contextHandle)
{
	auto impl = ArkFoundation::AFGetImplement(this);
	impl->_eglConfig = contextHandle;
}

ArkEngine::GFX::AEGFXContext::AEGFXContext()
{
	
}

void ArkEngine::GFX::AEGFXContext::MakeCurrent()
{
}
