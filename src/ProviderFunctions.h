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

class ProviderFunctions 
{
//---------------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------------- Public methods
    void loadFromDatabase();

    vector<float> studyAirCleaner(string idCleaner);

//-------------------------------------------------------- Operator overloading
    ProviderFunctions & operator = ( const ProviderFunctions & unProviderFunctions );

//--------------------------------------------------- Constructors - destructor
    ProviderFunctions ( const ProviderFunctions & unProviderFunctions);

    ProviderFunctions ( );

    virtual ~ProviderFunctions ( );

};

#endif // ProviderFunctions_H