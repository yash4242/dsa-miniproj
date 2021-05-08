//DEPENDENCIES vector.h, miscstructs.h
#pragma once
#include "vector.h"


struct city{
	int dangerValue;
	int covidPosNum;
	int noOfResidents;
	int noOfPrimary;
	int noOfSecondary;
    //double safetyValue; // = 1.0 / double(dangerValue); always DONT NEED THIS
	//[TO DO] use linked list of ints for list of persons in this city
};

typedef struct city city;
typedef struct city* city_ptr;

//todo
//make a  function whenever covid+ve list is released
//make a function whenever covid +ve list is released
//need to make a function which goes through this city's all residents and printout who all are riskFactor ==1 and ==2;
//updateCityStats function which updates city when noew people leave or enter, updates all members of the struct 