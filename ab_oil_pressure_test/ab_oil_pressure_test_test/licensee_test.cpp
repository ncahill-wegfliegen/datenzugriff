#include "pch.h"
#include "CppUnitTest.h"
#include "../ab_oil_pressure_test/licensee.h"
#include "../ab_oil_pressure_test/licensee_index.h"
#include "../ab_oil_pressure_test/licensee_index_facade.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace nhill::datenzugriff::ab_oil_pressure_test;
using namespace nhill::datenzugriff::ab_oil_pressure_test::txt;

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

	TEST_METHOD( build_licensee_index_test )
	{
		std::filesystem::path path_txt{ R"(C:\temp\abopt\oil_pressure_test2019-09-08.txt)" };
		std::filesystem::path path_out{ path_txt.parent_path() };
		path_out /= "licensee.idx";

		bool success{ build_licensee_index( path_out, path_txt ) };
		Assert::IsTrue( success );
	}

	TEST_METHOD( facade_test )
	{
		Licensee_index_facade facade;
		

		Licensee_index lic_idx{ facade.find_by_code( "0LC7" ) };
	}
};
}