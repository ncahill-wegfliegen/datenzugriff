#include "record05.h"
#include <memory>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Record05::Record05()
	: base{Record_type::remark}
	, remark_indicator{0}
	, remark{}
{
}

nhill::datenzugriff::ab_oil_pressure_test::Record05::Record05( const Record05& ) = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Record05::operator=( const Record05& other )->Record05 & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record05::Record05( Record05&& ) noexcept = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Record05::operator=( Record05&& other ) noexcept->Record05 & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record05::~Record05() = default;

void nhill::datenzugriff::ab_oil_pressure_test::Record05::clear()
{
	remark_indicator = 0;
	remark.clear();
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator==( const Record05& a, const Record05& b )
{
	return dynamic_cast<const Record&>(a) == dynamic_cast<const Record&>(b)
		&& a.remark_indicator == b.remark_indicator
		&& a.remark == b.remark
		;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator!=( const Record05& a, const Record05& b )
{
	return !(a == b);
}
