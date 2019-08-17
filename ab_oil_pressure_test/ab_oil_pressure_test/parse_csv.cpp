#include "parse_txt.h"
#include "key.h"
#include "record00.h"
#include "record01.h"
#include "record02.h"
#include "record03.h"
#include "record04.h"
#include "record05.h"
#include "../../gemeinsam/utility/str.h"
#include <string>
#include <vector>

using namespace std;

namespace rec00
{
enum Index
{
   type = 0,	// record type
   le,			// location exception
   lsd,			// legal subdivision
   sc,			// section
   twp,			// township
   rg,			// range
   m,				// meridian
   es,			// event sequence
   cinum,		// consolidation interval number
   name,			// well name
   date,			// on production date

   cnt,			// number of indices
};
}

namespace rec01
{
enum Index
{
   lcd = 0,   // licensee code
   lab,       // licensee abbreviation
   scd,       // survey coordinating operator code      
   sab,       // survey coordinating operator abbreviation
   wdt,       // well status date
   wcd,       // well status code

   cnt,       // number of indices
};
}

namespace rec02
{
enum Index
{
   fn, // field name
   pn, // pool name

   cnt,  // number of indices
};
}

namespace rec03
{
enum Index
{
	fcd, // field code
	pcd, // pool code
	top, // consolidation interval top
	btm, // consolidation interval bottom
	kb,  // kb elevation
	pdt, // pool datum depth
	ge,  // ground elevation
	wdt, // well datum depth
	ip,  // initial pool pressure
	rg,  // reservoir gradient

	cnt, // number of indices
};
}

namespace
{
char tab{'\t'};

nhill::Date parse_date( const string& str )
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
	if( string_view rt{str.substr( 0,2 )}; rt != record_type )
	{
		return {};
	}

	// Skip to the end of the key
	str.remove_prefix( 26 );

	// Parse the string (split on tab character)
	return nhill::str::split( str, tab );
}

}

bool nhill::datenzugriff::ab_oil_pressure_test::parse_txt( Key& key, Record00& rec, string_view str )
{
   using namespace rec00;

   // Prepare the record
   rec.clear();

   // Parse the string (split on tab character)
   vector<string> vs; // vector of strings

   vs.reserve( cnt );
   vs = str::split( str, tab );

   if( vs.size() != cnt )
   {
      return false;
   }

   // Check the record type
   if( vs[type] != "00" )
   {
      return false;
   }

   // Well Identifier
   key.well_id.le ( vs[le].c_str() );
   key.well_id.lsd( atoi( vs[lsd].c_str() ) );
   key.well_id.sc ( atoi( vs[sc ].c_str() ) );
   key.well_id.twp( atoi( vs[twp].c_str() ) );
   key.well_id.rg ( atoi( vs[rg ].c_str() ) );
   key.well_id.m  ( atoi( vs[m  ].c_str() ) );
   key.well_id.es ( atoi( vs[es ].c_str() ) );

   // Consolidation invterval number
   key.consol_interval_num = atoi( vs[cinum].c_str() );

   // Well name
   rec.well_name = str::trim_end( vs[name] );

   // On production date
   rec.on_production_date = parse_date( vs[date] );

   return true;
}

bool nhill::datenzugriff::ab_oil_pressure_test::parse_txt( Record01& rec, string_view str )
{
   using namespace rec01;

   // Prepare the record
   rec.clear();

   // Parse the string (split on tab character)
	vector<string> vs{setup( "01", str )}; // vector of strings
   if( vs.size() != cnt )
   {
      return false;
   }

   rec.licensee_code          = str::trim_end( vs[lcd] );
   rec.licensee_abbrev        = str::trim_end( vs[lab] );
   rec.survey_coord_oper_code = str::trim_end( vs[scd] );
   rec.survey_coord_abbrev    = str::trim_end( vs[sab] );
   rec.well_status_date       = parse_date   ( vs[wdt] );
   rec.well_status_code       = str::trim_end( vs[wcd] );

   return true;
}

bool nhill::datenzugriff::ab_oil_pressure_test::parse_txt( Record02& rec, std::string_view str )
{
   using namespace rec02;

   // Prepare the record
   rec.clear();

	// Parse the string (split on tab character)
	vector<string> vs{setup( "02", str )}; // vector of strings
	if( vs.size() != cnt )
	{
		return false;
	}

   // Push the contents to the parameter
   rec.field_name = str::trim_end( vs[fn] );
   rec.pool_name = str::trim_end( vs[pn] );

   return true;
}

bool nhill::datenzugriff::ab_oil_pressure_test::parse_txt( Record03& rec, std::string_view str )
{
	using namespace rec03;

	// Prepare the record
	rec.clear();

	// Parse the string (split on tab character)
	vector<string> vs{setup( "03", str )}; // vector of strings
	if( vs.size() != cnt )
	{
		return false;
	}

	// Push the contents to the parameter
	rec.field_code = str::trim_end( vs[fcd] );
	rec.pool_code  = str::trim_end( vs[pcd] );

	rec.consol_interval_top    = atof( vs[top].c_str() );
	rec.consol_interval_bottom = atof( vs[btm].c_str() );
	rec.kb_elevation           = atof( vs[kb ].c_str() );
	rec.pool_datum_depth       = atof( vs[pdt].c_str() );
	rec.ground_elevation			= atof( vs[ge ].c_str() );
	rec.well_datum_depth			= atof( vs[wdt].c_str() );
	rec.initial_pool_pressure  = atof( vs[ip ].c_str() );
	rec.reservoir_gradient		= atof( vs[rg ].c_str() );

	return true;
}
