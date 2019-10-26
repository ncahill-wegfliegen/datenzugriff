#pragma once

#include "port.h"
#include "facade_interface.h"
#include "../../../gemeinsam/uwi/dls.h"
#include <fstream>
#include <map>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
namespace txt
{

class NHILL_DZG_ABOPT_PORT_CLASS Txt_raw_facade : public Facade_interface
{
public:
	Txt_raw_facade();
	~Txt_raw_facade();

	Test_container find_test_by_uwi( const uwi::Dls& uwi ) final;
	Test_container find_test_by_licensee_code( const std::string& licensee_code ) final;
	Test_container find_test_by_field_pool( const std::string& field_code, const std::string& pool_code = {} ) final;
	Test_container find_test_by_test_type( const std::list<Test_type>& test_types ) final;

	std::streampos find_index( const uwi::Dls::Township& twp ) const;

private:
	std::ifstream in_;
	std::map<uint8_t, std::streampos> twpidx_; // Township index
};

}
}
}
}