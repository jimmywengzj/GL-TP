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
#include "TestMeasurement.h"

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//------------------------------------------------------------ Public functions

void testMeasurementCreation(){
    cout << "Testing Creation" << endl;
    struct tm * date;
    date->tm_year = 2022;
    date->tm_mon = 4;
    date->tm_mday = 4;
    date->tm_hour = 12;
    string sensorId = "1";
    float valueO3 = 0.05;
    float valueNO2 = 0.04;
    float valueSO2 = 0.03;
    float valuePM10 = 0.02;
    Measurement* measurement = new Measurement(*date, sensorId, valueO3, valueNO2, valueSO2, valuePM10);
    assert(measurement != nullptr);
    cout << "Passed 1/7 : pointer is not null" << endl;
    struct tm measurementDate = measurement->getTimestamp();
    assert(measurementDate.tm_mon == date->tm_mon);
    assert(measurementDate.tm_year == date->tm_year);
    assert(measurementDate.tm_mday == date->tm_mday);
    assert(measurementDate.tm_hour == date->tm_hour);
    cout << "Passed 2/7 : timestamp is right" << endl;
    assert(measurement->getSensorId() == sensorId);
    cout << "Passed 3/7 : id is right" << endl;
    assert(measurement->getValueO3() == valueO3);
    cout << "Passed 4/7 : valueO3 is right" << endl;
    assert(measurement->getValueNO2() == valueNO2);
    cout << "Passed 5/7 : valuesNO2 is right" << endl;
    assert(measurement->getValueSO2() == valueSO2);
    cout << "Passed 6/7 : valuesSO2 is right" << endl;
    assert(measurement->getValuePM10() == valuePM10);
    cout << "Passed 7/7 : valuesPM10 is right" << endl;
}

void testOperatorEquality(){
    cout << "Testing Operator ==" << endl;
    struct tm * date;
    date->tm_year = 2022;
    date->tm_mon = 4;
    date->tm_mday = 4;
    date->tm_hour = 12;
    Measurement* m1 = new Measurement(*date, "1", 0.05, 0.04, 0.03, 0.02);
    Measurement* m2 = new Measurement(*date, "1", 0.05, 0.04, 0.03, 0.02);
    date->tm_year = 2021;
    Measurement* m3 = new Measurement(*date, "1", 0.05, 0.04, 0.03, 0.02);
    assert(*m1==*m2);
    cout << "Passed 1/2 : two similar measurements are equal" << endl;
    assert(!(*m1==*m3));
    cout << "Passed 2/2 : two different measurements are different" << endl;
}

void testCopyConstructor(){
    cout << "Testing Copy Constructor" << endl;
    struct tm * date;
    date->tm_year = 2022;
    date->tm_mon = 4;
    date->tm_mday = 4;
    date->tm_hour = 12;
    Measurement* m1 = new Measurement(*date, "1", 0.05, 0.04, 0.03, 0.02);
    Measurement* m2 = new Measurement(*m1);
    assert(*m1==*m2);
    cout << "Passed 1/1 : copy construction produces similar object" << endl;
    assert(m1!=m2);
}

int main(){
    cout << "Beginning of Measurement Class' test" << endl;
    testMeasurementCreation();
    testOperatorEquality();
    testCopyConstructor();
    cout << "End of Measurement Class' test" << endl;
    return 0;
}
