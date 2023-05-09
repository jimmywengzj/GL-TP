/******************************************************************************
                             Xxx  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <Xxx> class interface (Xxx.h file) -----------------------
#if ! defined ( XXX_H )
#define XXX_H

//------------------------------------------------------------- Used interfaces

//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <Service> class
//
//
//-----------------------------------------------------------------------------

class Service : public Ancestor
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
    Xxx & operator = ( const Xxx & unXxx );
    // Instruction:
    //
    // Precondition:
    //

//--------------------------------------------------- Constructors - destructor
    Xxx ( const Xxx & unXxx );
    // Instruction (copy constructor):
    //
    // Precondition:
    //

    Xxx ( );
    // Instruction:
    //
    // Precondition:
    //

    virtual ~Xxx ( );
    // Instruction:
    //
    // Precondition:
    //

//--------------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------------- Private methods

//-------------------------------------------------------- Protected attributes

};

//---------------------------------------- Other definitions depending on <Xxx>

#endif // XXX_H