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

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
// type Xxx::Method ( parameter list )
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
    return mequality;
}

float Service::instantAirQuality(float id, float latitude, float longtitude, time_t date)
{
    float iequality = sensorFunctions.instantAirQuality(id, latitude, longtitude, date);
    return iequality;
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
Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithm:
//
{
} //----- End of operator =

//--------------------------------------------------- Constructors - destructor
Xxx::Xxx ( const Xxx & unXxx )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling copy constructor of <Xxx>" << endl;
#endif
} //----- End of Xxx (copy constructor)

Xxx::Xxx ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling constructor of <Xxx>" << endl;
#endif
} //----- End of Xxx

Xxx::~Xxx ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling destructor of <Xxx>" << endl;
#endif
} //----- End of ~Xxx

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------- Private methods
