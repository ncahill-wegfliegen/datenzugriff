#pragma once

#include <filesystem>
#include <string_view>

namespace ab_oil_pressure_test_test
{

std::filesystem::path get_path( std::string_view file_name );

}