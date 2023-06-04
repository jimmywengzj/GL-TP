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
//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
// type Provider::Method ( parameter list )
// Algorithm:
//
//{
//} //----- End of Method
void Provider::addCleaner( Cleaner aCleaner)
// Algorithm:
{
    cleaners[aCleaner.getId()] =aCleaner;

#ifdef MAP
    cout << "Calling for addMeasurement method of <Sensor>" << endl;
#endif
}
map<string,Cleaner> Provider::getCleanerList() const{
    return cleaners;
}
//-------------------------------------------------------- Operator overloading
/*Provider & Provider::operator = ( const Provider & unProvider)
// Algorithm:
//
{
} //----- End of operator =
*/
//--------------------------------------------------- Constructors - destructor
Provider::Provider ( const Provider & unProvider)
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling copy constructor of <Provider>" << endl;
#endif
} //----- End of Provider (copy constructor)

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
