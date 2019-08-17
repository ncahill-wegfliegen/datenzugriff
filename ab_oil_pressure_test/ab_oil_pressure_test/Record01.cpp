#include "record01.h"
#include <memory>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Record01::Record01()
	: base{Record_type::licensee}
{
}

nhill::datenzugriff::ab_oil_pressure_test::Record01::Record01( const Record01& ) = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Record01::operator=( const Record01& other )->Record01 & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record01::Record01( Record01&& ) noexcept = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Record01::operator=( Record01&& other ) noexcept->Record01 & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record01::~Record01() = default;

void nhill::datenzugriff::ab_oil_pressure_test::Record01::clear()
{
	base::clear();

	licensee_code.clear();
	licensee_abbrev.clear();
	survey_coord_oper_code.clear();
	survey_coord_abbrev.clear();
	well_status_date.clear();
	well_status_code.clear();
}


bool nhill::datenzugriff::ab_oil_pressure_test::operator==( const Record01& a, const Record01& b )
{
	return dynamic_cast<const Record&>(a) == dynamic_cast<const Record&>(b)
		&& a.licensee_code == b.licensee_code
		&& a.licensee_abbrev == b.licensee_abbrev
		&& a.survey_coord_oper_code == b.survey_coord_oper_code
		&& a.survey_coord_abbrev == b.survey_coord_abbrev
		&& a.well_status_date == b.well_status_date
		&& a.well_status_code == b.well_status_code;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator!=( const Record01& a, const Record01& b )
{
	return !(a == b);
}

