#include "mysql_facade.h"
#include "mysql_selector.h"
#include "configuration.h"
#include "test.h"

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::mysql::Facade::Facade()
   : selector_{std::make_unique<Selector>(ab_oil_pressure_test::Configuration::instance().mysql)}
{
}

nhill::datenzugriff::ab_oil_pressure_test::mysql::Facade::~Facade()
{
}

auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Facade::find_test_by_uwi( const uwi::Dls& uwi )->Test_container
{
   return Test_container();
}

auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Facade::find_test_by_licensee_code( const std::string& licensee_code )->Test_container
{
   return Test_container();
}

auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Facade::find_test_by_field_pool( const std::string& field_code, const std::string& pool_code )->Test_container
{
   return Test_container();
}

auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Facade::find_test_by_test_type( const std::list<Test_type>& test_types )->Test_container
{
   return Test_container();
}
