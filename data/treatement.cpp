#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;
void printUsers(){
	std::ifstream ifs ("users.csv", std::ifstream::in);
	while(!ifs.eof()){
		string user;
		getline(ifs,user,';');
		if(user!=""){
			string sensor;
			getline(ifs,sensor,';');
			string forget;
			getline(ifs,forget,'\n');
			cout<<"User : "<<user<<" Sensor : "<<sensor<<endl;
		}
	}

}
void printProviders(){
	std::ifstream ifs ("providers.csv", std::ifstream::in);
	while(!ifs.eof()){
		string provider;
		getline(ifs,provider,';');
		if(provider!=""){
			string cleaner;
			getline(ifs,cleaner,';');
			string forget;
			getline(ifs,forget,'\n');
			cout<<"Provider : "<<provider<<" Cleaner : "<<cleaner<<endl;
		}
	}

}
void printSensors(){
	std::ifstream ifs ("sensors.csv", std::ifstream::in);
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
			cout<<"Sensor : "<<sensor<<" latitude : "<<latitude<<" longitude : "<<longitude<<endl;
		}
	}

}
void printCleaner(){
	std::ifstream ifs ("cleaners.csv", std::ifstream::in);
	int i=0;
	while(!ifs.eof()){

		string cleaner;
		getline(ifs,cleaner,';');
		if(cleaner!=""){
		struct tm time;
			string latitudeString;
			getline(ifs,latitudeString,';');
			float latitude = stof(latitudeString);
			string longitudeString;
			getline(ifs,longitudeString,';');
			float longitude = stof(longitudeString);						
			string startDateString;
			getline(ifs,startDateString,';');
			string endDateString;
			time.tm_year=stoi(startDateString.substr (0,4))-1900;
			cout<<time.tm_year<<endl;
			time.tm_mon=stoi(startDateString.substr (5,2));
			cout<<time.tm_mon<<endl;
			time.tm_mday=stoi(startDateString.substr (8,2));
			cout<<time.tm_mday<<endl;
			time.tm_hour=stoi(startDateString.substr (11,2));
			cout<<time.tm_hour<<endl;
			time.tm_min=stoi(startDateString.substr (14,2));
			cout<<time.tm_min<<endl;
			time.tm_hour=stoi(startDateString.substr (17,2));
			cout<<time.tm_hour<<endl;


			getline(ifs,endDateString,';');
			string forget;
			getline(ifs,forget,'\n');
			cout<<"Cleaner : "<<cleaner<<" Latitude : "<<latitude<<" Longitude : "<<longitude<<" startDate : "<<startDateString<<" endDate : "<<endDateString<<endl;
		}
	}
}
void printMeasurements(){
	std::ifstream ifs ("measurements.csv", std::ifstream::in);
	int i=0;
	while(!ifs.eof()){
		i++;
		string forget;
		string measureTimeString;
		getline(ifs,measureTimeString,';');
		if(measureTimeString!=""){
			string sensor;
			getline(ifs,sensor,';');
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
			cout<<"Measured at : "<<measureTimeString<<" by sensor : "<<sensor<<" O3 : "<<O3String<<" NO2 : "<<NO2String<<" SO2 : "<<SO2String<<" PM10 : "<<PM10String<<endl;
		}
	}
}
int main(){
	//printUsers();
	printCleaner();
	//printMeasurements();
	//printProviders();
	//printSensors();
	return 0;	
}


