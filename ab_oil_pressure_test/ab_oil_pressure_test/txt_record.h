#pragma once

#include "port.h"
#include "record_type.h"
#include "txt_key.h"
#include <string>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
namespace txt
{

class NHILL_DZG_ABOPT_PORT_CLASS Txt_record
{
public:
	virtual ~Txt_record();

	Record_type record_type() const;
	const Txt_key& key() const;

protected:
	Txt_record();

	virtual void parse( const std::string& );

private:
#pragma warning(push)
#pragma warning(disable:4251)
	std::string text_{};
	Record_type type_{};
	Txt_key key_{};
#pragma warning(pop)
};

}
}
}
}