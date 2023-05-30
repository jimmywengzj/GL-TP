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
    userFunctions.loadFromDatabase();
    sensorFunctions.loadFromDatabase();
    providerFunctions.loadFromDatabase();
}

int Service::getPoints (string name)
{
    int points = userFunctions.getPoints(name);
    return points;
}

void Service::markUser (string name)
{
   userFunctions.markUser(name);
}

float Service::meanAirQuality(float id, float latitude, float longtitude, time_t start, time_t end)
{
    float mquality = sensorFunctions.meanAirQuality(id, latitude, longtitude, start, end);
    return mquality;
}

float Service::instantAirQuality(float id, float latitude, float longtitude, time_t date)
{
    float iquality = sensorFunctions.instantAirQuality(id, latitude, longtitude, date);
    return iquality;
}

float * Service::studyAirCleaner(string id)
{
    float *iequality = providerFunctions.studyAirCleaner(id);
    return iequality;
}

float Service::analyseOneSensor(int id)
{
    float quality = sensorFunctions.analyseOneSensor(id);
    return quality;
}

float Service::compareOneSensor(int id, time_t start, time_t end)
{
    float quality = sensorFunctions.compareOneSensor(id, start, end);
    return quality;
}

//-------------------------------------------------------- Operator overloading
Service & Service::operator = ( const Service & unService )
// Algorithm:
//
{
} //----- End of operator =

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
