#include "xml_txt_configuration.h"

using namespace nhill::datenzugriff::ab_oil_pressure_test;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const txt::Configuration& txt, std::string element_name )
{
	using namespace tinyxml2;

	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "txt";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, txt.path.string(), "path" );
	element->LinkEndChild( child );

	return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( txt::Configuration& txt, tinyxml2::XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	std::string s;
	error = from_parent_handle( s, handle, "path" );
	if( error == XMLError::XML_NO_ERROR )
		txt.path = s;
	else
		retrn = error;

	return retrn;
}
