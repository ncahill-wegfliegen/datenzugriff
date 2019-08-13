#pragma once

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

enum class Record_type
{
   well_id   , // Well ID and On Production Date
   licensee  , // Licensee and Well Status
   field_pool, // Designated Field and Pool
   well_data , // Well Data
   test_data , // Test Data
   remarks   , // Remarks

   end,
   begin = well_id
};

}
}
}