#pragma once

#include "port.h"
#include <filesystem>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Txt_configuration
{
public:
	
#pragma warning (suppress:4251)
	std::filesystem::path path;	/// <summary>The full path of the 'ab_oil_pressure_test.txt' text file.</summary>

};

}
}
}