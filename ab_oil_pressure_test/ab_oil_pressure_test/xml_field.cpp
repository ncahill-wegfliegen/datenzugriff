#include "xml_field.h"
#include <algorithm>

using namespace std;
using namespace tinyxml2;

template<>
XMLElement* nhill::xml::make_element( XMLDocument& doc, const Field& field, string element_name )
{
	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "field";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, field.code, "code" );
	element->LinkEndChild( child );

	child = make_element( doc, field.name, "name" );
	element->LinkEndChild( child );

	return element;
}

template<>
XMLError nhill::xml::from_handle( Field& field, XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	string str{};
	error = from_parent_handle( str, handle, "code" );
	if( error == XMLError::XML_NO_ERROR )
		field.code = str;
	else
		retrn = error;

	str.clear();
	error = from_parent_handle( str, handle, "name" );
	if( error == XMLError::XML_NO_ERROR )
		field.name = str;
	else
		retrn = error;

	return retrn;
}

template<>
XMLElement* nhill::xml::make_element( XMLDocument& doc, const Field_container& fields, string element_name )
{
	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "fields";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );
	XMLElement* child = nullptr;

	for( const auto& field : fields )
	{
		child = make_element( doc, field, "field" );
		element->LinkEndChild( child );
	}

	return element;
}

template<>
XMLError nhill::xml::from_handle( Field_container& fields, XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	for( XMLNode* node = handle.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
	{
		Field field{};
		error = from_handle( field, node );
		if( error == XML_NO_ERROR )
			fields.push_back( field );
		else
			retrn = error;
	}

	return retrn;
}




