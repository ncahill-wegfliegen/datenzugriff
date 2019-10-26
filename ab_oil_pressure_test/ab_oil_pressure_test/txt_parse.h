#pragma once

#include "port.h"
#include "record_type.h"
#include <string_view>
#include <list>
#include <array>
#include <filesystem>
#include <map>

namespace nhill
{
namespace uwi
{
class Dls;
}
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
namespace txt
{

struct Parse
{
	size_t pos;
	size_t count;
};

struct Twpidx
{
	uint8_t twp; // The township number
	std::streampos idx; // The position in the text file
};
using Twpidx_container = std::map<uint8_t, std::streampos>;


NHILL_DZG_ABOPT_PORT_FUNCTION bool operator==( const Parse& a, const Parse& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator!=( const Parse& a, const Parse& b );

namespace parse
{
static constexpr Parse record_type{ 0,2 };

static constexpr Parse location_exception{ 3,2 };
static constexpr Parse legal_subdivision{ 6, 2 };
static constexpr Parse section{ 9,2 };
static constexpr Parse township{ 12, 3 };
static constexpr Parse range{ 16, 2 };
static constexpr Parse meridian{ 19, 1 };
static constexpr Parse event_sequence{ 21, 1 };
static constexpr Parse consol_interval_num{ 23,2 };

static constexpr Parse uwi{ 3, 20 };
static constexpr Parse key{ 3, 23 };

static constexpr Parse well_name{ 26,36 };
static constexpr Parse on_production_date{ 63,8 };


NHILL_DZG_ABOPT_PORT_FUNCTION bool equal( std::string_view a, std::string_view b, const std::list<Parse>& parse_list );

NHILL_DZG_ABOPT_PORT_FUNCTION Record_type get_record_type( std::string_view raw_line );

NHILL_DZG_ABOPT_PORT_FUNCTION std::string uwi_display_to_raw( std::string_view display, int consol_interval_num = 0, std::string_view record_type = "00" );
NHILL_DZG_ABOPT_PORT_FUNCTION std::string uwi_basic_to_raw( std::string_view basic, int consol_interval_num = 0, std::string_view record_type = "00" );
NHILL_DZG_ABOPT_PORT_FUNCTION std::string uwi_sort_to_raw( std::string_view sort, int consol_interval_num = 0, std::string_view record_type = "00" );

NHILL_DZG_ABOPT_PORT_FUNCTION std::pair<std::string, int> uwi_raw_to_display( std::string raw );
NHILL_DZG_ABOPT_PORT_FUNCTION std::pair<std::string, int> uwi_raw_to_basic( std::string raw );
NHILL_DZG_ABOPT_PORT_FUNCTION std::pair<std::string, int> uwi_raw_to_sort( std::string raw );

NHILL_DZG_ABOPT_PORT_FUNCTION bool build_township_index( const std::filesystem::path& path_out, const std::filesystem::path& path_txt );
NHILL_DZG_ABOPT_PORT_FUNCTION bool read_township_index( Twpidx_container& twpidxs, const std::filesystem::path& path );

}


}
}
}
}
