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
    float valueNO2 = 0.05;
    float valueSO2 = 0.05;
    float valuePM10 = 0.05;
    Measurement* measurement = new Measurement(*date, sensorId, valueO3, valueNO2, valueSO2, valuePM10);
    assert(measurement != nullptr);
    cout << "Passed 1/7 : pointer is not null" << endl;
    struct tm measurementDate = measurement->getTimestamp();
    assert(difftime(mktime(&measurementDate),mktime(date)) == 0);
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

int main(){
    cout << "Beginning of Measurement Class' test" << endl;
    testMeasurementCreation();
    cout << "End of Measurement Class' test" << endl;
    return 0;
}
