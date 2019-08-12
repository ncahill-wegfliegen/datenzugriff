///////////////////////////////////////////////////////////////////////
//
// File: nhill/datenzugriff/ab_oil_pressure_test/port.h
// Date: 11 Aug 2019 nhill
//
// Definitions for exporting/importing library elements.
// Define NHILL_DZG_ABOPT_STATIC if the module is a static library, 
// or if you want to use the code directly.
// Define NHILL_DZG_ABOPT_EXPORT if the module is dynamic (shared) library.
//
// NHILL_DZG_ABOPT_PORT_CLASS      export/import a class
// NHILL_DZG_ABOPT_PORT_CFUNCTION  export/import a "C" function
// NHILL_DZG_ABOPT_PORT_FUNCTION   export/import a function( which is not a "C" function )
// NHILL_DZG_ABOPT_PORT_TEMPLATE   export/import a template instantiation
// 
// Copyright (c) 2019 Bemühen, ltd.  All rights reserved.
//
// NONDISCLOSURE
//   This is proprietary software of Bemühen, ltd.
//   This software is considered to contain trade secret information,
//   the exclusive rights to whom belong to Bemühen, ltd.
//   Source code may NOT be disclosed to any person without prior
//   written permission of Bemühen, ltd. Object code may be
//   disclosed or transmitted upon proper licensing.
//
///////////////////////////////////////////////////////////////////////
#pragma once

#if defined(NHILL_DZG_ABOPT_STATIC)
#   ifndef NHILL_DZG_ABOPT_PORT_CLASS
#       define NHILL_DZG_ABOPT_PORT_CLASS
#   endif
#   ifndef NHILL_DZG_ABOPT_PORT_CFUNCTION
#       define NHILL_DZG_ABOPT_PORT_CFUNCTION
#   endif
#   ifndef NHILL_DZG_ABOPT_PORT_FUNCTION
#       define NHILL_DZG_ABOPT_PORT_FUNCTION
#   endif
#   ifndef NHILL_DZG_ABOPT_PORT_TEMPLATE
#       define NHILL_DZG_ABOPT_PORT_TEMPLATE
#   endif
#elif defined(NHILL_DZG_ABOPT_EXPORT)
#   ifndef NHILL_DZG_ABOPT_PORT_CLASS
#       define NHILL_DZG_ABOPT_PORT_CLASS __declspec(dllexport)
#   endif
#   ifndef NHILL_DZG_ABOPT_PORT_CFUNCTION
#       define NHILL_DZG_ABOPT_PORT_CFUNCTION extern "C" __declspec(dllexport)
#   endif
#   ifndef NHILL_DZG_ABOPT_PORT_FUNCTION
#       define NHILL_DZG_ABOPT_PORT_FUNCTION __declspec(dllexport)
#   endif
#   ifndef NHILL_DZG_ABOPT_PORT_TEMPLATE
#       define NHILL_DZG_ABOPT_PORT_TEMPLATE
#   endif
#else
#   ifndef NHILL_DZG_ABOPT_PORT_CLASS
#       define NHILL_DZG_ABOPT_PORT_CLASS __declspec(dllimport)
#   endif
#   ifndef NHILL_DZG_ABOPT_PORT_CFUNCTION
#       define NHILL_DZG_ABOPT_PORT_CFUNCTION extern "C" __declspec(dllimport)
#   endif
#   ifndef NHILL_DZG_ABOPT_PORT_FUNCTION
#       define NHILL_DZG_ABOPT_PORT_FUNCTION __declspec(dllimport)
#   endif
#   ifndef NHILL_DZG_ABOPT_PORT_TEMPLATE
#       define NHILL_DZG_ABOPT_PORT_TEMPLATE extern
#   endif
#endif
