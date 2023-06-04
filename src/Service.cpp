/******************************************************************************
                             Service  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//--------------- Realisation of <Service> class (Service.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>

//----------------------------------------------------------- Personal includes
#include "Service.h"
#include "UserFunctions.h"
#include "SensorFunctions.h"
#include "ProviderFunctions.h"
//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
// type Service::Method ( parameter list )
// Algorithm:
//
//{
//} //----- End of Method

void Service::loadFromDatabase ()
{
    sensorFunctions.loadFromDatabase();
    providerFunctions.loadFromDatabase();
    userFunctions.loadFromDatabase(sensorFunctions);

}

int Service::getPoints (User name)
{
    int points = userFunctions.getPoints(name);
    return points;
}

void Service::markUser (User name)
{
   userFunctions.markUser(name);
}

float Service::meanAirQualityArea(float area, float latitude, float longtitude, struct tm start, struct tm end)
{
    float mquality = sensorFunctions.meanAirQualityArea(area, latitude, longtitude, start, end);
    return mquality;
}

float Service::instantAirQuality(float id, float latitude, float longtitude, struct tm date)
{
    float iquality = sensorFunctions.instantAirQuality(id, latitude, longtitude, date);
    return iquality;
}

list<float> Service::studyAirCleaner(string id)
{
    list<float> iequality = providerFunctions.studyAirCleaner(id);
    return iequality;
}

float Service::analyseOneSensor(Sensor id)
{
    float quality = sensorFunctions.analyseOneSensor(id);
    return quality;
}

list<Sensor> Service::compareOneSensor(Sensor id, struct tm start, struct tm end)
{
    list<Sensor> quality = sensorFunctions.compareOneSensor(id, start, end);
    return quality;
}

//-------------------------------------------------------- Operator overloading
/*Service & Service::operator = ( const Service & unService )
// Algorithm:
//
{
} //----- End of operator =
*/
//--------------------------------------------------- Constructors - destructor
Service::Service ( const Service & unService )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling copy constructor of <Service>" << endl;
#endif
} //----- End of Service (copy constructor)

Service::Service ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling constructor of <Service>" << endl;
#endif
} //----- End of Service

Service::~Service ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling destructor of <Service>" << endl;
#endif
} //----- End of ~Service

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------- Private methods
