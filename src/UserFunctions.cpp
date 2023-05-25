/******************************************************************************
                             UserFunctions  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//------- Realisation of <UserFunctions> class (UserFunctions.cpp file) -------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>
#include <fstream>
//----------------------------------------------------------- Personal includes
#include "UserFunctions.h"
#include "Sensor.h"

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
// type UserFunctions::Method ( parameter list )
// Algorithm:
//
//{
//} //----- End of Method
void UserFunctions::loadFromDatabase()
{
	std::ifstream ifs ("users.csv", std::ifstream::in);
	while(!ifs.eof()){
		string user;
		getline(ifs,user,';');
		if(user!=""){
			string sensor;
			getline(ifs,sensor,';');
			string forget;
			getline(ifs,forget,'\n');
            User u= new User(user,0);
		}
	}
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
		}
	}

}

void UserFunctions::markUser(User user)
{
    user.setBad();
}

int UserFunctions::getPoints(User user)
{
    user.getPoints();
}

vector<pair<User, float>> UserFunctions::checkData(SensorFunctions sensorFunctions)
{
    vector<pair<User, float>> score;

    for (const auto &[id, user] : users) {
        vector<sensor> sensors = user.getSensors();
        float sum = 0;
        for (Sensor sensor : sensors) {
            sum += sensorFunctions.analyseOneSensor(sensor);
        }
        score.push_back(make_pair(user, sum / sensors.size()));
    }

    return score;
}

//-------------------------------------------------------- Operator overloading
UserFunctions & UserFunctions::operator = ( const UserFunctions & unUserFunctions )
// Algorithm:
//
{
} //----- End of operator =

//--------------------------------------------------- Constructors - destructor
UserFunctions::UserFunctions ( const UserFunctions & unUserFunctions )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling copy constructor of <UserFunctions>" << endl;
#endif
} //----- End of UserFunctions (copy constructor)

UserFunctions::UserFunctions ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling constructor of <UserFunctions>" << endl;
#endif
} //----- End of UserFunctions

UserFunctions::~UserFunctions ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling destructor of <UserFunctions>" << endl;
#endif
} //----- End of ~UserFunctions

//----------------------------------------------------------------------- PRIVE

//------------------------------------------------------------- Private methods
