#include "field_index.h"
#include "xml_field_index.h"
#include "../../../gemeinsam/utility/str.h"
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void nhill::datenzugriff::ab_oil_pressure_test::Field_index::
clear()
{
	field.code.clear();
	pool.code.clear();

	field.name.clear();
	pool.name.clear();

	uwis.clear();
}

auto nhill::datenzugriff::ab_oil_pressure_test::
build_field_index( const std::filesystem::path& path_txt )->Field_index_container
{
	string line02; // Field and pool names
	string line03; // Field and pool codes
	string field_code;
	string pool_code;
	Field_index_container fld_idxs; // The field indexes
	ifstream in{ path_txt };

	if( !in.is_open() )
	{
		return fld_idxs;
	}

	while( getline( in, line02 ) )
	{
		if( txt::parse::get_record_type( line02 ) == Record_type::field_pool )
		{
			// Get the field and pool codes
			getline( in, line03 );
			field_code = str::trim_copy_end( line03.substr( txt::parse::field_code.pos, txt::parse::field_code.count ) );
			pool_code  = str::trim_copy_end( line03.substr( txt::parse::pool_code.pos, txt::parse::pool_code.count ) );
			// Find the codes in the container
			auto itr{
				find_if(
					fld_idxs.begin(),
					fld_idxs.end(),
					[&field_code,&pool_code]( const auto& fld_idx )
					{
						return fld_idx.field.code == field_code && fld_idx.pool.code == pool_code;
					}
				)
			};
			if( itr == fld_idxs.end() )
			{
				Field_index fld_idx{};
				fld_idx.field.code = field_code;
				fld_idx.pool.code = pool_code;
				fld_idx.field.name = str::trim_copy_end( line02.substr( txt::parse::field_name.pos, txt::parse::field_name.count ) );
				fld_idx.pool.name = str::trim_copy_end( line02.substr( txt::parse::pool_name.pos, txt::parse::pool_name.count ) );
				fld_idxs.push_back( fld_idx );
				itr = fld_idxs.end();
				--itr; // point to the field index that we just added
			}

			// Add the uwi to the index
			itr->uwis.emplace( txt::parse::uwi_raw_to_sort( line02 ).first );
		}
	}

	in.close();

	return fld_idxs;
}

bool nhill::datenzugriff::ab_oil_pressure_test::
build_field_index( const std::filesystem::path& path_out, const std::filesystem::path& path_txt )
{
	Field_index_container lic_idxs{ build_field_index( path_txt ) };
	tinyxml2::XMLError error{ xml::write( path_out.string(), lic_idxs, "field_indexes" ) };
	return error == tinyxml2::XMLError::XML_NO_ERROR;
}
