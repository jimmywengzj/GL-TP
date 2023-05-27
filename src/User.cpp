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
// type User::Method ( parameter list )
// Algorithm:
//
//{
//} //----- End of Method

void User::incrementPoints(const int numberToAdd)
{
    points += numberToAdd;
} //----- End of incrementPoints

void User::addSensor(const Sensor sensor)
{
    sensors.push_back(sensor);
} //----- End of addSensor

void User::setBad()
{
    points += false;
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

list<Sensor> User::getSensors() const
{
    return sensors;
} // ----- End of getSensors

//--------------------------------------------------- Constructors - destructor
User::User ( const User & unUser )
// Only used for debugging purposes
{
#ifdef MAP
    cout << "Calling copy constructor of <User>" << endl;
#endif
} //----- End of User (copy constructor)

User::~User ( )
{
#ifdef MAP
    cout << "Calling destructor of <User>" << endl;
#endif
} //----- End of ~User
User::User (const string id, const int initialPoints){
    this->id=id;
    points=initialPoints;
}
//--------------------------------------------------------------------- PRIVATE

//------------------------------------------------------------- Private methods
