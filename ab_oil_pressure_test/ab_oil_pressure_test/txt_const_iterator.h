#pragma once

#include "port.h"
#include "const_iterator_base.h"
#include <fstream>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
namespace txt
{

class NHILL_DZG_ABOPT_PORT_CLASS Const_iterator : public Const_iterator_base<Const_iterator>
{
public:
   using base = Const_iterator_base<Const_iterator>;

   Const_iterator();
   Const_iterator( std::ifstream& in );

   Const_iterator( const Const_iterator& );
   Const_iterator& operator=( const Const_iterator& );

   Const_iterator( Const_iterator&& ) noexcept;
   Const_iterator& operator=( Const_iterator&& ) noexcept;

   ~Const_iterator();

   bool operator==( const Const_iterator_base& ) const final;
   bool operator!=( const Const_iterator_base& ) const final;

   Const_iterator& operator++() final;
   Const_iterator  operator++( int ) final;

private:
   std::ifstream* in_{ nullptr }; // Never allocated. Do not delete.
};

}
}
}
}