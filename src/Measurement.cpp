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

//------------------------------------------------------ Include personnel

#include "Measurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Measurement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Measurement & Measurement::operator = ( const Measurement & unMeasurement )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Measurement::Measurement (struct tm aDate, string aSensorId, float O3, float NO2,float SO2, float PM10)
// Algorithme :
//
{
    this->timestamp = aDate;
    this->sensorId = aSensorId;
    this->valueO3 = O3;
    this->valueNO2 = NO2;
    this->valueSO2 = SO2;
    this->valuePM10= PM10;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Measurement>" << endl;
#endif
} //----- Fin de Measurement (constructeur de copie)


Measurement::Measurement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
} //----- Fin de Measurement


Measurement::~Measurement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Measurement>" << endl;
#endif
} //----- Fin de ~Measurement

//------------------------------------------------------------------ Getters/Setters

struct tm Measurement:: getTimestamp ( ) const
// Algorithme :
//
{
    return timestamp;
#ifdef MAP
    cout << "Calling for getTimestamp" << endl;
#endif
} //----- End of getTimestamp


string Measurement:: getSensorId ( ) const
// Algorithme :
//
{
    return sensorId;
#ifdef MAP
    cout << "Calling for getSensorId" << endl;
#endif
} //----- End of getSensorId

float Measurement:: getValueO3 ( ) const
// Algorithme :
//
{
    return valueO3;
#ifdef MAP
    cout << "Calling for getValueO3" << endl;
#endif
} //----- End of getValueO3


float Measurement:: getValueNO2 ( ) const
// Algorithme :
//
{
    return valueNO2;
#ifdef MAP
    cout << "Calling for getValueNO2" << endl;
#endif
} //----- End of getValueNO2

float Measurement:: getValuePM10 ( ) const
// Algorithme :
//
{
    return valuePM10;
#ifdef MAP
    cout << "Calling for getValuePM10" << endl;
#endif
} //----- End of getValuePM10


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

