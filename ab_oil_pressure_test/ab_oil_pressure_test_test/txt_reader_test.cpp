#include "pch.h"
#include "CppUnitTest.h"
#include "data.h"
#include "../ab_oil_pressure_test/key.h"
#include "../../../gemeinsam/uwi/dls.h"
#include "../ab_oil_pressure_test/txt_reader.h"
#include "../ab_oil_pressure_test/ab_oil_pressure_test.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace nhill::datenzugriff;
using namespace nhill::datenzugriff::ab_oil_pressure_test;

namespace ab_oil_pressure_test_test
{
TEST_CLASS( Txt_reader_test )
{
public:

	TEST_METHOD( find_by_key )
	{
		std::filesystem::path path{ get_path( "ab_oil_pressure_test.txt" ) };
		txt::Reader reader{ path };

		Key key;
		key.uwi.le( "F1" );
		key.uwi.lsd( 13 );
		key.uwi.sc( 3 );
		key.uwi.twp( 1 );
		key.uwi.rg( 17 );
		key.uwi.m( 4 );
		key.uwi.es( 0 );
		key.consol_interval_num = 1;

		Ab_oil_pressure_test test;
		bool actual{ reader.find( test, key ) };
		Assert::IsTrue( actual );
	}

	TEST_METHOD( find_by_uwi )
	{
		std::filesystem::path path{ get_path( "ab_oil_pressure_test.txt" ) };
		txt::Reader reader{ path };

		nhill::uwi::Dls uwi;
		uwi.le( 0 );
		uwi.lsd( 12 );
		uwi.sc( 3 );
		uwi.twp( 1 );
		uwi.rg( 17 );
		uwi.m( 4 );
		uwi.es( 0 );

		vector<Ab_oil_pressure_test> test;
		bool actual{ reader.find( test, uwi ) };
		Assert::IsTrue( actual, L"Failed to find the records." );
		Assert::AreEqual( static_cast<size_t>(3), test.size(), L"Failed to find all of the tests." );
	}

	TEST_METHOD( find_by_field )
	{
		std::filesystem::path path{ get_path( "ab_oil_pressure_test.txt" ) };
		txt::Reader reader{ path };

		const char* const field_code{ "0260" };
		const char* const pool_code{ "" };

		vector<Ab_oil_pressure_test> test;
		bool actual{ reader.find( test, field_code, pool_code ) };
		Assert::IsTrue( actual, L"Failed to find the records." );
		Assert::AreEqual( static_cast<size_t>(95), test.size(), L"Failed to find all of the tests." );
	}


};
}
