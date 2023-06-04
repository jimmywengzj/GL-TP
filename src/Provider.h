/******************************************************************************
                             Provider  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <Provider> class interface (Provider.h file) -----------------------
#if ! defined ( Provider_H )
#define Provider_H

using namespace std;
//------------------------------------------------------------- Used interfaces
#include <list>
#include <map>
#include <string>
#include "Cleaner.h"

//-----------------------------------------------------------------------------
// Role of <Provider> class
//
//
//-----------------------------------------------------------------------------

class Provider 
{
//---------------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------------- Public methods
    void addCleaner(Cleaner aCleaner);

//-------------------------------------------------------- Operator overloading
    Provider & operator = ( const Provider & unProvider );

    bool operator == ( const Provider & unProvider ) const;

//------------------------------------------------------------- Getters - Setters
    string getId() const;

    map<string,Cleaner> getCleanerList() const;

//--------------------------------------------------- Constructors - destructor
    Provider ( const Provider & unProvider);

    Provider ( );

    Provider (string id);

    virtual ~Provider ( );

//--------------------------------------------------------------------- PRIVATE

protected:
//-------------------------------------------------------- Protected attributes
    string id;
    map<string,Cleaner> cleaners;
};


#endif