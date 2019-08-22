#include "txt_write.h"
#include "record00.h"
#include "record01.h"
#include "record02.h"
#include "record03.h"
#include "record04.h"
#include "record05.h"
#include "key.h"
#include "ab_oil_pressure_test.h"
#include "../../../gemeinsam/date_time/date.h"
#include "../../../gemeinsam/enum/core/int.h"

using namespace std;

namespace
{
constexpr const char zero{ '0' };
constexpr const char space{ ' ' };
constexpr const char tab{ '\t' };
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::is_valid( const Date& date )
{
   return date.year().value() != 1;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Date& date )
{
   if( is_valid( date ) )
   {
      return out << to_string( date, date_format ) << tab;
   }
   else
   {
      return out << "00000000" << tab;
   }
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, string_view str, unsigned width )
{
   string formatted( width, space );

   copy( str.cbegin(), str.cend(), formatted.begin() );

   return out << formatted << tab;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, double value, unsigned width, unsigned precision, bool is_signed )
{
   if( is_signed )
   {
      --width;
      out << (value < 0 ? '-' : space);
   }

   return out << fixed << setw( width ) << setprecision( precision ) << setfill( zero ) << value << tab;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, int value, unsigned width )
{
   return out << setw( width ) << setfill( zero ) << value << tab;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, Record_type record_type )
{
   return write( out, to_int( record_type ), 2 );
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, Test_type test_type )
{
   return write( out, to_int( test_type ), 2 );
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, char c )
{
   return out << c << tab;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Key& key )
{
   write( out, key.well_id.clocation_exception(), 2 );
   write( out, key.well_id.legal_subdivision(), 2 );
   write( out, key.well_id.section(), 2 );
   write( out, key.well_id.township(), 3 );
   write( out, key.well_id.range(), 2 );
   write( out, key.well_id.meridian(), 1 );
   write( out, key.well_id.cevent_sequence() );
   write( out, key.consol_interval_num, 2 );

   return out;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Record00& rec )
{
   write( out, rec.well_name, 36 );
   write( out, rec.on_production_date );

   return out;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Record01& rec )
{
   write( out, rec.licensee_code, 5 );
   write( out, rec.licensee_abbrev, 14 );
   write( out, rec.survey_coord_oper_code, 4 );
   write( out, rec.survey_coord_abbrev, 14 );
   write( out, rec.well_status_date );
   write( out, rec.well_status_code, 10 );

   return out;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Record02& rec )
{
   write( out, rec.field_name, 20 );
   write( out, rec.pool_name, 21 );

   return out;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Record03& rec )
{
   write( out, rec.field_code, 4 );
   write( out, rec.pool_code, 7 );
   write( out, rec.consol_interval_top, 7, 2 ); // 1234.67
   write( out, rec.consol_interval_bottom, 7, 2 );
   write( out, rec.kb_elevation, 7, 2 );
   write( out, rec.pool_datum_depth, 8, 2, true );
   write( out, rec.ground_elevation, 7, 2 );
   write( out, rec.well_datum_depth, 7, 2 );
   write( out, rec.initial_pool_pressure, 5, 0 );
   write( out, rec.reservoir_gradient, 6, 3 );

   return out;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Record04& rec )
{
   char extrapolated_pressure_indicator{ rec.extrapolated_pressure_indicator == '\0' ? space : rec.extrapolated_pressure_indicator };

   write( out, rec.test_date );
   write( out, rec.test_type );
   write( out, rec.historical_well_status_date );
   write( out, rec.historical_well_status_code, 10 );
   write( out, rec.casing_pressure, 9, 2 );
   write( out, rec.mpp_depth, 7, 2 );
   write( out, rec.gauge_run_depth, 7, 2 );
   write( out, rec.run_depth_gradient, 6, 3 );
   write( out, rec.run_depth_pressure, 9, 2 );
   write( out, rec.reservoir_temperature, 6, 2 );
   write( out, rec.initial_liquid_level, 7, 2 );
   write( out, rec.final_liquid_level, 7, 2 );
   write( out, rec.gas_gradient, 6, 3 );
   write( out, rec.oil_gradient, 6, 3 );
   write( out, rec.water_gradient, 6, 3 );
   write( out, rec.mpp_pressure, 9, 2 );
   write( out, rec.datum_depth_pressure, 9, 2 );
   write( out,     extrapolated_pressure_indicator );
   write( out, rec.extrapolated_mpp_pressure, 9, 2 );
   write( out, rec.extrapolated_datum_depth_pressure, 9, 2);
   write( out, rec.shut_in_period, 8, 1 );
   write( out, rec.footnote_number, 2 );

   return out;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Record05& rec )
{
   write( out, rec.remark_indicator, 2 );
   write( out, rec.remark, 50 );

   return out;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Key& key, const Record00& rec )
{
   write( out, rec.type() );
   write( out, key );
   write( out, rec );

   return out << endl;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Key& key, const Record01& rec )
{
   write( out, rec.type() );
   write( out, key );
   write( out, rec );

   return out << endl;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Key& key, const Record02& rec )
{
   write( out, rec.type() );
   write( out, key );
   write( out, rec );

   return out << endl;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Key& key, const Record03& rec )
{
   write( out, rec.type() );
   write( out, key );
   write( out, rec );

   return out << endl;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Key& key, const Record04& rec )
{
   write( out, rec.type() );
   write( out, key );
   write( out, rec );

   return out << endl;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Key& key, const Record05& rec )
{
   write( out, rec.type() );
   write( out, key );
   write( out, rec );

   return out << endl;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::txt::write( ostream& out, const Ab_oil_pressure_test& test )
{
   const Key& key{ test.key };

   write( out, key, test.rec00 );
   write( out, key, test.rec01 );
   write( out, key, test.rec02 );
   write( out, key, test.rec03 );

   for( const auto& rec04 : test.rec04c )
   {
      write( out, key, rec04 );
   }

   for( const auto& rec05 : test.rec05c )
   {
      write( out, key, rec05 );
   }

   return out;
}
