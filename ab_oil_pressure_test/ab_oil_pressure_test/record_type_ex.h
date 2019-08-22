#pragma once

#include "record_type.h"

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "../../../gemeinsam/enum/core/text/bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_ENUM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::datenzugriff::ab_oil_pressure_test::Record_type>& nhill::text::bundle_container<nhill::datenzugriff::ab_oil_pressure_test::Record_type>();
#pragma endregion

#include "../../../gemeinsam/enum/core/text/methods.h"
#include "../../../gemeinsam/enum/core/text/stream_in.h"
#include "../../../gemeinsam/enum/core/text/stream_out.h"
#pragma endregion



