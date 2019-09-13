#include "licensee.h"
#include "../../../gemeinsam/utility/str.h"
#include <string>
#include <algorithm>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::Licensee::Licensee() = default;

nhill::datenzugriff::ab_oil_pressure_test::Licensee::Licensee( string_view code, string_view abbr )
   : code_(code)
   , abbr_(abbr)
{
}

nhill::datenzugriff::ab_oil_pressure_test::Licensee::Licensee( const Licensee& ) = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Licensee::operator=( const Licensee& )->Licensee & = default;

nhill::datenzugriff::ab_oil_pressure_test::Licensee::Licensee( Licensee&& other ) noexcept = default;
auto nhill::datenzugriff::ab_oil_pressure_test::Licensee::operator=( Licensee&& ) noexcept->Licensee & = default;

nhill::datenzugriff::ab_oil_pressure_test::Licensee::~Licensee() = default;

const char* nhill::datenzugriff::ab_oil_pressure_test::Licensee::code() const
{
   return code_.c_str();
}

void nhill::datenzugriff::ab_oil_pressure_test::Licensee::code( string_view s)
{
   code_ = s;
}

const char* nhill::datenzugriff::ab_oil_pressure_test::Licensee::abbreviation() const
{
   return abbr_.c_str();
}

void nhill::datenzugriff::ab_oil_pressure_test::Licensee::abbreviation( string_view s)
{
   abbr_ = s;
}

istream& nhill::datenzugriff::ab_oil_pressure_test::operator>>( istream& in, Licensee& licensee )
{
   string s;

   getline( in, s, ',' );
   // remove double quote from front and back
   s.erase( s.begin() ); 
   s.erase( s.end() - 1 ); 
   licensee.code( s );

   getline( in, s );
   // remove double quote from front and back
   s.erase( s.begin() );
   s.erase( s.end() - 1 );
   licensee.abbreviation( s );

   return in;
}

ostream& nhill::datenzugriff::ab_oil_pressure_test::operator<<( ostream& out, const Licensee& licensee )
{
   return out << '\"' << licensee.code() << '\"' << ',' << '\"' << licensee.abbreviation() << '\"';
}
