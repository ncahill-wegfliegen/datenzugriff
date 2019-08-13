#include "record_type_ex.h"

template<>
const nhill::text::Bundle_container<nhill::datenzugriff::ab_oil_pressure_test::Record_type>& nhill::text::bundle_container<nhill::datenzugriff::ab_oil_pressure_test::Record_type>()
{
   using namespace nhill::datenzugriff::ab_oil_pressure_test;

   static const Bundle_container<Record_type> bundles{
      { Record_type::well_id   , { {Text::string, "well_id"		}, {Text::label, "Well ID and On Production Date" }, {Text::description, "Well ID and On Production Date" } }},
      { Record_type::licensee  , { {Text::string, "licensee"	}, {Text::label, "Licensee and Well Status"		  }, {Text::description, "Licensee and Well Status"       } }},
      { Record_type::field_pool, { {Text::string, "field_pool" }, {Text::label, "Designated Field and Pool"		  }, {Text::description, "Designated Field and Pool"      } }},
      { Record_type::well_data , { {Text::string, "well_data"	}, {Text::label, "Well Data"							  }, {Text::description, "Well Data"                      } }},
      { Record_type::test_data , { {Text::string, "test_data" 	}, {Text::label, "Test Data"					        }, {Text::description, "Test Data"                      } }},
      { Record_type::remarks   , { {Text::string, "remarks"		}, {Text::label, "Remarks"								  }, {Text::description, "Remarks"                        } }},
   };

   return bundles;
}


