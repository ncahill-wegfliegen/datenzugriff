#pragma once

#include "port.h"
#include "record_type.h"
#include "dls.h"
#include <memory>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Record
{
public:
   ~Record();

   Record_type type() const;
	uwi::Dls well_id;

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

