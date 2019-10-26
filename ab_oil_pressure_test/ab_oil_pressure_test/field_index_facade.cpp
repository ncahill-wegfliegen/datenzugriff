#include "field_index_facade.h"
#include "field_pool.h"
#include <gsl/gsl_assert>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Field_index_facade::
Field_index_facade( Source source )
	: source_{ source }
	, facade_{ base::make_unique( source ) }
{
}

nhill::datenzugriff::ab_oil_pressure_test::Field_index_facade::
~Field_index_facade() = default;

auto nhill::datenzugriff::ab_oil_pressure_test::Field_index_facade::find_by_code( const string& field_code, const string& pool_code )->Field_index
{
	return facade_->find_by_code(field_code, pool_code);
}

auto nhill::datenzugriff::ab_oil_pressure_test::Field_index_facade::find_all_codes()->Field_index_container
{
	return facade_->find_all_codes();
}

auto nhill::datenzugriff::ab_oil_pressure_test::Field_index_facade::find_all_field_pools()->Field_pool_container
{
	return facade_->find_all_field_pools();
}

auto nhill::datenzugriff::ab_oil_pressure_test::Field_index_facade::
source() const->Source
{
	return source_;
}

void nhill::datenzugriff::ab_oil_pressure_test::Field_index_facade::
source( Source source )
{
	Expects( source != Source::none );

	if( source != this->source() )
	{
		source_ = source;
		facade_ = base::make_unique( source );
	}
}
