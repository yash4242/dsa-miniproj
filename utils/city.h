#pragma once

//DEPENDENCIES vector.h, miscstructs.h

struct city{
	int dangerValue;
	int covidPosNum;
    double safetyValue; // = 1.0 / double(dangerValue); always
	//VECTOR <INT> for list of all people in it
    //VECTOR of <INT> for list of cities which are connected to this city
    

};

typedef struct city city;
typedef struct city* city_ptr;

//todo
//make a dangerValue updater function whenever covid+ve list is released
//make a safetyValue updater function whenever covid ve list is released
//need to make a function which goes through this city's all residents and printout who all are riskFactor ==1 and ==2;