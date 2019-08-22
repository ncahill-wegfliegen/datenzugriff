#include "record03.h"
#include "../../../gemeinsam/math/compare.h"
#include <memory>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Record03::Record03()
	: base{Record_type::well_data}
	, field_code{}
	, pool_code{}
	, consol_interval_top{0}
	, consol_interval_bottom{0}
	, kb_elevation{0}
	, pool_datum_depth{0}
	, ground_elevation{0}
	, well_datum_depth{0}
	, initial_pool_pressure{0}
	, reservoir_gradient{0}
{
}

nhill::datenzugriff::ab_oil_pressure_test::Record03::Record03( const Record03& ) = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Record03::operator=( const Record03& other )->Record03 & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record03::Record03( Record03&& ) noexcept = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Record03::operator=( Record03&& other ) noexcept->Record03 & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record03::~Record03() = default;

void nhill::datenzugriff::ab_oil_pressure_test::Record03::clear()
{
	base::clear();

	field_code.clear();
	pool_code.clear();
	consol_interval_top = 0;
	consol_interval_bottom = 0;
	kb_elevation = 0;
	pool_datum_depth = 0;
	ground_elevation = 0;
	well_datum_depth = 0;
	initial_pool_pressure = 0;
	reservoir_gradient = 0;
}


bool nhill::datenzugriff::ab_oil_pressure_test::operator==( const Record03& a, const Record03& b )
{
	return dynamic_cast<const Record&>(a) == dynamic_cast<const Record&>(b)
		&& a.field_code == b.field_code
		&& a.pool_code == b.pool_code
		&& math::equal<double,double>( a.consol_interval_top, b.consol_interval_top )
		&& math::equal<double,double>( a.consol_interval_bottom, b.consol_interval_bottom )
		&& math::equal<double,double>( a.kb_elevation, b.kb_elevation )
		&& math::equal<double,double>( a.pool_datum_depth, b.pool_datum_depth )
		&& math::equal<double,double>( a.ground_elevation, b.ground_elevation )
		&& math::equal<double,double>( a.well_datum_depth, b.well_datum_depth )
		&& math::equal<double,double>( a.initial_pool_pressure, b.initial_pool_pressure )
		&& math::equal<double,double>( a.reservoir_gradient, b.reservoir_gradient )
	;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator!=( const Record03& a, const Record03& b )
{
	return !(a == b);
}

