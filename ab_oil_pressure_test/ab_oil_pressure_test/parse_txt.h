#pragma once

#include "port.h"
#include "parse.h"
#include <string_view>
#include <fstream>

namespace nhill
{
namespace datenzugriff
{

class Ab_oil_pressure_test;

namespace ab_oil_pressure_test
{

class Key;
class Record00;
class Record01;
class Record02;
class Record03;
class Record04;
class Record05;

NHILL_DZG_ABOPT_PORT_FUNCTION bool parse_txt( Key& key, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool parse_txt( Record00& rec, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool parse_txt( Record01& rec, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool parse_txt( Record02& rec, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool parse_txt( Record03& rec, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool parse_txt( Record04& rec, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool parse_txt( Record05& rec, std::string_view str );
NHILL_DZG_ABOPT_PORT_FUNCTION bool parse_txt( Ab_oil_pressure_test& test, std::ifstream& in );

}
}
}