#pragma once

namespace nhill
{
namespace datenzugriff
{
namespace ab_oil_pressure_test
{

enum class Element
{
	record_type								,
	well_identifier						,
	consol_interval_num					,
	on_production_date					,
	survey_coord_oper_code				,
	field_code								,
	pool_code								,
	consol_interval_top					,
	consol_interval_bottom				,
	kb_elevation							,
	pool_datum_depth						,
	ground_elevation						,
	well_datum_depth						,
	initial_pool_pressure				,
	reservoir_gradient					,
	mid_point_perforation_depth		,
	gauge_run_depth						,
	run_depth_gradient					,
	run_depth_pressure					,
	reservoir_temperature				,
	initial_liquid_level					,
	final_liquid_level					,
	gas_gradient							,
	oil_gradient							,
	water_gradient							,
	mpp_pressure							,
	extrapolated_pressure_indicator	,
	extrapolated_mpp_pressure			,
	extrapolated_datum_depth_pressure,
	shut_in_period							,
	consol_interval_number				,
	remark_indicator						,

	end,
	beg = record_type
};

}
}
}