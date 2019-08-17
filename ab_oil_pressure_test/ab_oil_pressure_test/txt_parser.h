#pragma once

#include "port.h"
#include "ab_oil_pressure_test_container.h"
#include "const_iterator_txt.h"
#include <string>
#include <iterator>
#include <vector>
#include <filesystem>
#include <fstream>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_FUNCTION Txt_parser : public Forward_list<Const_iterator_txt>
{
public:
   using base = Forward_list<Txt_parser>;

   Txt_parser( const std::filesystem::path& path );
   ~Txt_parser();

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