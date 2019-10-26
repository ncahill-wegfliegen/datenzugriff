#include "../ab_oil_pressure_test/ab_oil_pressure_test/txt_parse.h"
#include "../ab_oil_pressure_test/ab_oil_pressure_test/licensee_index.h"
#include "../ab_oil_pressure_test/ab_oil_pressure_test/field_index.h"
#include <cassert>
#include <filesystem>
#include <iostream>

using namespace std;
using namespace nhill::datenzugriff::ab_oil_pressure_test;
using namespace nhill::datenzugriff::ab_oil_pressure_test::txt;

int main( int argc, char* argv[] )
{
	assert( argc == 2 && "The command line must include the full path of the text file." );

	// Get the path of the text file
	filesystem::path path_txt{ argv[1] };

	// If the file doesn't exist, then complain
	if( !filesystem::exists( path_txt ) )
	{
		cout << "The file '" << path_txt << "' does not exist or cannot be found." << endl;
		return 1;
	}

	// Get the directory of the text file (same for all indexed files)
	filesystem::path dir{ path_txt.parent_path() };

	////////////////////////////////////
	// The township index file
	filesystem::path path{ dir };
	path /= "twp.idx";

	filesystem::remove( path );
	bool success{ parse::build_township_index( path, path_txt ) };

	////////////////////////////////////
	// The licensee index file
	path = dir;
	path /= "licensee.idx";

	filesystem::remove( path );
	success = build_licensee_index( path, path_txt );

	////////////////////////////////////
	// The field/pool index
	path = dir;
	path /= "field.idx";

	filesystem::remove( path );
	success = build_field_index( path, path_txt );


	return 0;
}
