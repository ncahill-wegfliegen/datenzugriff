#include "field_pool.h"
#include <stdexcept>

using namespace std;

void nhill::Field_pool::clear()
{
	field.clear();
	pools.clear();
}

template<>
string nhill::get_string( size_t pos, const Field_pool& fld_pl )
{
	switch( pos )
	{
	case 0: return fld_pl.field.code;
	case 1: return fld_pl.field.name;
	default: throw invalid_argument( string{ "The position '" + to_string( pos ) + "' is out of range: [0,1]." }.c_str() );
	}
}

template<>
void nhill::set_string( size_t pos, Field_pool& fld_pl, std::string_view str )
{
	switch( pos )
	{
	case 0: fld_pl.field.code = str; break;
	case 1: fld_pl.field.name = str; break;
	default: throw invalid_argument( string{ "The position '" + to_string( pos ) + "' is out of range: [0,1]." }.c_str() );
	}
}


