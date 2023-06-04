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
#include "Measurement.h"
#include <time.h>
#include <vector>

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

    void loadFromDatabase ();
    // Instruction: 
    // Load the Sensors data from the Database

    Sensor* findSensor (string id);
    //Instruction:
    //Finds and return whichever sensor has the same ID sends back an error message otherwise
    
    vector<Sensor> searchSurrounding(float f);
    // Instruction: 
    // Load the Sensors data from the Database

    void markSensor(string id);
    // Instruction: 
    // Mark a Sensor as defective

    float meanAirQualityArea(float area, float latitude, float longtitude, struct tm start, struct tm end);
    // Instruction: 
    // Load the Sensors data from the Database

    float instantAirQuality(float area, float longitude, float latitude, struct tm date);
    // Instruction: 
    // Compute the AirQuality of a Zone in a precise time

    float analyseOneSensor(Sensor s);
    // Instruction: 
    // Load the Sensors data from the Database

    vector<Sensor> compareOneSensor(string id, struct tm begin, struct tm end);
    // Instruction: 
    // Load the Sensors data from the Database

//-------------------------------------------------------- Operator overloading
    SensorFunctions & operator = ( const SensorFunctions & unSensorFunctions );

//--------------------------------------------------- Constructors - destructor
    SensorFunctions ( const SensorFunctions & unSensorFunctions );

    SensorFunctions ( );

    virtual ~SensorFunctions ( );

//--------------------------------------------------------------------- PRIVATE

private:

    vector<Sensor> sensors;
};

#endif // SensorFunctions_H