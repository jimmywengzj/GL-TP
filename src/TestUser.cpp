/******************************************************************************
                             TestMeasurement  -  Tests for Measurement class
                               -------------------
    start                : 30/05/2023
    copyright            : (C) 2023 by *
    email                : *
******************************************************************************/

//--------------- Realisation of <TestMeasurement> (TestMeasurement.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>

//----------------------------------------------------------- Personal includes
#include "TestUser.h"

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//------------------------------------------------------------ Public functions

void TestUserCreation(){
    cout << "Testing Creation" << endl;
    string id = "1";
    int points = 0;
    User* user = new User(id, points);
    assert(user != nullptr);
    cout << "Passed 1/5 : pointer is not null" << endl;
    assert(user->getId() == id);
    cout << "Passed 2/5 : id is right" << endl;
    assert(user->getPoints() == points);
    cout << "Passed 3/5 : points are right" << endl;
    assert(user->isGood());
    cout << "Passed 4/5 : User is good by default" << endl;
    assert(user->getSensors().empty());
    cout << "Passed 5/5 : list of sensors is empty by default" << endl;
}

void testOperatorEquality(){
    cout << "Testing Operator ==" << endl;
    string id = "1";
    int points = 0;
    User* user = new User(id, points);
    User* user2 = new User(id, points);
    assert(*user == *user2);
    cout << "Passed 1/1 : Users are equal" << endl;
}

void testCopyConstructor(){
    cout << "Testing Copy Constructor" << endl;
    string id = "1";
    int points = 0;
    User* user = new User(id, points);
    User* user2 = new User(*user);
    assert(*user == *user2);
    cout << "Passed 1/2 : Users are equal" << endl;
    assert(user != user2);
    cout << "Passed 2/2 : Users are not the same" << endl;
}

void testIncrementPoints(){
    cout << "Testing Increment Points" << endl;
    string id = "1";
    int points = 0;
    User* user = new User(id, points);
    int pointsToAdd = 5;
    user->incrementPoints(pointsToAdd);
    assert(user->getPoints() == points + pointsToAdd);
    cout << "Passed 1/1 : points are right" << endl;
}

void testAddSensor(){
    cout << "Testing Add Sensor" << endl;
    string id = "1";
    int points = 0;
    User* user = new User(id, points);
    Sensor* sensor = new Sensor("1", 0, 0);
    user->addSensor(*sensor);
    assert(user->getSensors().size() == 1);
    cout << "Passed 1/2 : sensor is added" << endl;
    assert(user->getSensors().front() == *sensor);
    cout << "Passed 2/2 : sensor is right" << endl;
}

void testSetBad(){
    cout << "Testing Set Bad" << endl;
    string id = "1";
    int points = 0;
    User* user = new User(id, points);
    user->setBad();
    assert(!user->isGood());
    cout << "Passed 1/1 : user is bad" << endl;
}

int main(){
    cout << "Beginning of User Class' test" << endl;
    TestUserCreation();
    testOperatorEquality();
    testCopyConstructor();
    testIncrementPoints();
    testAddSensor();
    testSetBad();
    cout << "End of User Class' test" << endl;
    return 0;
}