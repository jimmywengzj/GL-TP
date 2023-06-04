#include <iostream>
using namespace std;
#include "Service.h"
int main ()
{
    string userName;
    string userPassword;
    int loginAttempt = 0;
    Service* service= new Service();
    service->loadFromDatabase();
    list<float> a=service->studyAirCleaner("Cleaner0");
    cout<<a.front()<<";"<<a.back()<<endl;
        list<float> b=service->studyAirCleaner("Cleaner1");
    cout<<b.front()<<";"<<b.back()<<endl;
    while (loginAttempt < 5)
    {
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if (userName == "admin" && userPassword == "1")
        {
            string function;
            float area;
            float latitude;
            float longitude;
            struct tm start;
            struct tm end;
            cout << "Welcome Admin!\n";
            cout << "Enter Function 1 or 2 !\n";
            cin >> function;
            if (function == "1") {
                cout << "Enter Area !\n";
                cin >> area;
                cout << "Enter Latitude !\n";
                cin >> latitude;
                cout << "Enter Longitude !\n";
                cin >> longitude;
                cout << "Start Time !\n";
                cin >> start;
                cout << "Enter End Time !\n";
                cin >> end;
                cout << service->meanAirQualityArea(area, latitude, longitude, start, end);

            }

            break;
        }
        else if (userName == "individual" && userPassword == "2")
        {
            cout << "Welcome Individual!\n";
            break;
        }
        else if (userName == "cleaner" && userPassword == "3")
        {
            cout << "Welcome Cleaner!\n";
            break;
        }
        else if (userName == "logout" && userPassword == "0")
        {
            cout << "Logged Out \n";
            return 0;
        }

        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
            cout << "Too many login attempts! The program will now terminate.";
            return 0;
    }
    cout << "Thank you for logging in.\n";
}