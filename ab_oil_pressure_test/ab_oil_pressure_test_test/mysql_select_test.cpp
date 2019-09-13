#include "pch.h"
#include "CppUnitTest.h"
#include "../../../gemeinsam/uwi/dls.h"
#include "../ab_oil_pressure_test/key.h"
#include "../ab_oil_pressure_test/mysql_selector.h"
#include "../ab_oil_pressure_test/test.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace nhill;
using namespace nhill::uwi;
using namespace nhill::uwi::dls;
using namespace nhill::datenzugriff;
using namespace nhill::datenzugriff::ab_oil_pressure_test;

namespace ab_oil_pressure_test_test
{
TEST_CLASS( Mysql_select_test )
{
public:

   TEST_METHOD( find_test )
   {
      Key key{ {0, 1, 1, 11, 16, 4, 0}, 1 };

      mysql::Selector select{ "nhill-bemuehen", "piondecay", "localhost" };

      try
      {
         Test test{ select.find_test( key ) };
         Assert::IsTrue( true );
      }
      catch( exception e )
      {
         string s{ e.what() };
         Assert::Fail( wstring{ s.cbegin(), s.cend() }.c_str() );
      }
   }

   TEST_METHOD( find_tests_by_uwi )
   {
      Dls uwi{0, 1, 1, 11, 16, 4, 0};

      mysql::Selector select{ "nhill-bemuehen", "piondecay", "localhost" };

      try
      {
         Key_container keys{ select.find_key_by_uwi( uwi ) };
         Test_container tests{ select.find_test( keys ) };
         Assert::IsTrue( true );
      }
      catch( exception e )
      {
         string s{ e.what() };
         Assert::Fail( wstring{ s.cbegin(), s.cend() }.c_str() );
      }
   }

   TEST_METHOD( find_key_by_licensee_code )
   {
      const char* const licensee_code{ "A6D5" };
      mysql::Selector select{ "nhill-bemuehen", "piondecay", "localhost" };

      try
      {
         Key_container keys{ select.find_key_by_licensee_code( licensee_code ) };
         Assert::AreEqual( static_cast<size_t>(420), keys.size() );
      }
      catch( exception e )
      {
         string s{ e.what() };
         Assert::Fail( wstring{ s.cbegin(), s.cend() }.c_str() );
      }
   }

   TEST_METHOD( find_key_by_field_pool )
   {
      const char* const field_code{ "0595" };
      const char* const pool_code{ "0332037" };
      mysql::Selector select{ "nhill-bemuehen", "piondecay", "localhost" };

      try
      {
         Key_container keys{ select.find_key_by_field_pool( field_code, pool_code ) };
         Assert::AreEqual( static_cast<size_t>(48), keys.size() );
      }
      catch( exception e )
      {
         string s{ e.what() };
         Assert::Fail( wstring{ s.cbegin(), s.cend() }.c_str() );
      }
   }

   TEST_METHOD( find_key_by_test_type)
   {
      list<Test_type> test_types{ Test_type::top_hole_undefined, Test_type::top_hole_buildup };
      mysql::Selector select{ "nhill-bemuehen", "piondecay", "localhost" };

      try
      {
         Key_container keys{ select.find_key_by_test_type( test_types ) };
         Assert::AreEqual( static_cast<size_t>(717), keys.size() );
      }
      catch( exception e )
      {
         string s{ e.what() };
         Assert::Fail( wstring{ s.cbegin(), s.cend() }.c_str() );
      }
   }

   TEST_METHOD( find_tests_by_licensee_code )
   {
      const char* const licensee_code{ "A6D5" };
      mysql::Selector select{ "nhill-bemuehen", "piondecay", "localhost" };

      try
      {
         Key_container keys{ select.find_key_by_licensee_code( licensee_code ) };
         Test_container tests{ select.find_test( keys ) };
         Assert::AreEqual( static_cast<size_t>(420), tests.size() );
      }
      catch( exception e )
      {
         string s{ e.what() };
         Assert::Fail( wstring{ s.cbegin(), s.cend() }.c_str() );
      }
   }



   TEST_METHOD( find_consol_interval_nums_by_uwi )
   {
      Dls uwi{ 0, 9, 4, 1, 17, 4, 0 };

      mysql::Selector select{ "nhill-bemuehen", "piondecay", "localhost" };

      unsigned consol_interval_nums{  select.count_consol_interval_num( uwi ) };
      Assert::AreEqual( 2U, consol_interval_nums );
   }

   TEST_METHOD( find_rec00_by_key )
   {
      Key key{ {0, 1, 5, 1, 9, 4, 2}, 1 };

      mysql::Selector select{ "nhill-bemuehen", "piondecay", "localhost" };

      try
      {
         Record00 rec{ select.find_rec<Record00>( key ) };
         Assert::IsTrue( true );
      }
      catch( exception e )
      {
         string s{ e.what() };
         Assert::Fail( wstring{ s.cbegin(), s.cend() }.c_str() );
      }
   }

   TEST_METHOD( find_rec01_by_key )
   {
      Key key{ {0, 1, 5, 1, 9, 4, 2}, 1 };

      mysql::Selector select{ "nhill-bemuehen", "piondecay", "localhost" };

      try
      {
         Record01 rec{ select.find_rec<Record01>( key ) };
         Assert::IsTrue( true );
      }
      catch( exception e )
      {
         string s{ e.what() };
         Assert::Fail( wstring{ s.cbegin(), s.cend() }.c_str() );
      }
   }

   TEST_METHOD( find_rec02_by_key )
   {
      Key key{ {0, 1, 5, 1, 9, 4, 2}, 1 };

      mysql::Selector select{ "nhill-bemuehen", "piondecay", "localhost" };

      try
      {
         Record02 rec{ select.find_rec<Record02>( key ) };
         Assert::IsTrue( true );
      }
      catch( exception e )
      {
         string s{ e.what() };
         Assert::Fail( wstring{ s.cbegin(), s.cend() }.c_str() );
      }
   }

   TEST_METHOD( find_rec03_by_key )
   {
      Key key{ {0, 1, 5, 1, 9, 4, 2}, 1 };

      mysql::Selector select{ "nhill-bemuehen", "piondecay", "localhost" };

      try
      {
         Record03 rec{ select.find_rec<Record03>( key ) };
         Assert::IsTrue( true );
      }
      catch( exception e )
      {
         string s{ e.what() };
         Assert::Fail( wstring{ s.cbegin(), s.cend() }.c_str() );
      }
   }

};
}