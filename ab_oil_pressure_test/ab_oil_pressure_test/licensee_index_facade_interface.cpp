#include "licensee_index_facade_interface.h"
#include "licensee_index_facade_xml.h"

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Licensee_index_facade_interface::Licensee_index_facade_interface() = default;
nhill::datenzugriff::ab_oil_pressure_test::Licensee_index_facade_interface::~Licensee_index_facade_interface() = default;

auto nhill::datenzugriff::ab_oil_pressure_test::Licensee_index_facade_interface::
make_unique( Source source )->std::unique_ptr<Licensee_index_facade_interface>
{
	switch( source )
	{
	case Source::xml: return std::make_unique<Licensee_index_facade_xml>();
	default: return nullptr;
	}
}
