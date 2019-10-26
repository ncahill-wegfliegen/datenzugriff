#include "xml_licensee_index.h"

using namespace std;
using namespace tinyxml2;
using namespace nhill::datenzugriff::ab_oil_pressure_test;

template<>
XMLElement* nhill::xml::make_element( XMLDocument& doc, const Licensee_index& licidx, string element_name )
{
	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "licensee_index";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, licidx.licensee_code, "licensee_code" );
	element->LinkEndChild( child );

	child = make_element( doc, licidx.licensee_abbrv, "licensee_abbrv" );
	element->LinkEndChild( child );

	child = doc.NewElement( "uwis" );
	XMLElement* childuwi{ nullptr };
	for( const auto& uwi : licidx.uwis )
	{
		childuwi = make_element( doc, uwi, "uwi" );
		child->LinkEndChild( childuwi );
	}
	element->LinkEndChild( child );

	return element;
}

template<>
XMLError nhill::xml::from_handle( Licensee_index& licidx, XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	string str{};
	error = from_parent_handle( str, handle, "licensee_code" );
	if( error == XMLError::XML_NO_ERROR )
		licidx.licensee_code = str;
	else
		retrn = error;


	str.clear();
	error = from_parent_handle( str, handle, "licensee_abbrv" );
	if( error == XMLError::XML_NO_ERROR )
		licidx.licensee_abbrv = str;
	else
		retrn = error;

	XMLHandle handleuwis{ handle.FirstChildElement( "uwis" ) };
	for( XMLNode* node = handleuwis.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
	{
		str.clear();
		error = from_handle( str, node );
		if( error == XML_NO_ERROR )
			licidx.uwis.emplace( str );
		else
			retrn = error;
	}

	return retrn;
}

template<>
XMLElement* nhill::xml::make_element( XMLDocument& doc, const Licensee_index_container& licidxc, string element_name )
{
	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "licensee_indexes";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );
	XMLElement* child = nullptr;

	for( const auto& licidx : licidxc )
	{
		child = make_element( doc, licidx, "licensee_index" );
		element->LinkEndChild( child );
	}

	return element;
}

template<>
XMLError nhill::xml::from_handle( Licensee_index_container& licidxc, XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	for( XMLNode* node = handle.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
	{
		Licensee_index licensee_index{};
		error = from_handle( licensee_index, node );
		if( error == XML_NO_ERROR )
			licidxc.push_back( licensee_index );
		else
			retrn = error;
	}

	return retrn;
}

bool nhill::xml::find_by_code( Licensee_index& licensee_index, const string& licensee_code, const string& path, string root_name )
{
	if( root_name.empty() )
		root_name = "licensee_indexes";

	XMLDocument doc;
	XMLError error{ make_document( doc, path ) };
	if( error != XMLError::XML_NO_ERROR )
	{
		ostringstream msg;
		msg << "nhill::xml::read. Failed to create document for " << root_name << " in the file " << path << ". " << to_label( error ) << ".";
		LOG_ERROR( msg.str() );
		return false;
	}

	XMLHandle hRoot = make_root_handle( doc, root_name );
	for( XMLNode* node = hRoot.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
	{
		if( find_by_code( licensee_index, licensee_code, node ) )
		{
			return true; // We found the licensee index element that we were looking for.
		}
	}

	return false; // Failed to find the licensee index by code
}

bool nhill::xml::find_by_code( Licensee_index& licensee_index, const std::string& licensee_code, tinyxml2::XMLHandle handle )
{
	XMLError error = XMLError::XML_NO_ERROR;

	string str{};
	error = from_parent_handle( str, handle, "licensee_code" );
	if( error == XMLError::XML_NO_ERROR )
	{
		if( str != licensee_code )
		{
			return false; // This is not the element we are looking for
		}
		else
		{
			licensee_index.licensee_code = str; // This is the element we are looking for.
		}
	}
	else
	{
		return false; // Something bad happened.
	}

	str.clear();
	error = from_parent_handle( str, handle, "licensee_abbrv" );
	if( error == XMLError::XML_NO_ERROR )
	{
		licensee_index.licensee_abbrv = str.c_str();
	}

	XMLHandle handleuwis{ handle.FirstChildElement( "uwis" ) };
	for( XMLNode* node = handleuwis.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
	{
		str.clear();
		error = from_handle( str, node );
		if( error == XML_NO_ERROR )
		{
			licensee_index.uwis.emplace( str );
		}
	}

	return true;
}

bool nhill::xml::find_all_codes( nhill::datenzugriff::ab_oil_pressure_test::Licensee_index_container& licensee_indexes, const std::string& path, std::string root_name )
{
	if( root_name.empty() )
		root_name = "licensee_indexes";

	XMLDocument doc;
	XMLError error{ make_document( doc, path ) };
	if( error != XMLError::XML_NO_ERROR )
	{
		ostringstream msg;
		msg << "nhill::xml::read. Failed to create document for " << root_name << " in the file " << path << ". " << to_label( error ) << ".";
		LOG_ERROR( msg.str() );
		return false;
	}

	licensee_indexes.clear();


	XMLHandle hRoot = make_root_handle( doc, root_name );
	for( XMLNode* node = hRoot.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
	{
		Licensee_index lic_idx{};

		string str{};
		error = from_parent_handle( str, node, "licensee_code" );
		if( error == XMLError::XML_NO_ERROR )
			lic_idx.licensee_code = str;

		str.clear();
		error = from_parent_handle( str, node, "licensee_abbrv" );
		if( error == XMLError::XML_NO_ERROR )
			lic_idx.licensee_abbrv = str;

		licensee_indexes.push_back( lic_idx );
	}

	return true; 
}




