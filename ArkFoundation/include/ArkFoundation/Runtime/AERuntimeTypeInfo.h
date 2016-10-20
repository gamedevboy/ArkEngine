#pragma once

#include <string>
#include "AERuntimeProperty.h"
#include <unordered_map>

namespace ArkFoundation
{
	namespace Runtime
	{
		class AFRuntimeObject;

		struct AFRuntimeTypeInfo
		{
			virtual ~AFRuntimeTypeInfo() { }
			virtual AFRuntimeObject* Create() const = 0;
			virtual std::wstring GetName() const = 0;
			void RegisterProperty(const AFRuntimeProperty& property);
			const AFRuntimeProperty* GetProperty(std::wstring propertyName) const;
		private:
			std::unordered_map<std::wstring, const AFRuntimeProperty*> _propertyMap;
		};
	}
}
