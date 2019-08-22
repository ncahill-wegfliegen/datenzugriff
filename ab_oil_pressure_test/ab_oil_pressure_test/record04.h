#pragma once

#include "port.h"
#include "record.h"
#include "test_type.h"
#include "../../../gemeinsam/date_time/date.h"

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

/// <summary>Test data.</summary>
class NHILL_DZG_ABOPT_PORT_CLASS Record04 : public Record
{
public:
	using base = Record;

	Record04();

	Record04( const Record04& );
	Record04& operator=( const Record04& );

	Record04( Record04&& ) noexcept;
	Record04& operator=( Record04&& ) noexcept;

	~Record04();


	Date test_date;
	Test_type test_type;
	Date historical_well_status_date;
#pragma warning(suppress:4251)
	std::string historical_well_status_code;
	double casing_pressure;							// uom: kPa (kilopascal)
	double mpp_depth;									// midpoint perforation depth; uom: m (metre)
	double gauge_run_depth;							// uom: m (metre)
	double run_depth_gradient;						// uom: kPa/m (kilopascal per metre)
	double run_depth_pressure;						// uom: kPa (kilopascal)
	double reservoir_temperature;					// uom: °C
	double initial_liquid_level;					// uom: m (metre)
	double final_liquid_level;						// uom: m (metre)
	double gas_gradient;								// uom: kPa/m (kilopascal per metre)
	double oil_gradient;								// uom: kPa/m (kilopascal per metre)
	double water_gradient;							// uom: kPa/m (kilopascal per metre)
	double mpp_pressure;								// midpoint perforation pressure; uom: kPa (kilopascal)
	double datum_depth_pressure;					// uom: kPa (kilopascal)
	char   extrapolated_pressure_indicator;
	double extrapolated_mpp_pressure;			// extrapolated midpoint perforation pressure; uom: kPa (kilopascal)
	double extrapolated_datum_depth_pressure;	// uom: kPa (kilopascal)
	double shut_in_period;							// uom: h (hours)
	int    footnote_number;

	void clear() override;
};

}
}
}

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator==( const Record04& a, const Record04& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator!=( const Record04& a, const Record04& b );

}
}
}
