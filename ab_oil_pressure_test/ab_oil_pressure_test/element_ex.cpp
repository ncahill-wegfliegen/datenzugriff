#include "element_ex.h"

template<>
const nhill::text::Bundle_container<nhill::datenzugriff::ab_oil_pressure_test::Element>& nhill::text::bundle_container<nhill::datenzugriff::ab_oil_pressure_test::Element>()
{
	using namespace nhill::datenzugriff::ab_oil_pressure_test;

	static const Bundle_container<Element> bundles{
		{ Element::record_type								, { {Text::string, "record_type"								}, {Text::label, "Record Type"												}, {Text::description, "Record type identifier (00, 01,02,03,04,or 05)"} }},
		{ Element::well_identifier							, { {Text::string, "well_identifier"				   	}, {Text::label, "Well Identifier"											}, {Text::description, "Unique identifier for the well."} }},
		{ Element::consol_interval_num					, { {Text::string, "consol_interval_num"					}, {Text::label, "Consolidation Interval Number"						}, {Text::description, "Depth from the surface to the top of the test consolidation interval."} }},
		{ Element::on_production_date						, { {Text::string, "on_production_date"					}, {Text::label, "On Production Date"										}, {Text::description, "The date the production string came on production."} }},
		{ Element::survey_coord_oper_code				, { {Text::string, "survey_coord_oper_code"				}, {Text::label, "Survey Coordinating Operator Code"					}, {Text::description, "Operator assigned to coordinate pool pressure survey.The Coordinating Operator is defined as the operator who produced the most in the pool the previous survey year."} }},
		{ Element::field_code								, { {Text::string, "field_code"								}, {Text::label, "Field Code"													}, {Text::description, "Field code of the field."} }},
		{ Element::pool_code									, { {Text::string, "pool_code"								}, {Text::label, "Pool Code"													}, {Text::description, "Pool code of the pool."} }},
		{ Element::consol_interval_top					, { {Text::string, "consol_interval_top"					}, {Text::label, "Consolidation Interval Top"							}, {Text::description, "Depth from the surface to the top of the test consolidation interval."} }},
		{ Element::consol_interval_bottom				, { {Text::string, "consol_interval_bottom"				}, {Text::label, "Consolidation Interval Bottom"						}, {Text::description, "Depth from the surface to the bottom of the test consolidation interval."} }},
		{ Element::kb_elevation								, { {Text::string, "kb_elevation"							}, {Text::label, "Kelly Bushing Elevation"								}, {Text::description, "The elevation of the kelly bushing measured as metres above mean sea level."} }},
		{ Element::pool_datum_depth						, { {Text::string, "pool_datum_depth"						}, {Text::label, "Pool Datum Depth"											}, {Text::description, "The pool datum is the pool mid formation depth (mfd) adjusted to subsea."} }},
		{ Element::ground_elevation						, { {Text::string, "ground_elevation"						}, {Text::label, "Ground Elevation"											}, {Text::description, "The elevation above sea level at which point the hole was drilled."} }},
		{ Element::well_datum_depth						, { {Text::string, "well_datum_depth"						}, {Text::label, "Well Datum Depth"											}, {Text::description, "Bottom hole pressure adjusted to the pool datum depth (average mid formation depth for each well on pool, adjusted to sea level)."} }},
		{ Element::initial_pool_pressure					, { {Text::string, "initial_pool_pressure"				}, {Text::label, "Initial Pool Pressure"									}, {Text::description, "This is a monthly publication of the pool pressure survey requirements."} }},
		{ Element::reservoir_gradient						, { {Text::string, "reservoir_gradient"					}, {Text::label, "Reservoit Gradient"										}, {Text::description, "Sampled reservoir gas relative density to air."} }},
		{ Element::mid_point_perforation_depth			, { {Text::string, "mid_point_perforation_depth"		}, {Text::label, "Mid-Point Perforation Depth"							}, {Text::description, "The mid point between the top and the base of the perforated producing interval being tested."} }},
		{ Element::run_depth_gradient						, { {Text::string, "run_depth_gradient"					}, {Text::label, "Run Depth Gradient"										}, {Text::description, "The pressure gradient at run depth. It is based on the weight of the material in the production tubing at run depthand is used to adjust the measured pressure to different depths."} }},
		{ Element::run_depth_pressure						, { {Text::string, "run_depth_pressure"					}, {Text::label, "Run Depth Pressure"										}, {Text::description, "The static pressure measured by a recorder at the reported run depth after the well had been shut in for a period of time as part of the test."} }},
		{ Element::reservoir_temperature					, { {Text::string, "reservoir_temperature"				}, {Text::label, "Reservoir Temperature"									}, {Text::description, "The reservoir temperature (°C) for the pool. This is either measured temperature or estimated."} }},
		{ Element::initial_liquid_level					, { {Text::string, "initial_liquid_level"					}, {Text::label, "Initial Liquid Level"									}, {Text::description, "Reported top of the liquid column, in measured (or Log) depth within the well borehole (production casing or tubing) at the moment the well was shut in for pressure testing."} }},
		{ Element::gauge_run_depth							, { {Text::string, "gauge_run_depth"						}, {Text::label, "Gauge Run Depth"											}, {Text::description, "The measured depth from the top of the casing flange where the pressure reading was taken by the recorder.For gradient test this is equivalent to the representative stop depth."} }},
		{ Element::final_liquid_level						, { {Text::string, "final_liquid_level"					}, {Text::label, "Final Liquid Level"										}, {Text::description, "Reported top of final liquid column, in measured (or Log) depth within the well borehole."} }},
		{ Element::oil_gradient								, { {Text::string, "oil_gradient"							}, {Text::label, "Oil Gradient"												}, {Text::description, "Oil gradient is the measure of fluid pressure changes over depth for the fluids produced by the pool. This value is used to adjust test pressures from different depths to a common 'datum' depth."} }},
		{ Element::gas_gradient								, { {Text::string, "gas_gradient"							}, {Text::label, "Gas Gradient"												}, {Text::description, "Calculated gas gradient near the recorder (run) depth which is based on the gas density and depth. Used to make depth corrections in conjunction with the fluid gradient if the pressure recorder is not at datum depth."} }},
		{ Element::water_gradient							, { {Text::string, "water_gradient"							}, {Text::label, "Water Gradient"											}, {Text::description, "Estimated gradient for water in the liquid column of the wellbore (production tubing)."} }},
		{ Element::mpp_pressure								, { {Text::string, "mpp_pressure"							}, {Text::label, "Mid-Point of Perforations Pressure"					}, {Text::description, "Indicates whether the MPP Pressure has been calculated or manually overridden."} }},
		{ Element::extrapolated_pressure_indicator	, { {Text::string, "extrapolated_pressure_indicator"	}, {Text::label, "Extrapolated Pressure Indicator"						}, {Text::description, "Reported results of a well pressure test done to determine the pressure exerted by one or more reservoirs penetrated by the well."} }},
		{ Element::extrapolated_mpp_pressure			, { {Text::string, "extrapolated_mpp_pressure"			}, {Text::label, "Extrapolated Mid-Point of Perforations Pressure"}, {Text::description, "The tepresentative extrapolated/false pressure adjust to mid-point of perforations."} }},
		{ Element::extrapolated_datum_depth_pressure	, { {Text::string, "extrapolated_datum_depth_pressure"}, {Text::label, "Extrapolated Datum Depth Pressure"					}, {Text::description, "The representative extrapolated/false pressure, commonly known as P* adjusted to datum depth."} }},
		{ Element::shut_in_period							, { {Text::string, "shut_in_period"							}, {Text::label, "Shut-In Period"											}, {Text::description, "Reported period of time the well was shut in prior to testing to allow the pressure to build up to the formation pressure."} }},
		{ Element::consol_interval_number				, { {Text::string, "consol_interval_number"				}, {Text::label, "Consolidation Interval Number"						}, {Text::description, "A sequential number used to uniquely identify each well testing consolidation interval for a specific well."} }},
		{ Element::remark_indicator						, { {Text::string, "remark_indicator"						}, {Text::label, "Remark Indicator"											}, {Text::description, "Indicator corresponding to test footnote number."} }},
	};

	return bundles;
}

