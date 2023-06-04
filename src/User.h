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
#include <vector>
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

    void incrementPoints(const int numberToAdd);
    // Precondition:
    // numberToAdd is positive

    void addSensor(const Sensor& sensor);

    void setBad();

    string getId() const;

    int getPoints() const;

    bool isGood() const;

    vector<Sensor> getSensors() const;

//--------------------------------------------------- Constructors - destructor
    User ( const User & unUser );

    User (const string id, const int initialPoints);

    virtual ~User ( );

    bool operator==(const User & unUser) const;

//--------------------------------------------------------------------- PRIVATE

protected:
//------------------------------------------------------------- Private methods

//-------------------------------------------------------- Protected attributes
    string id;
    int points;
    bool good;
    vector<Sensor> sensors;
};

#endif // User_H