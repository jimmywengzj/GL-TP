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

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods

void Service::loadFromDatabase ()
{
    sensorFunctions.loadFromDatabase();
    //cout<<"ended Sensor"<<endl;
    providerFunctions.loadFromDatabase();
    //cout<<"ended Provider"<<endl;
    userFunctions.loadFromDatabase(sensorFunctions);
    //cout<<"ended user"<<endl;
}

int Service::getPoints (User user)
{
    int points = userFunctions.getPoints(user);
    return points;
}
Sensor* Service::findSensor(string SensorId)
{
    return sensorFunctions.findSensor(SensorId);
}
void Service::markUser (User user)
{
   userFunctions.markUser(user);
}

float Service::meanAirQualityArea(float area, float latitude, float longitude, tm start, tm end)
{
    float meanQuality = sensorFunctions.meanAirQualityArea(area, latitude, longitude, start, end);
    return meanQuality;
}

float Service::instantAirQuality(float id, float latitude, float longitude, struct tm date)
{
    float instantQuality = sensorFunctions.instantAirQuality(id, latitude, longitude, date);
    return instantQuality;
}

list<float> Service::studyAirCleaner(string id)
{
    list<float> iequality = providerFunctions.studyAirCleaner(id);
    return iequality;
}

float Service::analyseOneSensor(Sensor sensor)
{
    float quality = sensorFunctions.analyseOneSensor(sensor);
    return quality;
}

list<Sensor> Service::compareOneSensor(Sensor sensor, tm start, tm end)
{
    list<Sensor> quality = sensorFunctions.compareOneSensor(sensor.getId(), start, end);
    return quality;
}

//--------------------------------------------------- Constructors - destructor
Service::Service ( const Service & unService )
// Only for debug purpose
{
#ifdef MAP
    cout << "Calling copy constructor of <Service>" << endl;
#endif
} //----- End of Service (copy constructor)

Service::Service ( )
{
#ifdef MAP
    cout << "Calling constructor of <Service>" << endl;
#endif
} //----- End of Service

Service::~Service ( )
{
#ifdef MAP
    cout << "Calling destructor of <Service>" << endl;
#endif
} //----- End of ~Service
