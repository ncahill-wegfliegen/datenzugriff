#pragma once

#include "port.h"
#include <list>
#include <string>

#pragma region Forward Declarations
namespace nhill
{
namespace uwi
{
class Dls;
}
namespace datenzugriff
{
class Ab_oil_pressure_test;
namespace ab_oil_pressure_test
{
enum class Test_type;
}
}
}
#pragma endregion

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Facade_interface
{
public:
	Facade_interface();
	~Facade_interface();

	virtual std::list<Ab_oil_pressure_test> find_test_by_uwi( const uwi::Dls& uwi ) = 0;
	virtual std::list<Ab_oil_pressure_test> find_test_by_licensee_code( const std::string& licensee_code ) = 0;
	virtual std::list<Ab_oil_pressure_test> find_test_by_field_pool( const std::string& field_code, const std::string& pool_code = {} ) = 0;
	virtual std::list<Ab_oil_pressure_test> find_test_by_test_type( const std::list<Test_type>& test_types ) = 0;
};

}
}
}