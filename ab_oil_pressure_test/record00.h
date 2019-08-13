#pragma once

#include "port.h"
#include "record.h"

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

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
};

}
}
}
