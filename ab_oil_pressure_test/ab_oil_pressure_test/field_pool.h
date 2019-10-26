#pragma once

#include "port.h"
#include "field.h"
#include "pool.h"
#include "../../../gemeinsam/utility/get_string.h"
#include <string>

namespace nhill
{

class NHILL_DZG_ABOPT_PORT_CLASS Field_pool 
{
public:
	Field field;
	Pool_container pools;

	void clear();
};

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
std::string get_string( size_t pos, const Field_pool& fld_pls );

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
void set_string( size_t pos, Field_pool& fld_pls, std::string_view str );

}