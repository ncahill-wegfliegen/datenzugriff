#pragma once

#include "port.h"
#include "record.h"
#include "../../gemeinsam/date_time/date.h"
#include <string>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

/// <summary>Licensee and well status.</summary>
class NHILL_DZG_ABOPT_PORT_CLASS Record01 : public Record
{
public:
	using base = Record;

	Record01();

	Record01( const Record01& );
	Record01& operator=( const Record01& );

	Record01( Record01&& ) noexcept;
	Record01& operator=( Record01&& ) noexcept;

	~Record01();

#pragma warning(push)
#pragma warning(disable:4251)
	std::string licensee_code;
	std::string licensee_abbrev;
	std::string survey_coord_oper_code;
	std::string survey_coord_abbrev;

	Date well_status_date;
	std::string well_status_code;
#pragma warning(pop)

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

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator==( const Record01& a, const Record01& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator!=( const Record01& a, const Record01& b );

}
}
}


