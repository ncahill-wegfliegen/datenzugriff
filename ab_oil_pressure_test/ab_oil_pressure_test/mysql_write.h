#pragma once

#include "port.h"
#include <string_view>
#include <ostream>
#include <string>

namespace nhill
{
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

constexpr char single_quote{ '\'' };
constexpr const char* const date_format{ "%Y-%m-%d" };
constexpr const char* const schema{ "ab_oil_pressure_test" };

NHILL_DZG_ABOPT_PORT_FUNCTION bool is_valid( char c );
NHILL_DZG_ABOPT_PORT_FUNCTION bool is_valid( std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool is_valid( Date date );

//NHILL_DZG_ABOPT_PORT_FUNCTION std::string format( char c ); // Format the value for output.
//NHILL_DZG_ABOPT_PORT_FUNCTION std::string format( std::string_view str ); // Format the value for output.
//NHILL_DZG_ABOPT_PORT_FUNCTION std::string format( Date date ); // Format the value for output.

NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write_column( std::ostream& out, std::string_view column, char c ); // If the value is valid, then write the column name to the output.
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write_column( std::ostream& out, std::string_view column, std::string_view str ); // If the value is valid, then write the column name to the output.
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write_column( std::ostream& out, std::string_view column, const Date& date ); // If the value is valid, then write the column name to the output.
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write_column( std::ostream& out, std::string_view column, double value ); // If the value is valid, then write the column name to the output.
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write_column( std::ostream& out, std::string_view column, Test_type test_type ); // If the value is valid, then write the column name to the output.
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write_column( std::ostream& out, std::string_view column, int value ); // If the value is valid, then write the column name to the output.
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write_key_columns( std::ostream& out, std::string_view table ); // Write the key column names to the output.

NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, char c ); // If the value is valid, then write the value to the output.
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, std::string str ); // If the value is valid, then write the value to the output.
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Date& date ); // If the value is valid, then write the value to the output.
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, double value ); // If the value is valid, then write the value to the output.
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, Test_type test_type ); // If the value is valid, then write the value to the output.
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, int value ); // If the value is valid, then write the value to the output.
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& write( std::ostream& out, const Key& key ); // Write the key values to the output.

}
}
}
}

