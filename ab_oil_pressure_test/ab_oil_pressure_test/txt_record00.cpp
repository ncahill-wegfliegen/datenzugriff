#include "txt_record00.h"
#include "txt_parse.h"
#include "../../../gemeinsam/utility/str.h"

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_record00::
Txt_record00() = default;

nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_record00::
Txt_record00( const string& s)
{
	parse( s );
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_record00::
operator=( const string& s )->Txt_record00 &
{
	parse( s );
	return *this;
}

nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_record00::
~Txt_record00() = default;


auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_record00::
well_name() const->string
{
	return well_name_;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_record00::
on_production_date() const->string
{
	return on_production_date_;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_record00::
parse( const string& s)->void
{
	base::parse( s );

	well_name_ = s.substr( parse::well_name.pos, parse::well_name.count );
	str::trim_end( well_name_ );

	on_production_date_ = s.substr( parse::on_production_date.pos, parse::on_production_date.count );
}
