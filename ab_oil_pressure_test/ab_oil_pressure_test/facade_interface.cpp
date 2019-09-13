#include "facade_interface.h"
#include "txt_facade.h"
#include "txt_raw_facade.h"
#include "mysql_facade.h"

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Facade_interface::Facade_interface() = default;
nhill::datenzugriff::ab_oil_pressure_test::Facade_interface::~Facade_interface() = default;

auto nhill::datenzugriff::ab_oil_pressure_test::Facade_interface::
make_unique( Source source )->std::unique_ptr<Facade_interface>
{
   switch( source )
   {
   case Source::txt: return std::make_unique<txt::Txt_raw_facade>();
   case Source::mysql: return std::make_unique<mysql::Facade>();
   default: return nullptr;
   }
}
