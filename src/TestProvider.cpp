/******************************************************************************
                             TestProvider  -  Tests for Provider class
                               -------------------
    start                : 30/05/2023
    copyright            : (C) 2023 by *
    email                : *
******************************************************************************/

//--------------- Realisation of <TestProvider> (TestProvider.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>

//----------------------------------------------------------- Personal includes
#include "TestProvider.h"

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//------------------------------------------------------------ Public functions

void testProviderCreation(){
    cout << "Testing Creation" << endl;
    string id = "1";
    Provider* provider = new Provider(id);
    assert(provider != nullptr);
    cout << "Passed 1/3 : pointer is not null" << endl;
    assert(provider->getId() == id);
    cout << "Passed 2/3 : id is right" << endl;
    map<string,Cleaner> cleaners = provider->getCleanerList();
    assert(cleaners.size() == 0);
    cout << "Passed 3/3 : cleaner map is empty" << endl;
}

void testOperatorEquality(){
    cout << "Testing Operator ==" << endl;
    string id = "1";
    Provider* provider = new Provider(id);
    Provider* provider2 = new Provider(id);
    assert(*provider == *provider2);
    cout << "Passed 1/2 : similar Providers are equal" << endl;
    string id2 = "2";
    Provider* provider3 = new Provider(id2);
    assert(!(*provider == *provider3));
    cout << "Passed 2/2 : different Providers are not equal" << endl;
}

void testCopyConstructor(){
    cout << "Testing Copy Constructor" << endl;
    string id = "1";
    Provider* provider = new Provider(id);
    Provider* provider2 = new Provider(*provider);
    assert(*provider == *provider2);
    cout << "Passed 1/2 : Copy is equal to original" << endl;
    assert(provider != provider2);
    cout << "Passed 2/2 : Copy is not the same object" << endl;
}

void testAddCleaner(){
    cout << "Testing Add Cleaner" << endl;
    string id = "1";
    Provider* provider = new Provider(id);
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
    string idCleaner = "1";
    float latitude = 0.05;
    float longitude = 0.04;
    Cleaner* cleaner = new Cleaner(idCleaner, longitude, latitude, *dateStart, *dateEnd);
    provider->addCleaner(*cleaner);
    map<string,Cleaner> cleaners = provider->getCleanerList();
    assert(cleaners.size() == 1);
    cout << "Passed 1/2 : cleaner map has one element" << endl;
    assert(cleaners.at(idCleaner) == *cleaner);
    cout << "Passed 2/2 : cleaner map has the right element" << endl;
}

int main(){
    cout << "Beginning of Provider Class' test" << endl;
    testProviderCreation();
    testOperatorEquality();
    testCopyConstructor();
    testAddCleaner();
    cout << "End of Provider Class' test" << endl;
    return 0;
}
