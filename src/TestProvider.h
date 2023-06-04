/******************************************************************************
                             TestProvider  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <TestProvider> class interface (TestProvider.h file) -----------------------
#if ! defined ( TestProvider_H )
#define TestProvider_H

//------------------------------------------------------------- Used interfaces
#include "time.h"
#include "Provider.h"
#include <cassert>
//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <TestProvider>
// Testing function for the Providers class :
// - Test Creation & getters
// - Testing Operator ==
//-----------------------------------------------------------------------------

//---------------------------------------------------------------------- PUBLIC

//------------------------------------------------------------ Public functions

void testProviderCreation();

void testOperatorEquality();

void testCopyConstructor();

#endif // TestProvider_H