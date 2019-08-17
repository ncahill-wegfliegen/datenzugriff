#include "record.h"
#include "record00.h"
#include "record01.h"
#include "record02.h"
#include "record03.h"
#include "record04.h"
#include "record05.h"
#include <stdexcept>
#include <memory>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Record::Record(Record_type type)
	: type_{type}
{
}

nhill::datenzugriff::ab_oil_pressure_test::Record::Record( const Record& ) = default;

auto nhill::datenzugriff::ab_oil_pressure_test::Record::operator=( const Record& other )->Record & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record::Record( Record&& ) noexcept = default;

auto nhill::datenzugriff::ab_oil_pressure_test::Record::operator=( Record&& other ) noexcept->Record & = default;

nhill::datenzugriff::ab_oil_pressure_test::Record::~Record() = default;

auto nhill::datenzugriff::ab_oil_pressure_test::Record::type() const->Record_type
{
	return type_;
}

void nhill::datenzugriff::ab_oil_pressure_test::Record::clear()
{
}

auto nhill::datenzugriff::ab_oil_pressure_test::Record::make_unique( Record_type type )->std::unique_ptr<Record>
{
	switch( type )
	{
	case Record_type::well_id   : return std::make_unique<Record00>();
	case Record_type::licensee  : return std::make_unique<Record01>();
	case Record_type::field_pool: return std::make_unique<Record02>();
	case Record_type::well_data : return std::make_unique<Record03>();
	case Record_type::test_data : return std::make_unique<Record04>();
	case Record_type::remarks   : return std::make_unique<Record05>();
	default: return nullptr;
	}
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator==( const Record& a, const Record& b )
{
	return a.type() == b.type();
}

bool nhill::datenzugriff::ab_oil_pressure_test::operator!=( const Record& a, const Record& b )
{
	return !(a == b);
}
