#pragma once

#include "port.h"
#include <cstdint>

namespace nhill
{
namespace uwi
{

class NHILL_DZG_ABOPT_PORT_CLASS Dls
{
public:
   Dls();
   Dls( const char* le, int lsd, int sc, int twp, int rg, int m, int es );
   Dls( int le, int lsd, int sc, int twp, int rg, int m, int es );

   Dls( const Dls& );
   Dls& operator=( const Dls& );

   Dls( Dls&& ) noexcept;
   Dls& operator=( Dls&& ) noexcept;

   ~Dls();

   const char* location_exception() const;
   void location_exception( const char* );

   int ilocation_exception() const;
   void location_exception( int );

   int legal_subdivision() const;
   void legal_subdivision( int );

   int section() const;
   void section( int );

   int township() const;
   void township( int );

   int range() const;
   void range( int );

   int meridian() const;
   void meridian( int );

   int event_sequence() const;
   void event_sequence( int );



   const char* le() const;
   void le( const char* );

   int ile() const;
   void le( int );

   int lsd() const;
   void lsd( int );

   int sc() const;
   void sc( int );

   int twp() const;
   void twp( int );

   int rg() const;
   void rg( int );

   int m() const;
   void m( int );

   int es() const;
   void es( int );

private:
   using value_type = uint8_t;

   char       le_[3]{ };  // location exception
   value_type lsd_  {0};  // legal subdivision
   value_type sc_   {0};  // section
   value_type twp_  {0};  // township
   value_type rg_   {0};  // range
   value_type m_    {0};  // meridian
   value_type es_   {0};  // event sequence
};

}
}