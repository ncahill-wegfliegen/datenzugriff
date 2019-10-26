#include "txt_parse.h"
#include "../../../gemeinsam/enum/core/int.h"
#include "../../../gemeinsam/uwi/dls.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

auto nhill::datenzugriff::ab_oil_pressure_test::txt::
operator==( const Parse& a, const Parse& b )->bool
{
	return a.pos == b.pos && a.count == b.count;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::
operator!=( const Parse& a, const Parse& b )->bool
{
	return !(a == b);
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::parse::
equal( string_view a, string_view b, const list<Parse>& parse_list )->bool
{
	bool ret{ true }; // The return value; true if the two string are equal according to the parse items

	for( const auto& parse : parse_list )
	{
		if( a.substr( parse.pos, parse.count ) != b.substr( parse.pos, parse.count ) )
		{
			ret = false;
			break;
		}
	}

	return ret;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::parse::
get_record_type( std::string_view raw_line )->Record_type
{
	string_view record_type{ raw_line.substr( parse::record_type.pos, parse::record_type.count ) };

	if( record_type == "00" )
	{
		return Record_type::well_id;
	}
	else if( record_type == "01" )
	{
		return Record_type::licensee;
	}
	else if( record_type == "02" )
	{
		return Record_type::field_pool;
	}
	else if( record_type == "03" )
	{
		return Record_type::well_data;
	}
	else if( record_type == "04" )
	{
		return Record_type::test_data;
	}
	else if( record_type == "05" )
	{
		return Record_type::remark;
	}
	else
	{
		throw exception( string{ "Failed to determine the record type of the raw line '" + string{ raw_line } +"'." }.c_str() );
	}
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::parse::
uwi_display_to_raw( string_view display, int consol_interval_num, string_view record_type )->string
{
	//           1         2
	// 012345678901234567890
	// 1XX/LL-SS-TTT-RRDM/0E

	static constexpr char tab{ '\t' };
	ostringstream oss;

	oss << record_type.substr( 0, 2 ); // record type
	oss << tab;
	oss << display.substr( 1, 2 ); // location exception
	oss << tab;
	oss << display.substr( 4, 2 ); // legal subdivisiion
	oss << tab;
	oss << display.substr( 7, 2 ); // section
	oss << tab;
	oss << display.substr( 10, 3 ); // township
	oss << tab;
	oss << display.substr( 14, 2 ); // range
	oss << tab;
	oss << display.substr( 17, 1 ); // meridian
	oss << tab;
	oss << display.substr( 20, 1 ); // event sequence
	oss << tab;
	if( 0 < consol_interval_num )
	{
		oss << setw( 2 ) << setfill( '0' ) << consol_interval_num;
		oss << tab;
	}

	return oss.str();
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::parse::
uwi_basic_to_raw( string_view basic, int consol_interval_num, string_view record_type )->string
{
	//           1  
	// 01234567890123
	// XXLLSSTTTRRDME

	static constexpr char tab{ '\t' };
	ostringstream oss;

	oss << record_type.substr(0,2); // record type
	oss << tab;
	oss << basic.substr( 0, 2 ); // location exception
	oss << tab;
	oss << basic.substr( 2, 2 ); // legal subdivisiion
	oss << tab;
	oss << basic.substr( 4, 2 ); // section
	oss << tab;
	oss << basic.substr( 6, 3 ); // township
	oss << tab;
	oss << basic.substr( 9, 2 ); // range
	oss << tab;
	oss << basic.substr( 12, 1 ); // meridian
	oss << tab;
	oss << basic.substr( 13, 1 ); // event sequence
	oss << tab;
	if( 0 < consol_interval_num )
	{
		oss << setw( 2 ) << setfill( '0' ) << consol_interval_num;
		oss << tab;
	}

	return oss.str();
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::parse::
uwi_sort_to_raw( string_view sort, int consol_interval_num, string_view record_type )->string
{
	//           1  
	// 012345678901234
	// 1DMRRTTTSSLLXXE

	static constexpr char tab{ '\t' };
	ostringstream oss;

	oss << record_type.substr( 0, 2 ); // record type
	oss << tab;
	oss << sort.substr( 12, 2 ); // location exception
	oss << tab;
	oss << sort.substr( 10, 2 ); // legal subdivisiion
	oss << tab;
	oss << sort.substr( 8, 2 ); // section
	oss << tab;
	oss << sort.substr( 5, 3 ); // township
	oss << tab;
	oss << sort.substr( 3, 2 ); // range
	oss << tab;
	oss << sort.substr( 2, 1 ); // meridian
	oss << tab;
	oss << sort.substr( 14, 1 ); // event sequence
	oss << tab;
	if( 0 < consol_interval_num )
	{
		oss << setw( 2 ) << setfill( '0' ) << consol_interval_num;
		oss << tab;
	}

	return oss.str();
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::parse::
uwi_raw_to_display( string raw )->pair<string,int>
{
	ostringstream oss;

	oss << '1'; // survey system
	oss << raw.substr( parse::location_exception.pos, parse::location_exception.count );
	oss << '/'; 
	oss << raw.substr( parse::legal_subdivision.pos, parse::legal_subdivision.count );
	oss << '-';
	oss << raw.substr( parse::section.pos, parse::section.count );
	oss << '-';
	oss << raw.substr( parse::township.pos, parse::township.count );
	oss << '-';
	oss << raw.substr( parse::range.pos, parse::range.count );
	oss << 'W';
	oss << raw.substr( parse::meridian.pos, parse::meridian.count );
	oss << '/';
	oss << '0';
	oss << raw.substr( parse::event_sequence.pos, parse::event_sequence.count );

	int consol_interval_num{ stoi( raw.substr( parse::consol_interval_num.pos, parse::consol_interval_num.count ) ) };

	return { oss.str(), consol_interval_num };
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::parse::
uwi_raw_to_basic( string raw )->pair<string, int>
{
	ostringstream oss;

	oss << raw.substr( parse::location_exception.pos, parse::location_exception.count );
	oss << raw.substr( parse::legal_subdivision.pos, parse::legal_subdivision.count );
	oss << raw.substr( parse::section.pos, parse::section.count );
	oss << raw.substr( parse::township.pos, parse::township.count );
	oss << raw.substr( parse::range.pos, parse::range.count );
	oss << 'W';
	oss << raw.substr( parse::meridian.pos, parse::meridian.count );
	oss << raw.substr( parse::event_sequence.pos, parse::event_sequence.count );

	int consol_interval_num{ stoi( raw.substr( parse::consol_interval_num.pos, parse::consol_interval_num.count ) ) };

	return { oss.str(), consol_interval_num };
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::parse::
uwi_raw_to_sort( string raw )->pair<string, int>
{
	ostringstream oss;

	oss << '1'; // survey system
	oss << 'W';
	oss << raw.substr( parse::meridian.pos, parse::meridian.count );
	oss << raw.substr( parse::range.pos, parse::range.count );
	oss << raw.substr( parse::township.pos, parse::township.count );
	oss << raw.substr( parse::section.pos, parse::section.count );
	oss << raw.substr( parse::legal_subdivision.pos, parse::legal_subdivision.count );
	oss << raw.substr( parse::location_exception.pos, parse::location_exception.count );
	oss << raw.substr( parse::event_sequence.pos, parse::event_sequence.count );

	int consol_interval_num{ stoi( raw.substr( parse::consol_interval_num.pos, parse::consol_interval_num.count ) ) };

	return { oss.str(), consol_interval_num };
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::parse::
build_township_index( const std::filesystem::path& path_out, const std::filesystem::path& path_txt )
{
	ifstream in{ path_txt };
	if( !in.is_open() )
	{
		return false;
	}

	ofstream out{ path_out };
	if( !out.is_open() )
	{
		in.close();
		return false;
	}

	string line;
	string twp{"000"};
	streampos idx{ 0 }; // The position of the start of the 00 line
	while( getline( in, line ) )
	{
		// we are only looking for 00 records
		if( get_record_type( line) == Record_type::well_id )
		{
			if( line.compare( parse::township.pos, parse::township.count, twp  ) != 0 )
			{
				// We have found a new township number
				twp = line.substr( parse::township.pos, parse::township.count );
				// Write the township and index to the output file
				out << twp << '\t' << idx << endl;
			}
		}

		// The position of the beginning of the next line
		idx = in.tellg();
	}

	out.close();
	in.close();

	return true;
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::parse::
read_township_index( Twpidx_container& twpidxs, const std::filesystem::path& path )
{
	ifstream in{ path };
	if( !in.is_open() )
	{
		return false;
	}

	unsigned twp;
	long idx;

	while( !in.eof() )
	{
		in >> twp >> idx;
		twpidxs.emplace( twp, idx );
	}
	in.close();

	return true;
}

