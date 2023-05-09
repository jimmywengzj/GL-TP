/******************************************************************************
                             Service  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <Service> class interface (Service.h file) -----------------------
#if ! defined ( Service_H )
#define Service_H

//------------------------------------------------------------- Used interfaces
#include <string>
#include <list>
//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <Service> class
//
//
//-----------------------------------------------------------------------------

class Service
{
//---------------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------------- Public methods
    // type Method ( parameter list );
    // Instruction:
    //
    // Precondition:
    //
    void loadFromDatabase();
    int getPoints(string);
    void markUser(string);
    float meanAirQuality(float, float, float, time_t, time_t);
    float instantAirQuality(float, float, float, time_t);
    float * studyAirCleaner(string);
    float analyseOneSensor(int);
    
    float compareOneSensor(int, time_t, time_t);

//-------------------------------------------------------- Operator overloading
    Service & operator = ( const Service & unService );
    // Instruction:
    //
    // Precondition:
    //

//--------------------------------------------------- Constructors - destructor
    Service ( const Service & unService );
    // Instruction (copy constructor):
    //
    // Precondition:
    //

    Service ( );
    // Instruction:
    //
    // Precondition:
    //

    virtual ~Service ( );
    // Instruction:
    //
    // Precondition:
    //

//--------------------------------------------------------------------- PRIVATE

protected:
UserFunctions userFunctions;
SensorFunctions sensorFunctions;
ProviderFunctions providerFunctions;

//------------------------------------------------------------- Private methods

//-------------------------------------------------------- Protected attributes

};

//---------------------------------------- Other definitions depending on <Service>

#endif // Service_H