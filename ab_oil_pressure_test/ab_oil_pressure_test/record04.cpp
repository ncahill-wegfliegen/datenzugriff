#include "record04.h"
#include "../../../gemeinsam/math/compare.h"
#include <memory>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Record04::Record04()
	: base{Record_type::test_data}
{
}

nhill::datenzugriff::ab_oil_pressure_test::Record04::Record04( const Record04& ) = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Record04::operator=( const Record04& other )->Record04 & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record04::Record04( Record04&& ) noexcept = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Record04::operator=( Record04&& other ) noexcept->Record04 & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record04::~Record04() = default;

void nhill::datenzugriff::ab_oil_pressure_test::Record04::clear()
{
	test_date.clear();
	test_type = Test_type::top_hole_undefined;
	historical_well_status_date.clear();
	historical_well_status_code.clear();
	casing_pressure = 0;							// uom: kPa (kilopascal)
	mpp_depth = 0;									// midpoint perforation depth; uom: m (metre)
	gauge_run_depth = 0;							// uom: m (metre)
	run_depth_gradient = 0;						// uom: kPa/m (kilopascal per metre)
	run_depth_pressure = 0;						// uom: kPa (kilopascal)
	reservoir_temperature = 0;					// uom: °C
	initial_liquid_level = 0;					// uom: m (metre)
	final_liquid_level = 0;						// uom: m (metre)
	gas_gradient = 0;								// uom: kPa/m (kilopascal per metre)
	oil_gradient = 0;								// uom: kPa/m (kilopascal per metre)
	water_gradient = 0;							// uom: kPa/m (kilopascal per metre)
	mpp_pressure = 0;								// midpoint perforation pressure; uom: kPa (kilopascal)
	datum_depth_pressure = 0;					// uom: kPa (kilopascal)
	extrapolated_pressure_indicator = '\0';
	extrapolated_mpp_pressure = 0;			// extrapolated midpoint perforation pressure; uom: kPa (kilopascal)
	extrapolated_datum_depth_pressure = 0;	// uom: kPa (kilopascal)
	shut_in_period = 0;							// uom: h (hours)
	footnote_number = 0;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator==( const Record04& a, const Record04& b )
{
	return dynamic_cast<const Record&>(a) == dynamic_cast<const Record&>(b)
		&& a.test_date == b.test_date
		&& a.test_type == b.test_type
		&& a.historical_well_status_date == b.historical_well_status_date
		&& a.historical_well_status_code == b.historical_well_status_code
		&& math::equal<double, double>( a.casing_pressure, b.casing_pressure )
		&& math::equal<double, double>( a.mpp_depth, b.mpp_depth )
		&& math::equal<double, double>( a.gauge_run_depth, b.gauge_run_depth )
		&& math::equal<double, double>( a.run_depth_gradient, b.run_depth_gradient )
		&& math::equal<double, double>( a.run_depth_pressure, b.run_depth_pressure )
		&& math::equal<double, double>( a.reservoir_temperature, b.reservoir_temperature )
		&& math::equal<double, double>( a.initial_liquid_level, b.initial_liquid_level )
		&& math::equal<double, double>( a.final_liquid_level, b.final_liquid_level )
		&& math::equal<double, double>( a.gas_gradient, b.gas_gradient )
		&& math::equal<double, double>( a.oil_gradient, b.oil_gradient )
		&& math::equal<double, double>( a.water_gradient, b.water_gradient )
		&& math::equal<double, double>( a.mpp_pressure, b.mpp_pressure )
		&& math::equal<double, double>( a.datum_depth_pressure, b.datum_depth_pressure )
		&& a.extrapolated_pressure_indicator == b.extrapolated_pressure_indicator
		&& math::equal<double, double>( a.extrapolated_mpp_pressure, b.extrapolated_mpp_pressure )
		&& math::equal<double, double>( a.extrapolated_datum_depth_pressure, b.extrapolated_datum_depth_pressure )
		&& math::equal<double, double>( a.shut_in_period, b.shut_in_period )
		&& a.footnote_number == b.footnote_number
		;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator!=( const Record04& a, const Record04& b )
{
	return !(a == b);
}

