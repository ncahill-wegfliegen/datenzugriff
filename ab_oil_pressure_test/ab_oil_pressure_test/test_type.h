#pragma once

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

enum class Test_type
{
	top_hole_undefined						= 1,
	top_hole_buildup							= 2,
	bottom_hole_static_gradient			= 3,
	bottom_hole_build_up						= 4,
	bottom_hole_undefined					= 5,
	bottom_hole_fall_off						= 6,
	drill_stem_test							= 7,
	pressure_sentry							= 8,
	acoustic_well_sounder_single_shot	= 10,
	acoustic_well_sounder_build_up		= 11,
	acoustic_well_sounder_fall_off		= 12,
	rejected_misrun							= 99
};

}
}
}

