#ifndef _GRAPH_H_
#define _GRAPH_H_
//DEPENCIES: pair
// #pragma once
// #include "vector.h"

#include "pair.h"
#include "city.h"

typedef struct person person;
typedef struct person* person_ptr;
typedef person_ptr List;

struct person{
	int location; // Current City of the person.
	int covidStatus;// 0 for healthy, 1 for Covid+ve
	int quarantineEndsOn;// date on which the quaranrine ends
	int riskFactor; // 2--> If is a primary contact of a covid +ve , 1--> If is a secondary contact of a covid + , 0-->If none
    pair* contacts; //during initialising person struct, allocate n indices to this array where n is the no of people in total
    //pair's "first" element has 0/1/2: 1=> secondary contact of;
    //pairs "second" element has the date of meeting
    //aray's index means met which person


};

#endif


//NEEDED FUNCTIONS 

// prototypes here and func definitions in ../src/person.c

// create an array of person with  their  respective id and sets the pointer to their contacts as NULL
person_ptr CreatePersonArray(int No_Of_Persons);


// Updates the array of person when two person meet i.e when a person goes from a city 1 to city 2
person_ptr Update_Person_And_Contact(person_ptr P,int city1,int city2);

// This function Prints all primary and secondary contacts of a person P
// in the list L and  who all found posiitve updates their quarantine time
void PrintList(List L);


//in case this person comes out + then a function which informs his primary contacts& secondary contacts;
//i.e. updates those people's riskFactor



//make a function whichdoes the following:
//once this person comes into a new city
//the function adds all the people of the city a person is living in, into its primaryContactList
//this function should also add this person to all other residents' primaryContactList

//key thing to notice: when you add a personB to person A's primary contact list,
//person B's primary contacts become person A's secondary and person A's primary become person B's
//secondary



