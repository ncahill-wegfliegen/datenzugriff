#pragma once

#include "port.h"
#include "../ab_oil_pressure_test/test_type.h"
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

class NHILL_DZG_ABOPT_MYSQL_PORT_CLASS Mysql
{
public:
   Mysql();
   Mysql( std::string_view  username, std::string_view password );
   ~Mysql();

   bool open_session();
   bool open_session( std::string_view  username, std::string_view password );
   bool is_session_open();
   void close_session();

	bool insert_txt( std::string_view path_in, std::string_view path_log = {} );
	bool insert( const Ab_oil_pressure_test& test );
   bool insert( const Key& key, const Record00& rec00 ); // well name and on production date
   bool insert( const Key& key, const Record01& rec01 ); // licensee and well status
   bool insert( const Key& key, const Record02& rec02 ); // designated field and pool
   bool insert( const Key& key, const Record03& rec03 ); // well data
   bool insert( const Key& key, const Record04& rec04, int index ); // test data. The zero-based index uniquely defines the tests for a well.
   bool insert( const Key& key, const Record05& rec05 ); // remark
	bool insert( std::string_view table, const Key& key, std::string_view columns, std::string_view values );

   std::map<Test_type,std::string> get_test_types(); // key=test type, value=description

	static constexpr char single_quote{ '\'' };
	static constexpr const char* const date_format{ "%Y-%m-%d" };
	static constexpr const char* const schema{ "ab_oil_pressure_test" };

	static bool is_valid( char c );
	static bool is_valid( std::string_view str );
	static bool is_valid( Date date );

	static std::string format( char c); // Format the value for output.
	static std::string format( std::string_view str); // Format the value for output.
	static std::string format( Date date ); // Format the value for output.

	static std::ostream& write_column( std::ostream& out, std::string_view column, char c ); // If the value is valid, then write the column name to the output.
	static std::ostream& write_column( std::ostream& out, std::string_view column, std::string_view str ); // If the value is valid, then write the column name to the output.
	static std::ostream& write_column( std::ostream& out, std::string_view column, const Date& date ); // If the value is valid, then write the column name to the output.
	static std::ostream& write_column( std::ostream& out, std::string_view column, double value ); // If the value is valid, then write the column name to the output.
	static std::ostream& write_column( std::ostream& out, std::string_view column, Test_type test_type); // If the value is valid, then write the column name to the output.
	static std::ostream& write_column( std::ostream& out, std::string_view column, int value ); // If the value is valid, then write the column name to the output.
	static std::ostream& write_key_columns( std::ostream& out, std::string_view table ); // Write the key column names to the output.

	static std::ostream& write( std::ostream& out, char c ); // If the value is valid, then write the value to the output.
	static std::ostream& write( std::ostream& out, std::string_view str ); // If the value is valid, then write the value to the output.
	static std::ostream& write( std::ostream& out, const Date& date ); // If the value is valid, then write the value to the output.
	static std::ostream& write( std::ostream& out, double value ); // If the value is valid, then write the value to the output.
	static std::ostream& write( std::ostream& out, Test_type test_type); // If the value is valid, then write the value to the output.
	static std::ostream& write( std::ostream& out, int value ); // If the value is valid, then write the value to the output.
	static std::ostream& write( std::ostream& out, const Key& key ); // Write the key values to the output.

private:
#pragma warning(push)
#pragma warning(disable:4251)
   std::string username_;
   std::string password_;

   class Session_impl;
   std::unique_ptr<Session_impl> session_impl_;
#pragma warning(pop)
};

}
}
}