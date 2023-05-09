/******************************************************************************
                             Measurement  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <Measurement> class interface (Measurement.h file) -----------------------
#if ! defined ( Measurement )
#define Measurement

//------------------------------------------------------------- Used interfaces



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

    date getTimestamp();

    string getSensorid();

    float getValueO3();

    float getValueNO2();

    float getValuePM10();
    


    void setLongitude(float aLong);

    void setLatitude(float aLat);

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

    Measurement (date aDate, string aSensorid, float O3, float NO2, float PM10);
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

    date timestamp;
    string sensorid;
    float valueO3;
    float valueNO2;
    float valuePM10;

protected:
//------------------------------------------------------------- Private methods

//-------------------------------------------------------- Protected attributes

};

//---------------------------------------- Other definitions dependent on <Measurement>

#endif // Measurement