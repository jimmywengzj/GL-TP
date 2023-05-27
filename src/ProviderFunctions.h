/******************************************************************************
                             ProviderFunction  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <ProviderFunction> class interface (ProviderFunction.h file) -----------------------
#if ! defined ( ProviderFunctions_H )
#define ProviderFunctions_H

//------------------------------------------------------------- Used interfaces

//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <ProviderFunctions> class
//
//
//-----------------------------------------------------------------------------

class ProviderFunctions 
{
//---------------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------------- Public methods
    // type Method ( parameter list );
    // Instruction:
    //
    // Precondition:
    //
    void loadFromDataBase();
//-------------------------------------------------------- Operator overloading
    ProviderFunctions & operator = ( const ProviderFunctions & unProviderFunctions );
    // Instruction:
    //
    // Precondition:
    //

//--------------------------------------------------- Constructors - destructor
    ProviderFunctions ( const ProviderFunctions & unProviderFunctions);
    // Instruction (copy constructor):
    //
    // Precondition:
    //

    ProviderFunctions ( );
    // Instruction:
    //
    // Precondition:
    //

    virtual ~ProviderFunctions ( );
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