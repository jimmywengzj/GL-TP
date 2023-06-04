/******************************************************************************
                             TestCleaner  -  Tests for Cleaner class
                               -------------------
    start                : 30/05/2023
    copyright            : (C) 2023 by *
    email                : *
******************************************************************************/

//--------------- Realisation of <TestCleaner> (TestCleaner.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>

//----------------------------------------------------------- Personal includes
#include "TestCleaner.h"

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//------------------------------------------------------------ Public functions

void testCleanerCreation(){
    cout << "Testing Creation" << endl;
    tm * dateStart;
    dateStart->tm_year = 2022;
    dateStart->tm_mon = 4;
    dateStart->tm_mday = 4;
    dateStart->tm_hour = 12;
    struct tm * dateEnd;
    dateEnd->tm_year = 2022;
    dateEnd->tm_mon = 4;
    dateEnd->tm_mday = 4;
    dateEnd->tm_hour = 14;
    string id = "1";
    float latitude = 0.05;
    float longitude = 0.04;
    Cleaner* cleaner = new Cleaner(id, longitude, latitude, *dateStart, *dateEnd);
    assert(cleaner != nullptr);
    cout << "Passed 1/6 : pointer is not null" << endl;
    assert(cleaner->getId() == id);
    cout << "Passed 2/6 : id is right" << endl;
    assert(cleaner->getLatitude() == latitude);
    cout << "Passed 3/6 : latitude is right" << endl;
    assert(cleaner->getLongitude() == longitude);
    cout << "Passed 4/6 : longitude is right" << endl;
    tm cleanerDateStart = cleaner->getStart();
    assert(cleanerDateStart.tm_mon == dateStart->tm_mon);
    assert(cleanerDateStart.tm_year == dateStart->tm_year);
    assert(cleanerDateStart.tm_mday == dateStart->tm_mday);
    assert(cleanerDateStart.tm_hour == dateStart->tm_hour);
    cout << "Passed 5/6 : dateStart is right" << endl;
    tm cleanerDateEnd = cleaner->getEnd();
    assert(cleanerDateEnd.tm_mon == dateEnd->tm_mon);
    assert(cleanerDateEnd.tm_year == dateEnd->tm_year);
    assert(cleanerDateEnd.tm_mday == dateEnd->tm_mday);
    assert(cleanerDateEnd.tm_hour == 14);
    cout << "Passed 6/6 : dateEnd is right" << endl;
}

void testOperatorEquality(){
    cout << "Testing Operator ==" << endl;
    tm * dateStart;
    dateStart->tm_year = 2022;
    dateStart->tm_mon = 4;
    dateStart->tm_mday = 4;
    dateStart->tm_hour = 12;
    tm * dateEnd;
    dateEnd->tm_year = 2022;
    dateEnd->tm_mon = 4;
    dateEnd->tm_mday = 4;
    dateEnd->tm_hour = 14;
    string id = "1";
    float latitude = 0.05;
    float longitude = 0.04;
    Cleaner* cleaner = new Cleaner(id, longitude, latitude, *dateStart, *dateEnd);
    Cleaner* cleaner2 = new Cleaner(id, longitude, latitude, *dateStart, *dateEnd);
    assert(*cleaner == *cleaner2);
    cout << "Passed 1/2 : Similar Cleaners are equal" << endl;
    id = "2";
    Cleaner* cleaner3 = new Cleaner(id, longitude, latitude, *dateStart, *dateEnd);
    assert(!(*cleaner == *cleaner3));
    cout << "Passed 2/2 : Different Cleaners are not equal" << endl;
}

void testCopyConstructor(){
    cout << "Testing Copy Constructor" << endl;
    tm * dateStart;
    dateStart->tm_year = 2022;
    dateStart->tm_mon = 4;
    dateStart->tm_mday = 4;
    dateStart->tm_hour = 12;
    tm * dateEnd;
    dateEnd->tm_year = 2022;
    dateEnd->tm_mon = 4;
    dateEnd->tm_mday = 4;
    dateEnd->tm_hour = 14;
    string id = "1";
    float latitude = 0.05;
    float longitude = 0.04;
    Cleaner* cleaner = new Cleaner(id, longitude, latitude, *dateStart, *dateEnd);
    Cleaner* cleaner2 = new Cleaner(*cleaner);
    assert(*cleaner == *cleaner2);
    cout << "Passed 1/1 : Copy Constructor works" << endl;
}

int main(){
    cout << "Beginning of Cleaner Class' test" << endl;
    testCleanerCreation();
    testOperatorEquality();
    testCopyConstructor();
    cout << "End of Cleaner Class' test" << endl;
    return 0;
}
