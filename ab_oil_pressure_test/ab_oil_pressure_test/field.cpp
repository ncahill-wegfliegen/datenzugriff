#include "field.h"
#include <stdexcept>

using namespace std;

template<>
string nhill::get_string( size_t pos, const Field& field )
{
	switch( pos )
	{
	case 0: return field.code;
	case 1: return field.name;
	default: throw invalid_argument( string{ "The position '" + to_string( pos ) + "' is out of range: [0,1]." }.c_str() );
	}
}

template<>
void nhill::set_string( size_t pos, Field& field, std::string_view str )
{
	switch( pos )
	{
	case 0: field.code = str; break;
	case 1: field.name = str; break;
	default: throw invalid_argument( string{ "The position '" + to_string( pos ) + "' is out of range: [0,1]." }.c_str() );
	}
}

void nhill::Field::clear()
{
	code.clear();
	name.clear();
}
