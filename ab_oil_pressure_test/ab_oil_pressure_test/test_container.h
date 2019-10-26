#pragma once

#include <list>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
class Test;

using Test_container = std::list<Test>;

using Test_ptr = Test *;
using Test_ptr_container = std::list<Test*>;

}
}
}