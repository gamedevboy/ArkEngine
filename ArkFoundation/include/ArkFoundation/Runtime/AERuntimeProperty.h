#pragma once

#include <string>

namespace ArkFoundation
{
	namespace Runtime
	{
		struct AFRuntimeProperty 
		{
			template<typename _ClassType, typename _PropertyType>
			static AFRuntimeProperty Register(_PropertyType _ClassType::* m, std::wstring name, std::wstring desc, std::wstring catalog)
			{
				//auto type = typeid(m).name();

				return AFRuntimeProperty();
			}

			std::wstring GetName() const 
			{
				return std::wstring();
			}

			std::wstring GetCatalogName() const 
			{
				return std::wstring();
			}

			void SetValue(void* object, void* value) const
			{
			}

			void* GetValue(void* object) const
			{
				return nullptr;
			}

		private:
			AFRuntimeProperty()
			{
				
			}
		};
	}
}

namespace std
{
	template<>
	struct hash<ArkFoundation::Runtime::AFRuntimeProperty>;
}
