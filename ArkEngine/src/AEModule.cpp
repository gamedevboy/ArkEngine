#include <ArkEngine/AEModule.h>
#include <ArkEngine/AEModuleManager.h>

AF_DECLARE_INTERNAL_IMPLEMENT(ArkEngine::AEModule,
{
	const ArkEngine::AEModule* _initAfter;
	const ArkEngine::AEModule* _shutdownBefore;
});

ArkEngine::AEModule::AEModule(const AEModule* initAfter, const AEModule* shutdownBefore) 
{
	auto impl = GetImplement(this);

	impl->_initAfter = initAfter;
	impl->_shutdownBefore = shutdownBefore;

	AEModuleManager::Get().RegisterModule(this);
}

bool ArkEngine::AEModule::IsInitAfter(const AEModule* module) const
{
	return GetImplement(this)->_initAfter == module;
}

bool ArkEngine::AEModule::IsShutdownBefore(const AEModule* module) const
{
	return GetImplement(this)->_shutdownBefore == module;
}

void ArkEngine::AEModule::Init()
{
}

void ArkEngine::AEModule::Shutdown()
{
}
