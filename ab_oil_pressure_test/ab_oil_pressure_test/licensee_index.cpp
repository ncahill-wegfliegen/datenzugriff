#include "licensee_index.h"
#include "xml_licensee_index.h"
#include "../../../gemeinsam/utility/str.h"
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


void nhill::datenzugriff::ab_oil_pressure_test::
Licensee_index::clear()
{
	licensee_code.clear();
	licensee_abbrv.clear();
	uwis.clear();
}


auto nhill::datenzugriff::ab_oil_pressure_test::
build_licensee_index( const std::filesystem::path& path_txt )->Licensee_index_container
{
	string line;
	string licensee_code{};
	Licensee_index_container licidxc{};
	ifstream in{ path_txt };

	if( !in.is_open() )
	{
		return licidxc;
	}

	while( getline( in, line ) )
	{
		// we are only looking for 01 records
		if( txt::parse::get_record_type( line ) == Record_type::licensee )
		{
			// Get the licensee code
			licensee_code = str::trim_copy_end( line.substr( txt::parse::licensee_code.pos, txt::parse::licensee_code.count ) );
			// Find this licensee code in the container
			auto itr{
				find_if(
					licidxc.begin(),
					licidxc.end(),
					[&licensee_code]( const auto& licidx )
					{
						return licidx.licensee_code == licensee_code;
					}
				)
			};
			if( itr == licidxc.end() )
			{
				// Add a new licensee index to the collection
				Licensee_index licidx{};
				licidx.licensee_code  = licensee_code;
				licidx.licensee_abbrv = str::trim_copy_end( line.substr( txt::parse::licensee_abbrv.pos, txt::parse::licensee_abbrv.count ) );
				licidxc.push_back( licidx );
				itr = licidxc.end();
				--itr; // point to the licensee index that we just added
			}

			// Add the uwi to the licensee index
			itr->uwis.emplace( txt::parse::uwi_raw_to_sort( line ).first );
		}
	}

	in.close();

	return licidxc;
}

bool nhill::datenzugriff::ab_oil_pressure_test::
build_licensee_index( const std::filesystem::path& path_out, const std::filesystem::path& path_txt )
{
	Licensee_index_container lic_idxs{ build_licensee_index( path_txt ) };
	tinyxml2::XMLError error{ xml::write( path_out.string(), lic_idxs, "licensee_indexes" ) };
	return error == tinyxml2::XMLError::XML_NO_ERROR;
}

void nhill::datenzugriff::ab_oil_pressure_test::
sort_code_ascending( Licensee_index_container& lic_idxs )
{
	sort(
		lic_idxs.begin(),
		lic_idxs.end(),
		[]( const auto& a, const auto& b )
		{
			return a.licensee_code.compare( b.licensee_code ) > 0;
		}
	);
}

void nhill::datenzugriff::ab_oil_pressure_test::
sort_code_descending( Licensee_index_container& lic_idxs )
{
	sort(
		lic_idxs.begin(),
		lic_idxs.end(),
		[]( const auto& a, const auto& b )
		{
			return a.licensee_code.compare( b.licensee_code ) < 0;
		}
	);
}

void nhill::datenzugriff::ab_oil_pressure_test::
sort_code( Licensee_index_container& lic_idxs, Sort_order sort_order )
{
	switch( sort_order )
	{
	case Sort_order::ascending: sort_code_ascending( lic_idxs ); break;
	case Sort_order::descending: sort_code_descending( lic_idxs ); break;
	}
}

void nhill::datenzugriff::ab_oil_pressure_test::
sort_abbrv_ascending( Licensee_index_container& lic_idxs )
{
	sort(
		lic_idxs.begin(),
		lic_idxs.end(),
		[]( const auto& a, const auto& b )
		{
			return a.licensee_abbrv.compare( b.licensee_abbrv ) > 0;
		}
	);
}

void nhill::datenzugriff::ab_oil_pressure_test::
sort_abbrv_descending( Licensee_index_container& lic_idxs )
{
	sort(
		lic_idxs.begin(),
		lic_idxs.end(),
		[]( const auto& a, const auto& b )
		{
			return a.licensee_abbrv.compare( b.licensee_abbrv ) < 0;
		}
	);
}


void nhill::datenzugriff::ab_oil_pressure_test::
sort_abbrv( Licensee_index_container& lic_idxs, Sort_order sort_order )
{
	switch( sort_order )
	{
	case Sort_order::ascending:  sort_abbrv_ascending( lic_idxs ); break;
	case Sort_order::descending: sort_abbrv_descending( lic_idxs ); break;
	}
}
