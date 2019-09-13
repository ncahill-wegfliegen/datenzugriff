#include "pch.h"
#include "CppUnitTest.h"
#include "../ab_oil_pressure_test/licensee.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace nhill::datenzugriff::ab_oil_pressure_test;

namespace ab_oil_pressure_test_test
{
TEST_CLASS( Licensee_test )
{
public:

   TEST_METHOD( io_test )
   {
      Licensee licensee{ "ABCD", "Hoola Hoop, Inc." };

      stringstream ss;
      ss << licensee;

      ss >> licensee;
   }
};
}