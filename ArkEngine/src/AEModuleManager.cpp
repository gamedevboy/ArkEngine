#include <ArkEngine/AEModuleManager.h>

#include <algorithm>
#include <cassert>

ArkEngine::AEModuleManager& ArkEngine::AEModuleManager::Get()
{
	static AEModuleManager instance;
	return instance;
}

void ArkEngine::AEModuleManager::RegisterModule(AEModule* module)
{
	assert(module != nullptr);
	if (module == nullptr) return;

	_moduleSet.insert(module);
}

void ArkEngine::AEModuleManager::Initialize() const
{
	std::vector<AEModule*> initList(begin(_moduleSet), end(_moduleSet));

	std::sort(begin(initList), end(initList), [](AEModule* a, AEModule* b)
	{
		return b->IsInitAfter(a);
	});

	for (auto module : initList)
		module->Init();

}

void ArkEngine::AEModuleManager::Shutdown() const
{
	std::vector<AEModule*> shutdownList(begin(_moduleSet), end(_moduleSet));

	std::sort(begin(shutdownList), end(shutdownList), [](AEModule* a, AEModule* b)
	{
		return a->IsShutdownBefore(b);
	});

	for (auto module : shutdownList)
		module->Shutdown();
}
