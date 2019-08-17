#include "pch.h"
#include "CppUnitTest.h"
#include "../ab_oil_pressure_test/key.h"
#include "../ab_oil_pressure_test/record00.h"
#include "../ab_oil_pressure_test/record01.h"
#include "../ab_oil_pressure_test/record02.h"
#include "../ab_oil_pressure_test/record03.h"
#include "../ab_oil_pressure_test/record04.h"
#include "../ab_oil_pressure_test/record05.h"
#include "../ab_oil_pressure_test/parse_txt.h"
#include "../ab_oil_pressure_test/ab_oil_pressure_test.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::datenzugriff::ab_oil_pressure_test;
using namespace nhill::datenzugriff;
using namespace std;

namespace ab_oil_pressure_test_test
{
TEST_CLASS( Parse_txt_test )
{
public:

	TEST_METHOD( parsekey )
	{
		const char* const str{"00	00	03	05	001	08	4	0	01	ONEFOUR BLKBT 3-5-1-8               	00000000	"};
		Key key;
		bool success{parse_txt( key, str )};
		Assert::IsTrue( success, L"Failed to parse the key." );
	}


   TEST_METHOD( parse00 )
   {
      const char* const str{"00	00	03	05	001	08	4	0	01	ONEFOUR BLKBT 3-5-1-8               	00000000	"};
      Record00 rec;
      bool success{parse_txt( rec, str )};
      Assert::IsTrue( success, L"Failed to parse Record 00." );
   }

   TEST_METHOD( parse01 )
   {
      const char* const str{"01	00	03	05	001	08	4	0	01	A1EZ 	FIRENZE       	    	              	20060120	0002000000\t"};
      Record01 rec;
      bool success{parse_txt( rec, str )};
      Assert::IsTrue( success, L"Failed to parse Record 01." );
   }

   TEST_METHOD( parse02 )
   {
      const char* const str{"02	00	09	20	001	08	4	0	01	ADEN                	LOWER MANNVILLE H    	"};
      Record02 rec;
      bool success{parse_txt( rec, str )};
      Assert::IsTrue( success, L"Failed to parse Record 02." );
   }

	TEST_METHOD( parse03 )
	{
		const char* const str{"03	00	09	20	001	08	4	0	01	0014	0310008	0936.50	0940.00	1041.20	 0102.25	1037.60	0935.35	07538	08.729	"};
		Record03 rec;
		bool success{parse_txt( rec, str )};
		Assert::IsTrue( success, L"Failed to parse Record 03." );
	}

	TEST_METHOD( parse04 )
	{
		const char* const str{"04	00	09	20	001	08	4	0	01	19910301	11	19900105	0111000000	002533.00	0934.65	0000.00	00.000	000000.00	036.00	0666.00	0666.00	00.197	08.670	09.795	005026.00	005122.00	R	007560.00	007656.00	000171.0	01	"};
		Record04 rec;
		bool success{parse_txt( rec, str )};
		Assert::IsTrue( success, L"Failed to parse Record 04." );
	}

	TEST_METHOD( parse05 )
	{
		const char* const str{"05	02	15	20	001	08	4	0	01	01	INITIAL SHUT-IN.                                  	"};
		Record05 rec;
		bool success{parse_txt( rec, str )};
		Assert::IsTrue( success, L"Failed to parse Record 04." );
	}

   TEST_METHOD( parse_two_tests )
   {
      std::ifstream in{"(oil_pressure_test_data.txt)"};
      Assert::IsTrue( in.is_open(), L"Faile to open the data file." );

      Ab_oil_pressure_test test1;
      bool success{parse_txt( test1, in )};

      Ab_oil_pressure_test test2;
      success = parse_txt( test2, in );


      in.close();

   }


};
}
