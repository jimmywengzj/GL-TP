/******************************************************************************
                             User  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//--------------- Realisation of <User> class (User.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>

//----------------------------------------------------------- Personal includes
#include "User.h"

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods

void User::incrementPoints(const int numberToAdd)
{
    points += numberToAdd;
} //----- End of incrementPoints

void User::addSensor(const Sensor& sensor)
{
    sensors.push_back((*new Sensor(sensor)));
} //----- End of addSensor

void User::setBad()
{
    good = false;
} //----- End of setBad

string User::getId() const
{
    return id;
} //----- End of getId()

int User::getPoints() const
{
    return points;
} //----- End of getPoints()

bool User::isGood() const
{
    return good;
} //----- End of isGood()

vector<Sensor> User::getSensors() const
{
    return sensors;
} // ----- End of getSensors

//--------------------------------------------------- Constructors - destructor

User::User (const string id, const int initialPoints){
    this->id=id;
    points=initialPoints;
    good=true;
} //----- End of User (constructor)

User::User ( const User & unUser )
{
#ifdef MAP
    cout << "Calling copy constructor of <User>" << endl;
#endif
    id = unUser.id;
    points = unUser.points;
    good = unUser.good;
    sensors = *(new vector<Sensor>(unUser.sensors));
} //----- End of User (copy constructor)

User::~User ( )
{
#ifdef MAP
    cout << "Calling destructor of <User>" << endl;
#endif
} //----- End of ~User

bool User::operator==(const User & unUser) const
{
#ifdef MAP
    cout << "Calling operator == of <User>" << endl;
#endif
    return (
            id==unUser.id &&
            points==unUser.points &&
            good==unUser.good
            );
}

//--------------------------------------------------------------------- PRIVATE

//------------------------------------------------------------- Private methods
