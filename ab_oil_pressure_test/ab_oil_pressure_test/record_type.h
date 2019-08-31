#pragma once

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

enum class Record_type
{
   well_id    = 0, // Well ID and On Production Date
   licensee   = 1, // Licensee and Well Status
   field_pool = 2, // Designated Field and Pool
   well_data  = 3, // Well Data
   test_data  = 4, // Test Data
   remark    = 5, // Remarks

   end,
   begin = well_id
};

}
}
}