#include "mysql_selector.h"
#include "mysql_session.h"
#include "mysql_read.h"
#include "mysql_configuration.h"
#include "key.h"
#include "record00.h"
#include "record01.h"
#include "record02.h"
#include "record03.h"
#include "record04.h"
#include "record05.h"
#include "record_type_ex.h"
#include "test.h"
#include "helper.h"
#include "../../../gemeinsam/uwi/dls.h"
#include <mysqlx/xdevapi.h>
#include <list>
#include <stack>
#include <errno.h>

using namespace std;

namespace
{
using namespace nhill::datenzugriff::ab_oil_pressure_test;

constexpr char slash{ '\'' };

string columns(Record_type record_type)
{
	switch( record_type )
	{
	case Record_type::well_id: return  "well_name, UNIX_TIMESTAMP(on_production_date) AS on_production_unixts";
	case Record_type::licensee: return "licensee_code, licensee_abbrev, survey_coord_oper_code, survey_coord_abbrev, UNIX_TIMESTAMP(well_status_date) AS well_status_unixts, well_status_code";
	case Record_type::field_pool: return "field_name, pool_name";
	case Record_type::well_data: return "field_code, pool_code, consol_interval_top, consol_interval_bottom, kb_elevation, pool_datum_depth, ground_elevation, well_datum_depth, initial_pool_pressure, reservoir_gradient";
	case Record_type::test_data: return "UNIX_TIMESTAMP(test_date) AS test_unixts, test_type, UNIX_TIMESTAMP(historical_well_status_date) AS historical_well_status_unixts, historical_well_status_code, casing_pressure, mpp_depth, gauge_run_depth, run_depth_gradient, run_depth_pressure, reservoir_temperature, initial_liquid_level, final_liquid_level, gas_gradient, oil_gradient, water_gradient, mpp_pressure, datum_depth_pressure, extrapolated_pressure_indicator, extrapolated_mpp_pressure, extrapolated_datum_depth_pressure, shut_in_period, footnote_number";
	case Record_type::remark: return "remark_indicator, remark";
	default: return "";
	}
}




}

nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::
Selector()
   : base{}
{
}

nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::
Selector( std::string_view username, std::string_view password, std::string_view hostname )
   : base{ username, password, hostname }
{
}

nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::
Selector( const Configuration& config )
   : Selector{config.username, config.password, config.hostname }
{
}

nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::
~Selector()
{
}

unsigned nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::count_consol_interval_num( const uwi::Dls& uwi )
{
   try
   {
      mysqlx::Table table{ base::table( Record_type::well_id ) };
      mysqlx::RowResult row_result{ table
      .select( "COUNT(consol_interval_num)" )
      .where( "location_exception=:le  AND legal_subdivision=:lsd AND section=:sc AND township=:twp AND well_id.range=:rg AND meridian=:m AND event_sequence=:es" )
      .bind( "le" , uwi.le.value() )
      .bind( "lsd", uwi.lsd.value() )
      .bind( "sc" , uwi.sc.value() )
      .bind( "twp", uwi.twp.value() )
      .bind( "rg" , uwi.rg.value() )
      .bind( "m"  , uwi.m.value() )
      .bind( "es" , uwi.es.str() )
      .execute()
      };

      return row_result.fetchOne()[0];
   }
   catch( exception e )
   {
      throw e;
   }
}

unsigned nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::count_test_index( const Key& key )
{
   try
   {
      mysqlx::Table table{ base::table( Record_type::test_data ) };
      mysqlx::RowResult row_result{ table
      .select( "COUNT(test_index)" )
      .where( "location_exception=:le  AND legal_subdivision=:lsd AND section=:sc AND township=:twp AND test_data.range=:rg AND meridian=:m AND event_sequence=:es AND consol_interval_num=:cin" )
      .bind( "le" , key.uwi.le.value() )
      .bind( "lsd", key.uwi.lsd.value() )
      .bind( "sc" , key.uwi.sc.value() )
      .bind( "twp", key.uwi.twp.value() )
      .bind( "rg" , key.uwi.rg.value() )
      .bind( "m"  , key.uwi.m.value() )
      .bind( "es" , key.uwi.es.str() )
      .bind( "cin", key.consol_interval_num)
      .execute()
      };

      return row_result.fetchOne()[0];
   }
   catch( exception e )
   {
      throw e;
   }
}

