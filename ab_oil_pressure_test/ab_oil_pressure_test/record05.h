#pragma once

#include "port.h"
#include "record.h"
#include <string>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

/// <summary>Remark.</summary>
class NHILL_DZG_ABOPT_PORT_CLASS Record05 : public Record
{
public:
	using base = Record;

	Record05();

	Record05( const Record05& );
	Record05& operator=( const Record05& );

	Record05( Record05&& ) noexcept;
	Record05& operator=( Record05&& ) noexcept;

	~Record05();

	int remark_indicator;
#pragma warning(suppress:4251)
	std::string remark;

	void clear();
};

}
}
}


namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator==( const Record05& a, const Record05& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator!=( const Record05& a, const Record05& b );

}
}
}
