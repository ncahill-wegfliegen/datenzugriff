#include "xml_pool.h"
#include <algorithm>

using namespace std;
using namespace tinyxml2;

template<>
XMLElement* nhill::xml::make_element( XMLDocument& doc, const Pool& pool, string element_name )
{
	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "pool";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, pool.code, "code" );
	element->LinkEndChild( child );

	child = make_element( doc, pool.name, "name" );
	element->LinkEndChild( child );

	return element;
}

template<>
XMLError nhill::xml::from_handle( Pool& pool, XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	string str{};
	error = from_parent_handle( str, handle, "code" );
	if( error == XMLError::XML_NO_ERROR )
		pool.code = str;
	else
		retrn = error;

	str.clear();
	error = from_parent_handle( str, handle, "name" );
	if( error == XMLError::XML_NO_ERROR )
		pool.name = str;

	return retrn;
}

template<>
XMLElement* nhill::xml::make_element( XMLDocument& doc, const Pool_container& pools, string element_name )
{
	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "pools";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );
	XMLElement* child = nullptr;

	for( const auto& pool : pools )
	{
		child = make_element( doc, pool, "pool" );
		element->LinkEndChild( child );
	}

	return element;
}

template<>
XMLError nhill::xml::from_handle( Pool_container& pools, XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	for( XMLNode* node = handle.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
	{
		Pool pool{};
		error = from_handle( pool, node );
		if( error == XML_NO_ERROR )
			pools.push_back( pool );
		else
			retrn = error;
	}

	return retrn;
}




