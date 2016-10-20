#include <ArkFoundation/Runtime/AFRuntimeObject.h>
#include <ArkFoundation/Refrence/AFRefrenceObject.h>
#include <ArkFoundation/AFString.h>

struct AFRuntimeObjectTypeInfo : ArkFoundation::Runtime::AFRuntimeTypeInfo
{
	ArkFoundation::Runtime::AFRuntimeObject* Create() const override;
	std::wstring GetName() const override;
};

ArkFoundation::Runtime::AFRuntimeObject* AFRuntimeObjectTypeInfo::Create() const
{
	return new ArkFoundation::Runtime::AFRuntimeObject();
}

std::wstring AFRuntimeObjectTypeInfo::GetName() const
{
	return ArkFoundation::ToString(typeid(ArkFoundation::Runtime::AFRuntimeObject).name());
}

struct ArkFoundation::Runtime::AFRuntimeObject::Impl
{
	AFRuntimeObjectTypeInfo _typeInfo;
	Refrence::AFRefrenceObject* _refObject;
	std::unordered_map<const AFRuntimeProperty*, void*> _propertyMap;
};

ArkFoundation::Runtime::AFRuntimeObject::AFRuntimeObject()
{
	_impl = new Impl();
	_impl->_refObject = new Refrence::AFRefrenceObject();

	Retain();
}

ArkFoundation::Runtime::AFRuntimeObject::~AFRuntimeObject()
{
	delete _impl;
}

void ArkFoundation::Runtime::AFRuntimeObject::Retain() const
{
	_impl->_refObject->Retain();
	_impl->_refObject->RetainWeak();
}

void ArkFoundation::Runtime::AFRuntimeObject::Release() const
{
	auto refObject = _impl->_refObject;

	if (refObject->Release())
		delete this;

	refObject->ReleaseWeak();
}

void* ArkFoundation::Runtime::AFRuntimeObject::GetValue(const AFRuntimeProperty& property) const
{
	auto it = _impl->_propertyMap.find(&property);
	if( it == _impl->_propertyMap.end())
		return nullptr;

	return it->second;
}

void ArkFoundation::Runtime::AFRuntimeObject::SetValue(const AFRuntimeProperty& property, void* value) const
{
	_impl->_propertyMap.insert_or_assign(&property, value);
}

const ArkFoundation::Runtime::AFRuntimeTypeInfo& ArkFoundation::Runtime::AFRuntimeObject::GetType() const
{
	return _impl->_typeInfo;
}

std::wstring ArkFoundation::Runtime::AFRuntimeObject::ToString()
{
	return ArkFoundation::ToString(typeid(*this).name());
}

int ArkFoundation::Runtime::AFRuntimeObject::GetHashCode()
{
	return std::hash<AFRuntimeObject*>()(this);
}
