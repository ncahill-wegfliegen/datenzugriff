#pragma once

#include "port.h"
#include "txt_record.h"

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
namespace txt
{

class NHILL_DZG_ABOPT_PORT_CLASS Txt_record00 : public Txt_record
{
public:
	using base = Txt_record;

	Txt_record00();

	Txt_record00( const std::string& );
	Txt_record00& operator=( const std::string& );

	~Txt_record00();

	std::string well_name() const;
	std::string on_production_date() const;

protected:
	void parse( const std::string& ) override;

private:
#pragma warning(push)
#pragma warning(disable:4251)
	std::string well_name_;
	std::string on_production_date_;
#pragma warning(pop)
};

}
}
}
}