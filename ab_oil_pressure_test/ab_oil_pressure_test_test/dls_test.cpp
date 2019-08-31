#include "pch.h"
#include "CppUnitTest.h"
#include "../../../gemeinsam/uwi/dls.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ab_oil_pressure_test_test
{
TEST_CLASS( Dls_test )
{
public:

   TEST_METHOD( sort )
   {
      nhill::uwi::Dls dls{ 2, 2, 3, 4, 5, 6, 7 };
      string actual{dls.sort()};
      Assert::AreEqual( "004W6050302027", actual.c_str() );
   }

   TEST_METHOD( plain_without_rgd )
   {
      nhill::uwi::Dls dls{ 2, 2, 3, 4, 5, 6, 7 };
      string actual{dls.plain()};
      Assert::AreEqual( "0202030040567", actual.c_str() );
   }

   TEST_METHOD( plain_with_rgd )
   {
      nhill::uwi::Dls dls{ 2, 2, 3, 4, 5, 6, 7 };
      string actual{dls.plain(true)};
      Assert::AreEqual( "02020300405W67", actual.c_str() );
   }

   TEST_METHOD( full )
   {
      nhill::uwi::Dls dls{ 2, 2, 3, 4, 5, 6, 7 };
      string actual{dls.full()};
      Assert::AreEqual( "102020300405W607", actual.c_str() );
   }

   TEST_METHOD( plain_dressed)
   {
      nhill::uwi::Dls dls{ 2, 2, 3, 4, 5, 6, 7 };
      string actual{dls.plain_dressed()};
      Assert::AreEqual( "02/02-03-004-05W6/7", actual.c_str() );
   }

   TEST_METHOD( full_dressed )
   {
      nhill::uwi::Dls dls{ 2, 2, 3, 4, 5, 6, 7 };
      string actual{dls.full_dressed()};
      Assert::AreEqual( "102/02-03-004-05W6/07", actual.c_str() );
   }


};
}
