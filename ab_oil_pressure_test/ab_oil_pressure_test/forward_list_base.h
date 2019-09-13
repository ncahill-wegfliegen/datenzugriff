#pragma once

#include "port.h"
#include "test.h"

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

template<typename Const_iterator>
class Forward_list_base
{
public:
	using value_type              = Test;
	using pointer                 = Test *;
	using const_pointer           = const Test*;
	using reference               = Test &;
	using const_reference         = const Test &;
	using size_type               = size_t;
	using difference_type         = std::ptrdiff_t;
	using const_iterator          = Const_iterator;

	virtual ~Forward_list_base();

	const_iterator begin() const noexcept;
	const_iterator end() const noexcept;

	virtual const_iterator cbegin() const noexcept = 0;
	virtual const_iterator cend() const noexcept = 0;
};

}
}
}


template<typename Const_iterator> inline
nhill::datenzugriff::ab_oil_pressure_test::Forward_list_base<Const_iterator>::~Forward_list_base() = default;

template<typename Const_iterator> inline
auto nhill::datenzugriff::ab_oil_pressure_test::Forward_list_base<Const_iterator>::begin() const noexcept->const_iterator
{
	return cbegin();
}

template<typename Const_iterator> inline
auto nhill::datenzugriff::ab_oil_pressure_test::Forward_list_base<Const_iterator>::end() const noexcept->const_iterator
{
	return cend();
}
