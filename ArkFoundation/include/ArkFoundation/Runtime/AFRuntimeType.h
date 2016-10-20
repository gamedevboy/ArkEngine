#pragma once

#include <ArkFoundation/AFString.h>

#include "AFRuntimeObject.h"
#include "AERuntimeTypeInfo.h"
#include <unordered_map>

namespace ArkFoundation
{
	namespace Runtime
	{
		template<typename _Ty>
		const AFRuntimeTypeInfo& AFTypeOf()
		{
			return _Ty::RuntimeType;
		}

		template<typename _Ty, typename _Parent>
		class AFRuntimeType : public _Parent
		{
			struct InternalRuntimeType : AFRuntimeTypeInfo
			{
				std::unordered_map<std::wstring, const AFRuntimeProperty&> _proerptyMap;

				AFRuntimeObject* Create() const override
				{
					return new _Ty();
				}

				std::wstring GetName() const override
				{
					return ToString(typeid(_Ty).name());
				}
			};

			static InternalRuntimeType RuntimeType;

			friend const AFRuntimeTypeInfo& AFTypeOf<_Ty>();

		protected:
			using ThisType = _Ty;
			using Parent = _Parent;

		public:
			const AFRuntimeTypeInfo& GetType() const override
			{
				return RuntimeType;
			}
		};

		template<typename _Ty, typename _Parent>
		typename AFRuntimeType<_Ty, _Parent>::InternalRuntimeType AFRuntimeType<_Ty, _Parent>::RuntimeType;
	}
}

#define	AF_RUNTIME_TYPE(type, parent, ...) type : public ArkFoundation::Runtime::AFRuntimeType<type, parent>, ##__VA_ARGS__
