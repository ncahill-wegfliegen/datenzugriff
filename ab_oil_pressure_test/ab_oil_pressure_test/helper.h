#pragma once

namespace key
{
enum Index
{
	type,			// record type
	le,			// location exception
	lsd,			// legal subdivision
	sc,			// section
	twp,			// township
	rg,			// range
	m,				// meridian
	es,			// event sequence
	cinum,		// consolidation interval number

	cnt,			// number of indices
};
}

namespace rec00
{
enum Index
{
	name,			// well name
	date,			// on production date

	cnt,			// number of indices
};
}

namespace rec01
{
enum Index
{
	lcd,   // licensee code
	lab,   // licensee abbreviation
	scd,   // survey coordinating operator code      
	sab,   // survey coordinating operator abbreviation
	wdt,   // well status date
	wcd,   // well status code

	cnt,   // number of indices
};
}

namespace rec02
{
enum Index
{
	fn, // field name
	pn, // pool name

	cnt,  // number of indices
};
}

namespace rec03
{
enum Index
{
	fcd, // field code
	pcd, // pool code
	top, // consolidation interval top
	btm, // consolidation interval bottom
	kb,  // kb elevation
	pdt, // pool datum depth
	ge,  // ground elevation
	wdt, // well datum depth
	ip,  // initial pool pressure
	rg,  // reservoir gradient

	cnt, // number of indices
};
}

namespace rec04
{
enum Index
{
	td,	// test date
	tt,	// test type
	hwsd, // historical well status date
	hwsc, // historical well status code
	cp,	// casing pressure
	mppd,	// midpoint perforation depth
	grd,	// gauge run depth
	rdg,	// run depth gradient
	rdp,	// run depth pressure
	rt,	// reservoir temperature
	ill,	// initial liquid level
	fll,	// final liquid level
	gg,	// gas gradient
	og,	// oil gradient
	wg,	// water gradient
	mppp,	// midpoint perforation pressure
	ddp,	// datum depth pressure
	epi,	// extrpolated pressure indicator
	emppp,// extrapolated midpoint perforation pressure
	eddp,	// extrapolated datum depth pressure
	sip,	// shut in period
	fn,	// footnote number

	cnt,
};
}

namespace rec05
{
enum Index
{
	ri, // remark indicator
	r,  // remark

	cnt,
};
}
