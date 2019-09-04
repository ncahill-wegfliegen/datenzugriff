#include "xml_mysql_configuration.h"

using namespace nhill::datenzugriff::ab_oil_pressure_test;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Mysql_configuration& mysql, std::string element_name )
{
	using namespace tinyxml2;

	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "mysql";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, mysql.username, "username" );
	element->LinkEndChild( child );

	child = make_element( doc, mysql.password, "password" );
	element->LinkEndChild( child );

	child = make_element( doc, mysql.hostname, "hostname" );
	element->LinkEndChild( child );

	return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Mysql_configuration& txt, tinyxml2::XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	std::string s;
	error = from_parent_handle( s, handle, "username" );
	if( error == XMLError::XML_NO_ERROR )
		txt.username = s;
	else
		retrn = error;

	s.clear();
	error = from_parent_handle( s, handle, "password" );
	if( error == XMLError::XML_NO_ERROR )
		txt.password = s;
	else
		retrn = error;

	s.clear();
	error = from_parent_handle( s, handle, "hostname" );
	if( error == XMLError::XML_NO_ERROR )
		txt.hostname = s;
	else
		retrn = error;

	return retrn;
}
