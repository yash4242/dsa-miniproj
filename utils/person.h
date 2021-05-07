//DEPENCIES: pair
#pragma once
//#include "vector.h"
#include "pair.h"

struct person{
	int location; // Current City of the person.
	int covidStatus;// 0 for healthy, 1 for Covid+ve
	int quarantineEndsOn;// date on which the quaranrine ends
	int riskFactor; // 2--> If is a primary contact of a covid +ve , 1--> If is a secondary contact of a covid + , 0-->If none
    pair contacts[1001]; ///[ALERT]=> 1001 taken this is a static value, if no. of ppl are more than 1000 then this needs to be changed
    //pair's "first" element has 0/1/2: 1=> secondary contact of;
    //pairs "second" element has the date of meeting
    //aray's index means met which person

};

typedef struct person person;
typedef struct person* person_ptr;


//NEEDED FUNCTIONS 
//write the prototypes here and func definitions in ../src/person.c

//in case this person comes out + then a function which informs his primary contacts& secondary contacts;
//i.e. updates those people's riskFactor



//make a function whichdoes the following:
//once this person comes into a new city
//the function adds all the people of the city a person is living in, into its primaryContactList
//this function should also add this person to all other residents' primaryContactList

//key thing to notice: when you add a personB to person A's primary contact list,
//person B's primary contacts become person A's secondary and person A's primary become person B's
//secondary



