#pragma once

#include "port.h"
#include "forward_list_base.h"
#include "txt_const_iterator.h"
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
namespace txt
{

class NHILL_DZG_ABOPT_PORT_FUNCTION Forward_list : public ab_oil_pressure_test::Forward_list_base<Const_iterator>
{
public:
   using base = ab_oil_pressure_test::Forward_list_base<Forward_list>;

	Forward_list();
   Forward_list( const std::filesystem::path& path );
   ~Forward_list();

	bool open();
	bool open( const std::filesystem::path& path );
	bool is_open() const;
	void close();

	const std::filesystem::path& path() const;

	const_iterator cbegin() const noexcept final;
	const_iterator cend() const noexcept final;

private:
#pragma warning(push)
#pragma warning(disable:4251)
   std::filesystem::path path_;
   mutable std::ifstream in_;
#pragma warning(pop)
};

}
}
}
}