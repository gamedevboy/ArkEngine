#pragma once

#include "AERuntimeTypeInfo.h"
#include "AERuntimeProperty.h"

namespace ArkFoundation
{
	namespace Runtime
	{
		class AFRuntimeObject
		{
			struct Impl;
			Impl* _impl;
		public:
			AFRuntimeObject();
			virtual ~AFRuntimeObject();

			void Retain() const;
			void Release() const;

			void* GetValue(const AFRuntimeProperty& property) const;
			void SetValue(const AFRuntimeProperty& property, void* value) const;

			virtual const AFRuntimeTypeInfo& GetType() const;

			virtual std::wstring ToString();
			virtual int GetHashCode();
		};
	}
}


