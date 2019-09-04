#include "configuration.h"
#include "xml_configuration.h"
#include <fstream>

auto nhill::datenzugriff::ab_oil_pressure_test::Configuration::instance()->Configuration &
{
	static Configuration instance;
	return instance;
}

nhill::datenzugriff::ab_oil_pressure_test::Configuration::Configuration()
	: txt{}
	, mysql{}
{
	load();
}


nhill::datenzugriff::ab_oil_pressure_test::Configuration::~Configuration() = default;

bool nhill::datenzugriff::ab_oil_pressure_test::Configuration::load()
{
	tinyxml2::XMLError error{ xml::read( *this, filename, "configuration" ) };
	return error == tinyxml2::XML_NO_ERROR;
}

bool nhill::datenzugriff::ab_oil_pressure_test::Configuration::save()
{
	tinyxml2::XMLError error{ xml::write( filename, *this, "configuration" ) };
	return error == tinyxml2::XML_NO_ERROR;
}
