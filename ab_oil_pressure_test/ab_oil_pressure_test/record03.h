#pragma once

#include "port.h"
#include "record.h"
#include <string>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

/// <summary>Well data.</summary>
class NHILL_DZG_ABOPT_PORT_CLASS Record03 : public Record
{
public:
	using base = Record;

	Record03();

	Record03( const Record03& );
	Record03& operator=( const Record03& );

	Record03( Record03&& ) noexcept;
	Record03& operator=( Record03&& ) noexcept;

	~Record03();

#pragma warning(push)
#pragma warning(disable:4251)
	std::string field_code;
	std::string pool_code;
#pragma warning(pop)
	double consol_interval_top;
	double consol_interval_bottom;
	double kb_elevation;
	double pool_datum_depth;
	double ground_elevation;
	double well_datum_depth;
	double initial_pool_pressure;
	double reservoir_gradient;

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

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator==( const Record03& a, const Record03& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator!=( const Record03& a, const Record03& b );

}
}
}
