/******************************************************************************
                             SensorFunctions  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//--------------- Realisation of <SensorFunctions> class (SensorFunctions.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>

//----------------------------------------------------------- Personal includes
#include "SensorFunctions.h"

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
// type SensorFunctions::Method ( parameter list )
// Algorithm:
//
//{
//} //----- End of Method

//-------------------------------------------------------- Operator overloading
SensorFunctions & SensorFunctions::operator = ( const SensorFunctions & unSensorFunctions )
// Algorithm:
//
{
} //----- End of operator =

//--------------------------------------------------- Constructors - destructor
SensorFunctions::SensorFunctions ( const SensorFunctions & unSensorFunctions )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling copy constructor of <SensorFunctions>" << endl;
#endif
} //----- End of SensorFunctions (copy constructor)

SensorFunctions::SensorFunctions ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling constructor of <SensorFunctions>" << endl;
#endif
} //----- End of SensorFunctions

SensorFunctions::~SensorFunctions ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling destructor of <SensorFunctions>" << endl;
#endif
} //----- End of ~SensorFunctions

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------- Private methods
