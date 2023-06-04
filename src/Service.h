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
#include <vector>
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
    void loadFromDatabase();

    int getPoints(User);

    void markUser(User);

    float meanAirQualityArea(float, float, float, struct tm, struct tm);

    float instantAirQuality(float, float, float, struct tm);

    vector<float> studyAirCleaner(string);

    float analyseOneSensor(Sensor);

    Sensor findSensor(string SensorId);

    vector<Sensor> compareOneSensor(Sensor, struct tm, struct tm);

//-------------------------------------------------------- Operator overloading
    Service & operator = ( const Service & unService );

//--------------------------------------------------- Constructors - destructor
    Service ( const Service & unService );

    Service ( );

    virtual ~Service ( );

//--------------------------------------------------------------------- PRIVATE

protected:

//------------------------------------------------------------- Private methods
    UserFunctions userFunctions;

    SensorFunctions sensorFunctions;

    ProviderFunctions providerFunctions;

};
#endif // Service_H