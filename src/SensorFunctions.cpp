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
#include <cmath>
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
			time.tm_mon=stoi(measureTimeString.substr (5,2))-1;
			time.tm_mday=stoi(measureTimeString.substr (8,2));
			time.tm_hour=stoi(measureTimeString.substr (11,2));
			time.tm_min=stoi(measureTimeString.substr (14,2));
			time.tm_sec=stoi(measureTimeString.substr (17,2));
			time.tm_isdst = 0;
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
	for (Sensor &sensor : sensorList) {
		if (sensor.getId() == id) {
			return &sensor;
		}
	}
	return nullptr;
}

void SensorFunctions::markSensor(string id)
{
	findSensor(id)->setBad();
}

float SensorFunctions::instantAirQuality(float radius, float longitude, float latitude, struct tm date){
	float avg = 0;
	float total = 0;
	float radian = 0.0174533; //Pi/180=3.14159/180
	float latTarget = latitude * radian;
	float lonTarget = longitude * radian;
	float earthRadius = 6371.01; //Kilometers
    float bigFloat = std::numeric_limits<float>::max();
	float distances[4]={bigFloat,bigFloat,bigFloat,bigFloat};
	float averages[4]={0.0,0.0,0.0,0.0};

    // Finding the 4 closest Measurements' AQI
	for (Sensor sensor : sensorList){
		float latSensor = sensor.getLatitude() * radian;
		float lonSensor = sensor.getLongitude() * radian;
		float distance = earthRadius * acos((sin(latTarget)*sin(latSensor)) + (cos(latTarget)*cos(latSensor)*cos(lonTarget - lonSensor)));
		float valueAQI=-1.0;
        // Finding a measurement made within the time range
		for (Measurement &measurement : sensor.getMeasurements()){
			struct tm time= measurement.getTimestamp();
			if (abs(difftime(mktime(&time), mktime(&date))) < 86400){
                valueAQI=measurement.getAQI();
				break;
			}
		}
		if(valueAQI==-1.0){
			continue;
		}

		if (distance <= radius){
			avg += valueAQI;
			total++;
		}
        // Updating and sorting distances and averages arrays
        // To keep 4 closest
		if(distance<distances[3]){
			if(distance<distances[2]){
				if(distance<distances[1]){
					if(distance<distances[0]){
						averages[3]=averages[2];
						averages[2]=averages[1];
						averages[1]=averages[0];
						averages[0]=valueAQI;
						distances[3]=distances[2];
						distances[2]=distances[1];
						distances[1]=distances[0];
						distances[0]=distance;
					}
					else{
						averages[3]=averages[2];
						averages[2]=averages[1];
						averages[1]=valueAQI;
						distances[3]=distances[2];
						distances[2]=distances[1];
						distances[1]=distance;
					}
				}
				else{
					averages[3]=averages[2];
					averages[2]=valueAQI;
					distances[3]=distances[2];
					distances[2]=distance;
				}
			}
			else{
				distances[3]=distance;
				averages[3]=valueAQI;
			}
		}
	}
	if (total < 4) {
		total = 4;
		avg=averages[0]+averages[1]+averages[2]+averages[3];
	}
	return avg/total;
}

float SensorFunctions::analyseOneSensor(Sensor sensor)
{
	vector <Measurement> measurementVector = sensor.getMeasurements();
	float sum;
	int numDate = 0;
	for(Measurement &measurement : measurementVector){
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

	for (Sensor &sensor : sensorList) {
		if (sensor.getId() == s->getId()) continue;
		float difference = 0;
		for (Measurement &measurement : sensor.getMeasurements()) {
			struct tm tm1 = measurement.getTimestamp();
			time_t t = mktime(&tm1);
			if (difftime(t, mktime(&begin)) >= 0 && difftime(t, mktime(&end)) <= 0){
				for (Measurement &m : s->getMeasurements()) {
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
	float total = 0.0;

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
