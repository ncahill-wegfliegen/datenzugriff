#include "txt_facade.h"
#include "ab_oil_pressure_test.h"

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_facade::
find_test_by_uwi( const uwi::Dls& uwi )->std::list<Ab_oil_pressure_test>
{
	return std::list<Ab_oil_pressure_test>();
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_facade::
find_test_by_licensee_code( const std::string& licensee_code )->std::list<Ab_oil_pressure_test>
{
	return std::list<Ab_oil_pressure_test>();
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_facade::
find_test_by_field_pool( const std::string& field_code, const std::string& pool_code )->std::list<Ab_oil_pressure_test>
{
	return std::list<Ab_oil_pressure_test>();
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_facade::
find_test_by_test_type( const std::list<Test_type>& test_types )->std::list<Ab_oil_pressure_test>
{
	return std::list<Ab_oil_pressure_test>();
}
