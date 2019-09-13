#pragma once

#pragma once

#include "port.h"
#include <string_view>
#include <istream>

namespace nhill
{
namespace uwi
{
class Dls;
}

namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class Key;
class Record00;
class Record01;
class Record02;
class Record03;
class Record04;
class Record05;
class Test;

namespace txt
{

NHILL_DZG_ABOPT_PORT_FUNCTION bool read( Key& key, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool read( Record00& rec, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool read( Record01& rec, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool read( Record02& rec, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool read( Record03& rec, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool read( Record04& rec, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool read( Record05& rec, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool read( Test& test, std::istream& in );

}
}
}
}