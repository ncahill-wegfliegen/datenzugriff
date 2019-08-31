#include "mysql_write.h"
#include "ab_oil_pressure_test.h"
#include "key.h"
#include "record00.h"
#include "record01.h"
#include "record02.h"
#include "record03.h"
#include "record04.h"
#include "record05.h"
#include "../../../gemeinsam/date_time/date.h"
#include "../../../gemeinsam/enum/core/int.h"

using namespace std;

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::is_valid( char c )
{
   return c != '\0';
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::is_valid( std::string_view str )
{
   return !str.empty();
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::is_valid( Date date )
{
   return date.year().value() != 1;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write_column( ostream& out, string_view column, char c )
{
   if( is_valid( c ) )
   {
      out << ", " << column;
   }
   return out;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write_column( ostream& out, string_view column, string_view str )
{
   if( is_valid( str ) )
   {
      out << ", " << column;
   }
   return out;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write_column( ostream& out, string_view column, const Date& date )
{
   if( is_valid( date ) )
   {
      out << ", " << column;
   }
   return out;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write_column( ostream& out, string_view column, double value )
{
   return out << ", " << column;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write_column( ostream& out, string_view column, Test_type test_type )
{
   return out << ", " << column;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write_column( ostream& out, string_view column, int value )
{
   return out << ", " << column;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write_key_columns( ostream& out, std::string_view table_name )
{
   // NOTE: 'range' is a reserved keyword in MySQL, 
   // so it must qualified by the table name 
   // in order to use it as a column name.

   out << "location_exception";
   out << ", legal_subdivision";
   out << ", section";
   out << ", township";
   out << ", " << table_name << ".range";
   out << ", meridian";
   out << ", event_sequence";
   out << ", consol_interval_num";

   return out;
}

std::ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write( std::ostream& out, char c )
{
   if( is_valid( c ) )
   {
      char s[2]{ c };
      write( out, s );
   }
   return out;
}

std::ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write( std::ostream& out, std::string str )
{
   if( is_valid( str ) )
   {
      out << ", " << quoted( str, single_quote );
   }
   return out;
}

std::ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write( std::ostream& out, const Date& date )
{
   if( is_valid( date ) )
   {
      write( out, to_string( date, date_format ) );
   }
   return out;
}

std::ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write( std::ostream& out, double value )
{
   return out << ", " << value;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write( ostream& out, Test_type test_type )
{
   return out << ", " << to_int( test_type );
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write( ostream& out, int value )
{
   return out << ", " << value;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::mysql::write( ostream& out, const Key& key )
{
   out << quoted( key.uwi.le.value(), '\'' );
   out << ", " << key.uwi.lsd;
   out << ", " << key.uwi.sc;
   out << ", " << key.uwi.twp;
   out << ", " << key.uwi.rg;
   out << ", " << key.uwi.m;
   write(out, key.uwi.es.value() );
   out << ", " << key.consol_interval_num;

   return out;
}
