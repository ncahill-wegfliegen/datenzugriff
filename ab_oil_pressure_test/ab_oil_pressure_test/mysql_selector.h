#pragma once

#include "port.h"
#include "mysql_session.h"
#include "test_container.h"
#include "key_container.h"
#include <map>
#include <string>
#include <memory>
#include <string_view>
#include <ostream>
#include <list>

namespace mysqlx
{
inline namespace abi2
{
inline namespace r0
{
class Row;
}
}
}


namespace nhill
{
namespace uwi
{
class Dls;
}

class Date;

namespace datenzugriff
{
namespace ab_oil_pressure_test
{

class Record00;
class Record01;
class Record02;
class Record03;
class Record04;
class Record05;
enum class Record_type;
enum class Test_type;

namespace mysql
{
class Configuration;

class NHILL_DZG_ABOPT_PORT_CLASS Selector : public Session
{
public:
   using base = Session;

   Selector();
   Selector( std::string_view  username, std::string_view password, std::string_view hostname );
   Selector( const Configuration& config );
   ~Selector();

   /// <summary>The count of the consol_interval_nums that are associated with the given uwi.</summary>
   unsigned count_consol_interval_num( const uwi::Dls& uwi );
   unsigned count_test_index( const Key& key );
   unsigned count_remark_indicator( const Key& key );

   template<typename RECORD> RECORD find_rec( const Key& key, int index = -1 );
   template<> Record00 find_rec( const Key& key, int );
   template<> Record01 find_rec( const Key& key, int );
   template<> Record02 find_rec( const Key& key, int );
   template<> Record03 find_rec( const Key& key, int );
   template<> Record04 find_rec( const Key& key, int test_index );
   template<> Record05 find_rec( const Key& key, int remark_indicator );

   Key_container find_key_by_uwi( const uwi::Dls& uwi );
   Key_container find_key_by_licensee_code( const std::string& licensee_code );
   Key_container find_key_by_field_pool( const std::string& field_code, const std::string& pool_code = {} );
   Key_container find_key_by_test_type( const std::list<Test_type>& test_types );

   Test find_test( const Key& key );
   Test_container find_test( const Key_container& keys );

protected:
   static std::string build_where( Record_type record_type, const Key& key, int index = -1 );

   template<typename RECORD> RECORD convert( const mysqlx::Row& row );
   template<> Record00 convert( const mysqlx::Row& row );
   template<> Record01 convert( const mysqlx::Row& row );
   template<> Record02 convert( const mysqlx::Row& row );
   template<> Record03 convert( const mysqlx::Row& row );
   template<> Record04 convert( const mysqlx::Row& row );
   template<> Record05 convert( const mysqlx::Row& row );
   template<> Key convert( const mysqlx::Row& row );


   //static Record00 to00( const mysqlx::Row& row );
   mysqlx::SqlResult execute_select( Record_type record_type, const Key& key, int index = -1 );

};



}
}
}
}

template<typename RECORD>
inline RECORD nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::find_rec( const Key& key, int index )
{
   throw std::exception( "This template must be specialized for each record type." );
}

template<typename RECORD>
inline RECORD nhill::datenzugriff::ab_oil_pressure_test::mysql::Selector::convert( const mysqlx::Row& row )
{
   throw std::exception( "This template must be specialized for each record type." );
}

