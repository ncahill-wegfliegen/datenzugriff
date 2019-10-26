#include "txt_raw_facade.h"
#include "configuration.h"
#include "txt_parse.h"
#include "txt_test.h"
#include "txt_read.h"
#include "test.h"
#include "../../../gemeinsam/uwi/dls.h"
#include "../../../gemeinsam/utility/user.h"
#include <string>
#include <list>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_raw_facade::
Txt_raw_facade()
{
	std::filesystem::path path_txt{ ab_oil_pressure_test::Configuration::instance().txt.path };
	in_.open( path_txt );
	if( !in_.is_open() )
	{
		string msg{ "Failed to open the text data '" };
		msg.append( ab_oil_pressure_test::Configuration::instance().txt.path.string() ).append( "'." );
		throw exception( msg.c_str() );
	}

	std::filesystem::path path_twpidx{ user::local_app( user::Bemühen, user::ab_oil_pressure_test, "", "twp.idx" ) };
	if( !filesystem::exists( path_twpidx ) )
	{
		parse::build_township_index( path_twpidx, path_txt );
	}
	parse::read_township_index( twpidx_, path_twpidx );
}

nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_raw_facade::
~Txt_raw_facade()
{
	in_.close();
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_raw_facade::
find_test_by_uwi( const uwi::Dls& uwi )->Test_container
{
	string uwi_raw{ parse::uwi_sort_to_raw( uwi.sort() ) };
	list<Parse> parse_list{ parse::uwi };

	// Clear out any errors
	in_.clear();

	// Set the position of the stream
	std::streampos idx{ find_index( uwi.twp )};
	in_.seekg( idx );

	list<Txt_test> raw_tests;
	Txt_test raw_test;
	string line;
	bool found{ false };
	while( getline( in_, line ) )
	{
		if( parse::equal( uwi_raw, line, parse_list) )
		{ 
			found = true;
			Record_type record_type{ parse::get_record_type( line ) };
			switch( record_type )
			{
			case Record_type::well_id:
				if( !raw_test.line00.empty() )
				{
					raw_tests.push_back( raw_test );
					raw_test.clear();
				}
				raw_test.line00 = line;
				break;

			case Record_type::licensee:
				raw_test.line01 = line;
				break;

			case Record_type::field_pool:
				raw_test.line02 = line;
				break;

			case Record_type::well_data:
				raw_test.line03 = line;
				break;

			case Record_type::test_data:
				raw_test.line04c.push_back( line );
				break;

			case Record_type::remark:
				raw_test.line05c.push_back( line );
				break;
			}
		}
		else if( found )
		{
			raw_tests.push_back( raw_test );
			break; // if we have found at least one, and this line is not equal, then we aren't going to find any maore
		}
	}

	// Convert the raw test into tests
	Test_container tests;
	Test test;
	for( const auto& raw_test : raw_tests )
	{
		test.clear();
		read( test.key, raw_test.line00 );
		read( test.rec00, raw_test.line00 );
		read( test.rec01, raw_test.line01 );
		read( test.rec02, raw_test.line02 );
		read( test.rec03, raw_test.line03 );

		for( const auto& raw_line04 : raw_test.line04c )
		{
			Record04 rec04;
			read( rec04, raw_line04 );
			test.rec04c.push_back( rec04 );
		}

		for( const auto& raw_line05 : raw_test.line05c )
		{
			Record05 rec05;
			read( rec05, raw_line05 );
			test.rec05c.push_back( rec05 );
		}
		tests.push_back( test );
	}


	return tests;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_raw_facade::
find_test_by_licensee_code( const std::string& licensee_code )->Test_container
{
	return Test_container();
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_raw_facade::
find_test_by_field_pool( const std::string& field_code, const std::string& pool_code )->Test_container
{
	return Test_container();
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_raw_facade::
find_test_by_test_type( const std::list<Test_type>& test_types )->Test_container
{
	return Test_container();
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Txt_raw_facade::
find_index( const uwi::Dls::Township& twp ) const->std::streampos
{
	auto itr{ twpidx_.find( twp.value() ) };
	if( itr == twpidx_.end() )
	{
		return 0;
	}
	else
	{
		return itr->second;
	}
}

