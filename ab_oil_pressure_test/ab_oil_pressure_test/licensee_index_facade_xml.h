#pragma once

#include "port.h"
#include "licensee_index_facade_interface.h"

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Licensee_index_facade_xml : public Licensee_index_facade_interface
{
public:
	Licensee_index find_by_code( const std::string& licensee_code ) override;
	Licensee_index_container find_all_codes() override;

};


}
}
}