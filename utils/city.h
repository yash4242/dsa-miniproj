//DEPENDENCIES vector.h, miscstructs.h
#pragma once
#include "vector.h"
#include "person.h"

/* Used to store id's of People living in a city
struct People{
	int id;						
	struct People * next;
};
*/

typedef struct People People;
typedef struct People * People_Ptr;

// Used to store all information Regarding a particular city
struct city{
	float dangerValue;        // Danger Value = covidPosNum + (# Primary/5) + (# Secondary/10)
	float covidPosNum;
	float noOfResidents;      // changed data type to float from int, not to conflict when
	float noOfPrimary;        // calculating danger value.
	float noOfSecondary;
    double safetyValue;       // = 1.0 / double(dangerValue); always DONT NEED THIS
//	struct People * head;     // use linked list of ints for list of persons in this city
};

typedef struct city city;
typedef struct city* city_ptr;

// This function adds people belongs to a city to the linked list of people in that city
// initially when the input is given fron user
void AddPeople(city C[],person P[],int NoOfPeople);


// This function creates Array of struct cities and returns it's pointer
// Here all values are initialised to 0
city_ptr Create_City_Nodes(int no_of_cities);


//make a  function whenever covid+ve list is released
void UpdateToPos(city C[],person P[],int array_of_positive[],int size);
// 'C' is array of city structs, 'array_of_positive' is list of positive, 'size' is size of array
// 'p' is array of person structs


// This function Prints all primary and secondary contacts in a city
void Print_P_S(city C[],person P[], int id_of_city,int noOfPeople);


// This function Prints all covid positive in a city
void Print_Positives(city C[],person P[],int id_of_city,int NoOfPeople);



// Prints all stats of a particular city
void Status_of_city(city C[],int city_index);


//updateCityStats function which updates city when noew people leave or enter, updates all members of the struct 
void Update_City(city C[],person P[], int origin,int destination,int Persion_ID);


// Used to remove a person from a city when he travels and update the 
// Remaining info in present city
void Remove_from_city(city_ptr T,person P[],int Person_ID);

// This function returns danger value of that city
float DangerValue(city_ptr T);

// This function returns Safety Value of the city
float SafetyValue(city_ptr T);

// Used to Add a person to person to a city when he travels
// And updates the remaining info in the city of origin
void Add_to_city(city_ptr T,person P[],int Person_ID);


