#include "mysql.h"
#include "../ab_oil_pressure_test/key.h"
#include "../ab_oil_pressure_test/record00.h"
#include "../ab_oil_pressure_test/record01.h"
#include "../ab_oil_pressure_test/record02.h"
#include "../ab_oil_pressure_test/record03.h"
#include "../ab_oil_pressure_test/record04.h"
#include "../ab_oil_pressure_test/record05.h"
#include "../ab_oil_pressure_test/ab_oil_pressure_test.h"
#include "../ab_oil_pressure_test/txt_parser.h"
#include "../ab_oil_pressure_test/txt_write.h"
#include "../../../gemeinsam/enum/core/int.h"
#include <string>
#include <sstream>
#include <fstream>
#include <mysqlx/xdevapi.h>

using namespace mysqlx;
using namespace std;

namespace
{
using namespace nhill;
using namespace nhill::datenzugriff::ab_oil_pressure_test;


std::string quote( string_view s )
{
   std::string q;
   return q.assign( "'" ).append( s ).append( "'" );
}

std::string quote( char c )
{
   char cc[2]{ c, '\0' };
   std::string q;
   return q.assign( "'" ).append( cc ).append( "'" );
}


std::string format_date( const Date& date )
{
   return (date.year().value() == 1) ? "" : quote(to_string( date, "%Y-%m-%d" ));
}

}

class nhill::datenzugriff::ab_oil_pressure_test::Mysql::Session_impl
{
public:
   Session_impl( const std::string& url );
   ~Session_impl();

   Session& session();

private:
   Session session_;
};


nhill::datenzugriff::ab_oil_pressure_test::Mysql::Session_impl::Session_impl( const std::string& url )
   : session_{url}
{
}

nhill::datenzugriff::ab_oil_pressure_test::Mysql::Session_impl::~Session_impl() = default;

Session& nhill::datenzugriff::ab_oil_pressure_test::Mysql::Session_impl::session()
{
   return session_;
}


nhill::datenzugriff::ab_oil_pressure_test::Mysql::Mysql()
   : username_{}
   , password_{}
   , session_impl_{nullptr}
{
}

nhill::datenzugriff::ab_oil_pressure_test::Mysql::Mysql( std::string_view username, std::string_view password )
   : username_{username}
   , password_{password}
   , session_impl_{nullptr }
{
   open_session();
}

