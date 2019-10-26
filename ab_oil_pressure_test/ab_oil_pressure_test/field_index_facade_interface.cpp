#include "field_index_facade_interface.h"
#include "field_index_facade_xml.h"

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Field_index_facade_interface::Field_index_facade_interface() = default;
nhill::datenzugriff::ab_oil_pressure_test::Field_index_facade_interface::~Field_index_facade_interface() = default;

auto nhill::datenzugriff::ab_oil_pressure_test::Field_index_facade_interface::
make_unique( Source source )->std::unique_ptr<Field_index_facade_interface>
{
	switch( source )
	{
	case Source::xml: return std::make_unique<Field_index_facade_xml>();
	default: return nullptr;
	}
}
