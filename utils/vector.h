#pragma once
#include "miscstructs.h" 

//DEPENDECNCIES: miscstructs.h

//NEED VECTOR OF <INT>--<INT>--<INT>
struct vectorint
{
    int* arr;
    int size;
    int capacity;
};
typedef struct vectorint vectorint;


//same functions as for vectorpair


//=================================================================================//

//NEED VECTOR OF <INT, INT>---<INT, INT>---
struct vectorpair
{
    pair* arr;
    int size; //how many elements are beig used/non garbage
    int capacity;    //in total how many slots have been allocated to the array
};

typedef struct vectorpair vectorpair;

//FUNC PROTOTYPES

//create vector: malloc first the struct, then maybe( say 100) slots for the array inside the vector

//insert into vector: 
//btw, insert into vectors has to take care that if a vector becomes larger than its 
//allocated capacity, use realloc to get more capacity. (say, 1.5 times or twice)
//personal experience: what has to be inserted into the vector, if we pass that as argument
//in this insert func then life is quite easy

//[OPTIONAL] should we remove those people who met the person more than 15 days ago?