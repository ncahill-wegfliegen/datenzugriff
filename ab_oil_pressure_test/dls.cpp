#include "dls.h"
#include <string>
#include <sstream>

nhill::uwi::Dls::Dls() = default;

nhill::uwi::Dls::Dls( const char* le, int lsd, int sc, int twp, int rg, int m, int es )
{
   this->le( le );
   this->lsd( lsd );
   this->sc( sc );
   this->twp( twp );
   this->rg( rg );
   this->m( m );
   this->es( es );
}

nhill::uwi::Dls::Dls( int le, int lsd, int sc, int twp, int rg, int m, int es )
{
   this->le( le );
   this->lsd( lsd );
   this->sc( sc );
   this->twp( twp );
   this->rg( rg );
   this->m( m );
   this->es( es );
}

nhill::uwi::Dls::Dls( const Dls& ) = default;
auto nhill::uwi::Dls::operator=( const Dls& )->Dls & = default;

nhill::uwi::Dls::Dls( Dls&& ) noexcept = default;
auto nhill::uwi::Dls::operator=( Dls&& ) noexcept->Dls & = default;

nhill::uwi::Dls::~Dls() = default;

const char* nhill::uwi::Dls::location_exception() const
{
   return le();
}

void nhill::uwi::Dls::location_exception( const char* value)
{
   le( value );
}

int nhill::uwi::Dls::ilocation_exception() const
{
   return ile();
}

void nhill::uwi::Dls::location_exception( int value)
{
   le( value );
}

int nhill::uwi::Dls::legal_subdivision() const
{
   return lsd();
}

void nhill::uwi::Dls::legal_subdivision( int value)
{
   lsd( value );
}

int nhill::uwi::Dls::section() const
{
   return sc();
}

void nhill::uwi::Dls::section( int value)
{
   sc(value);
}

int nhill::uwi::Dls::township() const
{
   return twp();
}

void nhill::uwi::Dls::township( int value)
{
   twp( value );
}

int nhill::uwi::Dls::range() const
{
   return rg();
}

void nhill::uwi::Dls::range( int value)
{
   rg( value );
}

int nhill::uwi::Dls::meridian() const
{
   return m();
}

void nhill::uwi::Dls::meridian( int value)
{
   m( value );
}

int nhill::uwi::Dls::event_sequence() const
{
   return es();
}

void nhill::uwi::Dls::event_sequence( int value)
{
   es( value );
}

const char* nhill::uwi::Dls::le() const
{
   return le_;
}

void nhill::uwi::Dls::le( const char* value)
{
   if( value != nullptr && strlen( value ) <= 2 )
   {
      strcpy_s( le_, value );
   }
}

int nhill::uwi::Dls::ile() const
{
   return atoi(le());
}

void nhill::uwi::Dls::le( int value)
{
   le( std::to_string( value ).c_str() );
}

int nhill::uwi::Dls::lsd() const
{
   return static_cast<int>(lsd_);
}

void nhill::uwi::Dls::lsd( int value)
{
   lsd_ = static_cast<value_type>(value);
}

int nhill::uwi::Dls::sc() const
{
   return static_cast<int>(sc_);
}

void nhill::uwi::Dls::sc( int value)
{
   sc_ = static_cast<value_type>(value);
}

int nhill::uwi::Dls::twp() const
{
   return static_cast<int>(twp_);
}

void nhill::uwi::Dls::twp( int value)
{
   twp_ = static_cast<value_type>(value);
}

int nhill::uwi::Dls::rg() const
{
   return static_cast<int>(rg_);
}

void nhill::uwi::Dls::rg( int value)
{
   rg_ = static_cast<value_type>(value);
}

int nhill::uwi::Dls::m() const
{
   return static_cast<int>(m_);
}

void nhill::uwi::Dls::m( int value)
{
   m_ = static_cast<value_type>(value);
}

int nhill::uwi::Dls::es() const
{
   return static_cast<int>(es_);
}

void nhill::uwi::Dls::es( int value)
{
   es_ = static_cast<value_type>(value);
}
