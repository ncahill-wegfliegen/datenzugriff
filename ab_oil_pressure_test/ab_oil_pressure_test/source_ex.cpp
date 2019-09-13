#include "source_ex.h"

template<>
const nhill::text::Bundle_container<nhill::datenzugriff::ab_oil_pressure_test::Source>& nhill::text::bundle_container<nhill::datenzugriff::ab_oil_pressure_test::Source>()
{
   using namespace nhill::datenzugriff::ab_oil_pressure_test;

   static const Bundle_container<Source> bundles{
      { Source::none,	{ "NONE", "NONE", "none", "None", "None"}},
      //
      { Source::txt,   { {Text::string, "txt"	}, {Text::label, "Gov't Text File" } } },
      { Source::mysql, { {Text::string, "mysql"	}, {Text::label, "MySql Database"  } } },
   };

   return bundles;
}


