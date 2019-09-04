#include "txt_reader.h"
#include "txt_forward_list.h"
#include "../../../gemeinsam/uwi/dls.h"
#include <algorithm>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::txt::Reader::
Reader()
	: forward_list_{make_unique<Forward_list>()}
{
}

nhill::datenzugriff::ab_oil_pressure_test::txt::Reader::
Reader( const std::filesystem::path& path )
	: forward_list_{ make_unique<Forward_list>( path ) }
{
}

nhill::datenzugriff::ab_oil_pressure_test::txt::Reader::
~Reader()
{
	close();
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::Reader::
open()
{
	return forward_list_->open();
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::Reader::
open( const std::filesystem::path& path )
{
	return forward_list_->open(path);
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::Reader::
is_open() const
{
	return forward_list_->is_open();
}

void nhill::datenzugriff::ab_oil_pressure_test::txt::Reader::
close()
{
	forward_list_->close();
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::Reader::
find( Ab_oil_pressure_test& test, const Key& key )
{
	test.clear();

	if( !is_open() && !open())
	{
		return false;
	}

	bool found{ false };
	for( const auto& current_test : *forward_list_ )
	{
		if( current_test.key == key )
		{
			found = true;
			test = current_test;
			break;
		}
	}

	return found;
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::Reader::
find( std::vector<Ab_oil_pressure_test>& tests, const uwi::Dls& uwi )
{
	tests.clear();

	if( !is_open() && !open() )
	{
		return false;
	}

	for( const auto& current_test : *forward_list_ )
	{
		if( current_test.key.uwi == uwi )
		{
			tests.push_back( current_test );
		}
		else if( 0 < tests.size() )
		{
			// We have arrived at the first test AFTER the uwi we were searching for.
			// We have found all of the wells associated with the uwi.
			break;
		}
	}

	return 0 < tests.size();
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::Reader::find( std::vector<Ab_oil_pressure_test>& tests, std::string_view field_code, std::string_view pool_code )
{
	tests.clear();

	if( !is_open() && !open() )
	{
		return false;
	}

	for( const auto& current_test : *forward_list_ )
	{
		if( current_test.rec03.field_code == field_code )
		{
			if( pool_code.empty() || (current_test.rec03.pool_code == pool_code) )
			{
				tests.push_back( current_test );
			}
		}
	}

	return 0 < tests.size();
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::Reader::find( std::vector<Ab_oil_pressure_test>& tests, std::string_view licensee_code )
{
	tests.clear();

	if( !is_open() && !open() )
	{
		return false;
	}

	for( const auto& current_test : *forward_list_ )
	{
		if( current_test.rec01.licensee_code == licensee_code )
		{
			tests.push_back( current_test );
		}
	}

	return 0 < tests.size();
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::Reader::find( std::vector<Ab_oil_pressure_test>& tests, const std::list<Test_type>& test_types )
{
	tests.clear();

	if( !is_open() && !open() )
	{
		return false;
	}

	for( const auto& current_test : *forward_list_ )
	{
		for( const auto& rec04 : current_test.rec04c )
		{
			auto itr{ std::find( test_types.cbegin(), test_types.cend(), rec04.test_type ) };
			if( itr != test_types.cend())
			{
				tests.push_back( current_test );
				break;
			}
		}
	}

	return 0 < tests.size();
}
