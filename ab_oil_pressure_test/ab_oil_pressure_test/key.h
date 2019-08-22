#pragma once

#include "port.h"
#include "dls.h"
#include <cstdint>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Key
{
public:
	uwi::Dls well_id;
	int consol_interval_num;

	void clear();
};

}
}
}


namespace nhill
{

template<> NHILL_DZG_ABOPT_PORT_FUNCTION inline
Compare compare( const datenzugriff::ab_oil_pressure_test::Key& a, const datenzugriff::ab_oil_pressure_test::Key& b ) noexcept;

namespace datenzugriff
{
namespace ab_oil_pressure_test
{

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator==( const Key& a, const Key& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator!=( const Key& a, const Key& b );

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator<( const Key& a, const Key& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator>( const Key& a, const Key& b );

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator<=( const Key& a, const Key& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator>=( const Key& a, const Key& b );

NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& operator<<( std::ostream& out, const Key& key );

}
}
}
