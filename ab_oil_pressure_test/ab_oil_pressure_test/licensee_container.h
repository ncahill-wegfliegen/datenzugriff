#pragma once

#include "port.h"
#include <list>
#include <filesystem>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
class Licensee;

using Licensee_container = std::list<Licensee>;

}
}
}


namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

NHILL_DZG_ABOPT_PORT_FUNCTION bool read( Licensee_container& licensees, const std::filesystem::path& path );
NHILL_DZG_ABOPT_PORT_FUNCTION bool write( const std::filesystem::path& path, const Licensee_container& licensees );

}
}
}