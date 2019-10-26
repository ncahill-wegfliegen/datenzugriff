#pragma once

#include "port.h"
#include "pool.h"
#include "../../../gemeinsam/utility/get_string.h"
#include <string>
#include <vector>

namespace nhill
{

class NHILL_DZG_ABOPT_PORT_CLASS Field
{
public:
	std::string code;
	std::string name;

	void clear();
};

using Field_container = std::vector<Field>;

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
std::string get_string( size_t pos, const Field& field );

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
void set_string( size_t pos, Field& field, std::string_view str );

}