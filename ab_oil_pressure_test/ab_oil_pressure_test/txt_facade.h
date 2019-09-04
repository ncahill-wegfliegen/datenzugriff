#pragma once

#include "port.h"
#include "facade_interface.h"

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
namespace txt
{

class NHILL_DZG_ABOPT_PORT_FUNCTION Txt_facade : public Facade_interface
{
public:
	std::list<Ab_oil_pressure_test> find_test_by_uwi( const uwi::Dls& uwi ) final;
	std::list<Ab_oil_pressure_test> find_test_by_licensee_code( const std::string& licensee_code ) final;
	std::list<Ab_oil_pressure_test> find_test_by_field_pool( const std::string& field_code, const std::string& pool_code = {} ) final;
	std::list<Ab_oil_pressure_test> find_test_by_test_type( const std::list<Test_type>& test_types ) final;
};

}
}
}
}