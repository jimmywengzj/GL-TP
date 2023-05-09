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

void incrementPoints(int numberToAdd)
{
    points += numberToAdd
} //----- End of incrementPoints

void addSensor(Sensor sensor)
{
    sensors.add(sensor);
} //----- End of addSensor

void setBad(){
    points += false;
} //----- End of setBad

//-------------------------------------------------------- Operator overloading
User & User::operator = ( const User & unUser )
// Algorithm:
//
{
} //----- End of operator =

//--------------------------------------------------- Constructors - destructor
User::User ( const User & unUser )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling copy constructor of <User>" << endl;
#endif
} //----- End of User (copy constructor)

User::User ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling constructor of <User>" << endl;
#endif
} //----- End of User

User::~User ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling destructor of <User>" << endl;
#endif
} //----- End of ~User

//--------------------------------------------------------------------- PRIVATE

//------------------------------------------------------------- Private methods
