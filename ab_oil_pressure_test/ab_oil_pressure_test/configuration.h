#pragma once

#include "port.h"
#include "txt_configuration.h"
#include "mysql_configuration.h"
#include <filesystem>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Configuration final
{
public:
	static Configuration& instance();

	~Configuration();

	Txt_configuration txt;
	Mysql_configuration mysql;

	bool load();
	bool save();

protected:
	Configuration();


	static constexpr const char* const filename{ "ab_oil_pressure_test.config" };

};

}
}
}