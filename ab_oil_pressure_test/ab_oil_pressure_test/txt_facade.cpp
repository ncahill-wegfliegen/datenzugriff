#include "txt_facade.h"
#include "txt_reader.h"
#include "test.h"
#include "configuration.h"

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::txt::Facade::Facade()
   : reader_{std::make_unique<Reader>( ab_oil_pressure_test::Configuration::instance().txt.path )}
{
}

nhill::datenzugriff::ab_oil_pressure_test::txt::Facade::~Facade() = default;

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Facade::
find_test_by_uwi( const uwi::Dls& uwi )->Test_container
{
   Test_container tests;

   reader_->open();
   reader_->find( tests, uwi );
   reader_->close();
   
   return tests;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Facade::
find_test_by_licensee_code( const std::string& licensee_code )->Test_container
{
   Test_container tests;

   reader_->open();
   reader_->find( tests, licensee_code );
   reader_->close();

   return tests;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Facade::
find_test_by_field_pool( const std::string& field_code, const std::string& pool_code )->Test_container
{
   Test_container tests;

   reader_->open();
   reader_->find( tests, field_code, pool_code );
   reader_->close();

   return tests;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Facade::
find_test_by_test_type( const std::list<Test_type>& test_types )->Test_container
{
   Test_container tests;

   reader_->open();
   reader_->find( tests, test_types );
   reader_->close();

   return tests;
}
