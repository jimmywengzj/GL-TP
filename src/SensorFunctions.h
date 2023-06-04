/******************************************************************************
                             SensorFunctions  -  description
                               -------------------
    start                : $tm$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <SensorFunctions> class interface (SensorFunctions.h file) -----------------------
#if ! defined ( SensorFunctions_H )
#define SensorFunctions_H

//------------------------------------------------------------- Used interfaces

#include "Sensor.h"

#include <Measurement.h>

#include <time.h>

#include <list>

//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <SensorFunctions> class
//
//
//-----------------------------------------------------------------------------

class SensorFunctions
{
//---------------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------------- Public methods
    // type Method ( parameter list );
    // Instruction:
    //
    // Precondition:
    //

    void loadFromDatabase ();
    // Instruction: 
    // Load the Sensors data from the Database
    // Precondition:
    //
    Sensor* findSensor (string SensorId);
    //Instruction:
    //Finds and return whichever sensor has the same Id sends back an error message otherwise
    
    list<Sensor> searchSurrounding(float f);
    // Instruction: 
    // Load the Sensors data from the Database
    // Precondition:
    //

    void markSensor(Sensor s);
    // Instruction: 
    // Mark a Sensor as defective
    // Precondition:
    //


    float meanAirQualityArea(float area, float latitude, float longtitude, struct tm start, struct tm end);
    // Instruction: 
    // Load the Sensors data from the Database
    // Precondition:
    //

    float instantAirQuality(float area, float longitude, float latitude, struct tm date);
    // Instruction: 
    // Compute the AirQuality of a Zone in a precise time
    // Precondition:
    //

    float analyseOneSensor(Sensor s);
    // Instruction: 
    // Load the Sensors data from the Database
    // Precondition:
    //
    

    list<Sensor> compareOneSensor(Sensor s, struct tm begin, struct tm end);
    // Instruction: 
    // Load the Sensors data from the Database
    // Precondition:
    //
//-------------------------------------------------------- Operator overloading
    SensorFunctions & operator = ( const SensorFunctions & unSensorFunctions );
    // Instruction:
    //  
    // Precondition:
    //

//--------------------------------------------------- Constructors - destructor
    SensorFunctions ( const SensorFunctions & unSensorFunctions );
    // Instruction (copy constructor):
    //
    // Precondition:
    //

    SensorFunctions ( );
    // Instruction:
    //
    // Precondition:
    //

    virtual ~SensorFunctions ( );
    // Instruction:
    //
    // Precondition:
    //

//--------------------------------------------------------------------- PRIVATE

private:

    list<Sensor> sensors;



protected:
//------------------------------------------------------------- Private methods

//-------------------------------------------------------- Protected attributes

};

//---------------------------------------- Other definitions depending on <SensorFunctions>

#endif // SensorFunctions_H