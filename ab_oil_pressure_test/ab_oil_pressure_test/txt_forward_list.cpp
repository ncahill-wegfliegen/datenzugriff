#include "txt_forward_list.h"
#include "../../../gemeinsam/utility/exception/file_not_found.h"

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::txt::Forward_list::Forward_list()
	: path_{}
	, in_{}
{
}

nhill::datenzugriff::ab_oil_pressure_test::txt::Forward_list::Forward_list( const std::filesystem::path& path )
   : path_{path}
   , in_{path}
{
   if( !in_.is_open() )
   {
      throw File_not_found( "Failed to open the file " + path.string() );
   }
}

nhill::datenzugriff::ab_oil_pressure_test::txt::Forward_list::~Forward_list()
{
   in_.close();
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::Forward_list::open()
{
	return open( path_ );
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::Forward_list::open( const std::filesystem::path& path )
{
	path_ = path;
	close();
	in_.open( path );
	return is_open();
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::Forward_list::is_open() const
{
	return in_.is_open();
}

void nhill::datenzugriff::ab_oil_pressure_test::txt::Forward_list::close()
{
	if( in_.is_open() )
	{
		in_.clear();
		in_.seekg( 0, ios::beg );
		in_.close();
	}
}

const std::filesystem::path& nhill::datenzugriff::ab_oil_pressure_test::txt::Forward_list::path() const
{
	return path_;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Forward_list::cbegin() const noexcept->const_iterator
{
	in_.clear();
	in_.seekg( 0, ios::beg );
	return { in_ };
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Forward_list::cend() const noexcept->const_iterator
{
	return {};
}
