#include "xml_configuration.h"
#include "source_ex.h"
#include "xml_txt_configuration.h"
#include "xml_mysql_configuration.h"
#include "configuration.h"

using namespace nhill::datenzugriff::ab_oil_pressure_test;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Configuration& object, std::string element_name )
{
   using namespace tinyxml2;

   // Create an element name if none was provided.
   if( element_name.empty() )
   {
      element_name = "configuration";
   }

   XMLElement* element = doc.NewElement( element_name.c_str() );

   XMLElement* child = nullptr;

   child = make_element( doc, object.source, "source" );
   element->LinkEndChild( child );

   child = make_element( doc, object.txt, "txt" );
   element->LinkEndChild( child );

   child = make_element( doc, object.mysql, "mysql" );
   element->LinkEndChild( child );

   return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Configuration& object, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;

   XMLError retrn = XMLError::XML_NO_ERROR;
   XMLError error = XMLError::XML_NO_ERROR;

   Source source{ Source::txt };
   error = from_parent_handle( source, handle, "source" );
   if( error == XMLError::XML_NO_ERROR )
      object.source = source;
   else
      retrn = error;


   txt::Configuration txt;
   error = from_parent_handle( txt, handle, "txt" );
   if( error == XMLError::XML_NO_ERROR )
      object.txt = txt;
   else
      retrn = error;

   mysql::Configuration mysql;
   error = from_parent_handle( mysql, handle, "mysql" );
   if( error == XMLError::XML_NO_ERROR )
      object.mysql = mysql;
   else
      retrn = error;

   return retrn;
}
