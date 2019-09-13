#include "facade.h"
#include "test.h"
#include <gsl/gsl_assert>

nhill::datenzugriff::ab_oil_pressure_test::Facade::Facade( Source source )
   : source_{source}
   , facade_{base::make_unique(source)}
{
}

nhill::datenzugriff::ab_oil_pressure_test::Facade::~Facade() = default;

auto nhill::datenzugriff::ab_oil_pressure_test::Facade::
find_test_by_uwi( const uwi::Dls& uwi )->Test_container
{
   return facade_->find_test_by_uwi( uwi );
}

auto nhill::datenzugriff::ab_oil_pressure_test::Facade::
find_test_by_licensee_code( const std::string& licensee_code )->Test_container
{
   return facade_->find_test_by_licensee_code( licensee_code );
}

auto nhill::datenzugriff::ab_oil_pressure_test::Facade::
find_test_by_field_pool( const std::string& field_code, const std::string& pool_code  )->Test_container
{
   return facade_->find_test_by_field_pool( field_code, pool_code );
}

auto nhill::datenzugriff::ab_oil_pressure_test::Facade::
find_test_by_test_type( const std::list<Test_type>& test_types )->Test_container
{
   return facade_->find_test_by_test_type( test_types );
}

auto nhill::datenzugriff::ab_oil_pressure_test::Facade::
source() const->Source
{
   return source_;
}

void nhill::datenzugriff::ab_oil_pressure_test::Facade::
source( Source source)
{
   Expects( source != Source::none );

   if( source != this->source() )
   {
      source_ = source;
      facade_ = base::make_unique( source );
   }
}


