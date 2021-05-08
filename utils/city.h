//DEPENDENCIES vector.h, miscstructs.h
#pragma once
#include "vector.h"

struct People{
	int id;
	struct People * next;
}

typedef struct People People;
typedef struct People * People_Ptr;

struct city{
	float dangerValue;     // Danger Value = covidPosNum + (# Primary/5) + (# Secondary/10)
	float covidPosNum;
	float noOfResidents;   // changed data type to float from int, not to conflict when
	float noOfPrimary;     // calculating danger value.
	float noOfSecondary;
    double safetyValue;   // = 1.0 / double(dangerValue); always DONT NEED THIS
	struct people * head; // use linked list of ints for list of persons in this city
};

typedef struct city city;
typedef struct city* city_ptr;

//todo
//make a  function whenever covid+ve list is released
//make a function whenever covid +ve list is released
//need to make a function which goes through this city's all residents and printout who all are riskFactor ==1 and ==2;
//updateCityStats function which updates city when noew people leave or enter, updates all members of the struct 