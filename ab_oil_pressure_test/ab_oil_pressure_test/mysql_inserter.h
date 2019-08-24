#pragma once

#include "port.h"
#include "mysql_session.h"
#include <map>
#include <string>
#include <memory>
#include <string_view>
#include <ostream>

namespace nhill { class Date; }

namespace nhill
{
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

class NHILL_DZG_ABOPT_PORT_CLASS Inserter : public Session
{
public:
	using base = Session;

	Inserter();
	Inserter( std::string_view  username, std::string_view password );
	~Inserter();

	bool insert_txt( std::string_view path_in, std::string_view path_log = {} );
	bool insert( const Ab_oil_pressure_test& test );
	bool insert( const Key& key, const Record00& rec00 ); // well name and on production date
	bool insert( const Key& key, const Record01& rec01 ); // licensee and well status
	bool insert( const Key& key, const Record02& rec02 ); // designated field and pool
	bool insert( const Key& key, const Record03& rec03 ); // well data
	bool insert( const Key& key, const Record04& rec04, int index ); // test data. The zero-based index uniquely defines the tests for a well.
	bool insert( const Key& key, const Record05& rec05 ); // remark
	bool insert( std::string_view table, const Key& key, std::string_view columns, std::string_view values );
};

}
}
}
}