nhill::datenzugriff::ab_oil_pressure_test::Mysql::~Mysql()
{
   close_session();
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::open_session()
{
   return open_session( username_, password_);
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::open_session( std::string_view username, std::string_view password )
{
   if( session_impl_ != nullptr )
   {
      close_session();
   }

   ostringstream url;
   url << username << ':' << password << "@localhost/";

   try
   {
      session_impl_ = make_unique<Session_impl>(url.str());
      return true;
   }
   catch( exception e )
   {
      session_impl_ = nullptr;
      return false;
   }
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::is_session_open()
{
   return session_impl_ != nullptr;
}

void nhill::datenzugriff::ab_oil_pressure_test::Mysql::close_session()
{
   if( session_impl_ != nullptr )
   {
      session_impl_->session().close();
      session_impl_ = nullptr;
   }
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::insert_txt( string_view path_in, string_view path_log )
{
   ofstream log{ path_log };

   txt::Txt_parser parser( path_in );

   Mysql mysql{ "nhill-bemuehen", "piondecay" };
   if( !mysql.is_session_open() )
   {
      if( log.is_open() )
      {
         log << "Failed to start the MySQL session." << endl;
         log.close();
      }
      return false;
   }

   for( const auto& test : parser )
   {
      if( !insert( test ) )
      {
         if( log.is_open() )
         {
            txt::write( log, test );
         }
      }
   }

   if( log.is_open() )
   {
      log.close();
   }

   return true;
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::insert( const Ab_oil_pressure_test& test )
{
   const Key& key{ test.key };

   if( !insert( key, test.rec00 ) )
   {
      return false;
   }

   if( !insert( key, test.rec01 ) )
   {
      return false;
   }

   if( !insert( key, test.rec02 ) )
   {
      return false;
   }

   if( !insert( key, test.rec03 ) )
   {
      return false;
   }

   // Must insert record 5 before record 4 
   // because the 'footnote_number; in record 4 referes to the 'remark_indicator' in record 5.
   for( const auto& rec05 : test.rec05c )
   {
      if( !insert( key, rec05 ) )
      {
         return false;
      }
   }

   for( int cnt{ static_cast<int>(test.rec04c.size()) }, index{ 0 }; index < cnt ; index++ )
   {
      const Record04& rec04{ test.rec04c[index] };
      if( !insert( key, rec04, index ) )
      {
         return false;
      }
   }

   return true;
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::insert( const Key& key, const Record00& rec00 )
{
   ostringstream columns;
   write_column( columns, "well_name"         , rec00.well_name          );
   write_column( columns, "on_production_date", rec00.on_production_date );

   ostringstream values;
   write( values, rec00.well_name );
   write( values, rec00.on_production_date );

   return insert( "well_id", key, columns.str(), values.str() );
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::insert( const Key& key, const Record01& rec01 )
{
   ostringstream columns;
   write_column( columns, "licensee_code", rec01.licensee_code );
   write_column( columns, "licensee_abbrev", rec01.licensee_abbrev );
   write_column( columns, "survey_coord_oper_code", rec01.survey_coord_oper_code );
   write_column( columns, "survey_coord_abbrev", rec01.survey_coord_abbrev);
   write_column( columns, "well_status_date", rec01.well_status_date );
   write_column( columns, "well_status_code", rec01.well_status_code );

   ostringstream values;
   write( values, rec01.licensee_code );
   write( values, rec01.licensee_abbrev );
   write( values, rec01.survey_coord_oper_code );
   write( values, rec01.survey_coord_abbrev );
   write( values, rec01.well_status_date );
   write( values, rec01.well_status_code );

   return insert( "licensee", key, columns.str(), values.str() );
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::insert( const Key& key, const Record02& rec02 )
{
   ostringstream columns;
   write_column( columns, "field_name", rec02.field_name);
   write_column( columns, "pool_name", rec02.pool_name );

   ostringstream values;
   write( values, rec02.field_name );
   write( values, rec02.pool_name );

   return insert( "field_pool", key, columns.str(), values.str() );
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::insert( const Key& key, const Record03& rec03 )
{
   ostringstream columns;
   write_column( columns, "field_code", rec03.field_code );
   write_column( columns, "pool_code", rec03.pool_code );
   write_column( columns, "consol_interval_top", rec03.consol_interval_top );
   write_column( columns, "consol_interval_bottom", rec03.consol_interval_bottom );
   write_column( columns, "kb_elevation", rec03.kb_elevation );
   write_column( columns, "pool_datum_depth", rec03.pool_datum_depth );
   write_column( columns, "ground_elevation", rec03.ground_elevation );
   write_column( columns, "well_datum_depth", rec03.well_datum_depth );
   write_column( columns, "initial_pool_pressure", rec03.initial_pool_pressure );
   write_column( columns, "reservoir_gradient", rec03.reservoir_gradient );

   ostringstream values;
   write( values, rec03.field_code );
   write( values, rec03.pool_code );
   write( values, rec03.consol_interval_top );
   write( values, rec03.consol_interval_bottom );
   write( values, rec03.kb_elevation );
   write( values, rec03.pool_datum_depth );
   write( values, rec03.ground_elevation );
   write( values, rec03.well_datum_depth );
   write( values, rec03.initial_pool_pressure );
   write( values, rec03.reservoir_gradient );

   return insert( "well_data", key, columns.str(), values.str() );
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::insert( const Key& key, const Record04& rec04, int index )
{
   ostringstream columns;
   write_column( columns, "test_index", index );
   write_column( columns, "test_date", rec04.test_date );
   write_column( columns, "test_type", rec04.test_type );
   write_column( columns, "historical_well_status_date", rec04.historical_well_status_date );
   write_column( columns, "historical_well_status_code", rec04.historical_well_status_code );
   write_column( columns, "casing_pressure", rec04.casing_pressure );
   write_column( columns, "mpp_depth", rec04.mpp_depth );
   write_column( columns, "gauge_run_depth", rec04.gauge_run_depth );
   write_column( columns, "run_depth_gradient", rec04.run_depth_gradient );
   write_column( columns, "run_depth_pressure", rec04.run_depth_pressure );
   write_column( columns, "reservoir_temperature", rec04.reservoir_temperature );
   write_column( columns, "initial_liquid_level", rec04.initial_liquid_level );
   write_column( columns, "final_liquid_level", rec04.final_liquid_level );
   write_column( columns, "gas_gradient", rec04.gas_gradient );
   write_column( columns, "oil_gradient", rec04.oil_gradient );
   write_column( columns, "water_gradient", rec04.water_gradient );
   write_column( columns, "mpp_pressure", rec04.mpp_pressure );
   write_column( columns, "datum_depth_pressure", rec04.datum_depth_pressure );
   write_column( columns, "extrapolated_pressure_indicator", rec04.extrapolated_pressure_indicator );
   write_column( columns, "extrapolated_mpp_pressure", rec04.extrapolated_mpp_pressure );
   write_column( columns, "extrapolated_datum_depth_pressure", rec04.extrapolated_datum_depth_pressure );
   write_column( columns, "shut_in_period", rec04.shut_in_period );
   if( 0 < rec04.footnote_number )
   {
      write_column( columns, "footnote_number", rec04.footnote_number );
   }

   ostringstream values;
   write( values, index );
   write( values, rec04.test_date );
   write( values, rec04.test_type );
   write( values, rec04.historical_well_status_date );
   write( values, rec04.historical_well_status_code );
   write( values, rec04.casing_pressure );
   write( values, rec04.mpp_depth );
   write( values, rec04.gauge_run_depth );
   write( values, rec04.run_depth_gradient );
   write( values, rec04.run_depth_pressure );
   write( values, rec04.reservoir_temperature );
   write( values, rec04.initial_liquid_level );
   write( values, rec04.final_liquid_level );
   write( values, rec04.gas_gradient );
   write( values, rec04.oil_gradient );
   write( values, rec04.water_gradient );
   write( values, rec04.mpp_pressure );
   write( values, rec04.datum_depth_pressure );
   write( values, rec04.extrapolated_pressure_indicator );
   write( values, rec04.extrapolated_mpp_pressure );
   write( values, rec04.extrapolated_datum_depth_pressure );
   write( values, rec04.shut_in_period );
   if( 0 < rec04.footnote_number )
   {
      write( values, rec04.footnote_number );
   }

   return insert( "test_data", key, columns.str(), values.str() );
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::insert( const Key& key, const Record05& rec05 )
{
   ostringstream columns;
   write_column( columns, "remark_indicator", rec05.remark_indicator );
   write_column( columns, "remark", rec05.remark );

   ostringstream values;
   write( values, rec05.remark_indicator );
   write( values, rec05.remark );

   return insert( "remark", key, columns.str(), values.str() );
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::insert( std::string_view table, const Key& key, std::string_view columns, std::string_view values )
{
   if( !is_session_open() )
   {
      return false;
   }

   ostringstream oss;

   oss << "INSERT INTO " << schema << '.' << table << endl;
   oss << "(";
   write_key_columns( oss, table );
   oss << columns;
   oss << ")" << endl;
   oss << "VALUES" << endl;
   oss << "(";
   write( oss, key );
   oss << values;
   oss << ");";

   try
   {
      SqlResult result{ session_impl_->session().sql( oss.str() ).execute() };
      return true;
   }
   catch( exception e )
   {
      return false;
   }
}

auto nhill::datenzugriff::ab_oil_pressure_test::Mysql::get_test_types()->std::map<Test_type, std::string>
{
   map<Test_type, std::string> test_types;

   if( !is_session_open() )
   {
      return test_types;
   }

   try
   {
      Schema schema = session_impl_->session().getSchema( L"ab_oil_pressure_test" );

      Table table{ schema.getTable( L"r_test_type" ) };

      RowResult rows{ table.select( "*" ).execute() };

      for( const auto& row : rows )
      {
         test_types.emplace( to_enum<Test_type>( row[0].get<int>() ), row[1] );
      }
   }
   catch( Error e )
   {
      e.what();
   }

   return test_types;
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::is_valid( char c )
{
   return c != '\0';
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::is_valid( std::string_view str )
{
   return !str.empty();
}

bool nhill::datenzugriff::ab_oil_pressure_test::Mysql::is_valid( Date date )
{
   return date.year().value() != 1;
}

std::string nhill::datenzugriff::ab_oil_pressure_test::Mysql::format( char c )
{
   if( is_valid(c) )
   {
      char s[2]{ c };
      return format( &s[0] );
   }
   else
   {
      return {};
   }
}

std::string nhill::datenzugriff::ab_oil_pressure_test::Mysql::format( string_view str )
{
   if( is_valid(str) )
   {
      ostringstream oss;
      oss << single_quote << str << single_quote;
      return oss.str();
   }
   else
   {
      return {};
   }
}

std::string nhill::datenzugriff::ab_oil_pressure_test::Mysql::format( Date date )
{
   if( is_valid(date) )
   {
      std::string str{ to_string( date, date_format ) };
      return format( str );
   }
   else
   {
      return {};
   }
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write_column( ostream& out, string_view column, char c )
{
   if( is_valid( c ) )
   {
      out << ", " << column;
   }
   return out;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write_column( ostream& out, string_view column, string_view str )
{
   if( is_valid( str ) )
   {
      out << ", " << column;
   }
   return out;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write_column( ostream& out, string_view column, const Date& date )
{
   if( is_valid( date ) )
   {
      out << ", " << column;
   }
   return out;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write_column( ostream& out, string_view column, double value )
{
   return out << ", " << column;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write_column( ostream& out, string_view column, Test_type test_type )
{
   return out << ", " << column;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write_column( ostream& out, string_view column, int value )
{
   return out << ", " << column;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write_key_columns( ostream& out, std::string_view table_name )
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

std::ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write( std::ostream& out, char c )
{
   if( is_valid( c ) )
   {
      out << ", " << format( c );
   }
   return out;
}

std::ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write( std::ostream& out, std::string_view str )
{
   if( is_valid( str ) )
   {
      out << ", " << format( str );
   }
   return out;
}

std::ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write( std::ostream& out, const Date& date )
{
   if( is_valid( date ) )
   {
      out << ", " << format( date );
   }
   return out;
}

std::ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write( std::ostream& out, double value )
{
   return out << ", " << value;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write( ostream& out, Test_type test_type )
{
   return out << ", " << to_int( test_type );
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write( ostream& out, int value )
{
   return out << ", " << value;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::Mysql::write( ostream& out, const Key& key )
{
   out << format( key.well_id.cle() );
   out << ", " << key.well_id.lsd();
   out << ", " << key.well_id.sc();
   out << ", " << key.well_id.twp();
   out << ", " << key.well_id.rg();
   out << ", " << key.well_id.m();
   out << ", " << format( key.well_id.ces() );
   out << ", " << key.consol_interval_num;

   return out;
}

