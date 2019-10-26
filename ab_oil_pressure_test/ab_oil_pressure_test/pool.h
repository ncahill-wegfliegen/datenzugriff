#pragma once

#include "port.h"
#include "../../../gemeinsam/utility/get_string.h"
#include <string>
#include <vector>

namespace nhill
{

class NHILL_DZG_ABOPT_PORT_CLASS Pool
{
public:
	std::string code;
	std::string name;

	void clear();
};

using Pool_container = std::vector<Pool>;

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
std::string get_string( size_t pos, const Pool& pool );

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
void set_string( size_t pos, Pool& pool, std::string_view str );

}