#include <ArkFoundation/Refrence/AFRefrenceObject.h>

void ArkFoundation::Refrence::AFRefrenceObject::Retain()
{
	++_refCount;
}

void ArkFoundation::Refrence::AFRefrenceObject::RetainWeak()
{
	++_weakRefCount;
}

bool ArkFoundation::Refrence::AFRefrenceObject::Release()
{
	while (true)
	{
		auto currCount = _refCount.load();

		if (!_refCount.compare_exchange_weak(currCount, currCount - 1))
			continue;

		if (currCount == 1)
			return true;

		return false;
	}
}

void ArkFoundation::Refrence::AFRefrenceObject::ReleaseWeak()
{
	while (true)
	{
		auto currCount = _refCount.load();

		if (!_refCount.compare_exchange_weak(currCount, currCount - 1))
			continue;

		if (currCount == 1)
			delete this;

		break;
	}
}
