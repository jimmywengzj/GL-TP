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
#include <string>
#include "Cleaner.h"
#include <list>
#include <map> 
using namespace std;
//------------------------------------------------------------- Used interfaces

//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

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
    // type Method ( parameter list );
    // Instruction:
    //
    // Precondition:
    //
    void addCleaner(Cleaner aCleaner);
//-------------------------------------------------------- Operator overloading
    Provider & operator = ( const Provider & unProvider );
    // Instruction:
    //
    // Precondition:
    //
    string getId() const;
    map<string,Cleaner> getCleanerList() const;

//--------------------------------------------------- Constructors - destructor
    Provider ( const Provider & unProvider);
    // Instruction (copy constructor):
    //
    // Precondition:
    //

    Provider ( );
    // Instruction:
    //
    // Precondition:
    //
    Provider (string id);
    // Instruction:
    //
    // Precondition:
    //
    virtual ~Provider ( );
    // Instruction:
    //
    // Precondition:
    //

//--------------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------------- Private methods

//-------------------------------------------------------- Protected attributes
string id;
map<string,Cleaner> cleaners;
};

//---------------------------------------- Other definitions depending on <Xxx>

#endif // XXX_H