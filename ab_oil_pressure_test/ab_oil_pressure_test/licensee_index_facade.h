#pragma once

#include "port.h"
#include "licensee_index_facade_interface.h"
#include "source.h"
#include <memory>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Licensee_index_facade final : public Licensee_index_facade_interface
{
public:
	using base = Licensee_index_facade_interface;

	Licensee_index_facade( Source source = Source::xml );
	~Licensee_index_facade();

	Licensee_index find_by_code( const std::string& licensee_code ) override;
	Licensee_index_container find_all_codes() override;

	Source source() const;
	void source( Source );

private:
#pragma warning(suppress:4251)
	std::unique_ptr<Licensee_index_facade_interface> facade_;
	Source source_;
};

}
}
}