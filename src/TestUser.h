/******************************************************************************
                             TestUser  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <TestUser> class interface (TestUser.h file) -----------------------
#if ! defined ( TestUser_H )
#define TestUser_H

//------------------------------------------------------------- Used interfaces
#include "time.h"
#include "User.h"
#include <cassert>
//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <TestUser>
// Testing function for the User class :
// - Test Creation & getters
// - Testing Operator ==
//-----------------------------------------------------------------------------

//---------------------------------------------------------------------- PUBLIC

//------------------------------------------------------------ Public functions

void TestUserCreation();

void testOperatorEquality();

void testCopyConstructor();

void testIncrementPoints();

void testAddSensor();

#endif // TestUser_H