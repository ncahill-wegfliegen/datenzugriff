#pragma once

#include "port.h"
#include "const_iterator.h"
#include <fstream>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class NHILL_DZG_ABOPT_PORT_CLASS Const_iterator_txt : public Const_iterator<Const_iterator_txt>
{
public:
   using base = Const_iterator<Const_iterator_txt>;

   Const_iterator_txt();
   Const_iterator_txt( std::ifstream& in );

   Const_iterator_txt( const Const_iterator_txt& );
   Const_iterator_txt& operator=( const Const_iterator_txt& );

   Const_iterator_txt( Const_iterator_txt&& ) noexcept;
   Const_iterator_txt& operator=( Const_iterator_txt&& ) noexcept;

   ~Const_iterator_txt();

   bool operator==( const Const_iterator& ) const final;
   bool operator!=( const Const_iterator& ) const final;

   Const_iterator_txt& operator++() final;
   Const_iterator_txt  operator++( int ) final;

private:
   std::ifstream* in_{nullptr}; // Never allocated. Do not delete.
};

}
}
}