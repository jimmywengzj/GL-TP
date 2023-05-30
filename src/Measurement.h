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

#include "time.h"

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

    struct tm getTimestamp() const;

    string getSensorId() const;

    float getValueO3() const;

    float getValueNO2() const;

    float getValuePM10() const;

    float getAQI() const;

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

    Measurement (struct tm aDate, string aSensorId, float O3, float NO2, float SO2, float PM10);
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

    struct tm timestamp;
    string sensorId;
    float valueO3;
    float valueNO2;
    float valueSO2;
    float valuePM10;
    float AQI;

protected:
//------------------------------------------------------------- Private methods

//-------------------------------------------------------- Protected attributes

};

//---------------------------------------- Other definitions dependent on <Measurement>

#endif // Measurement