#include "pch.h"
#include "CppUnitTest.h"
#include "data.h"
#include "../ab_oil_pressure_test/key.h"
#include "../ab_oil_pressure_test/record00.h"
#include "../ab_oil_pressure_test/txt_read.h"
#include "../ab_oil_pressure_test/txt_forward_list.h"
#include "../ab_oil_pressure_test/mysql_inserter.h"
#include "../ab_oil_pressure_test/mysql_write.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace nhill::datenzugriff::ab_oil_pressure_test;

namespace ab_oil_pressure_test_test
{
TEST_CLASS( My_sql_test )
{
public:

   //TEST_METHOD( test_types )
   //{
   //   Inserter mysql{ "nhill-bemuehen", "piondecay" };
   //   if( !mysql.is_session_open() )
   //   {
   //      Assert::Fail( L"Failed to open the session." );
   //   }
   //   mysql.close_session();
   //   std::map<Test_type, std::string> test_types{ mysql.get_test_types() };
   //}

   TEST_METHOD( write_string )
   {
      const char* const str{ "PENDANT D'OREILLE" };
      const char* const expected{ R"(, 'PENDANT D\'OREILLE')" };

      ostringstream oss;
      mysql::write( oss, str );
      string actual{ oss.str() };
      Assert::AreEqual( expected, actual.c_str() );
   }

   TEST_METHOD( insert_rec00 )
   {
      const char* const str{ "00	00	03	05	001	08	4	0	01	ONEFOUR BLKBT 3-5-1-8               	00000000	" };
      Key key;
      bool success{ txt::read( key, str ) };
      Assert::IsTrue( success, L"Failed to Parse the key." );

      Record00 rec00;
      success = txt::read( rec00, str );
      Assert::IsTrue( success, L"Failed to Parse Record 00." );

      mysql::Inserter mysql{ "nhill-bemuehen", "piondecay", "localhost" };
      if( !mysql.is_open() )
      {
         Assert::Fail( L"Failed to open the session." );
      }
      success = mysql.insert( key, rec00 );
      mysql.close();
      Assert::IsTrue( success, L"Failed to insert." );
   }

   TEST_METHOD( insert_rec01 )
   {
      //const char* const str0{ "00	00	03	05	001	08	4	0	01	ONEFOUR BLKBT 3-5-1-8               	00000000	" };
      const char* const str1{ "01	00	03	05	001	08	4	0	01	A2TG 	TQN           	A5RX	BEC           	20150401	0111000000	" };
      Key key;
      bool success{ txt::read( key, str1 ) };
      Assert::IsTrue( success, L"Failed to Parse the key." );

      //Record00 rec00;
      //success = txt::read( rec00, str0 );
      //Assert::IsTrue( success, L"Failed to Parse Record 00." );

      Record01 rec01;
      success = txt::read( rec01, str1 );
      Assert::IsTrue( success, L"Failed to Parse Record 01." );

      mysql::Inserter mysql{ "nhill-bemuehen", "piondecay", "localhost" };
      //success = mysql.insert( key, rec00 );
      //Assert::IsTrue( success, L"Failed to insert Record 00." );

      success = mysql.insert( key, rec01 );
      Assert::IsTrue( success, L"Failed to insert Record 01." );

   }

   TEST_METHOD( insert_rec02 )
   {
      const char* const str{ "02	00	03	05	001	08	4	0	01	ADEN                	                     	" };
      Key key;
      bool success{ txt::read( key, str ) };
      Assert::IsTrue( success, L"Failed to Parse the key." );

      Record02 rec;
      success = txt::read( rec, str );
      Assert::IsTrue( success, L"Failed to Parse Record." );

      mysql::Inserter mysql{ "nhill-bemuehen", "piondecay", "localhost" };
      success = mysql.insert( key, rec );
      Assert::IsTrue( success, L"Failed to insert Record." );

   }

   TEST_METHOD( insert_rec03 )
   {
      const char* const str{ "03	00	03	05	001	08	4	0	01	0014	0310008	0936.50	0940.00	1041.20	 0102.25	1037.60	0935.35	07538	08.729	" };
      Key key;
      bool success{ txt::read( key, str ) };
      Assert::IsTrue( success, L"Failed to Parse the key." );

      Record03 rec;
      success = txt::read( rec, str );
      Assert::IsTrue( success, L"Failed to Parse Record." );

      mysql::Inserter mysql{ "nhill-bemuehen", "piondecay", "localhost" };
      success = mysql.insert( key, rec );
      Assert::IsTrue( success, L"Failed to insert Record." );

   }

   TEST_METHOD( insert_rec05 )
   {
      const char* const str{ "05	00	03	05	001	08	4	0	01	01	INITIAL SHUT-IN.                                  	" };
      Key key;
      bool success{ txt::read( key, str ) };
      Assert::IsTrue( success, L"Failed to Parse the key." );

      Record05 rec;
      success = txt::read( rec, str );
      Assert::IsTrue( success, L"Failed to Parse Record." );

      mysql::Inserter mysql{ "nhill-bemuehen", "piondecay", "localhost" };
      success = mysql.insert( key, rec );
      Assert::IsTrue( success, L"Failed to insert Record." );

   }

   TEST_METHOD( insert_rec04 )
   {
      const char* const str{ "04	00	03	05	001	08	4	0	01	19970627	03	19970620	0007000000	000000.00	0935.50	0931.00	08.500	006672.00	036.00	0000.00	0483.90	00.000	00.000	00.000	006710.00	000000.00	 	000000.00	000000.00	000000.0	01	" };
      Key key;
      bool success{ txt::read( key, str ) };
      Assert::IsTrue( success, L"Failed to Parse the key." );

      Record04 rec;
      success = txt::read( rec, str );
      Assert::IsTrue( success, L"Failed to Parse Record." );

      mysql::Inserter mysql{ "nhill-bemuehen", "piondecay", "localhost" };
      success = mysql.insert( key, rec, 0 );
      Assert::IsTrue( success, L"Failed to insert Record." );
   }

   TEST_METHOD( insert_test )
   {
      txt::Forward_list parser( R"(..\..\..\ab_oil_pressure_test\ab_oil_pressure_test_test\data\ab_oil_pressure_test.txt)" );

      mysql::Inserter mysql{ "nhill-bemuehen", "piondecay", "localhost" };

      bool success{ mysql.insert( *parser.cbegin() ) };
      Assert::IsTrue( success, L"Failed to insert the test." );
   }

   TEST_METHOD( insert_txt )
   {
      string path_in( R"(..\..\..\ab_oil_pressure_test\ab_oil_pressure_test_test\data\oil_pressure_test2019-09-08.log)" );
      string path_log( R"(c:\temp\log.txt)" );

      mysql::Inserter mysql{ "nhill-bemuehen", "piondecay", "localhost" };

      bool success{ mysql.insert_txt( path_in, path_log ) };
      Assert::IsTrue( success, L"Failed to insert the test." );
   }

   TEST_METHOD( insert_00_13_03_001_16W4_2_01 )
   {
      string path_in( R"(..\..\..\ab_oil_pressure_test\ab_oil_pressure_test_test\data\00_13-03-001-16W4_2_01.txt)" );
      string path_log( R"(c:\temp\log2.txt)" );

      mysql::Inserter mysql{ "nhill-bemuehen", "piondecay", "localhost" };

      bool success{ mysql.insert_txt( path_in, path_log ) };
      Assert::IsTrue( success, L"Failed to insert the test." );
   }

   TEST_METHOD( insert_04_06_15_001_16W4_0 )
   {
      string path_in( R"(..\..\..\ab_oil_pressure_test\ab_oil_pressure_test_test\data\04_06_15_001_16W4_0.txt)" );
      string path_log( R"(c:\temp\04_06_15_001_16W4_0.log)" );

      mysql::Inserter mysql{ "nhill-bemuehen", "piondecay", "localhost" };

      bool success{ mysql.insert_txt( path_in, path_log ) };
      Assert::IsTrue( success, L"Failed to insert the test." );
   }

   TEST_METHOD( insert_full )
   {
      string path_in( R"(..\..\..\..\..\daten\petroleum\AB\oil_pressure_test\oil_pressure_test2019-09-08.txt)" );
      string path_log( R"(..\..\..\ab_oil_pressure_test\ab_oil_pressure_test_test\data\oil_pressure_test2019-09-08.log)" );

      mysql::Inserter mysql{ "nhill-bemuehen", "piondecay", "localhost" };

      bool success{ mysql.insert_txt( path_in, path_log ) };
      Assert::IsTrue( success, L"Failed to insert the test." );
   }

   TEST_METHOD( insert_partial)
   {
      string path_in ( R"(..\..\..\ab_oil_pressure_test\ab_oil_pressure_test_test\data\ab_oil_pressure_test.txt)" );
      string path_log( R"(..\..\..\ab_oil_pressure_test\ab_oil_pressure_test_test\data\ab_oil_pressure_test.log)" );

      mysql::Inserter mysql{ "nhill-bemuehen", "piondecay", "localhost" };

      bool success{ mysql.insert_txt( path_in, path_log ) };
      Assert::IsTrue( success, L"Failed to insert the test." );
   }


};
}
