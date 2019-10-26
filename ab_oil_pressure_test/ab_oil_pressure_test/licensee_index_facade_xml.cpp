#include "licensee_index_facade_xml.h"
#include "xml_licensee_index.h"
#include "configuration.h"
#include "licensee_index_facade_xml.h"

using namespace std;

namespace
{
std::filesystem::path path()
{
	std::filesystem::path path{ nhill::datenzugriff::ab_oil_pressure_test::Configuration::instance().txt.path.parent_path() };
	path /= "licensee.idx";
	return path;
}
}

auto nhill::datenzugriff::ab_oil_pressure_test::Licensee_index_facade_xml::
find_by_code( const std::string& licensee_code )->Licensee_index
{
	Licensee_index lic_idx;

	if( !xml::find_by_code( lic_idx, licensee_code, path().string() ) )
	{
		throw exception( string{ "Unable to find the licensee index element for the  licensee code '" + licensee_code + "'." }.c_str() );
	}

	return lic_idx;
}

auto nhill::datenzugriff::ab_oil_pressure_test::Licensee_index_facade_xml::
find_all_codes()->Licensee_index_container
{
	Licensee_index_container lic_idxs;

	if( !xml::find_all_codes( lic_idxs, path().string() ) )
	{
		throw exception( "Unable to find the all licesee codes." );
	}

	return lic_idxs;
}
