#pragma once

#include <atomic>

namespace ArkFoundation
{
	namespace Refrence
	{
		class AFRefrenceObject
		{
			std::atomic<int> _refCount;
			std::atomic<int> _weakRefCount;
		public:
			void Retain();
			void RetainWeak();

			bool Release();
			void ReleaseWeak();
		};
	}
}