#pragma once

#include "port.h"
#include "mysql_session.h"
#include <map>
#include <string>
#include <memory>
#include <string_view>
#include <ostream>
#include <vector>


namespace nhill
{
namespace uwi
{
class Dls;
}

class Date;

namespace datenzugriff
{
class Ab_oil_pressure_test;

namespace ab_oil_pressure_test
{

class Key;
class Record00;
class Record01;
class Record02;
class Record03;
class Record04;
class Record05;
enum class Test_type;

namespace mysql
{

class NHILL_DZG_ABOPT_PORT_CLASS Selector : public Session
{
public:
	using base = Session;

	Selector();
	Selector( std::string_view  username, std::string_view password );
	~Selector();

	bool find( Ab_oil_pressure_test& test, const Key& key );
	bool find( std::vector<Ab_oil_pressure_test>& tests, const uwi::Dls& uwi );
	bool find( std::vector<Ab_oil_pressure_test>& tests, std::string_view field_code, std::string_view pool_code );
	bool find( std::vector<Ab_oil_pressure_test>& tests, std::string_view licensee_code );


};

}
}
}
}