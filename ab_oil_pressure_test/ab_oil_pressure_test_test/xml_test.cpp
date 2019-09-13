#include "pch.h"
#include "CppUnitTest.h"
#include "data.h"
#include "../ab_oil_pressure_test/xml_configuration.h"
#include "../../../gemeinsam/crypt/crypt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace nhill::datenzugriff::ab_oil_pressure_test;

namespace ab_oil_pressure_test_test
{
TEST_CLASS( Xml_test )
{
public:

	TEST_METHOD( write_configuration_test )
	{
		Configuration& config{ Configuration::instance() };

      config.source = Source::txt;

		config.txt.path = get_path( "ab_oil_pressure_test.txt" );

		config.mysql.username = nhill::crypt::encrypt( "Nicholas C.A. Hill" );
		config.mysql.password = nhill::crypt::encrypt( "Hoola5Hoopla$" );
		config.mysql.hostname = "localhost";

		config.save();

	}

	TEST_METHOD( read_configuration_test )
	{
		Configuration& config{ Configuration::instance() };

		string username = nhill::crypt::decrypt( config.mysql.username );
		string password = nhill::crypt::decrypt( config.mysql.password );

	}


};
}
