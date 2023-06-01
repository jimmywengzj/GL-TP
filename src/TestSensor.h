/******************************************************************************
                             TestSensor  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <TestSensor> class interface (TestSensor.h file) -----------------------
#if ! defined ( TestSensor_H )
#define TestSensor_H

//------------------------------------------------------------- Used interfaces
#include "time.h"
#include "Sensor.h"
#include <cassert>
//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <TestSensor>
// Testing function for the Measurements class :
// - Test Creation & getters
//-----------------------------------------------------------------------------

//---------------------------------------------------------------------- PUBLIC

//------------------------------------------------------------ Public functions

void testSensorCreation();


#endif // TestSensor_H