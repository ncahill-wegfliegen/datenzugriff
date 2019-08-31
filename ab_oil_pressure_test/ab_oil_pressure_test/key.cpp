#include "key.h"
#include <iomanip>

using namespace std;

void nhill::datenzugriff::ab_oil_pressure_test::Key::clear()
{
   uwi.clear();
   consol_interval_num = 0;
}

template<>
auto nhill::compare( const datenzugriff::ab_oil_pressure_test::Key& a, const datenzugriff::ab_oil_pressure_test::Key& b ) noexcept->Compare
{
   Compare cmp_well_id{compare<uwi::Dls>( a.uwi, b.uwi )};
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
   return (a.uwi == b.uwi) && (a.consol_interval_num == b.consol_interval_num);
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
   out <<         key.uwi.le;
   out << '\t' << key.uwi.lsd;
   out << '\t' << key.uwi.sc;
   out << '\t' << key.uwi.twp;
   out << '\t' << key.uwi.rg;
   out << '\t' << key.uwi.m;
   out << '\t' << key.uwi.es;
   out << '\t' << setw( 2 ) << setfill( '0' ) << key.consol_interval_num;
   out << '\t';

   return out;
}



