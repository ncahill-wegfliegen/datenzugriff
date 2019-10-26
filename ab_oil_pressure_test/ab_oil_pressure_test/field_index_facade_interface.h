#pragma once

#include "port.h"
#include "field_index.h"
#include "field.h"
#include "field_pool_container.h"
#include "source.h"

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Field_index_facade_interface
{
public:
	Field_index_facade_interface();
	virtual ~Field_index_facade_interface();

	virtual Field_index find_by_code( const std::string& field_code, const std::string& pool_code ) = 0;
	virtual Field_index_container find_all_codes() = 0;
	virtual Field_pool_container find_all_field_pools() = 0;

	static std::unique_ptr<Field_index_facade_interface> make_unique( Source source );
};

}
}
}
