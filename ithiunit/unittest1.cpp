#include "targetver.h"
#include "CppUnitTest.h"
#include "hashtest.h"
#include "testRfc6761.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ithiunit
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Hash)
		{
			// TODO: Your test code here
            hashtest test;
            bool ret = test.DoTest();

            Assert::AreEqual(ret, true);
		}

        TEST_METHOD(Rfc6761)
        {
            // TODO: Your test code here
            testRfc6761 test;
            bool ret = test.DoTest();

            Assert::AreEqual(ret, true);
        }
	};
}