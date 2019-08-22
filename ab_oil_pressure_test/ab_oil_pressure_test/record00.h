#pragma once

#include "port.h"
#include "record.h"
#include "../../../gemeinsam/date_time/date.h"

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

/// <summary>Well name and on production date.</summary>
class NHILL_DZG_ABOPT_PORT_CLASS Record00 : public Record
{
public:
   using base = Record;

   Record00();

   Record00( const Record00& );
   Record00& operator=( const Record00& );

   Record00( Record00&& ) noexcept;
   Record00& operator=( Record00&& ) noexcept;

   ~Record00();

#pragma warning(suppress:4251)
   std::string well_name;
   Date on_production_date;

   void clear() final;
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

class Key;

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator==( const Record00& a, const Record00& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator!=( const Record00& a, const Record00& b );

NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& operator<<( std::ostream& out, const Record00& rec );

}
}
}


