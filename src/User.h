/******************************************************************************
                             User  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------------------ <User> class interface (User.h file) -----------------------
#if ! defined ( User_H )
#define User_H

//------------------------------------------------------------- Used interfaces
#include <string>
#include <list>
#include "Sensor.h"
//------------------------------------------------------------------- Constants

//----------------------------------------------------------------------- Types

//-----------------------------------------------------------------------------
// Role of <User> class
//
//
//-----------------------------------------------------------------------------

class User
{
//---------------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------------------------- Public methods
    // type Method ( parameter list );
    // Instruction:
    //
    // Precondition:
    //

    void incrementPoints(const int numberToAdd);
    // Precondition:
    // numberToAdd is positive

    void addSensor(const Sensor sensor);

    void setBad();

    string getId() const;

    int getPoints() const;

    bool isGood() const;

    list<Sensor> getSensors() const;

//--------------------------------------------------- Constructors - destructor
    User ( const User & unUser );
    // Instruction (copy constructor):
    //
    // Precondition:
    //

    User (const string id, const int initialPoints);
    // Instruction:
    //
    // Precondition:
    //

    virtual ~User ( );
    // Instruction:
    //
    // Precondition:
    //

//----------------------------------------------------------------------- PRIVE

protected:
//------------------------------------------------------------- Private methods

//-------------------------------------------------------- Protected attributes
    string id;
    int points;
    bool good;
    list<Sensor> sensors;
};

//---------------------------------------- Other definitions dependent on <User>

#endif // User_H