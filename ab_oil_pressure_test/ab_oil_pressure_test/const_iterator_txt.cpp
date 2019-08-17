#include "const_iterator_txt.h"
#include "parse_txt.h"

nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_txt::Const_iterator_txt() = default;

nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_txt::Const_iterator_txt( std::ifstream& in )
   : in_{&in}
{
   parse_txt( test_, *in_ );
}

nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_txt::Const_iterator_txt( const Const_iterator_txt& other)
   : in_{other.in_}
{
}

auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_txt::operator=( const Const_iterator_txt& other)->Const_iterator_txt &
{
   in_ = other.in_;
   return *this;
}

nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_txt::Const_iterator_txt( Const_iterator_txt&& other) noexcept
   : in_{other.in_}
{
}

auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_txt::operator=( Const_iterator_txt&& other) noexcept->Const_iterator_txt &
{
   in_ = other.in_;
   return *this;
}

nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_txt::~Const_iterator_txt() = default;

bool nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_txt::operator==( const Const_iterator& other_param) const
{
   const Const_iterator_txt& other{dynamic_cast<const Const_iterator_txt&>(other_param)};
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

bool nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_txt::operator!=( const Const_iterator& other_param) const
{
   const Const_iterator_txt& other{dynamic_cast<const Const_iterator_txt&>(other_param)};
   return !( *this == other);
}

auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_txt::operator++()->Const_iterator_txt &
{
   if( in_->eof() )
   {
      in_ = nullptr;
   }
   else
   {
      parse_txt( base::test_, *in_ );
   }
   return *this;
}

auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_txt::operator++( int )->Const_iterator_txt
{
   Const_iterator_txt tmp{*this};
   ++(*this);
   return tmp;
}
