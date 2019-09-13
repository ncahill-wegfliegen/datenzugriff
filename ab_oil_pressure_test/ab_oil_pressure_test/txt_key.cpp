#include "txt_key.h"
#include "txt_parse.h"

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
Txt_key()
	: le_{'0','0'}
	, lsd_{0}
	, sc_{0}
	, twp_{0}
	, rg_{0}
	, m_{0}
	, es_{'0'}
	, cin_{0}
{
}

nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
Txt_key( const std::string& s)
	: Txt_key{}
{
	parse( s );
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
operator=( const std::string& s )->Txt_key &
{
	parse( s );
	return *this;
}

nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
Txt_key( const Txt_key& ) = default;

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
operator=( const Txt_key& )->Txt_key & = default;

nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
Txt_key( Txt_key&& ) noexcept = default;

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
operator=( Txt_key&& ) noexcept->Txt_key & = default;

nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
~Txt_key() = default;

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
location_exception() const->array<char, 2>
{
	return le_;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
legal_subdivision() const->int
{
	return lsd_;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
section() const->int
{
	return sc_;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
township() const->int
{
	return twp_;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
range() const->int
{
	return rg_;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
meridian() const->int
{
	return m_;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
event_sequence() const->char
{
	return es_;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
consol_interval_num() const->int
{
	return cin_;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::
parse( const string& s)->void
{
	le_  = { s[parse::location_exception.pos], s[parse::location_exception.pos + 1] };
	lsd_ = static_cast<uint8_t>(stoi( s.substr( parse::legal_subdivision.pos, parse::legal_subdivision.count ) ));
	sc_  = static_cast<uint8_t>(stoi( s.substr( parse::section.pos, parse::section.count ) ));
	twp_ = static_cast<uint8_t>(stoi( s.substr( parse::township.pos, parse::township.count ) ));
	rg_  = static_cast<uint8_t>(stoi( s.substr( parse::range.pos, parse::range.count ) ));
	m_   = static_cast<uint8_t>(stoi( s.substr( parse::meridian.pos, parse::meridian.count ) ));
	es_  = s[parse::event_sequence.pos];
	cin_ = static_cast<uint8_t>(stoi( s.substr( parse::consol_interval_num.pos, parse::consol_interval_num.count ) ));
}

void nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_key::clear()
{
	le_ = {'0', '\0'};
	lsd_ = 0;
	sc_ = 0;
	twp_ = 0;
	rg_ = 0;
	m_ = 0;
	es_ = '0';
	cin_ = 0;
}
