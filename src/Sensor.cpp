/******************************************************************************
                             Sensor  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//--------------- Realisation of <Sensor> class (Sensor.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>

//----------------------------------------------------------- Personal includes

#include "Sensor.h"

#include <list>

#include "Measurement.h"

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods

void Sensor::addMeasurement( Measurement aMeasurement )
{
    measurements.push_back(aMeasurement);


#ifdef MAP
    cout << "Calling for addMeasurement method of <Sensor>" << endl;
#endif
} //----- End of addMeasurement

void Sensor::setBad()
{
    good = false;
#ifdef MAP
    cout << "Calling for setBad method of <Sensor>" << endl;
#endif
} //----- End of setBad

//-------------------------------------------------------- Operator overloading


//--------------------------------------------------- Constructors - destructor
Sensor::Sensor ( const Sensor & unSensor )
{
#ifdef MAP
    cout << "Calling copy constructor of <Sensor>" << endl;
#endif
} //----- End of Sensor (copy constructor)


Sensor::Sensor (string anId, float along,  float alat )
{
    this->id = anId;
    this->longitude = along;
    this->latitude = alat;
    this->good = true;
   // this->measurements = new list <Measurement>;
#ifdef MAP
    cout << "Calling constructor of <Sensor>" << endl;
#endif
} //----- End of Sensor

Sensor::~Sensor ( )
{
#ifdef MAP
    cout << "Calling destructor of <Sensor>" << endl;
#endif
} //----- End of ~Sensor

//----------------------------------------------------------------------- Getters/Setters

float Sensor :: getLongitude ( ) const
{
    return longitude;
#ifdef MAP
    cout << "Calling for getLongitude" << endl;
#endif
} //----- End of getLongitude

float Sensor :: getLatitude ( ) const
{
    return latitude;
#ifdef MAP
    cout << "Calling for getLatitude" << endl;
#endif
} //----- End of getLatitude

string Sensor :: getId ( ) const
{
    return id;
#ifdef MAP
    cout << "Calling for getId" << endl;
#endif
} //----- End of getId

bool Sensor :: getGood ( ) const
{
    return good;
} //----- End of getGood

list<Measurement> Sensor :: getMeasurements ( ) const
{
    return measurements;
#ifdef MAP
    cout << "Calling for getMeasurements" << endl;
#endif
} //----- End of getId


//--------------------------------------------------------------------- PRIVATE

//------------------------------------------------------------- Private methods
