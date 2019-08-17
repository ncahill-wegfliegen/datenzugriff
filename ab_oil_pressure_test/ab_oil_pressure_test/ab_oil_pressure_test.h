#pragma once

#include "port.h"
#include "key.h"
#include "record00.h"
#include "record01.h"
#include "record02.h"
#include "record03.h"
#include "record04.h"
#include "record05.h"
#include <vector>

namespace nhill
{
namespace datenzugriff
{

class NHILL_DZG_ABOPT_PORT_CLASS Ab_oil_pressure_test
{
public:
	ab_oil_pressure_test::Key key;

	ab_oil_pressure_test::Record00 rec00;
	ab_oil_pressure_test::Record01 rec01;
	ab_oil_pressure_test::Record02 rec02;
	ab_oil_pressure_test::Record03 rec03;
#pragma warning(push)
#pragma warning(disable:4251)
	std::vector<ab_oil_pressure_test::Record04> rec04c; // Record04 Collection
	std::vector<ab_oil_pressure_test::Record05> rec05c; // Record05 Collection
#pragma warning(pop)

	void clear();
};

}
}

namespace nhill
{
template<> NHILL_DZG_ABOPT_PORT_FUNCTION inline
Compare comparex( const datenzugriff::Ab_oil_pressure_test& a, const datenzugriff::Ab_oil_pressure_test& b ) noexcept;

namespace datenzugriff
{

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator==( const Ab_oil_pressure_test& a, const Ab_oil_pressure_test& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator!=( const Ab_oil_pressure_test& a, const Ab_oil_pressure_test& b );

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator<( const Ab_oil_pressure_test& a, const Ab_oil_pressure_test& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator>( const Ab_oil_pressure_test& a, const Ab_oil_pressure_test& b );

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator<=( const Ab_oil_pressure_test& a, const Ab_oil_pressure_test& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator>=( const Ab_oil_pressure_test& a, const Ab_oil_pressure_test& b );

}
}
