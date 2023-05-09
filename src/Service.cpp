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
