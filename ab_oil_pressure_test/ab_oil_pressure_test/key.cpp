#include "key.h"

void nhill::datenzugriff::ab_oil_pressure_test::Key::clear()
{
   well_id.clear();
   consol_interval_num = 0;
}

template<>
auto nhill::comparex( const datenzugriff::ab_oil_pressure_test::Key& a, const datenzugriff::ab_oil_pressure_test::Key& b ) noexcept->Compare
{
   Compare cmp_well_id{comparex( a.well_id, b.well_id )};
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
   return comparex(a,b) == Compare::less;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator>( const Key& a, const Key& b )
{
   return comparex(a,b) == Compare::greater;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator<=( const Key& a, const Key& b )
{
   return (a == b) || (a < b);
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator>=( const Key& a, const Key& b )
{
   return (a == b) || (a > b);
}



