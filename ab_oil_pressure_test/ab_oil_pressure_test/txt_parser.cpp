#include "txt_parser.h"
#include "../../gemeinsam/utility/exception/file_not_found.h"

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Txt_parser::Txt_parser( const std::filesystem::path& path )
   : path_{path}
   , in_{path}
{
   if( !in_.is_open() )
   {
      throw File_not_found( "Failed to open the file " + path.string() );
   }
}

nhill::datenzugriff::ab_oil_pressure_test::Txt_parser::~Txt_parser()
{
   in_.close();
}

auto nhill::datenzugriff::ab_oil_pressure_test::Txt_parser::cbegin() const noexcept->const_iterator
{
   in_.clear();
   in_.seekg( 0, ios::beg );
   return {in_};
}

auto nhill::datenzugriff::ab_oil_pressure_test::Txt_parser::cend() const noexcept->const_iterator
{
   return {};
}
