#include "field_index_facade_xml.h"
#include "field_pool.h"
#include "xml_field_index.h"
#include "configuration.h"

using namespace std;

namespace
{
std::filesystem::path path()
{
	std::filesystem::path path{ nhill::datenzugriff::ab_oil_pressure_test::Configuration::instance().txt.path.parent_path() };
	path /= "field.idx";
	return path;
}
}

auto nhill::datenzugriff::ab_oil_pressure_test::Field_index_facade_xml::
find_by_code( const std::string& field_code, const std::string& pool_code )->Field_index
{
	Field_index lic_idx;

	if( !xml::find_by_code( lic_idx, field_code, pool_code, path().string() ) )
	{
		throw exception( string{ "Unable to find the field index element for the  field code '" + field_code + "'." }.c_str() );
	}

	return lic_idx;
}

auto nhill::datenzugriff::ab_oil_pressure_test::Field_index_facade_xml::
find_all_codes()->Field_index_container
{
	Field_index_container lic_idxs;

	if( !xml::find_all_codes( lic_idxs, path().string() ) )
	{
		throw exception( "Unable to find the all licesee codes." );
	}

	return lic_idxs;
}

auto nhill::datenzugriff::ab_oil_pressure_test::Field_index_facade_xml::find_all_field_pools()->Field_pool_container
{
	Field_pool_container fld_pls;

	if( !xml::find( fld_pls, path().string() ) )
	{
		throw exception( "Unable to find the all fields and pools." );
	}

	return fld_pls;
}
