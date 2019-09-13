#pragma once

#include "port.h"
#include "test_container.h"
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
namespace ab_oil_pressure_test
{
class Key;
class Test;
enum class Test_type;

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

	bool find( Test& test, const Key& key );
	bool find( Test_container& tests, const uwi::Dls& uwi );
	bool find( Test_container& tests, std::string_view field_code, std::string_view pool_code );
	bool find( Test_container& tests, std::string_view licensee_code );
	bool find( Test_container& tests, const std::list<Test_type>& test_types );

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


