//DEPENDENCIES vector.h, miscstructs.h
//#pragma once
#ifndef __COMB_H
#define __COMB_H

#include "vector.h"
#include "linkedlist.h"


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



struct person
{
    int id; // identity of a particular person
	int location; // Current City of the person.
	int covidStatus;// 0 for healthy, 1 for Covid+ve
	int quarantineEndsOn;// date on which the quaranrine ends
	int riskFactor; // 2--> If is a primary contact of a covid +ve , 1--> If is a secondary contact of a covid + , 0-->If none
    pair* contacts; //during initialising person struct, allocate n indices to this array where n is the no of people in total
    //pair's "first" element denotes the risk facotr of a person q,related to a person P
    // It has 0/1/2: 
    // 1=> secondary contact of P,
    // 2=> Primary contact of P;
    //pairs "second" element has the date of meeting
    //aray's index means P met which person


};

typedef struct person person;
typedef person* person_ptr;




void cityArrayInit(int noOfCity, city cityArray[]);

// This function Prints all primary and secondary contacts in a city
void cityPrimSec(person personArray[], int cityIndex,int noOfPeople);

// This function Prints all covid positive in a city
void printPositivesOfCity(person personArray[],int id_of_city,int NoOfPeople);


// Prints all stats of a particular city
void printStatusOfCity(city C[], int city_index);

//removes person from src, updates src city, adds him to dest, updates dest city, and updates contacts lists, src and dest have to be neighbours. if not then use this func in steps
void transferPerson(int personIndex, int sourceCity, int destCity, person personArray[], city cityArray[], list graph[], int noOfPerson);





void personArrayInit(person personArray[], int noOfPerson, city cityArray[]);

void feedList(person personArray[], int noOfPerson, city cityArray[], int noOfCity, list graph[]);

void getStatusOfPerson(int person_Id, person personArray[], int noOfPerson);

void PrintCovidPosPerson(person personArray[], int noOfPerson);

void printListOfResidents(int cityId , person personArray[] , int noOfPerson);

void incrementDay(person personArray[], int noOfPerson);



#endif