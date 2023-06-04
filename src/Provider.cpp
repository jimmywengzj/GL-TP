/******************************************************************************
                             Provider  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//--------------- Realisation of <Provider> class (Provider.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>
#include <map>
#include <string>

//----------------------------------------------------------- Personal includes
#include "Provider.h"

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
void Provider::addCleaner( Cleaner aCleaner)
{
#ifdef MAP
    cout << "Calling for addMeasurement method of <Sensor>" << endl;
#endif
    cleaners.insert(pair<string,Cleaner>(aCleaner.getId(),aCleaner));
} //----- End of addCleaner

map<string,Cleaner> Provider::getCleanerList() const
{
    return cleaners;
} //----- End of getCleanerList

string Provider::getId() const
{
    return id;
} //----- End of getId

//-------------------------------------------------------- Operator overloading
Provider & Provider::operator = ( const Provider & aProvider )
{
#ifdef MAP
    cout << "Calling = operator of <Provider>" << endl;
#endif
    id = aProvider.id;
    cleaners = *(new map<string,Cleaner>(aProvider.cleaners));
    return *this;
} //----- End of operator =

bool Provider::operator == ( const Provider & aProvider ) const
{
#ifdef MAP
    cout << "Calling == operator of <Provider>" << endl;
#endif
    return id == aProvider.id;
} //----- End of operator ==

//--------------------------------------------------- Constructors - destructor
Provider::Provider ( const Provider & aProvider)
{
#ifdef MAP
    cout << "Calling copy constructor of <Provider>" << endl;
#endif
    id = aProvider.id;
    cleaners = *(new map<string,Cleaner>(aProvider.cleaners));
} //----- End of Provider (copy constructor)

Provider::Provider ( string anId)
{
#ifdef MAP
    cout << "Calling constructor of <Provider>" << endl;
#endif
    id = anId;

} //----- End of Provider

Provider::~Provider ( )
{
#ifdef MAP
    cout << "Calling destructor of <Provider>" << endl;
#endif
} //----- End of ~Provider
