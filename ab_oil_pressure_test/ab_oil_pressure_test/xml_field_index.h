#pragma once

#include "port.h"
#include "../../../gemeinsam/xml/core/make_element.h"
#include "../../../gemeinsam/xml/core/from_handle.h"
#include "../../../gemeinsam/xml/core/from_parent_handle.h"
#include "../../../gemeinsam/xml/core/read.h"
#include "../../../gemeinsam/xml/core/write.h"
#include "field_index.h"
#include "field.h"
#include "field_pool_container.h"

namespace nhill
{

namespace xml
{

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const nhill::datenzugriff::ab_oil_pressure_test::Field_index& licidx, std::string element_name );

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLError from_handle( nhill::datenzugriff::ab_oil_pressure_test::Field_index& licidx, tinyxml2::XMLHandle handle );


template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const nhill::datenzugriff::ab_oil_pressure_test::Field_index_container& licidxc, std::string element_name );

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLError from_handle( nhill::datenzugriff::ab_oil_pressure_test::Field_index_container& licidxc, tinyxml2::XMLHandle handle );

bool find_by_code( nhill::datenzugriff::ab_oil_pressure_test::Field_index& field_index, const std::string& field_code, const std::string& pool_code, const std::string& path, std::string root_name = {} );
bool find_by_code( nhill::datenzugriff::ab_oil_pressure_test::Field_index& field_index, const std::string& field_code, const std::string& pool_code, tinyxml2::XMLHandle handle );

bool find_all_codes( nhill::datenzugriff::ab_oil_pressure_test::Field_index_container& field_indexes, const std::string& path, std::string root_name = {} );

bool find( nhill::Field_pool_container& fps, const std::string& path, std::string root_name = {} );

}
}


