#include "pch.h"
#include "CppUnitTest.h"
#include "../ab_oil_pressure_test/test.h"
#include "../ab_oil_pressure_test/txt_facade.h"
#include "../../../gemeinsam/uwi/dls.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace nhill::datenzugriff::ab_oil_pressure_test;
using namespace nhill::uwi;

namespace ab_oil_pressure_test_test
{
TEST_CLASS( Facade_test )
{
public:

   TEST_METHOD( txt_find_by_uwi_test )
   {
      txt::Facade facade;
      Dls dls{ 2, 12, 3, 1, 17, 4, 0 };

      Test_container tests{ facade.find_test_by_uwi( dls ) };
   }
};
}