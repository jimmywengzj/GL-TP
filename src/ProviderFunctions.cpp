/******************************************************************************
                             Xxx  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//--------------- Realisation of <Xxx> class (Xxx.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>
#include <string>
#include <list>
#include <fstream>
//----------------------------------------------------------- Personal includes
#include "ProviderFunctions.h"
#include "SensorFunctions.h"

#include "Provider.h"
#include "Cleaner.h"
#include <map>

list<Provider> providerList;
//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
// type ProviderFunctions::Method ( parameter list )
// Algorithm:
//
//{
//} //----- End of Method
void ProviderFunctions::loadFromDatabase(){
    map<string,Cleaner> cleanerList;
    std::ifstream ifs ("../data/cleaners.csv", std::ifstream::in);
	int i=0;
	while(!ifs.eof()){
		string cleaner;
		getline(ifs,cleaner,';');
        Cleaner* cleanerObject;
		if(cleaner!=""){
		struct tm timeStart;
		struct tm timeEnd;
			string latitudeString;
			getline(ifs,latitudeString,';');
			float latitude = stof(latitudeString);
			string longitudeString;
			getline(ifs,longitudeString,';');
			float longitude = stof(longitudeString);						
			string startDateString;
			getline(ifs,startDateString,';');
			string endDateString;
			timeStart.tm_year=stoi(startDateString.substr (0,4))-1900;
			timeStart.tm_mon=stoi(startDateString.substr (5,2));
			timeStart.tm_mday=stoi(startDateString.substr (8,2));
			timeStart.tm_hour=stoi(startDateString.substr (11,2));
			timeStart.tm_min=stoi(startDateString.substr (14,2));
			timeStart.tm_sec=stoi(startDateString.substr (17,2));
            timeEnd.tm_year=stoi(endDateString.substr (0,4))-1900;
			timeEnd.tm_mon=stoi(endDateString.substr (5,2));
			timeEnd.tm_mday=stoi(endDateString.substr (8,2));
			timeEnd.tm_hour=stoi(endDateString.substr (11,2));
			timeEnd.tm_min=stoi(endDateString.substr (14,2));
			timeEnd.tm_sec=stoi(endDateString.substr (17,2));
			getline(ifs,endDateString,';');
			string forget;
			getline(ifs,forget,'\n');
            cleanerObject= new Cleaner(cleaner,longitude,latitude, timeStart,timeEnd);
            cleanerList[cleanerObject->getId()] =*cleanerObject;
		}
	}
    std::ifstream ifs ("../data/cproviders.csv", std::ifstream::in);
		string providerString;
        string currentProvider="";
        Provider* providerObject;
	    while(!ifs.eof()){
		getline(ifs,providerString,';');
		if(providerString!=""){
			string cleanerId;
			getline(ifs,cleanerId,';');
			string forget;
			getline(ifs,forget,'\n');
            if(providerString!=currentProvider){
                providerObject= new Provider(providerString);
			    providerList.push_back(*providerObject);
            }
            providerObject->addCleaner(cleanerList.find(cleanerId)->second);
            }
        }
} //----- End of loadFromDatabase()

list<float> ProviderFunctions::studyAirCleaner(string idCleaner){
	//This isn't finished but I'm not going to be able to finish it
	list<float> returnValue;
    Cleaner* cleanerFound=NULL;
    Cleaner* cleanerStep=NULL;
    list<Provider> CheckProviderList=providerList;
    while(CheckProviderList.size()!=0 && cleanerFound==NULL){
        *cleanerStep=providerList.front().getCleanerList().find(idCleaner)->second;
        if(cleanerStep!=NULL){
            cleanerFound=cleanerStep;
        }
        CheckProviderList.pop_front();
    }
	struct tm start =cleanerFound->getStart();
	if(start.tm_mon==1){
		start.tm_mon=12;
		start.tm_year=start.tm_year-1;
	}
	else{
		start.tm_mon=start.tm_mon-1;
	}
	struct tm end =cleanerFound->getEnd();
	//I think this will become a problem
	SensorFunctions sensorFunctions;
	float start=sensorFunctions.meanAirQualityArea(10.0,cleanerFound->getLongitude(),cleanerFound->getLatitude(),start,cleanerFound->getStart());
}

//-------------------------------------------------------- Operator overloading
ProviderFunctions & ProviderFunctions::operator = ( const ProviderFunctions & unProviderFunctions)
{

} //----- End of operator =

//--------------------------------------------------- Constructors - destructor
ProviderFunctions::ProviderFunctions ( const ProviderFunctions & unProviderFunctions )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling copy constructor of <ProviderFunctions>" << endl;
#endif
} //----- End of ProviderFunctions (copy constructor)

ProviderFunctions::ProviderFunctions ( )
{
#ifdef MAP
    cout << "Calling constructor of <ProviderFunctions>" << endl;
#endif
} //----- End of ProviderFunctions

ProviderFunctions::~ProviderFunctions ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling destructor of <ProviderFunctions>" << endl;
#endif
} //----- End of ~ProviderFunctions

//--------------------------------------------------------------------- PRIVATE

//-------------------------------------------------------------- Private methods
