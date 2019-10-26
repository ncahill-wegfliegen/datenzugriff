#pragma once

#include "port.h"
#include "field_index_facade_interface.h"
#include "field_pool_container.h"
#include "source.h"
#include <memory>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Field_index_facade final : public Field_index_facade_interface
{
public:
	using base = Field_index_facade_interface;

	Field_index_facade( Source source = Source::xml );
	~Field_index_facade();

	Field_index find_by_code( const std::string& field_code, const std::string& pool_code ) override;
	Field_index_container find_all_codes() override;
	Field_pool_container find_all_field_pools() override;

	Source source() const;
	void source( Source );

private:
#pragma warning(suppress:4251)
	std::unique_ptr<Field_index_facade_interface> facade_;
	Source source_;
};

}
}
}