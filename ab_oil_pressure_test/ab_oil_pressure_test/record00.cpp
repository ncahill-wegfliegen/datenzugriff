#include "record00.h"
#include "key.h"
#include <memory>
#include <algorithm>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Record00::Record00()
   : base{Record_type::well_id}
   , well_name{}
   , on_production_date{1900,1,1}
{
}

nhill::datenzugriff::ab_oil_pressure_test::Record00::Record00( const Record00& ) = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Record00::operator=( const Record00& other )->Record00 & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record00::Record00( Record00&& ) noexcept = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Record00::operator=( Record00&& other ) noexcept->Record00 & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record00::~Record00() = default;

void nhill::datenzugriff::ab_oil_pressure_test::Record00::clear()
{
   base::clear();
   well_name.clear();
   on_production_date.clear();
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator==( const Record00& a, const Record00& b )
{
   return dynamic_cast<const Record&>(a) == dynamic_cast<const Record&>(b)
      && a.well_name == b.well_name
      && a.on_production_date == b.on_production_date;
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator!=( const Record00& a, const Record00& b )
{
   return !(a == b);
}
