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

/// <summary>Designated field and pool.</summary>
class NHILL_DZG_ABOPT_PORT_CLASS Record02 : public Record
{
public:
   using base = Record;

   Record02();

   Record02( const Record02& );
   Record02& operator=( const Record02& );

   Record02( Record02&& ) noexcept;
   Record02& operator=( Record02&& ) noexcept;

   ~Record02();

#pragma warning(push)
#pragma warning(disable:4251)
   std::string field_name;
   std::string pool_name;
#pragma warning(pop)

	void clear() override;
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

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator==( const Record02& a, const Record02& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator!=( const Record02& a, const Record02& b );

}
}
}

