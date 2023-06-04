/******************************************************************************
                             TestCleaner  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <TestCleaner> class interface (TestCleaner.h file) -----------------------
#if ! defined ( TestCleaner_H )
#define TestCleaner_H

//------------------------------------------------------------- Used interfaces
#include "time.h"
#include "Cleaner.h"
#include <cassert>
//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <TestCleaner>
// Testing function for the Cleaners class :
// - Test Creation & getters
// - Testing Operator ==
//-----------------------------------------------------------------------------

//---------------------------------------------------------------------- PUBLIC

//------------------------------------------------------------ Public functions

void testCleanerCreation();

void testOperatorEquality();

void testCopyConstructor();

#endif // TestCleaner_H