#include "xml_field_pool.h"
#include "xml_field.h"
#include "xml_pool.h"
#include <algorithm>

using namespace std;
using namespace tinyxml2;

template<>
XMLElement* nhill::xml::make_element( XMLDocument& doc, const Field_pool& fld_pl, string element_name )
{
	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "field_pool";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, fld_pl.field, "field" );
	element->LinkEndChild( child );

	child = doc.NewElement( "pools" );
	XMLElement* grand_child = nullptr;

	for( const auto& pool : fld_pl.pools )
	{
		grand_child = make_element( doc, pool, "pool" );
		child->LinkEndChild( grand_child );
	}
	element->LinkEndChild( child );

	return element;
}

template<>
XMLError nhill::xml::from_handle( Field_pool& fld_pl, XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	Field field{};
	error = from_parent_handle( field, handle, "field" );
	if( error == XMLError::XML_NO_ERROR )
		fld_pl.field = field;
	else
		retrn = error;

	XMLHandle hPools{ handle.FirstChildElement( "pools" ) };

	for( XMLNode* node = hPools.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
	{
		Pool pool{};
		error = from_handle( pool, node );
		if( error == XML_NO_ERROR )
			fld_pl.pools.push_back( pool );
		else
			retrn = error;
	}

	return retrn;
}

template<>
XMLElement* nhill::xml::make_element( XMLDocument& doc, const Field_pool_container& fld_pls, string element_name )
{
	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "fld_pls";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );
	XMLElement* child = nullptr;

	for( const auto& fld_pl : fld_pls )
	{
		child = make_element( doc, fld_pl, "fld_pl" );
		element->LinkEndChild( child );
	}

	return element;
}

template<>
XMLError nhill::xml::from_handle( Field_pool_container& fld_pls, XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	for( XMLNode* node = handle.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
	{
		Field_pool fld_pl{};
		error = from_handle( fld_pl, node );
		if( error == XML_NO_ERROR )
			fld_pls.push_back( fld_pl );
		else
			retrn = error;
	}

	return retrn;
}





