#include "record00.h"
#include <memory>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Record00::Record00()
	: base{Record_type::well_id}
{
}

nhill::datenzugriff::ab_oil_pressure_test::Record00::Record00( const Record00& ) = default;

auto nhill::datenzugriff::ab_oil_pressure_test::Record00::operator=( const Record00& other)->Record00 &
{
   base::operator=( other );
   return *this;
}

nhill::datenzugriff::ab_oil_pressure_test::Record00::Record00( Record00&& ) noexcept = default;

auto nhill::datenzugriff::ab_oil_pressure_test::Record00::operator=( Record00&& other) noexcept->Record00 &
{
   base::operator=( move( other ) );
   return *this;
}

nhill::datenzugriff::ab_oil_pressure_test::Record00::~Record00() = default;
