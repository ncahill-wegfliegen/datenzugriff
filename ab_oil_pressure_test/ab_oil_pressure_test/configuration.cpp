#include "configuration.h"
#include "xml_configuration.h"
#include "../../../gemeinsam/utility/user.h"
#include <fstream>
#include <filesystem>

using namespace std;

auto nhill::datenzugriff::ab_oil_pressure_test::Configuration::instance()->Configuration &
{
   static Configuration instance;
   return instance;
}

nhill::datenzugriff::ab_oil_pressure_test::Configuration::Configuration()
   : txt{}
   , mysql{}
	, path_{ user::local_app( user::Bemühen, user::ab_oil_pressure_test, "", string{user::abopt} + "-"  + user::Datenzugriff + "." + user::config ) }
{
   load();
}


nhill::datenzugriff::ab_oil_pressure_test::Configuration::~Configuration() = default;

bool nhill::datenzugriff::ab_oil_pressure_test::Configuration::load()
{
   tinyxml2::XMLError error{ xml::read( *this, path_.string(), "configuration" ) };
   return error == tinyxml2::XML_NO_ERROR;
}

bool nhill::datenzugriff::ab_oil_pressure_test::Configuration::save()
{
   tinyxml2::XMLError error{ xml::write( path_.string(), *this, "configuration" ) };
   return error == tinyxml2::XML_NO_ERROR;
}
