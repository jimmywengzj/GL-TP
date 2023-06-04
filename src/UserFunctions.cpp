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
#include <list>
#include <iostream>
#include <fstream>
//----------------------------------------------------------- Personal includes
#include "UserFunctions.h"
#include "SensorFunctions.h"
#include "User.h"
#include "Sensor.h"
list<User> userList;
//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
// type UserFunctions::Method ( parameter list )
// Algorithm:
//
//{
//} //----- End of Method
void UserFunctions::loadFromDatabase(SensorFunctions sensorFunctions)
{
    std::ifstream ifs;

    ifs.open ("../data/users.csv", std::ifstream::in);
    string lastUser="";
	string user;
    User* u;
	while(!ifs.eof()){
		getline(ifs,user,';');
		if(user!=""){
			string sensorString;
			getline(ifs,sensorString,';');
			string forget;
			getline(ifs,forget,'\n');
            if(user!=lastUser){
                u= new User(user,0);
			    userList.push_back(*u);
            }
            u->addSensor(*(sensorFunctions.findSensor(sensorString)));
		}
	}

}

void UserFunctions::markUser(User user)
{
    user.setBad();
}

int UserFunctions::getPoints(User user)
{
    return user.getPoints();
}

vector<pair<User, float>> UserFunctions::checkData(SensorFunctions sensorFunctions)
{
    vector<pair<User, float>> score;

    for (const auto &[id, user] : users) {
        list<Sensor> sensors = user.getSensors(); //James: changed vector<sensor> to lo list<Sensor> because that's how the code is made
        float sum = 0;
        for (Sensor sensor : sensors) {
            sum += sensorFunctions.analyseOneSensor(sensor);
        }
        score.push_back(make_pair(user, sum / sensors.size()));
    }

    return score;
}

//-------------------------------------------------------- Operator overloading
/*UserFunctions & UserFunctions::operator = ( const UserFunctions & unUserFunctions )
// Algorithm:
//
{
} //----- End of operator =
*/
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
