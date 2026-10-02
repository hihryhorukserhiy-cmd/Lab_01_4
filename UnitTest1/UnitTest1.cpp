#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_1_4/MyString.h"
#include "../lab_1_4/MyString.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			MyString s1, s2;
			s1.Init("Lab");
			s2.Init("1.4");
			MyString res = s1.Concat(s2);
			Assert::AreEqual(std::string("Lab1.4"), res.GetStr());
		}
	};
}
