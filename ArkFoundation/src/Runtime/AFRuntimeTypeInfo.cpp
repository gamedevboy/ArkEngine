#include <ArkFoundation/Runtime/AERuntimeTypeInfo.h>

void ArkFoundation::Runtime::AFRuntimeTypeInfo::RegisterProperty(const AFRuntimeProperty& property)
{
	if (_propertyMap.find(property.GetName()) != _propertyMap.end())
		throw new std::exception();

	_propertyMap.insert_or_assign(property.GetName(), &property);
}

const ArkFoundation::Runtime::AFRuntimeProperty* ArkFoundation::Runtime::AFRuntimeTypeInfo::GetProperty(std::wstring propertyName) const
{
	auto it = _propertyMap.find(propertyName);
	if (it != _propertyMap.end())
		return it->second;

	return nullptr;
}
