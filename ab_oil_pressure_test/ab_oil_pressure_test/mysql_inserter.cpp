#include "mysql_inserter.h"
#include "mysql_session.h"
#include "mysql_write.h"
#include "key.h"
#include "record00.h"
#include "record01.h"
#include "record02.h"
#include "record03.h"
#include "record04.h"
#include "record05.h"
#include "ab_oil_pressure_test.h"
#include "txt_forward_list.h"
#include "txt_write.h"
#include "../../../gemeinsam/enum/core/int.h"
#include <string>
#include <sstream>
#include <fstream>
#include <mysqlx/xdevapi.h>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::mysql::Inserter::Inserter()
   : base{}
{
}

nhill::datenzugriff::ab_oil_pressure_test::mysql::Inserter::Inserter( std::string_view username, std::string_view password )
   : base{ username, password }
{
}

nhill::datenzugriff::ab_oil_pressure_test::mysql::Inserter::~Inserter()
{
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Inserter::insert_txt( string_view path_in, string_view path_log )
{
   ofstream log{ path_log };

   txt::Forward_list parser( path_in );

   if( !is_open() )
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

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Inserter::insert( const Ab_oil_pressure_test& test )
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

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Inserter::insert( const Key& key, const Record00& rec00 )
{
   ostringstream columns;
   write_column( columns, "well_name"         , rec00.well_name          );
   write_column( columns, "on_production_date", rec00.on_production_date );

   ostringstream values;
   write( values, rec00.well_name );
   write( values, rec00.on_production_date );

   return insert( "well_id", key, columns.str(), values.str() );
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Inserter::insert( const Key& key, const Record01& rec01 )
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

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Inserter::insert( const Key& key, const Record02& rec02 )
{
   ostringstream columns;
   write_column( columns, "field_name", rec02.field_name);
   write_column( columns, "pool_name", rec02.pool_name );

   ostringstream values;
   write( values, rec02.field_name );
   write( values, rec02.pool_name );

   return insert( "field_pool", key, columns.str(), values.str() );
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Inserter::insert( const Key& key, const Record03& rec03 )
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

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Inserter::insert( const Key& key, const Record04& rec04, int index )
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

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Inserter::insert( const Key& key, const Record05& rec05 )
{
   ostringstream columns;
   write_column( columns, "remark_indicator", rec05.remark_indicator );
   write_column( columns, "remark", rec05.remark );

   ostringstream values;
   write( values, rec05.remark_indicator );
   write( values, rec05.remark );

   return insert( "remark", key, columns.str(), values.str() );
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Inserter::insert( std::string_view table, const Key& key, std::string_view columns, std::string_view values )
{
   if( !is_open() )
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

   return base::execute_sql( oss.str() );
}

//auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Inserter::get_test_types()->std::map<Test_type, std::string>
//{
//   map<Test_type, std::string> test_types;
//
//   if( !is_session_open() )
//   {
//      return test_types;
//   }
//
//   try
//   {
//      Schema schema = session_impl_->session().getSchema( L"ab_oil_pressure_test" );
//
//      Table table{ schema.getTable( L"r_test_type" ) };
//
//      RowResult rows{ table.select( "*" ).execute() };
//
//      for( const auto& row : rows )
//      {
//         test_types.emplace( to_enum<Test_type>( row[0].get<int>() ), row[1] );
//      }
//   }
//   catch( Error e )
//   {
//      e.what();
//   }
//
//   return test_types;
//}
