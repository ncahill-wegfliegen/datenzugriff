#include "mysql_session.h"
#include "record_type_ex.h"
#include <mysqlx/xdevapi.h>
#include <sstream>

using namespace std;

nhill::datenzugriff::ab_oil_pressure_test::mysql::Session::Session()
   : username_{}
   , password_{}
   , hostname_{}
   , session_{ nullptr }
{
}

nhill::datenzugriff::ab_oil_pressure_test::mysql::Session::Session( std::string_view username, std::string_view password, std::string_view hostname )
   : username_{ username }
   , password_{ password }
   , hostname_{ hostname }
   , session_{ nullptr }
{
   open();
}

nhill::datenzugriff::ab_oil_pressure_test::mysql::Session::~Session()
{
   close();
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Session::open()
{
   return open( username_, password_, hostname_ );
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Session::open( std::string_view username, std::string_view password, std::string_view hostname )
{
   if( session_ != nullptr )
   {
      close();
   }

   ostringstream url;
   url << username << ':' << password << "@" << hostname;

   try
   {
      session_ = make_unique<mysqlx::Session>( url.str() );
      return true;
   }
   catch( exception e )
   {
      session_ = nullptr;
      return false;
   }
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Session::is_open() const
{
   return session_ != nullptr;
}

void nhill::datenzugriff::ab_oil_pressure_test::mysql::Session::close()
{
   if( session_ != nullptr )
   {
      session_->close();
      session_ = nullptr;
   }
}

mysqlx::Session& nhill::datenzugriff::ab_oil_pressure_test::mysql::Session::session() const
{
   if( !is_open() )
   {
      throw exception( "The session is closed." );
   }
   else
   {
      return *session_;
   }
}

mysqlx::Schema nhill::datenzugriff::ab_oil_pressure_test::mysql::Session::db() const
{
   if( !is_open() )
   {
      throw exception( "The session is closed." );
   }
   else
   {
      return session_->getSchema( db_name );
   }
}

mysqlx::Table nhill::datenzugriff::ab_oil_pressure_test::mysql::Session::table( Record_type record_type ) const
{

   if( !is_open() )
   {
      throw exception( "The session is closed." );
   }
   else
   {
      return session_->getSchema( db_name ).getTable( to_string(record_type));
   }
}

bool nhill::datenzugriff::ab_oil_pressure_test::mysql::Session::execute_sql( const std::string& sql_command )
{
   try
   {
      mysqlx::SqlResult result{ session_->sql( sql_command ).execute() };
      return true;
   }
   catch( exception e )
   {
      return false;
   }
}

mysqlx::SqlResult nhill::datenzugriff::ab_oil_pressure_test::mysql::Session::execute_select( std::string_view table, std::string_view columns, std::string_view where )
{

   ostringstream oss;
   oss << "SELECT ";
   oss << columns;
   oss << " FROM ab_oil_pressure_test.";
   oss << table;
   oss << " WHERE ";
   oss << where;
   oss << ';';

   try
   {
      return session_->sql( oss.str() ).execute();
   }
   catch( exception e )
   {
      throw e;
   }
}

