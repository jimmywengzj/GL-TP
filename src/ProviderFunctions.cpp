/******************************************************************************
                             Xxx  -  description
                               -------------------
    start                : $DATE$
    copyright            : (C) $YEAR$ by $AUTHOR$
    email                : $EMAIL$
******************************************************************************/

//--------------- Realisation of <Xxx> class (Xxx.cpp file) -------------------

//-------------------------------------------------------------------- INCLUDES

//------------------------------------------------------------- System includes
using namespace std;
#include <iostream>
#include <string>
#include <list>
#include <fstream>
//----------------------------------------------------------- Personal includes
#include "ProviderFunctions.h"
#include "Provider.h"


list<Provider> providerList;
//------------------------------------------------------------------- Constants

//---------------------------------------------------------------------- PUBLIC

//-------------------------------------------------------------- Public methods
// type ProviderFunctions::Method ( parameter list )
// Algorithm:
//
//{
//} //----- End of Method
void ProviderFunctions::loadFromDataBase(){
    std::ifstream ifs ("providers.csv", std::ifstream::in);
		string providerString;
        string currentProvider="";
        Provider* providerObject;
	while(!ifs.eof()){
		getline(ifs,providerString,';');
		if(providerString!=""){
			string cleaner;
			getline(ifs,cleaner,';');
			string forget;
			getline(ifs,forget,'\n');
            if(providerString!=currentProvider){
                providerObject= new Provider(providerString);
			    providerList.push_back(*providerObject);
            }
            //we must add the measurement to the provider's list.
		}
	}
}
//-------------------------------------------------------- Operator overloading
ProviderFunctions & ProviderFunctions::operator = ( const ProviderFunctions & unProviderFunctions)
// Algorithm:
//
{
} //----- End of operator =

//--------------------------------------------------- Constructors - destructor
ProviderFunctions::ProviderFunctions ( const ProviderFunctions & unProviderFunctions )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling copy constructor of <ProviderFunctions>" << endl;
#endif
} //----- End of ProviderFunctions (copy constructor)

ProviderFunctions::ProviderFunctions ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling constructor of <ProviderFunctions>" << endl;
#endif
} //----- End of ProviderFunctions

ProviderFunctions::~ProviderFunctions ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Calling destructor of <ProviderFunctions>" << endl;
#endif
} //----- End of ~ProviderFunctions

//--------------------------------------------------------------------- PRIVATE

//-------------------------------------------------------------- Private methods
