#pragma once

#include "port.h"
#include <string>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Mysql_configuration
{
public:
#pragma warning (push)
#pragma warning (disable:4251)
	/// <summary>MySql user name (encrypted).</summary>
	std::string username;
	/// <summary>Encrypted user password (encrypted).</summary>
	std::string password;
	/// <summary>MySql host name.</summary>
	std::string hostname;
#pragma warning(pop)
};

}
}
}