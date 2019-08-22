#include "txt_const_iterator.h"
#include "txt_read.h"

nhill::datenzugriff::ab_oil_pressure_test::txt::Const_iterator::Const_iterator() = default;

nhill::datenzugriff::ab_oil_pressure_test::txt::Const_iterator::Const_iterator( std::ifstream& in )
   : in_{&in}
{
   txt::read( test_, *in_ );
}

nhill::datenzugriff::ab_oil_pressure_test::txt::Const_iterator::Const_iterator( const Const_iterator& other)
   : in_{other.in_}
{
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Const_iterator::operator=( const Const_iterator& other)->Const_iterator &
{
   in_ = other.in_;
   return *this;
}

nhill::datenzugriff::ab_oil_pressure_test::txt::Const_iterator::Const_iterator( Const_iterator&& other) noexcept
   : in_{other.in_}
{
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Const_iterator::operator=( Const_iterator&& other) noexcept->Const_iterator &
{
   in_ = other.in_;
   return *this;
}

nhill::datenzugriff::ab_oil_pressure_test::txt::Const_iterator::~Const_iterator() = default;

bool nhill::datenzugriff::ab_oil_pressure_test::txt::Const_iterator::operator==( const Const_iterator_base& other_param) const
{
   const Const_iterator& other{dynamic_cast<const Const_iterator&>(other_param)};
   if( in_ == nullptr && other.in_ == nullptr )
   {
      return true;
   }
   else if( in_ == nullptr && other.in_ != nullptr )
   {
      return false;
   }
   else if( in_ != nullptr && other.in_ == nullptr )
   {
      return false;
   }
   else
   {
      return base::operator==( other_param );
   }
}

bool nhill::datenzugriff::ab_oil_pressure_test::txt::Const_iterator::operator!=( const Const_iterator_base& other_param) const
{
   const Const_iterator& other{dynamic_cast<const Const_iterator&>(other_param)};
   return !( *this == other);
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Const_iterator::operator++()->Const_iterator &
{
   if( in_->eof() )
   {
      in_ = nullptr;
   }
   else
   {
      txt::read( base::test_, *in_ );
   }
   return *this;
}

auto nhill::datenzugriff::ab_oil_pressure_test::txt::Const_iterator::operator++( int )->Const_iterator
{
   Const_iterator tmp{*this};
   ++(*this);
   return tmp;
}
