//DEPENDENCIES vector.h, miscstructs.h
#pragma once
#include "vector.h"
#include "person.h"


//Stores all information Regarding a particular city
struct city{
	double dangerValue;        // Danger Value = covidPosNum + (# Primary/5) + (# Secondary/10)
	int covidPosNum;
	int noOfResidents;      // changed data type to float from int, not to conflict when
	int noOfPrimary;        // calculating danger value.
	int noOfSecondary;
    // double safetyValue;       // = 1.0 / double(dangerValue); always DONT NEED THIS
};

typedef struct city city;
typedef struct city* city_ptr;


// This function Prints all primary and secondary contacts in a city
void cityPrimSec(person personArray[], int cityIndex,int noOfPeople);

// This function Prints all covid positive in a city
void printPositivesOfCity(person personArray[],int id_of_city,int NoOfPeople);


// Prints all stats of a particular city
void printStatusOfCity(city C[], int city_index);

//removes person from src, updates src city, adds him to dest, updates dest city, and updates contacts lists, src and dest have to be neighbours. if not then use this func in steps
void transferPerson(int personIndex, int sourceCity, int destCity, person personArray[], city cityArray[], list graph[], int noOfPerson);



