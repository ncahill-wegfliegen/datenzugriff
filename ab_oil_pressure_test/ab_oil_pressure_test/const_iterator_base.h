#pragma once

#include "ab_oil_pressure_test.h"
#include "../../../gemeinsam/utility/exception/not_implemented.h"

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

template<typename Const_iterator_derived>
class Const_iterator_base
{
public:
   using iterator_category = std::forward_iterator_tag;
   using value_type        = Ab_oil_pressure_test;
   using difference_type   = ptrdiff_t;
   using pointer           = const Ab_oil_pressure_test*;
   using reference         = const Ab_oil_pressure_test &;
   using derived_type      = Const_iterator_derived;

   Const_iterator_base( const Const_iterator_base& );
   Const_iterator_base& operator=( const Const_iterator_base& );

   Const_iterator_base( Const_iterator_base&& ) noexcept;
   Const_iterator_base& operator=( Const_iterator_base&& ) noexcept;

   virtual ~Const_iterator_base();

   virtual bool operator==( const Const_iterator_base& ) const;
   virtual bool operator!=( const Const_iterator_base& ) const;

   virtual const Ab_oil_pressure_test& operator*() const;
   virtual const Ab_oil_pressure_test& operator->() const;

   virtual Const_iterator_derived& operator++() = 0;
   virtual Const_iterator_derived  operator++( int ) = 0;

protected:
   Const_iterator_base();

   mutable Ab_oil_pressure_test test_;
};

}
}
}



template<typename Const_iterator_derived>
nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_base<Const_iterator_derived>::Const_iterator_base() = default;

template<typename Const_iterator_derived>
nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_base<Const_iterator_derived>::Const_iterator_base( const Const_iterator_base& ) = default;

template<typename Const_iterator_derived>
auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_base<Const_iterator_derived>::operator=( const Const_iterator_base& )->Const_iterator_base & = default;

template<typename Const_iterator_derived>
nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_base<Const_iterator_derived>::Const_iterator_base( Const_iterator_base&& ) noexcept = default;

template<typename Const_iterator_derived>
auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_base<Const_iterator_derived>::operator=( Const_iterator_base&& ) noexcept->Const_iterator_base & = default;

template<typename Const_iterator_derived>
nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_base<Const_iterator_derived>::~Const_iterator_base() = default;

template<typename Const_iterator_derived>
bool nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_base<Const_iterator_derived>::operator==( const Const_iterator_base& other ) const
{
   return test_ == other.test_;
}

template<typename Const_iterator_derived>
bool nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_base<Const_iterator_derived>::operator!=( const Const_iterator_base& other ) const
{
   return !(*this == other);
}

template<typename Const_iterator_derived>
auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_base<Const_iterator_derived>::operator*() const->const Ab_oil_pressure_test &
{
   return test_;
}

template<typename Const_iterator_derived>
auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_base<Const_iterator_derived>::operator->() const->const Ab_oil_pressure_test &
{
   return test_;
}
