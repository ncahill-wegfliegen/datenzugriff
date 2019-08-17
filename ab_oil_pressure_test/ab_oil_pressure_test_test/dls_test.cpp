#include "pch.h"
#include "CppUnitTest.h"
#include "../ab_oil_pressure_test/dls.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ab_oil_pressure_test_test
{
TEST_CLASS( Dls_test )
{
public:

	TEST_METHOD( sort )
	{
		nhill::uwi::Dls dls;

		dls.le ( 1 );
		dls.lsd( 2 );
		dls.sc ( 3 );
		dls.twp( 4 );
		dls.rg ( 5 );
		dls.m  ( 6 );
		dls.es ( 7 );

		string actual{dls.sort()};
		Assert::AreEqual( "0046050302017", actual.c_str() );
	}

	TEST_METHOD( plain_without_rgd )
	{
		nhill::uwi::Dls dls;

		dls.le( 1 );
		dls.lsd( 2 );
		dls.sc( 3 );
		dls.twp( 4 );
		dls.rg( 5 );
		dls.m( 6 );
		dls.es( 7 );

		string actual{dls.plain()};
		Assert::AreEqual( "0102030040567", actual.c_str() );
	}

	TEST_METHOD( plain_with_rgd )
	{
		nhill::uwi::Dls dls;

		dls.le( 1 );
		dls.lsd( 2 );
		dls.sc( 3 );
		dls.twp( 4 );
		dls.rg( 5 );
		dls.m( 6 );
		dls.es( 7 );

		string actual{dls.plain(true)};
		Assert::AreEqual( "01020300405W67", actual.c_str() );
	}

	TEST_METHOD( full )
	{
		nhill::uwi::Dls dls;

		dls.le( 1 );
		dls.lsd( 2 );
		dls.sc( 3 );
		dls.twp( 4 );
		dls.rg( 5 );
		dls.m( 6 );
		dls.es( 7 );

		string actual{dls.full()};
		Assert::AreEqual( "101020300405W607", actual.c_str() );
	}

	TEST_METHOD( plain_dressed)
	{
		nhill::uwi::Dls dls;

		dls.le( 1 );
		dls.lsd( 2 );
		dls.sc( 3 );
		dls.twp( 4 );
		dls.rg( 5 );
		dls.m( 6 );
		dls.es( 7 );

		string actual{dls.plain_dressed()};
		Assert::AreEqual( "01/02-03-004-05W6/7", actual.c_str() );
	}

	TEST_METHOD( full_dressed )
	{
		nhill::uwi::Dls dls;

		dls.le( 1 );
		dls.lsd( 2 );
		dls.sc( 3 );
		dls.twp( 4 );
		dls.rg( 5 );
		dls.m( 6 );
		dls.es( 7 );

		string actual{dls.full_dressed()};
		Assert::AreEqual( "101/02-03-004-05W6/07", actual.c_str() );
	}


};
}
