/******************************************************************************
                             Cleaner  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//--------------- Realisation of <Cleaner> class (Cleaner.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>
#include <string>

//----------------------------------------------------------- Personal includes
#include "Cleaner.h"

//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
// type Cleaner::Method ( parameter list )
// Algorithm:
//
//{
//} //----- End of Method
string Cleaner::getId()const 
{
    return id;
} 

float Cleaner::getLatitude() const{
    return latitude;
}

float Cleaner::getLongitude() const{
    return longitude;
}

tm Cleaner::getStart() const{
    return timestampStart;
}

tm Cleaner::getEnd() const{
    return timestampEnd;
}

//-------------------------------------------------------- Operator overloading
Cleaner & Cleaner::operator = ( const Cleaner & unCleaner )
{
    this->id=unCleaner.id;
    this->longitude=unCleaner.longitude;
    this->latitude=unCleaner.latitude;
    this->timestampStart.tm_year=unCleaner.timestampStart.tm_year;
    this->timestampStart.tm_mon=unCleaner.timestampStart.tm_mon;
    this->timestampStart.tm_mday=unCleaner.timestampStart.tm_mday;
    this->timestampStart.tm_hour=unCleaner.timestampStart.tm_hour;
    this->timestampEnd.tm_year=unCleaner.timestampEnd.tm_year;
    this->timestampEnd.tm_mon=unCleaner.timestampEnd.tm_mon;
    this->timestampEnd.tm_mday=unCleaner.timestampEnd.tm_mday;
    this->timestampEnd.tm_hour=unCleaner.timestampEnd.tm_hour;
    return *this;
} //----- End of operator =

bool Cleaner::operator == (const Cleaner & unCleaner) const
{
    return (
            this->id==unCleaner.id &&
            this->longitude==unCleaner.longitude &&
            this->latitude==unCleaner.latitude &&
            this->timestampStart.tm_year==unCleaner.timestampStart.tm_year &&
            this->timestampStart.tm_mon==unCleaner.timestampStart.tm_mon &&
            this->timestampStart.tm_mday==unCleaner.timestampStart.tm_mday &&
            this->timestampStart.tm_hour==unCleaner.timestampStart.tm_hour &&
            this->timestampEnd.tm_year==unCleaner.timestampEnd.tm_year &&
            this->timestampEnd.tm_mon==unCleaner.timestampEnd.tm_mon &&
            this->timestampEnd.tm_mday==unCleaner.timestampEnd.tm_mday &&
            this->timestampEnd.tm_hour==unCleaner.timestampEnd.tm_hour);
}

//--------------------------------------------------- Constructors - destructor
Cleaner::Cleaner ( const Cleaner & unCleaner )
{
#ifdef MAP
    cout << "Calling copy constructor of <Cleaner>" << endl;
#endif
    this->id=unCleaner.id;
    this->longitude=unCleaner.longitude;
    this->latitude=unCleaner.latitude;
    this->timestampStart.tm_year=unCleaner.timestampStart.tm_year;
    this->timestampStart.tm_mon=unCleaner.timestampStart.tm_mon;
    this->timestampStart.tm_mday=unCleaner.timestampStart.tm_mday;
    this->timestampStart.tm_hour=unCleaner.timestampStart.tm_hour;
    this->timestampEnd.tm_year=unCleaner.timestampEnd.tm_year;
    this->timestampEnd.tm_mon=unCleaner.timestampEnd.tm_mon;
    this->timestampEnd.tm_mday=unCleaner.timestampEnd.tm_mday;
    this->timestampEnd.tm_hour=unCleaner.timestampEnd.tm_hour;
} //----- End of Cleaner (copy constructor)

Cleaner::Cleaner (string anId, float aLongitude, float aLatitude, const tm aTimestampStart, const tm aTimestampEnd)
{
#ifdef MAP
    cout << "Calling constructor of <Cleaner>" << endl;
#endif
    id = anId;
    longitude = aLongitude;
    latitude = aLatitude;
    // Copying the start timestamp
    timestampStart.tm_year = aTimestampStart.tm_year;
    timestampStart.tm_mon = aTimestampStart.tm_mon;
    timestampStart.tm_mday = aTimestampStart.tm_mday;
    timestampStart.tm_hour = aTimestampStart.tm_hour;
    // Copying the end timestamp
    timestampEnd.tm_year = aTimestampEnd.tm_year;
    timestampEnd.tm_mon = aTimestampEnd.tm_mon;
    timestampEnd.tm_mday = aTimestampEnd.tm_mday;
    timestampEnd.tm_hour = aTimestampEnd.tm_hour;
} //----- End of Cleaner

Cleaner::~Cleaner ( )
{
#ifdef MAP
    cout << "Calling destructor of <Cleaner>" << endl;
#endif
} //----- End of ~Cleaner
