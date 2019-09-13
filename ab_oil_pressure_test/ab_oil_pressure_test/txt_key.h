#pragma once

#include "port.h"
#include <string>
#include <string_view>
#include <array>
#include <cstdint>

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
namespace txt
{

class NHILL_DZG_ABOPT_PORT_CLASS Txt_key final
{
public:
	Txt_key();
	
	Txt_key( const std::string& );
	Txt_key& operator=( const std::string& );

	Txt_key( const Txt_key& );
	Txt_key& operator=( const Txt_key& );

	Txt_key( Txt_key&& ) noexcept;
	Txt_key& operator=( Txt_key&& ) noexcept;

	~Txt_key();

	std::array<char, 2> location_exception() const;
	int legal_subdivision() const;
	int section() const;
	int township() const;
	int range() const;
	int meridian() const;
	char event_sequence() const;
	int consol_interval_num() const;

	void parse( const std::string& );
	void clear();

private:
#pragma warning(push)
#pragma warning(disable:4251)
	std::array<char, 2> le_;
	uint8_t lsd_;
	uint8_t sc_;
	uint8_t twp_;
	uint8_t rg_;
	uint8_t m_;
	char es_;
	uint8_t cin_;
#pragma warning(pop)
};

}
}
}
}