unsigned nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::count_remark_indicator( const Key& key )
{
   try
   {
      mysqlx::Table table{ base::table( Record_type::remark ) };
      mysqlx::RowResult row_result{ table
      .select( "COUNT(remark_indicator)" )
      .where( "location_exception=:le  AND legal_subdivision=:lsd AND section=:sc AND township=:twp AND remark.range=:rg AND meridian=:m AND event_sequence=:es AND consol_interval_num=:cin" )
      .bind( "le" , key.uwi.le.value() )
      .bind( "lsd", key.uwi.lsd.value() )
      .bind( "sc" , key.uwi.sc.value() )
      .bind( "twp", key.uwi.twp.value() )
      .bind( "rg" , key.uwi.rg.value() )
      .bind( "m"  , key.uwi.m.value() )
      .bind( "es" , key.uwi.es.str() )
      .bind( "cin", key.consol_interval_num )
      .execute()
      };

      return row_result.fetchOne()[0];
   }
   catch( exception e )
   {
      throw e;
   }
}


template<> auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find_rec( const Key& key, int )->Record00
{
   try
   {
      mysqlx::SqlResult rows{ execute_select( Record_type::well_id, key ) };
      if( rows.count() != 1 )
      {
         throw exception( "The MySQL session failed to select Record by key." );
      }
      mysqlx::Row row{ rows.fetchOne() };
      return convert<Record00>( row );
   }
   catch( exception e )
   {
      throw e;
   }
}

template<> auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find_rec( const Key& key, int )->Record01
{
   try
   {
      mysqlx::SqlResult rows{ execute_select( Record_type::licensee, key ) };
      if( rows.count() != 1 )
      {
         throw exception( "The MySQL session failed to select Record by key." );
      }
      mysqlx::Row row{ rows.fetchOne() };
      return convert<Record01>( row );
   }
   catch( exception e )
   {
      throw e;
   }
}
template<> auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find_rec( const Key& key, int )->Record02
{
   try
   {
      mysqlx::SqlResult rows{ execute_select( Record_type::field_pool, key ) };
      if( rows.count() != 1 )
      {
         throw exception( "The MySQL session failed to select Record by key." );
      }
      mysqlx::Row row{ rows.fetchOne() };
      return convert<Record02>( row );
   }
   catch( exception e )
   {
      throw e;
   }
}

template<> auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find_rec( const Key& key, int )->Record03
{
   try
   {
      mysqlx::SqlResult rows{ execute_select( Record_type::well_data, key ) };
      if( rows.count() != 1 )
      {
         throw exception( "The MySQL session failed to select Record by key." );
      }
      mysqlx::Row row{ rows.fetchOne() };
      return convert<Record03>( row );
   }
   catch( exception e )
   {
      throw e;
   }
}

template<> auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find_rec( const Key& key, int test_index )->Record04
{
   try
   {
      mysqlx::SqlResult rows{ execute_select( Record_type::test_data, key, test_index ) };
      if( rows.count() != 1 )
      {
         throw exception( "The MySQL session failed to select Record by key." );
      }
      mysqlx::Row row{ rows.fetchOne() };
      return convert<Record04>( row );
   }
   catch( exception e )
   {
      throw e;
   }
}

template<> auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find_rec( const Key& key, int remark_indicator )->Record05
{
   try
   {
      mysqlx::SqlResult rows{ execute_select( Record_type::remark, key, remark_indicator ) };
      if( rows.count() != 1 )
      {
         throw exception( "The MySQL session failed to select Record by key." );
      }
      mysqlx::Row row{ rows.fetchOne() };
      return convert<Record05>( row );
   }
   catch( exception e )
   {
      throw e;
   }
}

Key_container nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find_key_by_uwi( const uwi::Dls& uwi )
{
   try
   {
      unsigned count_consol_interval_num{ this->count_consol_interval_num( uwi ) };

      Key_container keys;
      for( unsigned consol_interval_num{ 1 } ; consol_interval_num <= count_consol_interval_num ; ++consol_interval_num )
      {
         keys.push_back( { uwi, consol_interval_num } );
      }

      return keys;
   }
   catch( exception e )
   {
      throw e;
   }
}

auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find_key_by_licensee_code( const std::string& licensee_code )->Key_container
{
   try
   {
      ostringstream oss;

      oss << "SELECT ";
      oss << "location_exception, legal_subdivision, section, township, licensee.range, meridian, event_sequence, consol_interval_num";
      oss << " FROM ab_oil_pressure_test.licensee WHERE ";
      oss << "licensee_code=" << quoted( licensee_code, slash );
      oss << ";";

      mysqlx::SqlResult rows{ session().sql( oss.str() ).execute() };

      Key_container keys;
      for( const auto& row : rows )
      {
         keys.push_back( convert<Key>(row) );
      }

      return keys;
   }
   catch( exception e )
   {
      throw e;
   }
}

auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find_key_by_field_pool( const std::string& field_code, const std::string& pool_code )->Key_container
{
   try
   {
      ostringstream oss;

      oss << "SELECT ";
      oss << "location_exception, legal_subdivision, section, township, well_data.range, meridian, event_sequence, consol_interval_num";
      oss << " FROM ab_oil_pressure_test.well_data WHERE ";
      oss << "field_code=" << quoted( field_code, slash );
      if( !pool_code.empty() )
      {
         oss << " AND pool_code=" << quoted( pool_code, slash );
      }
      oss << ";";

      mysqlx::SqlResult rows{ session().sql( oss.str() ).execute() };

      Key_container keys;
      for( const auto& row : rows )
      {
         keys.push_back( convert<Key>( row ) );
      }

      return keys;
   }
   catch( exception e )
   {
      throw e;
   }
}

Key_container nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find_key_by_test_type( const std::list<Test_type>& test_types )
{
   try
   {
      auto test_type{ test_types.cbegin() };
      ostringstream oss;

      oss << "SELECT ";
      oss << "location_exception, legal_subdivision, section, township, test_data.range, meridian, event_sequence, consol_interval_num";
      oss << " FROM ab_oil_pressure_test.test_data WHERE ";
      oss << "test_type=" << to_int(*test_type);
      for( ; test_type != test_types.cend() ; ++test_type )
      {
         oss << " OR test_type=" << to_int( *test_type );
      }
      oss << ";";

      mysqlx::SqlResult rows{ session().sql( oss.str() ).execute() };

      Key_container keys;
      for( const auto& row : rows )
      {
         keys.push_back( convert<Key>( row ) );
      }

      return keys;
   }
   catch( exception e )
   {
      throw e;
   }
}

auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find_test( const Key& key )->Test
{
   try
   {
      unsigned count_test_index{ this->count_test_index( key ) };
      unsigned count_remark_indicator{ this->count_remark_indicator( key ) };

      Test test;

      test.rec00 = find_rec<Record00>( key );
      test.rec01 = find_rec<Record01>( key );
      test.rec02 = find_rec<Record02>( key );
      test.rec03 = find_rec<Record03>( key );

      for( unsigned test_index{ 0 } ; test_index < count_test_index ; test_index++ )
      {
         test.rec04c.push_back( find_rec<Record04>( key, test_index ) );
      }

      for( unsigned remark_indicator{ 1 } ; remark_indicator <= count_remark_indicator ; remark_indicator++ )
      {
         test.rec05c.push_back( find_rec<Record05>( key, remark_indicator ) );
      }

      return test;
   }
   catch( exception e )
   {
      throw e;
   }
}

auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find_test( const Key_container& keys )->Test_container
{
   try
   {
      Test_container tests;
      for( const auto& key : keys )
      {
         tests.push_back( find_test( key ) );
      }
      return tests;
   }
   catch( exception e )
   {
      throw e;
   }
}

string nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::build_where( Record_type record_type, const Key& key, int index )
{
   string table{ to_string( record_type ) };
   ostringstream oss;

   oss << "location_exception="				<< quoted( key.uwi.le.value(), slash );
   oss << " AND legal_subdivision="			<< key.uwi.lsd.value<int>();
   oss << " AND section="						<< key.uwi.sc.value<int>();
   oss << " AND township="						<< key.uwi.twp.value<int>();
   oss << " AND " << table << ".range="	<< key.uwi.rg.value<int>();
   oss << " AND meridian="						<< key.uwi.m.value<int>();
   oss << " AND event_sequence="				<< quoted( key.uwi.es.str(), slash );
   oss << " AND consol_interval_num="		<< key.consol_interval_num;

   switch( record_type )
   {
   case nhill::datenzugriff::ab_oil_pressure_test::Record_type::test_data:
   {
      oss << " AND test_index=" << index;
      break;
   }

   case nhill::datenzugriff::ab_oil_pressure_test::Record_type::remark:
   {
      oss << " AND remark_indicator=" << index;
      break;
   }

   }

   return oss.str();
}


template<> inline
Record00 nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::convert( const mysqlx::Row& row )
{
   using namespace rec00;
   try
   {
      Record00 rec;

      rec.well_name = read_string( row[name] );
      rec.on_production_date = read_date( row[date] );

      return rec;
   }
   catch( exception e )
   {
      throw e;
   }
}

