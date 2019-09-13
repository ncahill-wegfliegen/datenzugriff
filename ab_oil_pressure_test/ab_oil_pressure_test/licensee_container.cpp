#include "licensee_container.h"
#include "licensee.h"
#include <fstream>

using namespace std;

bool nhill::datenzugriff::ab_oil_pressure_test::read( Licensee_container& licensees, const std::filesystem::path& path )
{
   return false;
}

bool nhill::datenzugriff::ab_oil_pressure_test::write( const std::filesystem::path& path, const Licensee_container& licensees )
{
   ofstream out{ path };
   if( !out.is_open() )
   {
      return false;
   }

   for( const auto& licensee : licensees )
   {
      out << licensee << endl;
   }

   out.close();

   return true;
}
