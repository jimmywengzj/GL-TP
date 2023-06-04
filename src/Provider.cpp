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

//----------------------------------------------------------- Personal includes
#include "Provider.h"
#include "Cleaner.h"
#include <map> 
#include <string>
//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
void Provider::addCleaner( Cleaner aCleaner)
{
    cleaners.insert(pair<string,Cleaner>(aCleaner.getId(),aCleaner));

#ifdef MAP
    cout << "Calling for addMeasurement method of <Sensor>" << endl;
#endif
}
map<string,Cleaner> Provider::getCleanerList() const{
    return cleaners;
}
string Provider::getId() const{
    return id;
}
//-------------------------------------------------------- Operator overloading
Provider & Provider::operator = ( const Provider & aProvider ){
#ifdef MAP
    cout << "Calling = operator of <Provider>" << endl;
#endif
    id = aProvider.id;
    cleaners = *(new map<string,Cleaner>(aProvider.cleaners));
    return *this;
}

bool Provider::operator == ( const Provider & aProvider ) const{
#ifdef MAP
    cout << "Calling == operator of <Provider>" << endl;
#endif
    return id == aProvider.id;
}

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
    id= anId;
} //----- End of Provider

Provider::Provider ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling constructor of <Provider>" << endl;
#endif
} //----- End of Provider

Provider::Provider ( string id)
// Algorithm:
//
{
    this->id=id;
#ifdef MAP
    cout << "Calling constructor of <Provider>" << endl;
#endif
} //----- End of Provider

Provider::~Provider ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling destructor of <Provider>" << endl;
#endif
} //----- End of ~Provider

//--------------------------------------------------------------------- PRIVATE

//-------------------------------------------------------------- Private methods
