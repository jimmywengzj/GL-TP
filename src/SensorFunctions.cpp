/******************************************************************************
                             SensorFunctions  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//--------------- Realisation of <SensorFunctions> class (SensorFunctions.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <list>
#include <iostream>
#include <fstream>
#include <math.h>
#include <limits>
//----------------------------------------------------------- Personal includes
#include "SensorFunctions.h"
#include "Sensor.h"
#include "Measurement.h"
list<Sensor> sensorList;

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
// type SensorFunctions::Method ( parameter list )
// Algorithm:
//
//{
//} //----- End of Method
void SensorFunctions::loadFromDatabase(){
		  std::ifstream ifs;

  ifs.open ("../data/sensors.csv", std::ifstream::in);
    Sensor* sensorObject;
	while(!ifs.eof()){
		string sensor;
		getline(ifs,sensor,';');
		if(sensor!=""){
			string latitudeString;
			getline(ifs,latitudeString,';');
			float latitude = stof(latitudeString);
			string longitudeString;
			getline(ifs,longitudeString,';');
			float longitude = stof(longitudeString);
			string forget;
			getline(ifs,forget,'\n');
            sensorObject= new Sensor(sensor,latitude,longitude);
            sensorList.push_back(*sensorObject);
		}
	}
	cout<<sensorList.front().getId()<<endl;
	ifs.close();
	/*list<Sensor> CheckSensorList=sensorList;
    while(CheckSensorList.size()!=0){
        cout<<"Get Id: "<<CheckSensorList.front().getId()<<"Lat :"<<CheckSensorList.front().getLatitude()<<"Long :"<<CheckSensorList.front().getLongitude()<<endl;
        CheckSensorList.pop_front();
    }*/
  ifs.open ("../data/measurements.csv", std::ifstream::in);
	int i=0;
	while(!ifs.eof()){
		i++;
		string forget;
		string measureTimeString;
		struct tm time;
        Sensor * sensor;
		getline(ifs,measureTimeString,';');
		if(measureTimeString!=""){
			time.tm_year=stoi(measureTimeString.substr (0,4))-1900;
			time.tm_mon=stoi(measureTimeString.substr (5,2));
			time.tm_mday=stoi(measureTimeString.substr (8,2));
			time.tm_hour=stoi(measureTimeString.substr (11,2));
			time.tm_min=stoi(measureTimeString.substr (14,2));
			time.tm_sec=stoi(measureTimeString.substr (17,2));
			string sensorString;
			getline(ifs,sensorString,';');
			getline(ifs,forget,';');
			string O3String;
			getline(ifs,O3String,';');
			float O3 = stof(O3String);
			getline(ifs,forget,';');
			getline(ifs,forget,';');
			getline(ifs,forget,';');
			
			string NO2String;
			getline(ifs,NO2String,';');			
			float NO2 = stof(NO2String);
			getline(ifs,forget,';');
			getline(ifs,forget,';');
			getline(ifs,forget,';');
			
			string SO2String;
			getline(ifs,SO2String,';');			
			float SO2 = stof(SO2String);
			getline(ifs,forget,';');
			getline(ifs,forget,';');
			getline(ifs,forget,';');
						
			string PM10String;
			getline(ifs,PM10String,';');
			float PM10 = stof(PM10String);
			getline(ifs,forget,'\n');
            Measurement* measurement = new Measurement(time, sensorString, O3,  NO2,  SO2,  PM10);
			sensor=findSensor(sensorString);	
            sensor->addMeasurement((*measurement));			
		}
	}

}
Sensor* SensorFunctions::findSensor(string SensorId){
    Sensor* sensorFound=NULL;
    list<Sensor> CheckSensorList=sensorList;
    while(CheckSensorList.size()!=0 && sensorFound==NULL){

        if((CheckSensorList.front().getId())==SensorId){
            sensorFound=&(CheckSensorList.front());
        }		

        CheckSensorList.pop_front();
    }
    //J'ai tenté avec un iterator mais j'avais des problémes pour stocker les sensor.
    //ce code peut être optimisé mais j'ai préféré créer une base qui marche. EN plus que c'est un code rarement appelé.
    return sensorFound;
}

void SensorFunctions::markSensor(Sensor s){
	s.setBad();
}

