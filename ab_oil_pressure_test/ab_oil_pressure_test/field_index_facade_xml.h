#pragma once

#include "port.h"
#include "field_index_facade_interface.h"
#include "field_pool_container.h"

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Field_index_facade_xml : public Field_index_facade_interface
{
public:
	Field_index find_by_code( const std::string& field_code, const std::string& pool_code ) override;
	Field_index_container find_all_codes() override;
	Field_pool_container find_all_field_pools() override;
};


}
}
}