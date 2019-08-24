#include "pch.h"
#include "data.h"

using namespace std;

std::filesystem::path ab_oil_pressure_test_test::get_path( std::string_view file_name )
{
   filesystem::path path{filesystem::current_path().root_name()};
   path += R"(\bemühen\dev\datenzugriff\ab_oil_pressure_test\ab_oil_pressure_test_test\data)";
   path /= file_name;

   return path;
}
