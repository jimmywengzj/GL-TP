/******************************************************************************
                             Sensor  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <Sensor> class interface (Sensor.h file) -----------------------
#if ! defined ( Sensor )
#define Sensor

//------------------------------------------------------------------- Used interfaces

#include "Measurement.h"

#include <list>

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
    // type Method ( parameter list );
    // Instruction:
    //
    // Precondition:
    //


    void addMeasurement(Measurement aMeasurement);
    // Instruction: Add a Measurement to the List
    //
    // Precondition:
    //

    void setBad();
    // Instruction: Mark the sensor as Bad (not reliable)
    //
    // Precondition: The sensor is linked to a private user
    //

//-------------------------------------------------------- Operator overloading
    Sensor & operator = ( const Sensor & unSensor );
    // Instruction:
    //
    // Precondition:
    //

//-------------------------------------- ----------- Getters/Setters

    float getLongitude();

    float getLatitude();

    string getId();

    list<Measurement> getMeasurements();

    void setLongitude(float aLong);

    void setLatitude(float aLat);

//--------------------------------------------------- Constructors - destructor
    Sensor ( const Sensor & unSensor );
    // Instruction (copy constructor):
    //
    // Precondition:
    //

    Sensor (string anId, float along,  float alat );
    // Instruction:
    //
    // Precondition:
    //

    virtual ~Sensor ( );
    // Instruction:
    //
    // Precondition:
    //

//----------------------------------------------------------------------- PRIVATE

private : 
    string id;
    float longitude;
    float latitude;
    bool good;
    list<Measurement> measurements;

protected:
//------------------------------------------------------------- Private methods

//-------------------------------------------------------- Protected attributes

};

//---------------------------------------- Other definitions dependent on <Sensor>

#endif // Sensor