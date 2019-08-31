#pragma once

#include "port.h"
#include <string>

namespace mysqlx
{
inline namespace abi2
{
inline namespace r0
{
class Value;
}
}
}

namespace nhill
{
class Date;

namespace datenzugriff
{
namespace ab_oil_pressure_test
{
enum class Test_type;

namespace mysql
{

NHILL_DZG_ABOPT_PORT_FUNCTION Date read_date( const mysqlx::Value& value );
NHILL_DZG_ABOPT_PORT_FUNCTION std::string read_string( const mysqlx::Value& value );
NHILL_DZG_ABOPT_PORT_FUNCTION double read_double( const mysqlx::Value& value );
NHILL_DZG_ABOPT_PORT_FUNCTION Test_type read_test_type( const mysqlx::Value& value );
NHILL_DZG_ABOPT_PORT_FUNCTION char read_char( const mysqlx::Value& value );
NHILL_DZG_ABOPT_PORT_FUNCTION int read_int( const mysqlx::Value& value );


}
}
}
}

