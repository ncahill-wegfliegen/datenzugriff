#include "pch.h"
#include "CppUnitTest.h"
#include "data.h"
#include "../ab_oil_pressure_test/key.h"
#include "../ab_oil_pressure_test/record00.h"
#include "../ab_oil_pressure_test/record01.h"
#include "../ab_oil_pressure_test/record02.h"
#include "../ab_oil_pressure_test/record03.h"
#include "../ab_oil_pressure_test/record04.h"
#include "../ab_oil_pressure_test/record05.h"
#include "../ab_oil_pressure_test/txt_read.h"
#include "../ab_oil_pressure_test/txt_forward_list.h"
#include "../ab_oil_pressure_test/test.h"
#include <fstream>
#include <windows.h>
#include <filesystem>

#include <iomanip>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nhill::datenzugriff::ab_oil_pressure_test;
using namespace nhill::datenzugriff;
using namespace std;
using namespace std::filesystem;

namespace ab_oil_pressure_test_test
{
TEST_CLASS( Read_txt_test )
{
public:

   TEST_METHOD( readkey )
   {
      const char* const str{"00	00	03	05	001	08	4	0	01	ONEFOUR BLKBT 3-5-1-8               	00000000	"};
      Key key;
      bool success{txt::read( key, str )};
      Assert::IsTrue( success, L"Failed to read the key." );
   }


   TEST_METHOD( read00 )
   {
      const char* const str{"00	00	03	05	001	08	4	0	01	ONEFOUR BLKBT 3-5-1-8               	00000000	"};
      Record00 rec;
      bool success{txt::read( rec, str )};
      Assert::IsTrue( success, L"Failed to read Record 00." );
   }

   TEST_METHOD( read01 )
   {
      const char* const str{"01	00	03	05	001	08	4	0	01	A1EZ 	FIRENZE       	    	              	20060120	0002000000\t"};
      Record01 rec;
      bool success{txt::read( rec, str )};
      Assert::IsTrue( success, L"Failed to read Record 01." );
   }

   TEST_METHOD( read02 )
   {
      const char* const str{"02	00	09	20	001	08	4	0	01	ADEN                	LOWER MANNVILLE H    	"};
      Record02 rec;
      bool success{txt::read( rec, str )};
      Assert::IsTrue( success, L"Failed to read Record 02." );
   }

   TEST_METHOD( read03 )
   {
      const char* const str{"03	00	09	20	001	08	4	0	01	0014	0310008	0936.50	0940.00	1041.20	 0102.25	1037.60	0935.35	07538	08.729	"};
      Record03 rec;
      bool success{txt::read( rec, str )};
      Assert::IsTrue( success, L"Failed to read Record 03." );
   }

   TEST_METHOD( read04 )
   {
      const char* const str{"04	00	09	20	001	08	4	0	01	19910301	11	19900105	0111000000	002533.00	0934.65	0000.00	00.000	000000.00	036.00	0666.00	0666.00	00.197	08.670	09.795	005026.00	005122.00	R	007560.00	007656.00	000171.0	01	"};
      Record04 rec;
      bool success{txt::read( rec, str )};
      Assert::IsTrue( success, L"Failed to read Record 04." );
   }

   TEST_METHOD( read05 )
   {
      const char* const str{"05	02	15	20	001	08	4	0	01	01	INITIAL SHUT-IN.                                  	"};
      Record05 rec;
      bool success{txt::read( rec, str )};
      Assert::IsTrue( success, L"Failed to read Record 04." );
   }

   TEST_METHOD( read_test )
   {
      ifstream in{ get_path("ab_oil_pressure_test.txt")};
      Assert::IsTrue( in.is_open(), L"Failed to open the data file." );

      Test test1;
      txt::read( test1, in );

      Test test2;
      txt::read( test2, in );

      in.close();
   }

   TEST_METHOD( range_test )
   {
      txt::Forward_list readr{get_path( "ab_oil_pressure_test.txt" )};
      for( const auto& test : readr )
      {
         Key key{test.key};
      }

      for( const auto& test : readr )
      {
         Key key{test.key};
      }
   }
};
}
