#pragma once

#include "record_type.h"

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "../../../gemeinsam/enum/core/text/bundle_container.h"
#include "../../../gemeinsam/enum/core/values.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_DZG_ABOPT_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::datenzugriff::ab_oil_pressure_test::Record_type>& nhill::text::bundle_container<nhill::datenzugriff::ab_oil_pressure_test::Record_type>();
#pragma endregion

template<> inline nhill::datenzugriff::ab_oil_pressure_test::Record_type nhill::begin() { return nhill::datenzugriff::ab_oil_pressure_test::Record_type::well_id; }
template<> inline nhill::datenzugriff::ab_oil_pressure_test::Record_type nhill::end  () { return to_enum<nhill::datenzugriff::ab_oil_pressure_test::Record_type>( to_int( nhill::datenzugriff::ab_oil_pressure_test::Record_type::remark ) + 1 ); }

#include "../../../gemeinsam/enum/core/text/methods.h"
#include "../../../gemeinsam/enum/core/text/stream_in.h"
#include "../../../gemeinsam/enum/core/text/stream_out.h"
#pragma endregion



