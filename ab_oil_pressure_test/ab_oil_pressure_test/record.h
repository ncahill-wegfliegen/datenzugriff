#pragma once

#include "port.h"
#include "record_type.h"
#include <memory>
#include <cstdint>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Record
{
public:
   virtual ~Record();

   Record_type type() const;

	virtual void clear();
	static std::unique_ptr<Record> make_unique( Record_type type );

protected:
   Record(Record_type type);

	Record( const Record& );
	Record& operator=( const Record& );

	Record( Record&& ) noexcept;
	Record& operator=( Record&& ) noexcept;

private:
	Record_type type_;
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

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator==( const Record& a, const Record& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator!=( const Record& a, const Record& b );

}
}
}

