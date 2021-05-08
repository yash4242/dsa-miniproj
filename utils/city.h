//DEPENDENCIES vector.h, miscstructs.h
#pragma once
#include "vector.h"
#include "person.h"

struct People{
	int id;
	struct People * next;
};

typedef struct People People;
typedef struct People * People_Ptr;

struct city{
	float dangerValue;     // Danger Value = covidPosNum + (# Primary/5) + (# Secondary/10)
	float covidPosNum;
	float noOfResidents;   // changed data type to float from int, not to conflict when
	float noOfPrimary;     // calculating danger value.
	float noOfSecondary;
    double safetyValue;   // = 1.0 / double(dangerValue); always DONT NEED THIS
	struct People * head; // use linked list of ints for list of persons in this city
};

typedef struct city city;
typedef struct city* city_ptr;

// This function adds people belongs to a city to the linked list of people in that city
void AddPeople(city C[],person P[]);

// This function creates Array of struct cities and returns it's pointer
city_ptr Create_City_Nodes(int no_of_cities);
// Here all values are initialised to 0


//make a  function whenever covid+ve list is released
void UpdateToPos(city C[],person P[],int array_of_positive[],int size);
// 'C' is array of city structs, 'array_of_positive' is list of positive, 'size' is size of array
// 'p' is array of person structs


//need to make a function which goes through this city's all residents and printout who all are riskFactor ==1 and ==2;
void Print_P_S(city C[],person P[], int id_of_city);

// Prints all info of a particular city
void Status_of_city(city C[],int city_index);

//updateCityStats function which updates city when noew people leave or enter, updates all members of the struct 
void Update_City(city C[],person P[], int origin,int destination,int Person_ID);
