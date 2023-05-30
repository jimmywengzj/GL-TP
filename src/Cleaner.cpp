/******************************************************************************
                             Cleaner  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//--------------- Realisation of <Cleaner> class (Cleaner.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>
#include <string>

//----------------------------------------------------------- Personal includes
#include "Cleaner.h"

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
// type Cleaner::Method ( parameter list )
// Algorithm:
//
//{
//} //----- End of Method
string Cleaner::getId()const 
{
    return id;
} 
//-------------------------------------------------------- Operator overloading
Cleaner & Cleaner::operator = ( const Cleaner & unCleaner )
// Algorithm:
//
{
} //----- End of operator =

//--------------------------------------------------- Constructors - destructor
Cleaner::Cleaner ( const Cleaner & unCleaner )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling copy constructor of <Cleaner>" << endl;
#endif
} //----- End of Cleaner (copy constructor)

Cleaner::Cleaner ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling constructor of <Cleaner>" << endl;
#endif
} //----- End of Cleaner
Cleaner::Cleaner (string id, float longitude, float latitude, struct tm timestampStart, struct tm timestampEnd)
{
    this->id=id;
    this->longitude=longitude;
    this->latitude=latitude;
    this->timestampStart=timestampStart;
    this->timestampEnd=timestampEnd;
#ifdef MAP
    cout << "Calling constructor of <Cleaner>" << endl;
#endif
} //----- End of Cleaner
Cleaner::~Cleaner ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling destructor of <Cleaner>" << endl;
#endif
} //----- End of ~Cleaner

//--------------------------------------------------------------------- PRIVATE

//-------------------------------------------------------------- Private methods
