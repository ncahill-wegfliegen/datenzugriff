#include "pch.h"
#include "CppUnitTest.h"
#include "../ab_oil_pressure_test/field_index.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace nhill::datenzugriff::ab_oil_pressure_test;
using namespace nhill::datenzugriff::ab_oil_pressure_test::txt;

namespace ab_oil_pressure_test_test
{
TEST_CLASS( Field_index_test )
{
public:

	TEST_METHOD( build_field_index_test )
	{
		std::filesystem::path path_txt{ R"(C:\temp\abopt\oil_pressure_test2019-09-08.txt)" };
		std::filesystem::path path_out{ path_txt.parent_path() };
		path_out /= "field.idx";

		bool success{ build_field_index( path_out, path_txt ) };
		Assert::IsTrue( success );
	}

};
}