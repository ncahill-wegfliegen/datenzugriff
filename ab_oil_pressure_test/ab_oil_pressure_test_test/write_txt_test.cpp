#include "pch.h"
#include "CppUnitTest.h"
#include "../ab_oil_pressure_test/key.h"
#include "../ab_oil_pressure_test/record00.h"
#include "../ab_oil_pressure_test/record01.h"
#include "../ab_oil_pressure_test/record02.h"
#include "../ab_oil_pressure_test/record03.h"
#include "../ab_oil_pressure_test/record04.h"
#include "../ab_oil_pressure_test/record05.h"
#include "../ab_oil_pressure_test/txt_read.h"
#include "../ab_oil_pressure_test/txt_parser.h"
#include "../ab_oil_pressure_test/txt_write.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace nhill::datenzugriff::ab_oil_pressure_test;

namespace ab_oil_pressure_test_test
{
TEST_CLASS( Write_txt_test )
{
public:

   TEST_METHOD( write_rec00 )
   {
      const char* const str{ "00	00	03	05	001	08	4	0	01	ONEFOUR BLKBT 3-5-1-8               	00000000	" };
      Key key;
      bool success{ txt::read( key, str ) };
      Assert::IsTrue( success, L"Failed to parse the key." );

      Record00 rec00;
      success = txt::read( rec00, str );
      Assert::IsTrue( success, L"Failed to parse Record." );

      const char* const path_out{ R"(c:\temp\rec00.txt)" };
      ofstream out{ path_out };
      out << rec00;
      out.close();
   }

   TEST_METHOD( write_rec03 )
   {
      const char* const str{ "03	00	03	05	001	08	4	0	01	0014	0000000	0295.00	0310.29	1101.50	 0000.00	1097.80	0000.00	00000	00.000	" };
      Key key;
      bool success{ txt::read( key, str ) };
      Assert::IsTrue( success, L"Failed to parse the key." );

      Record03 rec;
      success = txt::read( rec, str );
      Assert::IsTrue( success, L"Failed to parse Record." );

      const char* const path_out{ R"(c:\temp\rec03.txt)" };
      ofstream out{ path_out };
      txt::write( out, rec );
      out.close();
   }

   TEST_METHOD( write_11_tests )
   {
      const char* const path_in { R"(..\..\..\ab_oil_pressure_test\ab_oil_pressure_test_test\data\11_tests.txt)"     };
      const char* const path_out{ R"(..\..\..\ab_oil_pressure_test\ab_oil_pressure_test_test\data\11_tests_out.txt)" };

      txt::Txt_parser parser{ path_in };
      ofstream out{ path_out };

      for( const auto& test : parser )
      {
         txt::write( out, test );
      }

      out.close();
   }
};
}