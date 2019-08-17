#pragma once

#include "port.h"
#include "ab_oil_pressure_test.h"

namespace nhill
{
namespace datenzugriff
{

template<typename Const_iterator>
class Ab_oil_pressure_test_container
{
public:
   using value_type              = Ab_oil_pressure_test;
   using pointer                 = Ab_oil_pressure_test *;
   using const_pointer           = const Ab_oil_pressure_test*;
   using reference               = Ab_oil_pressure_test &;
   using const_reference         = const Ab_oil_pressure_test &;
   using size_type               = size_t;
   using difference_type         = std::ptrdiff_t;
   using const_iterator          = Const_iterator;

   virtual ~Ab_oil_pressure_test_container();

   virtual const_iterator begin() const noexcept = 0;
   virtual const_iterator end() const noexcept = 0;

   virtual const_iterator cbegin() const noexcept = 0;
   virtual const_iterator cend() const noexcept = 0;
};

}
}



template<typename Const_iterator> inline
nhill::datenzugriff::Ab_oil_pressure_test_container<Const_iterator>::~Ab_oil_pressure_test_container() = default;
