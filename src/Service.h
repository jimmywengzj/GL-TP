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
#include "UserFunctions.h"
#include "SensorFunctions.h"
#include "ProviderFunctions.h"
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
    int getPoints(User);
    void markUser(User);
    float meanAirQualityArea(float, float, float, struct tm, struct tm);
    float instantAirQuality(float, float, float, struct tm);
    list<float> studyAirCleaner(string);
    float analyseOneSensor(Sensor);
    Sensor* findSensor(string SensorId);
    list<Sensor> compareOneSensor(Sensor, struct tm, struct tm);

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