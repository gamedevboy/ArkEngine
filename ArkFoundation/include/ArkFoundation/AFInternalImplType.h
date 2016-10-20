#pragma once

namespace ArkFoundation
{
	template<typename _Ty>
	struct AFInternalImplementType
	{
		struct Implement;
		Implement* _implement;
		
		AFInternalImplementType();
		virtual ~AFInternalImplementType();

		static Implement* GetImplement(AFInternalImplementType<_Ty>* ptr) { return ptr->_implement; }
		static Implement* GetImplement(const AFInternalImplementType<_Ty>* ptr) { return ptr->_implement; }
	};

	template<typename _Ty>
	auto AFGetImplement(_Ty* ptr)
	{
		return AFInternalImplementType<_Ty>::GetImplement(ptr);
	}

	template<typename _Ty>
	auto AFGetImplement(const _Ty* ptr)
	{
		return AFInternalImplementType<_Ty>::GetImplement(ptr);
	}
}

#define AF_DECLARE_INTERNAL_IMPLEMENT(type,def) \
template<> struct ArkFoundation::AFInternalImplementType<type>::Implement def;\
template<> ArkFoundation::AFInternalImplementType<type>::AFInternalImplementType() : _implement(new Implement()) {}\
template<> ArkFoundation::AFInternalImplementType<type>::~AFInternalImplementType() { delete _implement; }

#define AF_INTERNAL_IMPLEMENT(type) ArkFoundation::AFInternalImplementType<type>::Implement