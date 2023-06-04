/******************************************************************************
                             Sensor  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <Sensor> class interface (Sensor.h file) -----------------------
#if ! defined ( Sensor_H )
#define Sensor_H

using namespace std;

//------------------------------------------------------------------- Used interfaces
#include <vector>
#include "Measurement.h"

//------------------------------------------------------------------- Constants


//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <Sensor> class
//
//
//-----------------------------------------------------------------------------

class Sensor
{
//---------------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------------- Public methods


    void addMeasurement(const Measurement& aMeasurement);
    // Instruction:
    // Add a Measurement to the vector


    void setBad();
    // Instruction:
    // Mark the sensor as Bad (not reliable)
    // Precondition:
    // The sensor is linked to a private user

//-------------------------------------------------------- Operator overloading
    Sensor & operator = ( const Sensor & unSensor );

    bool operator == ( const Sensor & unSensor );

//-------------------------------------- ----------- Getters/Setters

    float getLongitude() const;

    float getLatitude() const;

    string getId() const;

    bool getGood() const;

    vector<Measurement> getMeasurements() const;

//--------------------------------------------------- Constructors - destructor
    Sensor ( const Sensor & unSensor );

    Sensor (string anId, float aLongitude,  float aLatitude);

    virtual ~Sensor ( );

//----------------------------------------------------------------------- PRIVATE

private : 
    string id;
    float longitude;
    float latitude;
    bool good;
    vector<Measurement> measurements;

};

#endif // Sensor