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
    cout << "Testing Sensor Creation" << endl;
    string id = "1";
    float lat = 49.0;
    float lon = -85.0;
    Sensor* sensor = new Sensor(id, lon, lat);
    assert(sensor != nullptr);
    cout << "Passed 1/6 : pointer is not null" << endl;
    assert(sensor->getId() == id);
    cout << "Passed 2/6 : id is right" << endl;
    assert(sensor->getLatitude() == lat);
    cout << "Passed 3/6 : latitude is right" << endl;
    assert(sensor->getLongitude() == lon);
    cout << "Passed 4/6 : longitude is right" << endl;
    assert(sensor->getGood());
    cout << "Passed 5/6 : good is right" << endl;
    assert(sensor->getMeasurements().empty());
    cout << "Passed 6/6 : Measurement list is initialized correctly" << endl;
}


void testOperatorEquality(){
    cout << "Testing Operator ==" << endl;
    string id = "1";
    float lat = 49.0;
    float lon = -85.0;
    Sensor* sensor1 = new Sensor(id, lon, lat);
    Sensor* sensor2 = new Sensor(id, lon, lat);
    assert(*sensor1 == *sensor2);
    cout << "Passed 1/1 : Sensors are equal" << endl;
}


void testCopyConstructor(){
    cout << "Testing Copy Constructor" << endl;
    string id = "1";
    float lat = 49.0;
    float lon = -85.0;
    Sensor* sensor1 = new Sensor(id, lon, lat);
    Sensor* sensor2 = new Sensor(*sensor1);
    assert(*sensor1 == *sensor2);
    cout << "Passed 1/2 : Sensors are equal" << endl;
    assert(sensor1 != sensor2);
    cout << "Passed 2/2 : Sensors are not the same object" << endl;
}


void testSensorFlag(){
    cout << "Testing Sensor flagging" << endl;
    string id = "1";
    float lat = 49.05;
    float lon = -85.23;
    Sensor* sensor = new Sensor(id, lon, lat);
    sensor->setBad();
    assert(!sensor->getGood());
    cout << "Passed 1/1 : Sensor has been flagged" << endl;
}


void testAddMeasurement(){
    cout << "Testing Measurement adding" << endl;
    Sensor* sensor = new Sensor("1", -85.0, 49.0);
    tm* date;
    date->tm_year = 2022;
    date->tm_mon = 5;
    date->tm_mday = 4;
    date->tm_hour = 12;
    Measurement* measurement = new Measurement(*date, "1", 0.05, 0.04, 0.03, 0.02);
    sensor->addMeasurement(*measurement);
    assert(sensor->getMeasurements().size() == 1);
    cout << "Passed 1/2 : a Measurement has been added" << endl;
    assert(sensor->getMeasurements().front() == *measurement);
    cout << "Passed 2/2 : the right Measurement has been added" << endl;
}


int main(){
    cout << "Beginning of Sensor Class' test" << endl;
    testSensorCreation();
    testOperatorEquality();
    testCopyConstructor();
    testSensorFlag();
    testAddMeasurement();
    cout << "End of Sensor Class' test" << endl;
    return 0;
}