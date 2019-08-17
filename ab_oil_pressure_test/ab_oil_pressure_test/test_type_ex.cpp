#include "test_type_ex.h"

template<>
const nhill::text::Bundle_container<nhill::datenzugriff::ab_oil_pressure_test::Test_type>& nhill::text::bundle_container<nhill::datenzugriff::ab_oil_pressure_test::Test_type>()
{
	using namespace nhill::datenzugriff::ab_oil_pressure_test;

	static const Bundle_container<Test_type> bundles{
		{ Test_type::top_hole_undefined					, { {Text::string, "top_hole_undefined"					}, {Text::label, "Top Hole Undefined"					   }}},
		{ Test_type::top_hole_buildup						, { {Text::string, "top_hole_buildup"						}, {Text::label, "Top Hole Build Up"					   }}},
		{ Test_type::bottom_hole_static_gradient		, { {Text::string, "bottom_hole_static_gradient"		}, {Text::label, "Bottom Hole Static Gradient"			}}},
		{ Test_type::bottom_hole_build_up					, { {Text::string, "bottom_hole_build_up"					}, {Text::label, "Bottom Hole Build Up"					}}},
		{ Test_type::bottom_hole_undefined				, { {Text::string, "bottom_hole_undefined"				}, {Text::label, "Bottom Hole Undefined"					}}},
		{ Test_type::bottom_hole_fall_off					, { {Text::string, "bottom_hole_fall_off"					}, {Text::label, "Bottom Hole Fall Off"					}}},
		{ Test_type::drill_stem_test						, { {Text::string, "drill_stem_test"						}, {Text::label, "Drill Stem Test"							}}},
		{ Test_type::pressure_sentry						, { {Text::string, "pressure_sentry"						}, {Text::label, "Pressure Sentry"							}}},
		{ Test_type::acoustic_well_sounder_single_shot, { {Text::string, "acoustic_well_sounder_single_shot"}, {Text::label, "Acoustice Well Sounder-Single Shot"	}}},
		{ Test_type::acoustic_well_sounder_build_up	, { {Text::string, "acoustic_well_sounder_build_up"	}, {Text::label, "Acoustice Well Sounder-Build Up"		}}},
		{ Test_type::acoustic_well_sounder_fall_off	, { {Text::string, "acoustic_well_sounder_fall_off"	}, {Text::label, "Acoustice Well Sounder-Fall Off"		}}},
		{ Test_type::rejected_misrun						, { {Text::string, "rejected_misrun"						}, {Text::label, "Rejected Misrun"							}}},
	};

	return bundles;
}

