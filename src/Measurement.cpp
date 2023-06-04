/*************************************************************************
                           Measurement  -  description
                             -------------------
    beginning                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Realisation of <Measurement> class (Measurement.cpp file) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include system
using namespace std;
#include <iostream>
#include <cmath>

//------------------------------------------------------- Personal include

#include "Measurement.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Operator Overload
bool Measurement::operator == ( const Measurement & unMeasurement )
{
    tm date = unMeasurement.getTimestamp();
    return (
            unMeasurement.sensorId == sensorId &&
            date.tm_year == timestamp.tm_year &&
            date.tm_mon == timestamp.tm_mon &&
            date.tm_mday == timestamp.tm_mday &&
            date.tm_hour == timestamp.tm_hour &&
            unMeasurement.valueNO2 == valueNO2 &&
            unMeasurement.valueO3 == valueO3 &&
            unMeasurement.valuePM10 == valuePM10 &&
            unMeasurement.valueSO2 == valueSO2 &&
            unMeasurement.AQI == AQI
            );
} //----- End of operator ==


//---------------------------------------------- Constructors - destructor
Measurement::Measurement (struct tm aDate, string aSensorId, float O3, float NO2,float SO2, float PM10)
{
    this->timestamp = aDate;
    this->sensorId = aSensorId;
    this->valueO3 = O3;
    this->valueNO2 = NO2;
    this->valueSO2 = SO2;
    this->valuePM10= PM10;

    int indexO3 = 0;
    if ((int)O3 < 29){
        indexO3 = 1;
    } else if ((int)O3 <= 54){
        indexO3 = 2;
    } else if ((int)O3 <= 79){
        indexO3 = 3;
    } else if ((int)O3 <= 104){
        indexO3 = 4;
    } else if ((int)O3 <= 129){
        indexO3 = 5;
    } else if ((int)O3 <= 149){
        indexO3 = 6;
    } else if ((int)O3 <= 179){
        indexO3 = 7;
    } else if ((int)O3 <= 209){
        indexO3 = 8;
    } else if ((int)O3 <= 239){
        indexO3 =  9;
    } else {
        indexO3 = 10;
    }

    int indexSO2 = 0;
    if ((int)SO2 < 39){
        indexSO2 = 1;
    } else if ((int)SO2 <= 79){
        indexSO2 = 2;
    } else if ((int)SO2 <= 119){
        indexSO2 = 3;
    } else if ((int)SO2 <= 159){
        indexSO2 = 4;
    } else if ((int)SO2 <= 199){
        indexSO2 = 5;
    } else if ((int)SO2 <= 249){
        indexSO2 = 6;
    } else if ((int)SO2 <= 299){
        indexSO2 = 7;
    } else if ((int)SO2 <= 399){
        indexSO2 = 8;
    } else if ((int)SO2 <= 499){
        indexSO2 =  9;
    }else {
        indexSO2 = 10;
    }

    int indexNO2 = 0;
    if ((int)NO2 < 29){
        indexNO2 = 1;
    } else if ((int)NO2 < 54){
        indexNO2 = 2;
    } else if ((int)NO2 < 84){
        indexNO2 = 3;
    } else if ((int)NO2 < 109){
        indexNO2 = 4;
    } else if ((int)NO2 < 134){
        indexNO2 = 5;
    } else if ((int)NO2 < 164){
        indexNO2 = 6;
    } else if ((int)NO2 < 199){
        indexNO2 = 7;
    } else if ((int)NO2 < 274){
        indexNO2 = 8;
    } else if ((int)NO2 < 399){
        indexNO2 =  9;
    } else {
        indexNO2 = 10;
    }

    int indexPM10 = 0;
    if ((int)PM10 <  6){
        indexPM10 = 1;
    } else if ((int)PM10 < 13){
        indexPM10 = 2;
    } else if ((int)PM10 < 20){
        indexPM10 = 3;
    } else if ((int)PM10 < 27){
        indexPM10 = 4;
    } else if ((int)PM10 < 34){
        indexPM10 = 5;
    } else if ((int)PM10 < 41){
        indexPM10 = 6;
    } else if ((int)PM10 < 49){
        indexPM10 = 7;
    } else if ((int)PM10 < 64){
        indexPM10 = 8;
    } else if ((int)PM10 < 79){
        indexPM10 =  9;
    } else {
        indexPM10 = 10;
    }

    AQI = indexO3;
    if (indexSO2 > AQI) AQI = indexSO2;
    if (indexNO2 > AQI) AQI = indexNO2;
    if (indexPM10 > AQI) AQI = indexPM10;

#ifdef MAP
    cout << "Appel au constructeur de copie de <Measurement>" << endl;
#endif
} //----- End of Measurement (constructor)


Measurement::Measurement ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
} //----- End of Measurement

Measurement::Measurement ( const Measurement & aMeasurement )
{
#ifdef MAP
    cout << "Calling copy constructor of <Measurement>" << endl;
#endif
    sensorId = aMeasurement.sensorId;
    timestamp.tm_year = aMeasurement.timestamp.tm_year;
    timestamp.tm_mon = aMeasurement.timestamp.tm_mon;
    timestamp.tm_mday = aMeasurement.timestamp.tm_mday;
    timestamp.tm_hour = aMeasurement.timestamp.tm_hour;
    timestamp.tm_min = aMeasurement.timestamp.tm_min;
    timestamp.tm_sec = aMeasurement.timestamp.tm_sec;
    valueO3 = aMeasurement.valueO3;
    valueSO2 = aMeasurement.valueSO2;
    valueNO2 = aMeasurement.valueNO2;
    valuePM10 = aMeasurement.valuePM10;
    AQI = aMeasurement.AQI;
} //----- End of Measurement (copy constructor)


Measurement::~Measurement ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Measurement>" << endl;
#endif
} //----- End of ~Measurement

//------------------------------------------------------------------ Getters/Setters

struct tm Measurement:: getTimestamp ( ) const

{
#ifdef MAP
    cout << "Calling for getTimestamp" << endl;
#endif
    return timestamp;
} //----- End of getTimestamp


string Measurement:: getSensorId ( ) const
{
#ifdef MAP
    cout << "Calling for getSensorId" << endl;
#endif
    return sensorId;
} //----- End of getSensorId


float Measurement:: getValueO3 ( ) const
{
#ifdef MAP
    cout << "Calling for getValueO3" << endl;
#endif
    return valueO3;
} //----- End of getValueO3


float Measurement:: getValueNO2 ( ) const
{
#ifdef MAP
    cout << "Calling for getValueNO2" << endl;
#endif
    return valueNO2;
} //----- End of getValueNO2


float Measurement:: getValueSO2 ( ) const
{
#ifdef MAP
    cout << "Calling for getValueNO2" << endl;
#endif
    return valueSO2;
} //----- End of getValueNO2


float Measurement:: getValuePM10 ( ) const
{
#ifdef MAP
    cout << "Calling for getValuePM10" << endl;
#endif
    return valuePM10;
} //----- End of getValuePM10


float Measurement:: getAQI ( ) const
{
#ifdef MAP
    cout << "Calling for getAQI" << endl;
#endif
    return AQI;
} //----- End of getAQI


//---------------------------------------------------------------- PRIVATE

//----------------------------------------------------- Protected Methods

