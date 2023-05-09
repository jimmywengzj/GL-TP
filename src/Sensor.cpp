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

//---------------------------------------------------------- Personnal includes

#include "Sensor.h"

#include <list>

#include "Measurement.h"

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
// type Sensor::Method ( parameter list )
// Algorithm:
//
//{
//} //----- End of Method

void Sensor::addMeasurement( Measurement aMeasurement )
// Algorithm:
{
    measurements.add(aMeasurement);

} //----- End of Method

void Sensor::setBad()
// Algorithm:
{
    good = false;

} //----- End of Method

//-------------------------------------------------------- Operator overloading


//--------------------------------------------------- Constructors - destructor
Sensor::Sensor ( const Sensor & unSensor )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling copy constructor of <Sensor>" << endl;
#endif
} //----- End of Sensor (copy constructor)



Sensor::Sensor (string anId, float along,  float alat )
// Algorithm:
//
{
    this->id = anId;
    this->longitude = along;
    this->latitude = alat;
    this->good = true;
    this->measurements = new list <Measurement>;
#ifdef MAP
    cout << "Calling constructor of <Sensor>" << endl;
#endif
} //----- End of Sensor

Sensor::~Sensor ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling destructor of <Sensor>" << endl;
#endif
} //----- End of ~Sensor

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------- Private methods
