#pragma once

#include "port.h"
#include <string>
#include <ostream>
#include <string_view>

namespace nhill
{

class Date;

namespace datenzugriff
{

class Ab_oil_pressure_test;

namespace ab_oil_pressure_test
{

class Key;
class Record;
class Record00;
class Record01;
class Record02;
class Record03;
class Record04;
class Record05;
enum class Record_type;
enum class Test_type;

namespace txt
{


NHILL_DZG_ABOPT_PORT_CFUNCTION bool is_valid( const Date& date );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Date& date );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, std::string_view str, unsigned width );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, double value, unsigned width, unsigned precision, bool is_signed = false );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, int value, unsigned width );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, Record_type record_type );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, Test_type test_type );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, char c );

constexpr const char* const date_format{ "%Y%m%d" };

NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Key& key );

NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Record00& rec );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Record01& rec );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Record02& rec );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Record03& rec );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Record04& rec );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Record05& rec );

NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Key& key, const Record00& rec );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Key& key, const Record01& rec );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Key& key, const Record02& rec );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Key& key, const Record03& rec );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Key& key, const Record04& rec );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Key& key, const Record05& rec );

NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Ab_oil_pressure_test& test );
}
}
}
}