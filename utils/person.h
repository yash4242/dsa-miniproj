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

#endif


//NEEDED FUNCTIONS 

// prototypes here and func definitions in ../src/person.c

// create an array of person with  their  respective id and sets the pointer to their contacts as NULL
person_ptr CreatePersonArray(int No_Of_Persons,int Station_No);


// Updates the array of person when two person meet i.e when a person goes from a city 1 to city 2
person_ptr Update_Person_And_Contact(person_ptr P,int city1,int city2);

// This function Prints all primary and secondary contacts of a person P
// in the list L and  who all found posiitve updates their quarantine time
void PrintList(List L);


//in case this person comes out + then a function which informs his primary contacts& secondary contacts;
//i.e. updates those people's riskFactor

person_ptr CreatePersonArray(int No_Of_Persons,int Station_No)
{
    person_ptr PersonArr=(person_ptr)malloc(No_Of_Persons*sizeof(person));
    assert(PersonArr!=NULL);
    
    PersonArr->contacts= malloc(No_Of_Persons*sizeof(pair));
    assert(PersonArr->contacts!=NULL);
     // Create Empty Person Array with assigning the destinantion of each person at a station S
    for (int i = 1; i <=No_Of_Persons; i++)
    {
       PersonArr->contacts[i].first= 0;//assign the risk factor of all the person related to P as 0 as initially no one is positive
       PersonArr->contacts[i].second= 0;//assign the date of meeting of a person q meeting a person P as 0 as  initially no one met anyone
       PersonArr[i].id = i; // id denoting the index of each person as its identity
        PersonArr[i].location = Station_No; // each and every person is not in
        PersonArr[i].covidStatus = 0;// everyone is healthy intially
        PersonArr[i]. quarantineEndsOn=0 ;//since initially no one is positive therefore no quarantine
        PersonArr[i].riskFactor = 0;
    }

    return PersonArr;
    
}



//make a function whichdoes the following:
//once this person comes into a new city
//the function adds all the people of the city a person is living in, into its primaryContactList
//this function should also add this person to all other residents' primaryContactList

//key thing to notice: when you add a personB to person A's primary contact list,
//person B's primary contacts become person A's secondary and person A's primary become person B's
//secondary


/**************************************************** MAIN NEEDED FUNCTION ********************************************************************/

// make a function which changes the riskFactor of contacts of all persons as soon as a person or multiple persons are declared Covid Positive ...// 

//traverse through the covidList array and for each person on the list:
      //  print out his primary contacts if date of meeting was within currentDay and currentDay - 14
       // similarly for 2ndary contacts
    

