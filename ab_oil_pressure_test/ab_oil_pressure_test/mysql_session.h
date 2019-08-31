#pragma once

#include "port.h"
#include <string>
#include <string_view>
#include <list>
#include <memory>

namespace mysqlx 
{
inline namespace abi2
{
inline namespace r0
{
class Session;
class Schema;
class Table;
class SqlResult;
}
}
}

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{
enum class Record_type;

namespace mysql
{

class NHILL_DZG_ABOPT_PORT_CLASS Session
{
public:
   Session();
   Session( std::string_view  username, std::string_view password );
   virtual ~Session();

   bool open();
   bool open( std::string_view  username, std::string_view password );
   bool is_open() const;
   void close();

   mysqlx::Session& session() const; // Check to make sure the session is open before calling this property.
   mysqlx::Schema db() const;
   mysqlx::Table table( Record_type record_type ) const;

   bool execute_sql( const std::string& sql_command );
   mysqlx::SqlResult execute_select( std::string_view table, std::string_view columns, std::string_view where );

   static constexpr const char* const db_name{ "ab_oil_pressure_test" }; // Schema name

private:
#pragma warning(push)
#pragma warning(disable:4251)
   std::string username_;
   std::string password_;
   std::unique_ptr<mysqlx::Session> session_;
#pragma warning(pop)
};

}
}
}
}