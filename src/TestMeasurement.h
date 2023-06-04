/******************************************************************************
                             TestMeasurement  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <TestMeasurement> class interface (TestMeasurement.h file) -----------------------
#if ! defined ( TestMeasurement_H )
#define TestMeasurement_H

//------------------------------------------------------------- Used interfaces
#include "time.h"
#include "Measurement.h"
#include <cassert>
//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <TestMeasurement>
// Testing function for the Measurements class :
// - Test Creation & getters
// - Testing Operator ==
//-----------------------------------------------------------------------------

//---------------------------------------------------------------------- PUBLIC

//------------------------------------------------------------ Public functions

void testMeasurementCreation();

void testOperatorEquality();

void testCopyConstructor();

#endif // TestMeasurement_H