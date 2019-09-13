#pragma once

#include "port.h"
#include "txt_parse.h"
#include <string>
#include <string_view>
#include <list>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
namespace txt
{

class Txt_test
{
public:
	std::string line00; // well id
	std::string line01; // licensee
	std::string line02; // designated field and pool
	std::string line03; // well data
	std::list<std::string> line04c; // test data container
	std::list<std::string> line05c; // remark container

	void clear();
};

}
}
}
}

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
namespace txt
{


}
}
}
}
