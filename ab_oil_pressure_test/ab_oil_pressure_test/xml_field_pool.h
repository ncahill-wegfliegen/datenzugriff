#include "port.h"
#include "../../../gemeinsam/xml/core/make_element.h"
#include "../../../gemeinsam/xml/core/from_handle.h"
#include "../../../gemeinsam/xml/core/from_parent_handle.h"
#include "../../../gemeinsam/xml/core/read.h"
#include "../../../gemeinsam/xml/core/write.h"
#include "field_pool.h"
#include "field_pool_container.h"

namespace nhill
{
namespace xml
{

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const nhill::Field_pool& fld_pl, std::string element_name );

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLError from_handle( nhill::Field_pool& fld_pl, tinyxml2::XMLHandle handle );


template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const nhill::Field_pool_container& fld_pls, std::string element_name );

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLError from_handle( nhill::Field_pool_container& fld_pls, tinyxml2::XMLHandle handle );

}
}