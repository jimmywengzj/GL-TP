/******************************************************************************
                             Cleaner  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <Cleaner> class interface (Cleaner.h file) -----------------------
#if ! defined ( CLEANER_H )
#define CLEANER_H
#include <string>
#include "time.h"
using namespace std;
//------------------------------------------------------------- Used interfaces

//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <Cleaner> class
//
//
//-----------------------------------------------------------------------------

class Cleaner 
{
//---------------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------------- Public methods

//-------------------------------------------------------- Operator overloading
    Cleaner & operator = ( const Cleaner & unCleaner );

    bool operator == ( const Cleaner & unCleaner ) const;

//------------------------------------------------- Getters/Setters

    string getId() const;

    float getLatitude() const;

    float getLongitude() const;

    tm getStart() const;

    tm getEnd() const;

//--------------------------------------------------- Constructors - destructor
    Cleaner( const Cleaner & unCleaner );

    Cleaner ( );

    Cleaner (string id, float longitude, float latitude, const tm timestampStart, const tm timeStampEnd);

    virtual ~Cleaner( );

//--------------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------------- Private methods

//-------------------------------------------------------- Protected attributes
tm timestampStart;
tm timestampEnd;
float longitude; 
float latitude;
string id;
};

//---------------------------------------- Other definitions depending on <Cleaner>

#endif // CLEANER_H