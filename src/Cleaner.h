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
    // type Method ( parameter list );
    // Instruction:
    //
    // Precondition:
    //

//-------------------------------------------------------- Operator overloading
    Cleaner & operator = ( const Cleaner & unCleaner );
    // Instruction:
    //
    // Precondition:
    //
    string getId() const;
    float getLatitude() const;
    float getLongitude() const;
    struct tm getStart() const;
    struct tm getEnd() const;

//--------------------------------------------------- Constructors - destructor
    Cleaner( const Cleaner & unCleaner );
    // Instruction (copy constructor):
    //
    // Precondition:
    //

    Cleaner ( );
    // Instruction:
    //
    // Precondition:
    //
    Cleaner (string id, float longitude, float latitude, struct tm timestampStart, struct tm timeStampEnd);
    // Instruction:
    //
    // Precondition:
    //

    virtual ~Cleaner( );
    // Instruction:
    //
    // Precondition:
    //

//--------------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------------- Private methods

//-------------------------------------------------------- Protected attributes
struct tm timestampStart;
struct tm timestampEnd;
float longitude; 
float latitude;
string id;
};

//---------------------------------------- Other definitions depending on <Cleaner>

#endif // CLEANER_H