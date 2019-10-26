#include "port.h"
#include "../../../gemeinsam/xml/core/make_element.h"
#include "../../../gemeinsam/xml/core/from_handle.h"
#include "../../../gemeinsam/xml/core/from_parent_handle.h"
#include "../../../gemeinsam/xml/core/read.h"
#include "../../../gemeinsam/xml/core/write.h"
#include "pool.h"

namespace nhill
{
namespace xml
{

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const nhill::Pool& pool, std::string element_name );

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLError from_handle( nhill::Pool& pool, tinyxml2::XMLHandle handle );


template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const nhill::Pool_container& pools, std::string element_name );

template<> NHILL_DZG_ABOPT_PORT_FUNCTION
tinyxml2::XMLError from_handle( nhill::Pool_container& pools, tinyxml2::XMLHandle handle );

}
}