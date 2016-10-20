#include <ArkEngine/Gameplay/AEGameplay.h>

AF_DECLARE_INTERNAL_IMPLEMENT(ArkEngine::Gameplay::AEGameplay,
{
});

ArkEngine::Gameplay::AEGameplay* theGameplay = nullptr;

ArkEngine::Gameplay::AEGameplay::AEGameplay()
{
	theGameplay = this;
}

void ArkEngine::Gameplay::AEGameplay::Init()
{
}

void ArkEngine::Gameplay::AEGameplay::Shutdown()
{
}

void ArkEngine::Gameplay::AEGameplay::OnAdvanceTime()
{
}

void ArkEngine::Gameplay::AEGameplay::DoMainLoop()
{
}

ArkEngine::Gameplay::AEGameplay* ArkEngine::Gameplay::AEGameplay::GetGameplay()
{
	return theGameplay;
}
