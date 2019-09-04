#pragma once
class Xml_txt_configuration
{
};

#pragma once

#include "port.h"
#include "txt_configuration.h"
#include "../../../gemeinsam/xml/core/make_element.h"
#include "../../../gemeinsam/xml/core/from_handle.h"
#include "../../../gemeinsam/xml/core/from_parent_handle.h"
#include "../../../gemeinsam/xml/core/read.h"
#include "../../../gemeinsam/xml/core/write.h"
#include <string>

namespace nhill
{
namespace xml
{

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const nhill::datenzugriff::ab_oil_pressure_test::Txt_configuration& item, std::string element_name );

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLError from_handle( nhill::datenzugriff::ab_oil_pressure_test::Txt_configuration& item, tinyxml2::XMLHandle handle );

}
}

