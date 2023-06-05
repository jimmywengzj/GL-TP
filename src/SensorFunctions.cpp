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
#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include <limits>
#include <utility>
#include <algorithm>
#include <vector>
//----------------------------------------------------------- Personal includes
#include "SensorFunctions.h"
#include "Sensor.h"
#include "Measurement.h"
vector<Sensor> sensorList;

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
void SensorFunctions::loadFromDatabase()
{
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
    ifs.open ("../data/measurements.csv", std::ifstream::in);
	int i=0;
	while(!ifs.eof()){
		i++;
		string forget;
		string measureTimeString;
		struct tm time;
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
			Sensor* sensor=findSensor(sensorString);	
            sensor->addMeasurement((*measurement));	
		}
	}
}

Sensor* SensorFunctions::findSensor(string id)
{
	sensorList[0];
	int p=0;
	for(int i=0;i<sensorList.size();i++){
        if((sensorList[i].getId())==id){
            p=i;
        }		
    }
    //J'ai tenté avec un iterator mais j'avais des problémes pour stocker les sensor.
    //ce code peut être optimisé mais j'ai préféré créer une base qui marche. EN plus que c'est un code rarement appelé.
    return &sensorList[p];
}

void SensorFunctions::markSensor(string id)
{
	findSensor(id)->setBad();
}

float SensorFunctions::instantAirQuality(float area, float longitude, float latitude, struct tm date){
	float avg = 0;
	float total = 0;
	float r = 0.0174533; //Pi/180=3.14159/180
	float lat = latitude * r;
	float lon = longitude * r;
	float er = 6371.01; //Kilometers
	float distance1=100000000000000000.0;
	float distance2=distance1;
	float distance3=distance1;
	float distance4=distance1;
	float avg1=0;
	float avg2=0;
	float avg3=0;
	float avg4=0;
	for (Sensor sensor : sensorList){
		float la2 = sensor.getLatitude() * r;
		float lo2 = sensor.getLongitude() * r;
		float distance = er * acos((sin(lat)*sin(la2)) + (cos(lat)*cos(la2)*cos(lon - lo2)));
		
		float stock=-1.0;
		for (Measurement measurement : sensor.getMeasurements()){
			struct tm time= measurement.getTimestamp();
			if (abs(difftime(mktime(&time), mktime(&date))) < 86400){
				stock=measurement.getAQI();
			}
		}
		if(stock==-1.0){
			continue;
		}

		if (distance <= area){
			avg += stock;
			total++;
		}
		cout<<stock;
		if(distance<distance4){
			if(distance<distance3){
				if(distance<distance2){
					if(distance<distance1){
						avg4=avg3;
						avg3=avg2;
						avg2=avg1;
						avg1=stock;
						distance4=distance3;
						distance3=distance2;
						distance2=distance1;
						distance1=distance;
					}
					else{
						avg4=avg3;
						avg3=avg2;
						avg2=stock;
						distance4=distance3;
						distance3=distance2;
						distance2=distance;
					}
				}
				else{
					avg4=avg3;
					avg3=stock;
					distance4=distance3;
					distance3=distance;
				}
			}
			else{
				distance4=distance;
				avg4=stock;
			}
		}
		 
	}
	if (total < 4) {
		total = 4;
		avg=avg1+avg2+avg3+avg4;
	}
	return avg/total;
}
float SensorFunctions::analyseOneSensor(Sensor sensor)
{
	vector <Measurement> measurementVector = sensor.getMeasurements();
	float sum;
	int numDate = 0;
	for(Measurement measurement : measurementVector){
		float avg = instantAirQuality(sensor.getLongitude(),sensor.getLatitude(),80,measurement.getTimestamp());
		float AQI = measurement.getAQI();
		sum = sum + abs(avg- AQI)/avg;
		numDate++;
	}
	return sum/numDate;
} //----- analyseOneSensor

vector<Sensor> SensorFunctions::compareOneSensor(string id, struct tm begin, struct tm end)
{
	Sensor* s = findSensor(id);

	vector<pair<Sensor, float>> order;
	
	for (Sensor sensor : sensors) {
		if (sensor.getId() == s->getId()) continue;
		float difference = 0;
		for (Measurement measurement : sensor.getMeasurements()) {
			struct tm tm1 = measurement.getTimestamp();
			time_t t = mktime(&tm1);
			if (difftime(t, mktime(&begin)) >= 0 && difftime(t, mktime(&end)) <= 0){
				for (Measurement m : s->getMeasurements()) {
					struct tm tm2 = m.getTimestamp();
					if (difftime(t, mktime(&tm2)) == 0) {
						difference += abs(measurement.getAQI() - m.getAQI());
						break;
					}
				}
			}
		}
		order.push_back(make_pair(sensor, difference));
	}
	sort(order.begin(), order.end(), [](auto &left, auto &right) {
		return left.second < right.second;
	});

	vector<Sensor> sorted;
	for (const auto &[sensor, difference] : order) {
		sorted.push_back(sensor);
	}

	return sorted;
} //----- compareOneSensor

float SensorFunctions::meanAirQualityArea(float area, float latitude, float longitude, struct tm start, struct tm end){
	 
    float avg = 0;
	float total = 0;

	for (time_t time = mktime(&start); time < mktime(&end); time += 86400) {
		total++;
		avg += instantAirQuality(area, longitude, latitude, *localtime(&time));

	}

	return avg/total;
}

//--------------------------------------------------- Constructors - destructor
SensorFunctions::SensorFunctions ( const SensorFunctions & unSensorFunctions )
{
#ifdef MAP
    cout << "Calling copy constructor of <SensorFunctions>" << endl;
#endif
} //----- End of SensorFunctions (copy constructor)

SensorFunctions::SensorFunctions ( )
{
#ifdef MAP
    cout << "Calling constructor of <SensorFunctions>" << endl;
#endif
} //----- End of SensorFunctions

SensorFunctions::~SensorFunctions ( )
{
#ifdef MAP
    cout << "Calling destructor of <SensorFunctions>" << endl;
#endif
} //----- End of ~SensorFunctions
