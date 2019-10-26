#include "pool.h"
#include <stdexcept>

using namespace std;

template<>
string nhill::get_string( size_t pos, const Pool& pool )
{
	switch( pos )
	{
	case 0: return pool.code;
	case 1: return pool.name;
	default: throw invalid_argument( string{ "The position '" + to_string( pos ) + "' is out of range: [0,1]." }.c_str() );
	}
}

template<>
void nhill::set_string( size_t pos, Pool& pool, string_view str )
{
	switch( pos )
	{
	case 0: pool.code = str; break;
	case 1: pool.name = str; break;
	default: throw invalid_argument( string{ "The position '" + to_string( pos ) + "' is out of range: [0,1]." }.c_str() );
	}
}

void nhill::Pool::clear()
{
	code.clear();
	name.clear();
}
