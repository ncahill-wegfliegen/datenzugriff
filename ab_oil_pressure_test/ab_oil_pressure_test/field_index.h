#pragma once

#include "port.h"
#include "txt_parse.h"
#include "field.h"
#include "pool.h"
#include "../../../gemeinsam/enum/sort_order.h"
#include "../../../gemeinsam/uwi/list.h"

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
namespace txt
{
namespace parse
{
constexpr Parse field_name{ 26, 20 };
constexpr Parse pool_name { 47, 21 };

constexpr Parse field_code{ 26, 4 };
constexpr Parse pool_code{ 31, 7 };
}
}

struct Field_index
{
	Field field;
	Pool pool;
	uwi::List uwis; // sort format

	void clear();
};

using Field_index_container = std::vector<Field_index>;


NHILL_DZG_ABOPT_PORT_FUNCTION Field_index_container build_field_index( const std::filesystem::path& path_txt );
NHILL_DZG_ABOPT_PORT_FUNCTION bool build_field_index( const std::filesystem::path& path_out, const std::filesystem::path& path_txt );

//NHILL_DZG_ABOPT_PORT_FUNCTION void sort_code_ascending( Licensee_index_container& lic_idxs );
//NHILL_DZG_ABOPT_PORT_FUNCTION void sort_code_descending( Licensee_index_container& lic_idxs );
//NHILL_DZG_ABOPT_PORT_FUNCTION void sort_code( Licensee_index_container& lic_idxs, Sort_order sort_order );
//
//NHILL_DZG_ABOPT_PORT_FUNCTION void sort_abbrv_ascending( Licensee_index_container& lic_idxs );
//NHILL_DZG_ABOPT_PORT_FUNCTION void sort_abbrv_descending( Licensee_index_container& lic_idxs );
//NHILL_DZG_ABOPT_PORT_FUNCTION void sort_abbrv( Licensee_index_container& lic_idxs, Sort_order sort_order );


}
}
}
