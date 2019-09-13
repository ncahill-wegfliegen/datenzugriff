#include "test.h"

void nhill::datenzugriff::ab_oil_pressure_test::Test::clear()
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
auto nhill::compare( const datenzugriff::ab_oil_pressure_test::Test& a, const datenzugriff::ab_oil_pressure_test::Test& b ) noexcept->Compare
{
   return compare<datenzugriff::ab_oil_pressure_test::Key>( a.key, b.key );
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator==( const Test& a, const Test& b )
{
   return a.key == b.key;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator!=( const Test& a, const Test& b )
{
   return !(a == b);
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator<( const Test& a, const Test& b )
{
   return compare<const Test &>(a,b) == Compare::less;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator>( const Test& a, const Test& b )
{
   return compare<const Test&>(a,b) == Compare::greater;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator<=( const Test& a, const Test& b )
{
   return (a == b) || (a < b);
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator>=( const Test& a, const Test& b )
{
   return (a == b) || (a > b);
}