float SensorFunctions::instantAirQuality(float area, float longitude, float latitude, struct tm date){

	std::list<Sensor>::iterator it;
	float avg = 0;
	float total = 0;
	float r = 0.0174533; //Pi/180=3.14159/180
	float lat = latitude * r;
	float lon = longitude * r;
	float er = 6371.01; //Kilometers
	float d1=100000000000000000.0;
	float d2=d1;
	float d3=d1;
	float d4=d1;
	float avg1=0;
	float avg2=0;
	float avg3=0;
	float avg4=0;
	float stock;
	for (it = sensorList.begin(); it != sensorList.end(); ++it){
		float la2 = it->getLatitude() * r;
		float lo2 = it->getLongitude() * r;
		float d = er * acos((sin(latitude)*sin(la2)) + (cos(latitude)*cos(la2)*cos(longitude - lo2)));
		if (d < area){
			std::list<Measurement>::iterator measurementIt;
			for (measurementIt = it->getMeasurements().begin(); measurementIt != it->getMeasurements().end(); ++measurementIt){
				struct tm time=measurementIt->getTimestamp();
				if (difftime(mktime(&time), mktime(&date)) <= 86400 || difftime(mktime(&time), mktime(&date)) >= 86400){
					avg += measurementIt->getAQI();
					total++;
				}
			}
		}
		stock=-1.0;
			std::list<Measurement>::iterator measurementIt;
				for (measurementIt = it->getMeasurements().begin(); measurementIt != it->getMeasurements().end(); ++measurementIt){
				struct tm time=measurementIt->getTimestamp();
					if (difftime(mktime(&time), mktime(&date)) <= 86400 || difftime(mktime(&time), mktime(&date)) >= 86400){
						stock=measurementIt->getAQI();
					}
				}
		if(stock>=0){
		if(d<d4){
			if(d<d3){
				if(d<d2){
					if(d<d1){
						avg4=avg3;
						avg3=avg2;
						avg2=avg1;
						avg1=stock;
						d4=d3;
						d3=d2;
						d2=d1;
						d1=d;
					}
					else{
						avg4=avg3;
						avg3=avg2;
						avg2=stock;
						d4=d3;
						d3=d2;
						d2=d;
					}
				}
				else{
					avg4=avg3;
					avg3=stock;


					d4=d3;
					d3=d;
				}
			}
			else{

				d4=d;
				avg4=stock;
			}
		}
		} 
	}
	if (total < 4) {
		total = 4;
		avg=avg1+avg2+avg3+avg4;
	}

	return avg/total;
}
float SensorFunctions::analyseOneSensor(Sensor s)
// Algorithm:
//
{
	list <Measurement> m = s.getMeasurements();
	float sum;
	int numDate = 0;
	for(list<Measurement>::iterator it = m.begin(); it != m.end(); it++){
		float avg = instantAirQuality(s.getLongitude(),s.getLatitude(),80,it->getTimestamp());
		float AQI = it->getAQI();
		sum = sum + abs(avg- AQI)/avg;
		numDate++;
	}
	return sum/numDate;
} //----- analyseOneSensor

list<Sensor> SensorFunctions::compareOneSensor(Sensor s, struct tm begin, struct tm end)
// Algorithm:
//
{
	list<Sensor> sorted;
	for (Sensor sensor : sensors) {
		if (sensor.getId() == s.getId()) continue;
		sorted.push_back(sensor);
	}
	return sorted;
	//////////////////////////////////not finished yet, needs pair<sensor, difference>
} //----- compareOneSensor

float SensorFunctions::meanAirQualityArea(float area, float latitude, float longtitude, struct tm start, struct tm end){
	 
    std::list<Sensor>::iterator it;
	float avg = 0;
	float total = 0;
	for (it = sensorList.begin(); it != sensorList.end(); ++it){
		float r = 0.0174533; //Pi/180=3.14159/180
		float latitude = latitude * r;
		float la2 = it->getLatitude() * r;
		float longtitude = longtitude * r;
		float lo2 = it->getLongitude() * r;
		float er = 6371.01; //Kilometers
		float d = er * acos((sin(latitude)*sin(la2)) + (cos(latitude)*cos(la2)*cos(longtitude - lo2)));
		if (d < area){
			std::list<Measurement>::iterator measurementIt;
			for (measurementIt = it->getMeasurements().begin(); measurementIt != it->getMeasurements().end(); ++measurementIt){
				struct tm time =measurementIt->getTimestamp();
				if (difftime(mktime(&time), mktime(&start)) >= 0 && difftime(mktime(&time), mktime(&end)) <= 0){
					avg += measurementIt->getAQI();
					total++;
				}
			}
		} 
	}
	if (total == 0) return -1;
	return avg/total;
}
//-------------------------------------------------------- Operator overloading
/*SensorFunctions & SensorFunctions::operator = ( const SensorFunctions & unSensorFunctions )
// Algorithm:
//
{
} //----- End of operator =
*/
//--------------------------------------------------- Constructors - destructor
SensorFunctions::SensorFunctions ( const SensorFunctions & unSensorFunctions )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling copy constructor of <SensorFunctions>" << endl;
#endif
} //----- End of SensorFunctions (copy constructor)

SensorFunctions::SensorFunctions ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling constructor of <SensorFunctions>" << endl;
#endif
} //----- End of SensorFunctions

SensorFunctions::~SensorFunctions ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling destructor of <SensorFunctions>" << endl;
#endif
} //----- End of ~SensorFunctions

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------- Private methods
