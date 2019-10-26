#pragma once

#include "port.h"
#include "source.h"
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

   Source source;
   txt::Configuration txt;
   mysql::Configuration mysql;

   bool load();
   bool save();

protected:
   Configuration();

	#pragma warning(suppress:4251)
	std::filesystem::path path_;
};

}
}
}