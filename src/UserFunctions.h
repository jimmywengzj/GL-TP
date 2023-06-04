/******************************************************************************
                          UserFunctions  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//-------- <UserFunctions> class interface (UserFunctions.h file) -------------
#if ! defined ( UserFunctions_H )
#define UserFunctions_H

//------------------------------------------------------------- Used interfaces
using namespace std;
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include "User.h"
#include "SensorFunctions.h"
//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <UserFunctions> class
//
//
//-----------------------------------------------------------------------------

class UserFunctions
{
//---------------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------------- Public methods
    // type Method ( parameter list );
    // Instruction:
    //
    // Precondition:
    //
    void loadFromDatabase(SensorFunctions sensorFunctions);

    void markUser(User);

    int getPoints(User);

    vector<pair<User, float>> checkData(SensorFunctions);

//-------------------------------------------------------- Operator overloading
    UserFunctions & operator = ( const UserFunctions & unUserFunctions );
    // Instruction:
    //
    // Precondition:
    //

//--------------------------------------------------- Constructors - destructor
    UserFunctions ( const UserFunctions & unUserFunctions );
    // Instruction (copy constructor):
    //
    // Precondition:
    //

    UserFunctions ( );
    // Instruction:
    //
    // Precondition:
    //

    virtual ~UserFunctions ( );
    // Instruction:
    //
    // Precondition:
    //

//--------------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------------- Private methods

//-------------------------------------------------------- Protected attributes
unordered_map <string, User> users;
};

//------------------------------- Other definitions depending on <UserFunctions>

#endif // UserFunctions_H