template<> inline
Record01 nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::convert( const mysqlx::Row& row )
{
   using namespace rec01;
   try
   {
      Record01 rec;

      rec.licensee_code = read_string( row[lcd] );
      rec.licensee_abbrev = read_string( row[lab] );
      rec.survey_coord_oper_code = read_string( row[scd] );
      rec.survey_coord_abbrev = read_string( row[sab] );
      rec.well_status_date = read_date( row[wdt] );
      rec.well_status_code = read_string( row[wcd] );

      return rec;
   }
   catch( exception e )
   {
      throw e;
   }
}

template<> inline
Record02 nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::convert( const mysqlx::Row& row )
{
   using namespace rec02;
   try
   {
      Record02 rec;

      rec.field_name = read_string( row[fn] );
      rec.pool_name  = read_string( row[pn] );

      return rec;
   }
   catch( exception e )
   {
      throw e;
   }
}

template<> inline
Record03 nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::convert( const mysqlx::Row& row )
{
   using namespace rec03;
   try
   {
      Record03 rec;

      rec.field_code = read_string( row[fcd] );
      rec.pool_code = read_string( row[pcd] );
      rec.consol_interval_top = read_double( row[top] );
      rec.consol_interval_bottom = read_double( row[btm] );
      rec.kb_elevation = read_double( row[kb] );
      rec.pool_datum_depth = read_double( row[pdt] );
      rec.ground_elevation = read_double( row[ge] );
      rec.well_datum_depth = read_double( row[wdt] );
      rec.initial_pool_pressure = read_double( row[ip] );
      rec.reservoir_gradient = read_double( row[rg] );

      return rec;
   }
   catch( exception e )
   {
      throw e;
   }
}


template<> inline
Record04 nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::convert( const mysqlx::Row& row )
{
   using namespace rec04;
   try
   {
      Record04 rec;

      rec.test_date = read_date     ( row[td] );
      rec.test_type = read_test_type( row[tt] );
      rec.historical_well_status_date = read_date( row[hwsd] );
      rec.historical_well_status_code = read_string( row[hwsc] );
      rec.casing_pressure = read_double( row[cp] );
      rec.mpp_depth = read_double( row[mppd] );
      rec.gauge_run_depth = read_double( row[grd] );
      rec.run_depth_gradient = read_double( row[rdg] );
      rec.run_depth_pressure = read_double( row[rdp] );
      rec.reservoir_temperature = read_double( row[rt] );
      rec.initial_liquid_level = read_double( row[ill] );
      rec.final_liquid_level = read_double( row[fll] );
      rec.gas_gradient = read_double( row[gg] );
      rec.oil_gradient = read_double( row[og] );
      rec.water_gradient = read_double( row[wg] );
      rec.mpp_pressure = read_double( row[mppp] );
      rec.datum_depth_pressure = read_double( row[ddp] );
      rec.extrapolated_pressure_indicator = read_char( row[epi] );
      rec.extrapolated_mpp_pressure = read_double( row[emppp] );
      rec.extrapolated_datum_depth_pressure = read_double( row[eddp] );
      rec.shut_in_period = read_double( row[sip] );
      rec.footnote_number = read_int( row[fn] );

      return rec;
   }
   catch( exception e )
   {
      throw e;
   }
}

template<> inline
auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::convert( const mysqlx::Row& row )->Record05
{
   using namespace rec05;
   try
   {
      Record05 rec;

      rec.remark_indicator = read_int( row[ri] );
      rec.remark = read_string( row[r] );

      return rec;
   }
   catch( exception e )
   {
      throw e;
   }
}

template<> inline auto nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::convert( const mysqlx::Row& row )->Key
{
   Key key;

   key.uwi.le = row[0].get<string>();
   key.uwi.lsd = row[1].get<int>();
   key.uwi.sc = row[2].get<int>();
   key.uwi.twp = row[3].get<int>();
   key.uwi.rg = row[4].get<int>();
   key.uwi.m = row[5].get<int>();
   key.uwi.es = row[6].get<string>();
   key.consol_interval_num = row[7].get<unsigned>();

   return key;
}




mysqlx::SqlResult nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::execute_select( Record_type record_type, const Key& key, int index )
{
   string table{ to_string( record_type ) };
   ostringstream oss;

   oss << "SELECT ";
   oss << columns(record_type);
   oss << " FROM ab_oil_pressure_test.";
   oss << table;
   oss << " WHERE ";
   oss << build_where( record_type, key, index);
   oss << ';';

   try
   {
      return session().sql( oss.str() ).execute();
   }
   catch( exception e )
   {
      throw e;
   }
}
