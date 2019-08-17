#include "pch.h"
#include "CppUnitTest.h"
#include "data.h"
#include "../ab_oil_pressure_test/const_iterator_txt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ab_oil_pressure_test_test
{
TEST_CLASS( Const_iterator_test )
{
public:

   TEST_METHOD( pre_increment )
   {
      std::ifstream in{get_path("AB_oil_pressure_test.txt")};
      Assert::IsTrue( in.is_open(), L"Failed to open the data file." );

      nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_txt itr{in};
      ++itr;
   }


};
}
