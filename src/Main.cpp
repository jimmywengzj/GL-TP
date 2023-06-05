#include <iostream>
#include <algorithm>
using namespace std;
#include "Service.h"

Service service;

void useMeanAirQualityArea() {
    float area, latitude, longitude;
    struct tm start, end;
    cout << "Area: ";
    cin >> area;
    cout << "Latitude: ";
    cin >> latitude;
    cout << "Longitude: ";
    cin >> longitude;

    cout << "Start Year: ";
    cin >> start.tm_year;
    start.tm_year -= 1900;
    cout << "Start Month: ";
    cin >> start.tm_mon;
    start.tm_mon--;
    cout << "Start Day: ";
    cin >> start.tm_mday;
    start.tm_hour = 12;
    start.tm_min = 0;
    start.tm_sec = 0;
    start.tm_isdst = 0;

    cout << "End Year: ";
    cin >> end.tm_year;
    end.tm_year -= 1900;
    cout << "End Month: ";
    cin >> end.tm_mon;
    end.tm_mon--;
    cout << "End Day: ";
    cin >> end.tm_mday;
    end.tm_hour = 12;
    end.tm_min = 0;
    end.tm_sec = 0;
    end.tm_isdst = 0;

    cout << service.meanAirQualityArea(area, latitude, longitude, start, end) << endl;
}

void useCompareOneSensor() {
    string id;
    struct tm start, end;
    int num;

    cout << "Sensor id: ";
    cin >> id;

    cout << "Start Year: ";
    cin >> start.tm_year;
    start.tm_year -= 1900;
    cout << "Start Month: ";
    cin >> start.tm_mon;
    start.tm_mon--;
    cout << "Start Day: ";
    cin >> start.tm_mday;
    start.tm_hour = 12;
    start.tm_min = 0;
    start.tm_sec = 0;
    start.tm_isdst = 0;

    cout << "End Year: ";
    cin >> end.tm_year;
    end.tm_year -= 1900;
    cout << "End Month: ";
    cin >> end.tm_mon;
    end.tm_mon--;
    cout << "End Day: ";
    cin >> end.tm_mday;
    end.tm_hour = 12;
    end.tm_min = 0;
    end.tm_sec = 0;
    end.tm_isdst = 0;

    cout << "Number of most similar sensors: ";
    cin >> num;

    vector<Sensor> res = service.compareOneSensor(id, start, end);
    
    for (int i = 0; i < min((int)res.size(), num); i++) {
        cout << i+1 << " most similar sensor: " << res[i].getId() << endl;
    }
}

void analyseOneSensors() {
    string id;

    cout << "Sensor id: ";
    cin >> id;

    float res = service.analyseOneSensor(id);

    cout<<res<<endl;
} 

int main () {
    service.loadFromDatabase();

    int command = -1;
    while (1) {
        cout << "Choose functionality" << endl;
        cout << "1: mean air quality of an area" << endl;
        cout << "2: compare one sensor (find most similar sensor results)" << endl;
        cout << "3: study air cleaner" << endl;
        cout << "0: exit" << endl;
        cin >> command;
        switch(command) {
            case 1:
                useMeanAirQualityArea();
                break;
            case 2:
                useCompareOneSensor();
                break;
            case 3:
                analyseOneSensors();
                break;
            default:
                break;
        }
        if (command == 0) break;
    }

    return 0;
}