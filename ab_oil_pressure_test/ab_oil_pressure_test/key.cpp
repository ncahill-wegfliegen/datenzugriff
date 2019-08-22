#include "key.h"
#include <iomanip>

using namespace std;

void nhill::datenzugriff::ab_oil_pressure_test::Key::clear()
{
   well_id.clear();
   consol_interval_num = 0;
}

template<>
auto nhill::compare( const datenzugriff::ab_oil_pressure_test::Key& a, const datenzugriff::ab_oil_pressure_test::Key& b ) noexcept->Compare
{
   Compare cmp_well_id{compare<uwi::Dls>( a.well_id, b.well_id )};
   if( cmp_well_id == Compare::less )
   {
      return Compare::less;
   }
   else if( cmp_well_id == Compare::equal )
   {
      if( a.consol_interval_num < b.consol_interval_num )
      {
         return Compare::less;
      }
      else if( a.consol_interval_num == b.consol_interval_num )
      {
         return Compare::equal;
      }
   }

   return Compare::greater;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator==( const Key& a, const Key& b )
{
   return (a.well_id == b.well_id) && (a.consol_interval_num == b.consol_interval_num);
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator!=( const Key& a, const Key& b )
{
   return !(a == b);
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator<( const Key& a, const Key& b )
{
   return compare<const Key&>(a,b) == Compare::less;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator>( const Key& a, const Key& b )
{
   return compare<const Key&>(a,b) == Compare::greater;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator<=( const Key& a, const Key& b )
{
   return (a == b) || (a < b);
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator>=( const Key& a, const Key& b )
{
   return (a == b) || (a > b);
}

std::ostream& nhill::datenzugriff::ab_oil_pressure_test::operator<<( std::ostream& out, const Key& key )
{
	out << key.well_id.clocation_exception();
	out << '\t' << setw( 2 ) << setfill( '0' ) << key.well_id.legal_subdivision();
	out << '\t' << setw( 2 ) << setfill( '0' ) << key.well_id.section();
	out << '\t' << setw( 3 ) << setfill( '0' ) << key.well_id.township();
	out << '\t' << setw( 2 ) << setfill( '0' ) << key.well_id.range();
	out << '\t' << key.well_id.meridian();
	out << '\t' << setw( 2 ) << setfill( '0' ) << key.well_id.cevent_sequence();
	out << '\t' << setw( 2 ) << setfill( '0' ) << key.consol_interval_num;
	out << '\t';

	return out;
}



