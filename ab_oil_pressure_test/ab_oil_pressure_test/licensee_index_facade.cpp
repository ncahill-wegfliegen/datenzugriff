#include "licensee_index_facade.h"
#include <gsl/gsl_assert>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Licensee_index_facade::
Licensee_index_facade( Source source )
	: source_{ source }
	, facade_{ base::make_unique( source ) }
{
}

nhill::datenzugriff::ab_oil_pressure_test::Licensee_index_facade::
~Licensee_index_facade() = default;

auto nhill::datenzugriff::ab_oil_pressure_test::Licensee_index_facade::find_by_code( const string& licensee_code )->Licensee_index
{
	return facade_->find_by_code(licensee_code);
}

auto nhill::datenzugriff::ab_oil_pressure_test::Licensee_index_facade::find_all_codes()->Licensee_index_container
{
	return facade_->find_all_codes();
}

auto nhill::datenzugriff::ab_oil_pressure_test::Licensee_index_facade::
source() const->Source
{
	return source_;
}

void nhill::datenzugriff::ab_oil_pressure_test::Licensee_index_facade::
source( Source source )
{
	Expects( source != Source::none );

	if( source != this->source() )
	{
		source_ = source;
		facade_ = base::make_unique( source );
	}
}
