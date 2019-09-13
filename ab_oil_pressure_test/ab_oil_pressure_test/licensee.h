#pragma once

#include "port.h"
#include "../../../gemeinsam/utility/buffer.h"
#include "../../../gemeinsam/utility/compare.h"
#include <string_view>
#include <ostream>
#include <istream>


namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Licensee
{
public:
   Licensee();
   Licensee( std::string_view code, std::string_view abbr );

   Licensee( const Licensee& );
   Licensee& operator=( const Licensee& );

   Licensee( Licensee&& ) noexcept;
   Licensee& operator=( Licensee&& ) noexcept;

   ~Licensee();

   const char* code() const;
   void code( std::string_view );

   const char* abbreviation() const;
   void abbreviation( std::string_view );

   void clear();

private:
   Buffer code_;
   Buffer abbr_;
};

}
}
}

namespace nhill
{

template<> NHILL_DZG_ABOPT_PORT_FUNCTION inline
Compare compare( const datenzugriff::ab_oil_pressure_test::Licensee& a, const datenzugriff::ab_oil_pressure_test::Licensee& b );

namespace datenzugriff
{
namespace ab_oil_pressure_test
{

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator==( const Licensee& a, const Licensee& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator!=( const Licensee& a, const Licensee& b );

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator<( const Licensee& a, const Licensee& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator>( const Licensee& a, const Licensee& b );

NHILL_DZG_ABOPT_PORT_FUNCTION bool operator<=( const Licensee& a, const Licensee& b );
NHILL_DZG_ABOPT_PORT_FUNCTION bool operator>=( const Licensee& a, const Licensee& b );

NHILL_DZG_ABOPT_PORT_FUNCTION std::istream& operator>>( std::istream& in , Licensee& licensee );
NHILL_DZG_ABOPT_PORT_FUNCTION std::ostream& operator<<( std::ostream& out, const Licensee& licensee );


}
}
}
