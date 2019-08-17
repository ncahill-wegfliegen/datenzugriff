#pragma once

#include "ab_oil_pressure_test.h"
#include "../../gemeinsam/utility/exception/not_implemented.h"

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

template<typename Const_iterator_derived>
class Const_iterator
{
public:
   using iterator_category = std::forward_iterator_tag;
   using value_type        = Ab_oil_pressure_test;
   using difference_type   = ptrdiff_t;
   using pointer           = const Ab_oil_pressure_test*;
   using reference         = const Ab_oil_pressure_test &;
   using derived_type      = Const_iterator_derived;

   Const_iterator( const Const_iterator& );
   Const_iterator& operator=( const Const_iterator& );

   Const_iterator( Const_iterator&& ) noexcept;
   Const_iterator& operator=( Const_iterator&& ) noexcept;

   virtual ~Const_iterator();

   virtual bool operator==( const Const_iterator& ) const;
   virtual bool operator!=( const Const_iterator& ) const;

   virtual const Ab_oil_pressure_test& operator*() const;
   virtual const Ab_oil_pressure_test& operator->() const;

   virtual Const_iterator_derived& operator++() = 0;
   virtual Const_iterator_derived  operator++( int ) = 0;

protected:
   Const_iterator();

   mutable Ab_oil_pressure_test test_;
};

}
}
}



template<typename Const_iterator_derived>
nhill::datenzugriff::ab_oil_pressure_test::Const_iterator<Const_iterator_derived>::Const_iterator() = default;

template<typename Const_iterator_derived>
nhill::datenzugriff::ab_oil_pressure_test::Const_iterator<Const_iterator_derived>::Const_iterator( const Const_iterator& ) = default;

template<typename Const_iterator_derived>
auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator<Const_iterator_derived>::operator=( const Const_iterator& )->Const_iterator & = default;

template<typename Const_iterator_derived>
nhill::datenzugriff::ab_oil_pressure_test::Const_iterator<Const_iterator_derived>::Const_iterator( Const_iterator&& ) noexcept = default;

template<typename Const_iterator_derived>
auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator<Const_iterator_derived>::operator=( Const_iterator&& ) noexcept->Const_iterator & = default;

template<typename Const_iterator_derived>
nhill::datenzugriff::ab_oil_pressure_test::Const_iterator<Const_iterator_derived>::~Const_iterator() = default;

template<typename Const_iterator_derived>
bool nhill::datenzugriff::ab_oil_pressure_test::Const_iterator<Const_iterator_derived>::operator==( const Const_iterator& other ) const
{
   return test_ == other.test_;
}

template<typename Const_iterator_derived>
bool nhill::datenzugriff::ab_oil_pressure_test::Const_iterator<Const_iterator_derived>::operator!=( const Const_iterator& other ) const
{
   return !(*this == other);
}

template<typename Const_iterator_derived>
auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator<Const_iterator_derived>::operator*() const->const Ab_oil_pressure_test &
{
   return test_;
}

template<typename Const_iterator_derived>
auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator<Const_iterator_derived>::operator->() const->const Ab_oil_pressure_test &
{
   return test_;
}

//template<typename Const_iterator_derived>
//auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_base<Const_iterator_derived>::operator++()->Const_iterator_derived &
//{
//   throw Not_implemented( "This method must be overriden in a derived class." );
//}
//
//template<typename Const_iterator_derived>
//auto nhill::datenzugriff::ab_oil_pressure_test::Const_iterator_base<Const_iterator_derived>::operator++( int )->Const_iterator_derived
//{
//   throw Not_implemented( "This method must be overriden in a derived class." );
//}
