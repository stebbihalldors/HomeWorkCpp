#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Projects\HomeWorkCpp\HelloWorld\Vector-Class\Vector3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/* ToString specialisation */
namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<struct HINSTANCE__>
			(struct HINSTANCE__* t)
			{
				RETURN_WIDE_STRING(t);
			}
		}
	}
}

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(AddingVectorsTogether)
		{
			Vector3 s{ 1,2,3 };
			Vector3 t{ 3,2,1 };
			Vector3 e{ s + t };
			Assert::AreEqual(Vector3(4,5,4), e);
		}
	};
}
