#include "mysql_read.h"
#include "../ab_oil_pressure_test/test_type_ex.h"
#include "../../../gemeinsam/date_time/date.h"
#include "../../../gemeinsam/enum/core/int.h"
#include <mysqlx/xdevapi.h>

using namespace std;

auto nhill::datenzugriff::ab_oil_pressure_test::mysql::read_date(  const mysqlx::Value& value )->Date
{
	if( value.getType() == mysqlx::Value::Type::VNULL )
	{
		return {};
	}

	try
	{
		time_t  time{ value.get<time_t>() };
		struct tm tm{};
		errno_t err{ ::localtime_s( &tm, &time ) };
		if( err != 0 )
		{
			throw exception{ "Failed to convert the mysqlx Value to a Date." };
		}
		return { tm };
	}
	catch( exception e )
	{
		throw e;
	}
}

string nhill::datenzugriff::ab_oil_pressure_test::mysql::read_string( const mysqlx::Value& value )
{
	if( value.getType() == mysqlx::Value::Type::VNULL )
	{
		return {};
	}

	try
	{
		return value.get<string>();
	}
	catch( exception e )
	{
		throw e;
	}
}

double nhill::datenzugriff::ab_oil_pressure_test::mysql::read_double( const mysqlx::Value& value )
{
	if( value.getType() == mysqlx::Value::Type::VNULL )
	{
		return 0;
	}

	try
	{
		return value.get<double>();
	}
	catch( exception e )
	{
		throw e;
	}
}

auto nhill::datenzugriff::ab_oil_pressure_test::mysql::read_test_type( const mysqlx::Value& value )->Test_type
{
	if( value.getType() == mysqlx::Value::Type::VNULL )
	{
		return {};
	}

	try
	{
		int i{ value.get<int>() };
		return to_enum<Test_type>( i );
	}
	catch( exception e )
	{
		throw e;
	}
}

char nhill::datenzugriff::ab_oil_pressure_test::mysql::read_char( const mysqlx::Value& value )
{
	if( value.getType() == mysqlx::Value::Type::VNULL )
	{
		return '\0';
	}
	
	try
	{
		string s{ value.get<string>() };
		if( s.length() == 0 )
		{
			return '\0';
		}
		else if( s.length() == 1 )
		{
			return s[0];
		}
		else
		{
			throw exception{ string{ "The string '" + s + "' is not a single character." }.c_str() };
		}
	}
	catch( exception e )
	{
		throw e;
	}
}

int nhill::datenzugriff::ab_oil_pressure_test::mysql::read_int( const mysqlx::Value& value )
{
	if( value.getType() == mysqlx::Value::Type::VNULL )
	{
		return 0;
	}

	try
	{
		return value.get<int>();
	}
	catch( exception e )
	{
		throw e;
	}

}
