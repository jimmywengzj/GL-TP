/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Realisation of <Measurement> class (Measurement.cpp file) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include system
using namespace std;
#include <iostream>
#include <cmath>

//------------------------------------------------------ Include personnel

#include "Measurement.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------- Surcharge d'opérateurs
Measurement & Measurement::operator = ( const Measurement & unMeasurement )
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Measurement::Measurement (struct tm aDate, string aSensorId, float O3, float NO2,float SO2, float PM10)
{
    this->timestamp = aDate;
    this->sensorId = aSensorId;
    this->valueO3 = O3;
    this->valueNO2 = NO2;
    this->valueSO2 = SO2;
    this->valuePM10= PM10;

    int indexO3 = 0;
    switch((int)O3) {
        case   0 ...  29 : indexO3 =  1; break;
        case  30 ...  54 : indexO3 =  2; break;
        case  55 ...  79 : indexO3 =  3; break;
        case  80 ... 104 : indexO3 =  4; break;
        case 105 ... 129 : indexO3 =  5; break;
        case 130 ... 149 : indexO3 =  6; break;
        case 150 ... 179 : indexO3 =  7; break;
        case 180 ... 209 : indexO3 =  8; break;
        case 210 ... 239 : indexO3 =  9; break;
        default          : indexO3 = 10; break; 
    }

    int indexSO2 = 0;
    switch((int)SO2) {
        case   0 ...  39 : indexSO2 =  1; break;
        case  40 ...  79 : indexSO2 =  2; break;
        case  80 ... 119 : indexSO2 =  3; break;
        case 120 ... 159 : indexSO2 =  4; break;
        case 160 ... 199 : indexSO2 =  5; break;
        case 200 ... 249 : indexSO2 =  6; break;
        case 250 ... 299 : indexSO2 =  7; break;
        case 300 ... 399 : indexSO2 =  8; break;
        case 400 ... 499 : indexSO2 =  9; break;
        default          : indexSO2 = 10; break; 
    }

    int indexNO2 = 0;
    switch((int)NO2) {
        case   0 ...  29 : indexNO2 =  1; break;
        case  30 ...  54 : indexNO2 =  2; break;
        case  55 ...  84 : indexNO2 =  3; break;
        case  85 ... 109 : indexNO2 =  4; break;
        case 110 ... 134 : indexNO2 =  5; break;
        case 135 ... 164 : indexNO2 =  6; break;
        case 165 ... 199 : indexNO2 =  7; break;
        case 200 ... 274 : indexNO2 =  8; break;
        case 275 ... 399 : indexNO2 =  9; break;
        default          : indexNO2 = 10; break; 
    }

    int indexPM10 = 0;
    switch((int)PM10) {
        case   0 ...   6 : indexPM10 =  1; break;
        case   7 ...  13 : indexPM10 =  2; break;
        case  14 ...  20 : indexPM10 =  3; break;
        case  21 ...  27 : indexPM10 =  4; break;
        case  28 ...  34 : indexPM10 =  5; break;
        case  35 ...  41 : indexPM10 =  6; break;
        case  42 ...  49 : indexPM10 =  7; break;
        case  50 ...  64 : indexPM10 =  8; break;
        case  65 ...  79 : indexPM10 =  9; break;
        default          : indexPM10 = 10; break; 
    }

    AQI = indexO3;
    if (indexSO2 > AQI) AQI = indexSO2;
    if (indexNO2 > AQI) AQI = indexNO2;
    if (indexPM10 > AQI) AQI = indexPM10;

#ifdef MAP
    cout << "Appel au constructeur de copie de <Measurement>" << endl;
#endif
} //----- Fin de Measurement (constructeur de copie)


Measurement::Measurement ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
} //----- Fin de Measurement


Measurement::~Measurement ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Measurement>" << endl;
#endif
} //----- Fin de ~Measurement

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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

