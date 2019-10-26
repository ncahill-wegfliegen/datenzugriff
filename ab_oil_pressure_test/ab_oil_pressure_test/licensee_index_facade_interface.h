#pragma once

#include "port.h"
#include "licensee_index.h"
#include "source.h"

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Licensee_index_facade_interface
{
public:
	Licensee_index_facade_interface();
	virtual ~Licensee_index_facade_interface();

	virtual Licensee_index find_by_code( const std::string& licensee_code) = 0;
	virtual Licensee_index_container find_all_codes() = 0;

	static std::unique_ptr<Licensee_index_facade_interface> make_unique( Source source );
};

}
}
}
