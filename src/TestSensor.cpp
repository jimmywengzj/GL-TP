/******************************************************************************
                             testSensor  -  Tests for Measurement class
                               -------------------
    start                : 30/05/2023
    copyright            : (C) 2023 by *
    email                : *
******************************************************************************/

//--------------- Realisation of <testSensor> (testSensor.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>

//----------------------------------------------------------- Personal includes
#include "TestSensor.h"

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//------------------------------------------------------------ Public functions

void testSensorCreation(){
    string id = "1";
    float lat = 49.05;
    float lon = -85.23;
    Sensor* sensor = new Sensor(id, lat, lon);
    assert(sensor != nullptr);
    cout << "Passed 1/6 : pointer is not null" << endl;
    assert(sensor->getId() == id);
    cout << "Passed 2/6 : id is right" << endl;
    assert(sensor->getLatitude() == lat);
    cout << "Passed 3/6 : latitude is right" << endl;
    assert(sensor->getLongitude() == lon);
    cout << "Passed 4/6 : longitude is right" << endl;
    assert(sensor->getGood() == true);
    cout << "Passed 5/6 : good is right" << endl;
    assert(sensor->getMeasurements().empty());
    cout << "Passed 6/6 : Measurement list is initialized correctly" << endl;
}


int main(){
    cout << "Beginning of Sensor Class' test" << endl;
    testSensorCreation();
    cout << "End of Sensor Class' test" << endl;
    return 0;
}