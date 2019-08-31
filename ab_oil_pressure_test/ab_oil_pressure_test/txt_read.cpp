#include "txt_read.h"
#include "key.h"
#include "record00.h"
#include "record01.h"
#include "record02.h"
#include "record03.h"
#include "record04.h"
#include "record05.h"
#include "ab_oil_pressure_test.h"
#include "helper.h"
#include "../../../gemeinsam/utility/str.h"
#include "../../../gemeinsam/enum/core/int.h"
#include <string>
#include <vector>

using namespace std;


namespace
{
char tab{ '\t' };

nhill::datenzugriff::ab_oil_pressure_test::Record_type read_record_type( string_view str )
{
   using namespace nhill::datenzugriff::ab_oil_pressure_test;

   Record_type record_type{ Record_type::well_id };
   string_view substr{ str.substr( 0,2 ) };

   if( substr == "00" )
   {
      record_type = Record_type::well_id;
   }
   else if( substr == "01" )
   {
      record_type = Record_type::licensee;
   }
   else if( substr == "02" )
   {
      record_type = Record_type::field_pool;
   }
   else if( substr == "03" )
   {
      record_type = Record_type::well_data;
   }
   else if( substr == "04" )
   {
      record_type = Record_type::test_data;
   }
   else if( substr == "05" )
   {
      record_type = Record_type::remark;
   }

   return record_type;
}

nhill::Date read_date( const string& str )
{
   if( str.size() == 8 && str != "00000000" )
   {
      return{
         atoi( str.substr( 0, 4 ).c_str() ),
         atoi( str.substr( 4, 2 ).c_str() ),
         atoi( str.substr( 6, 2 ).c_str() )
      };
   }
   else
   {
      return {};
   }
}

vector<string> setup( const char* const record_type, string_view str )
{
   // Verify the record type
   if( string_view rt{ str.substr( 0,2 ) }; rt != record_type )
   {
      return {};
   }

   // Skip to the end of the key
   str.remove_prefix( 26 );

   // Parse the string (split on tab character)
   return nhill::str::split( str, tab );
}

}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::read( Key& key, string_view str )
{
   using namespace key;

   // Prepare the key
   key.clear();

   // Parse the string (split on tab character)
   vector<string> vs; // vector of strings

   vs.reserve( 15 );
   vs = str::split( str, tab );

   // Well Identifier
   key.uwi.le = vs[le].c_str();
   key.uwi.lsd = atoi( vs[lsd].c_str() );
   key.uwi.sc = atoi( vs[sc].c_str() );
   key.uwi.twp = atoi( vs[twp].c_str() );
   key.uwi.rg = atoi( vs[rg].c_str() );
   key.uwi.m = atoi( vs[m].c_str() );
   key.uwi.es = vs[es][0];

   // Consolidation invterval number
   key.consol_interval_num = atoi( vs[cinum].c_str() );

   return true;
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::read( Record00& rec, string_view str )
{
   using namespace rec00;

   // Prepare the record
   rec.clear();

   // Parse the string (split on tab character)
   vector<string> vs{ setup( "00", str ) }; // vector of strings
   if( vs.size() != cnt )
   {
      return false;
   }

   // Well name
   rec.well_name = str::trim_end( vs[name] );

   // On production date
   rec.on_production_date = read_date( vs[date] );

   return true;
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::read( Record01& rec, string_view str )
{
   using namespace rec01;

   // Prepare the record
   rec.clear();

   // Parse the string (split on tab character)
   vector<string> vs{ setup( "01", str ) }; // vector of strings
   if( vs.size() != cnt )
   {
      return false;
   }

   rec.licensee_code = str::trim_end( vs[lcd] );
   rec.licensee_abbrev = str::trim_end( vs[lab] );
   rec.survey_coord_oper_code = str::trim_end( vs[scd] );
   rec.survey_coord_abbrev = str::trim_end( vs[sab] );
   rec.well_status_date = read_date( vs[wdt] );
   rec.well_status_code = str::trim_end( vs[wcd] );

   return true;
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::read( Record02& rec, std::string_view str )
{
   using namespace rec02;

   // Prepare the record
   rec.clear();

   // Parse the string (split on tab character)
   vector<string> vs{ setup( "02", str ) }; // vector of strings
   if( vs.size() != cnt )
   {
      return false;
   }

   // Push the contents to the parameter
   rec.field_name = str::trim_end( vs[fn] );
   rec.pool_name = str::trim_end( vs[pn] );

   return true;
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::read( Record03& rec, std::string_view str )
{
   using namespace rec03;

   // Prepare the record
   rec.clear();

   // Parse the string (split on tab character)
   vector<string> vs{ setup( "03", str ) }; // vector of strings
   if( vs.size() != cnt )
   {
      return false;
   }

   // Push the contents to the parameter
   rec.field_code = str::trim_end( vs[fcd] );
   rec.pool_code = str::trim_end( vs[pcd] );

   rec.consol_interval_top = atof( vs[top].c_str() );
   rec.consol_interval_bottom = atof( vs[btm].c_str() );
   rec.kb_elevation = atof( vs[kb].c_str() );
   rec.pool_datum_depth = atof( vs[pdt].c_str() );
   rec.ground_elevation = atof( vs[ge].c_str() );
   rec.well_datum_depth = atof( vs[wdt].c_str() );
   rec.initial_pool_pressure = atof( vs[ip].c_str() );
   rec.reservoir_gradient = atof( vs[rg].c_str() );

   return true;
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::read( Record04& rec, std::string_view str )
{
   using namespace rec04;

   // Prepare the record
   rec.clear();

   // Parse the string (split on tab character)
   vector<string> vs{ setup( "04", str ) }; // vector of strings
   if( vs.size() != cnt )
   {
      return false;
   }

   // Push the contents to the parameter
   rec.test_date = read_date( vs[td] );
   rec.test_type = nhill::to_enum<Test_type>( atoi( vs[tt].c_str() ) );
   rec.historical_well_status_date = read_date( vs[hwsd] );
   rec.historical_well_status_code = vs[hwsc];
   rec.casing_pressure = atof( vs[cp].c_str() );
   rec.mpp_depth = atof( vs[mppd].c_str() );
   rec.gauge_run_depth = atof( vs[grd].c_str() );
   rec.run_depth_gradient = atof( vs[rdg].c_str() );
   rec.run_depth_pressure = atof( vs[rdp].c_str() );
   rec.reservoir_temperature = atof( vs[rt].c_str() );
   rec.initial_liquid_level = atof( vs[ill].c_str() );
   rec.final_liquid_level = atof( vs[fll].c_str() );
   rec.gas_gradient = atof( vs[gg].c_str() );
   rec.oil_gradient = atof( vs[og].c_str() );
   rec.water_gradient = atof( vs[wg].c_str() );
   rec.mpp_pressure = atof( vs[mppp].c_str() );
   rec.datum_depth_pressure = atof( vs[ddp].c_str() );
   rec.extrapolated_pressure_indicator = (vs[epi] == " " ? '\0' : vs[epi][0]);
   rec.extrapolated_mpp_pressure = atof( vs[emppp].c_str() );
   rec.extrapolated_datum_depth_pressure = atof( vs[eddp].c_str() );
   rec.shut_in_period = atof( vs[sip].c_str() );
   rec.footnote_number = atoi( vs[fn].c_str() );

   return true;
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::read( Record05& rec, std::string_view str )
{
   using namespace rec05;

   // Prepare the record
   rec.clear();

   // Parse the string (split on tab character)
   vector<string> vs{ setup( "05", str ) }; // vector of strings
   if( vs.size() != cnt )
   {
      return false;
   }

   // Push the contents to the parameter
   rec.remark_indicator = atoi( vs[ri].c_str() );
   rec.remark = str::trim_end( vs[r] );

   return true;
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::read( Ab_oil_pressure_test& test, istream& in )
{
   test.clear();

   istream::pos_type pos{ in.tellg() };

   string line;
   if( !getline( in, line ) )
   {
      return false;
   }

   // This must be a '00' line
   if( read_record_type( line ) != Record_type::well_id )
   {
      in.seekg( pos ); // return the stream to its original position
      return false;
   }

   // Parse the key
   if( !read( test.key, line ) )
   {
      in.seekg( pos ); // return the stream to its original position
      return false;
   }

   // Parse the "00" line
   if( !read( test.rec00, line ) )
   {
      in.seekg( pos );
      return false;
   }

   // Now keep reading lines until we get to the next '00' line
   pos = in.tellg();
   while( getline( in, line ) )
   {
      switch( read_record_type( line ) )
      {
      case Record_type::well_id:
      // We have encounter the next "00" line indicating the start of a new test
      in.seekg( pos ); // return the position to beginning of the line
      return true; // and this test is finished

      case Record_type::licensee:
      read( test.rec01, line );
      break;

      case Record_type::field_pool:
      read( test.rec02, line );
      break;

      case Record_type::well_data:
      read( test.rec03, line );
      break;

      case Record_type::test_data:
      {
         Record04 r04;
         read( r04, line );
         test.rec04c.push_back( move( r04 ) );
         break;
      }

      case Record_type::remark:
      {
         Record05 r05;
         read( r05, line );
         test.rec05c.push_back( move( r05 ) );
         break;
      }
      }

      // Store the current file position before we move onto the next line.
      pos = in.tellg();
   }

   return true;
}
