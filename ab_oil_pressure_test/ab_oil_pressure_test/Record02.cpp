#include "record02.h"
#include <memory>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Record02::Record02()
   : base{Record_type::field_pool}
   , field_name{}
   , pool_name{}
{
}

nhill::datenzugriff::ab_oil_pressure_test::Record02::Record02( const Record02& ) = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Record02::operator=( const Record02& other )->Record02 & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record02::Record02( Record02&& ) noexcept = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Record02::operator=( Record02&& other ) noexcept->Record02 & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record02::~Record02() = default;

void nhill::datenzugriff::ab_oil_pressure_test::Record02::clear()
{
	base::clear();

	field_name.clear();
	pool_name.clear();
}


bool nhill::datenzugriff::ab_oil_pressure_test::operator==( const Record02& a, const Record02& b )
{
	return dynamic_cast<const Record&>(a) == dynamic_cast<const Record&>(b)
		&& a.field_name == b.field_name
		&& a.pool_name == b.pool_name;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator!=( const Record02& a, const Record02& b )
{
	return !(a == b);
}


