/******************************************************************************
                             Sensor  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <Sensor> class interface (Sensor.h file) -----------------------
#if ! defined ( Measurement_H )
#define Measurement_H

//------------------------------------------------------------- Used interfaces

#include <time.h>

//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <Measurement> class
//
//
//-----------------------------------------------------------------------------

class Measurement
{
//---------------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------------- Public methods
    // type Method ( parameter list );
    // Instruction:
    //
    // Precondition:
    //

//-------------------------------------------------------- Operator overloading
    Measurement & operator = ( const Measurement & unMeasurement );
    // Instruction:
    //
    // Precondition:
    //

//------------------------------------------------- Getters/Setters

    time_t getTimestamp() const;

    string getSensorId() const;

    float getValueO3() const;

    float getValueNO2() const;

    float getValuePM10() const;
    


//--------------------------------------------------- Constructors - destructor
    Measurement ( const Measurement & unMeasurement );
    // Instruction (copy constructor):
    //
    // Precondition:
    //

    Measurement ( );
    // Instruction:
    //
    // Precondition:
    //

    Measurement (time_t aDate, string aSensorId, float O3, float NO2, float PM10);
    // Instruction:
    //
    // Precondition:
    //

    virtual ~Measurement ( );
    // Instruction:
    //
    // Precondition:
    //

//----------------------------------------------------------------------- PRIVATE

private : 

    time_t timestamp;
    string sensorId;
    float valueO3;
    float valueNO2;
    float valuePM10;

protected:
//------------------------------------------------------------- Private methods

//-------------------------------------------------------- Protected attributes

};

//---------------------------------------- Other definitions dependent on <Measurement>

#endif // Measurement