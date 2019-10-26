#include "xml_field_index.h"
#include "xml_field.h"
#include "xml_pool.h"
#include "field_pool.h"
#include <algorithm>

using namespace std;
using namespace tinyxml2;
using namespace nhill::datenzugriff::ab_oil_pressure_test;

template<>
XMLElement* nhill::xml::make_element( XMLDocument& doc, const Field_index& licidx, string element_name )
{
	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "field_index";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );

	XMLElement* child = nullptr;

	child = make_element( doc, licidx.field, "field" );
	element->LinkEndChild( child );

	child = make_element( doc, licidx.pool, "pool" );
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
XMLError nhill::xml::from_handle( Field_index& licidx, XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	Field field{};
	error = from_parent_handle( field, handle, "field" );
	if( error == XMLError::XML_NO_ERROR )
		licidx.field = field;
	else
		retrn = error;

	Pool pool{};
	error = from_parent_handle( pool, handle, "pool" );
	if( error == XMLError::XML_NO_ERROR )
		licidx.pool = pool;
	else
		retrn = error;

	string str{};
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
XMLElement* nhill::xml::make_element( XMLDocument& doc, const Field_index_container& licidxc, string element_name )
{
	// Create an element name if none was provided.
	if( element_name.empty() )
	{
		element_name = "field_indexes";
	}

	XMLElement* element = doc.NewElement( element_name.c_str() );
	XMLElement* child = nullptr;

	for( const auto& licidx : licidxc )
	{
		child = make_element( doc, licidx, "field_index" );
		element->LinkEndChild( child );
	}

	return element;
}

template<>
XMLError nhill::xml::from_handle( Field_index_container& licidxc, XMLHandle handle )
{
	using namespace tinyxml2;

	XMLError retrn = XMLError::XML_NO_ERROR;
	XMLError error = XMLError::XML_NO_ERROR;

	for( XMLNode* node = handle.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
	{
		Field_index field_index{};
		error = from_handle( field_index, node );
		if( error == XML_NO_ERROR )
			licidxc.push_back( field_index );
		else
			retrn = error;
	}

	return retrn;
}

bool nhill::xml::find_by_code( Field_index& field_index, const string& field_code, const std::string& pool_code, const string& path, string root_name )
{
	if( root_name.empty() )
		root_name = "field_indexes";

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
		if( find_by_code( field_index, field_code, pool_code, node ) )
		{
			return true; // We found the field index element that we were looking for.
		}
	}

	return false; // Failed to find the field index by code
}

bool nhill::xml::find_by_code( Field_index& field_index, const std::string& field_code, const std::string& pool_code, tinyxml2::XMLHandle handle )
{
	field_index.clear();

	XMLError error = XMLError::XML_NO_ERROR;

	Field field{};
	error = from_parent_handle( field, handle, "field" );
	if( error == XMLError::XML_NO_ERROR )
	{
		if( field.code != field_code )
		{
			return false; // This is not the element we are looking for
		}
	}
	else
	{
		return false; // Something bad happened.
	}
	field_index.field = field;

	Pool pool{};
	if( !pool_code.empty() )
	{
		error = from_parent_handle( pool, handle, "pool" );
		if( error == XMLError::XML_NO_ERROR )
		{
			if( pool.code != pool_code )
			{
				field_index.clear();
				return false; // This is not the element we are looking for
			}
		}
		else
		{
			field_index.clear();
			return false; // Something bad happened.
		}
	}
	field_index.pool = pool;

	string uwi{};
	XMLHandle handleuwis{ handle.FirstChildElement( "uwis" ) };
	for( XMLNode* node = handleuwis.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
	{
		uwi.clear();
		error = from_handle( uwi, node );
		if( error == XML_NO_ERROR )
		{
			field_index.uwis.emplace( uwi );
		}
	}

	return true;
}

bool nhill::xml::find_all_codes( nhill::datenzugriff::ab_oil_pressure_test::Field_index_container& fld_idxs, const std::string& path, std::string root_name )
{
	if( root_name.empty() )
		root_name = "field_indexes";

	XMLDocument doc;
	XMLError error{ make_document( doc, path ) };
	if( error != XMLError::XML_NO_ERROR )
	{
		ostringstream msg;
		msg << "nhill::xml::read. Failed to create document for " << root_name << " in the file " << path << ". " << to_label( error ) << ".";
		LOG_ERROR( msg.str() );
		return false;
	}

	fld_idxs.clear();


	XMLHandle hRoot = make_root_handle( doc, root_name );
	for( XMLNode* node = hRoot.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
	{
		Field_index fld_idx{};

		Field field{};
		error = from_parent_handle( field, node, "field" );
		if( error == XMLError::XML_NO_ERROR )
			fld_idx.field = field;

		Pool pool{};
		error = from_parent_handle( pool, node, "pool" );
		if( error == XMLError::XML_NO_ERROR )
			fld_idx.pool = pool;

		fld_idxs.push_back( fld_idx );
	}

	return true;
}

bool nhill::xml::find( nhill::Field_pool_container& fld_pls, const std::string& path, std::string root_name )
{
	if( root_name.empty() )
		root_name = "field_indexes";

	XMLDocument doc;
	XMLError error{ make_document( doc, path ) };
	if( error != XMLError::XML_NO_ERROR )
	{
		ostringstream msg;
		msg << "nhill::xml::read. Failed to create document for " << root_name << " in the file " << path << ". " << to_label( error ) << ".";
		LOG_ERROR( msg.str() );
		return false;
	}

	fld_pls.clear();

	XMLHandle hRoot = make_root_handle( doc, root_name );
	for( XMLNode* node = hRoot.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
	{
		Field field;
		error = from_parent_handle( field, node, "field" );

		Pool pool;
		error = from_parent_handle( pool, node, "pool" );

		string field_code{ field.code };
		auto itr{
			find_if(
				fld_pls.begin(),
				fld_pls.end(),
				[&field_code]( const auto& field_pools )
				{
					return field_pools.field.code == field_code;
				}
			)
		};
		if( itr == fld_pls.end() )
		{
			fld_pls.push_back( { field, {pool} } );
		}
		else
		{
			itr->pools.push_back( pool );
		}
	}

	return true;
}




