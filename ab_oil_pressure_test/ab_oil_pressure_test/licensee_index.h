#pragma once

#include "port.h"
#include "txt_parse.h"
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
static constexpr Parse licensee_code{ 26, 5 };
static constexpr Parse licensee_abbrv{ 32, 14 };
}
}

struct Licensee_index
{
	std::string licensee_code{};
	std::string licensee_abbrv{};
	uwi::List uwis; // sort format

	void clear();
};

using Licensee_index_container = std::vector<Licensee_index>;


NHILL_DZG_ABOPT_PORT_FUNCTION Licensee_index_container build_licensee_index( const std::filesystem::path& path_txt );
NHILL_DZG_ABOPT_PORT_FUNCTION bool build_licensee_index( const std::filesystem::path& path_out, const std::filesystem::path& path_txt );

NHILL_DZG_ABOPT_PORT_FUNCTION void sort_code_ascending( Licensee_index_container& lic_idxs );
NHILL_DZG_ABOPT_PORT_FUNCTION void sort_code_descending( Licensee_index_container& lic_idxs );
NHILL_DZG_ABOPT_PORT_FUNCTION void sort_code( Licensee_index_container& lic_idxs, Sort_order sort_order );

NHILL_DZG_ABOPT_PORT_FUNCTION void sort_abbrv_ascending( Licensee_index_container& lic_idxs );
NHILL_DZG_ABOPT_PORT_FUNCTION void sort_abbrv_descending( Licensee_index_container& lic_idxs );
NHILL_DZG_ABOPT_PORT_FUNCTION void sort_abbrv( Licensee_index_container& lic_idxs, Sort_order sort_order );


}
}
}
