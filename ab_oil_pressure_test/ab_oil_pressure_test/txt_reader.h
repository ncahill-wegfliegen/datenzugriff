#pragma once

#include "port.h"
#include <memory>
#include <filesystem>


namespace nhill
{
namespace uwi
{
class Dls;
}

namespace datenzugriff
{
class Ab_oil_pressure_test;

namespace ab_oil_pressure_test
{
class Key;

namespace txt
{

class Forward_list;

class NHILL_DZG_ABOPT_PORT_CLASS Reader
{
public:
	Reader();
	Reader( const std::filesystem::path& path );
	~Reader();

	bool open();
	bool open( const std::filesystem::path& path );
	bool is_open() const;
	void close();

	bool find( Ab_oil_pressure_test& test, const Key& key );
	bool find( std::vector<Ab_oil_pressure_test>& tests, const uwi::Dls& uwi );
	bool find( std::vector<Ab_oil_pressure_test>& tests, std::string_view field_code, std::string_view pool_code );
	bool find( std::vector<Ab_oil_pressure_test>& tests, std::string_view licensee_code );

private:
#pragma warning(push)
#pragma warning(disable:4251)
	std::unique_ptr<Forward_list> forward_list_;
#pragma warning(pop)
};

}
}
}
}


