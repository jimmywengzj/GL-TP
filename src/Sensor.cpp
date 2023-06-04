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

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods

void Sensor::addMeasurement(const Measurement& aMeasurement )
{
#ifdef MAP
    cout << "Calling for addMeasurement method of <Sensor>" << endl;
#endif
    measurements.push_back(aMeasurement);
} //----- End of addMeasurement

void Sensor::setBad()
{
#ifdef MAP
    cout << "Calling for setBad method of <Sensor>" << endl;
#endif
    good = false;
} //----- End of setBad

//-------------------------------------------------------- Operator overloading


//--------------------------------------------------- Constructors - destructor
Sensor::Sensor ( const Sensor & unSensor )
{
#ifdef MAP
    cout << "Calling copy constructor of <Sensor>" << endl;
#endif
    id = unSensor.id;
    longitude = unSensor.longitude;
    latitude = unSensor.latitude;
    good = unSensor.good;
    measurements = *(new vector<Measurement>(unSensor.measurements));
} //----- End of Sensor (copy constructor)

Sensor & Sensor::operator = ( const Sensor & unSensor ){
    id = unSensor.id;
    longitude = unSensor.longitude;
    latitude = unSensor.latitude;
    good = unSensor.good;
    return *this;
} //----- End of operator =

bool Sensor::operator == ( const Sensor & unSensor ){
    return (
            id == unSensor.id &&
            longitude == unSensor.longitude &&
            latitude == unSensor.latitude &&
            good == unSensor.good
            );
} //----- End of operator ==

Sensor::Sensor (string anId, float aLongitude,  float aLatitude )
{
#ifdef MAP
    cout << "Calling constructor of <Sensor>" << endl;
#endif
    this->id = anId;
    this->longitude = aLongitude;
    this->latitude = aLatitude;
    this->good = true;
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
#ifdef MAP
    cout << "Calling for getLongitude" << endl;
#endif
    return longitude;
} //----- End of getLongitude

float Sensor :: getLatitude ( ) const
{
#ifdef MAP
    cout << "Calling for getLatitude" << endl;
#endif
    return latitude;
} //----- End of getLatitude

string Sensor :: getId ( ) const
{
#ifdef MAP
    cout << "Calling for getId" << endl;
#endif
    return id;
} //----- End of getId

bool Sensor :: getGood ( ) const
{
#ifdef MAP
    cout << "Calling for getGood" << endl;
#endif
    return good;
} //----- End of getGood

vector<Measurement> Sensor :: getMeasurements ( ) const
{
#ifdef MAP
    cout << "Calling for getMeasurements" << endl;
#endif
    return measurements;
} //----- End of getId


//--------------------------------------------------------------------- PRIVATE

//------------------------------------------------------------- Private methods
