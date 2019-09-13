#include "txt_record.h"
#include "record_type_ex.h"
#include "txt_parse.h"

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_record::
Txt_record() = default;

nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_record::
~Txt_record() = default;


auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_record::
record_type() const->Record_type
{
	return type_;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_record::
key() const->const Txt_key &
{
	return key_;
}


void nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_record::parse( const std::string& s)
{
	text_ = s;
	type_ = to_enum<Record_type>( stoi( s.substr( parse::record_type.pos, parse::record_type.count ) ) );
	key_.parse( s );
}

