#include "ab_oil_pressure_test.h"

void nhill::datenzugriff::Ab_oil_pressure_test::clear()
{
   key.clear();
   rec00.clear();
   rec01.clear();
   rec02.clear();
   rec03.clear();
   rec04c.clear();
   rec05c.clear();
}

template<>
auto nhill::compare( const datenzugriff::Ab_oil_pressure_test& a, const datenzugriff::Ab_oil_pressure_test& b ) noexcept->Compare
{
   return compare<datenzugriff::ab_oil_pressure_test::Key>( a.key, b.key );
}

bool nhill::datenzugriff::operator==( const Ab_oil_pressure_test& a, const Ab_oil_pressure_test& b )
{
   return a.key == b.key;
}

bool nhill::datenzugriff::operator!=( const Ab_oil_pressure_test& a, const Ab_oil_pressure_test& b )
{
   return !(a == b);
}

bool nhill::datenzugriff::operator<( const Ab_oil_pressure_test& a, const Ab_oil_pressure_test& b )
{
   return compare<const Ab_oil_pressure_test &>(a,b) == Compare::less;
}

bool nhill::datenzugriff::operator>( const Ab_oil_pressure_test& a, const Ab_oil_pressure_test& b )
{
   return compare<const Ab_oil_pressure_test&>(a,b) == Compare::greater;
}

bool nhill::datenzugriff::operator<=( const Ab_oil_pressure_test& a, const Ab_oil_pressure_test& b )
{
   return (a == b) || (a < b);
}

bool nhill::datenzugriff::operator>=( const Ab_oil_pressure_test& a, const Ab_oil_pressure_test& b )
{
   return (a == b) || (a > b);
}

