#include "mysql_selector.h"
#include "mysql_session.h"
#include "key.h"
#include "record00.h"
#include "record01.h"
#include "record02.h"
#include "record03.h"
#include "record04.h"
#include "record05.h"
#include "ab_oil_pressure_test.h"
#include "../../../gemeinsam/uwi/dls.h"
#include <mysqlx/xdevapi.h>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::
Selector()
   : base{}
{
}

nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::
Selector( std::string_view username, std::string_view password )
   : base{ username, password }
{
}

nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::
~Selector()
{
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find( Ab_oil_pressure_test& test, const Key& key )
{
   if( !is_open() )
   {
      return false;
   }

   mysqlx::Table table{ base::table( Record_type::field_pool ) };

   mysqlx::RowResult rows{ table
      .select( "*" )
      .where( "location_exception=:le AND legal_subdivision=:lsd AND section=:sc AND township=:twp AND field_pool.range=:rg AND meridian=:m AND event_sequence=:es AND consol_interval_num=:cin")
      .bind("le", key.uwi.cle())
      .bind("lsd", key.uwi.lsd())
      .bind("sc", key.uwi.sc())
      .bind("twp", key.uwi.twp())
      .bind("rg", key.uwi.rg())
      .bind("m", key.uwi.m())
      .bind("es", key.uwi.ces())
      .bind("cin", key.consol_interval_num)
      .execute()
   };


   return 0 < rows.count();
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find( std::vector<Ab_oil_pressure_test>& tests, const uwi::Dls& uwi )
{
   return false;
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find( std::vector<Ab_oil_pressure_test>& tests, std::string_view field_code, std::string_view pool_code )
{
   return false;
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find( std::vector<Ab_oil_pressure_test>& tests, std::string_view licensee_code )
{
   return false;
}
