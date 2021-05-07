//DEPENDENCIES: pair
#pragma once
#include <stdlib.h>
#include "pair.h" 

//DEPENDECNCIES: pair.h

//==============================VECTOR OF [INT][INT][INT]=============================
struct vectorInt
{
    int* arr;
    int numelems;
    int capacity;
};
typedef struct vectorInt vectorInt;

//======================== VECTORINT FUNCTIONS PROTOS====================================
//mallocs a new vectorInt
vectorInt* createVectorInt(int);

//pushes ints into vectorInt
void vectorIntPushBack(vectorInt*, int);



//============================VECTOR OF [INT, INT][INT, INT][INT, INT]===============================
struct vectorPair
{
    pair* arr;
    int numelems; //how many elements are beig used/non garbage
    int capacity;    //in total how many slots have been allocated to the array
};

typedef struct vectorPair vectorPair;

//===============================================VECTORPAIR FUNC PROTOS==================================

//mallocs a new vectorPair
vectorPair* createVectorPair(int);

//makes a pair of 2 ints and pushes it into vectorPair
void vectorPairPushBack(vectorPair* vpp, int a, int b);



//[OPTIONAL] should we remove those people who met the person more than 15 days ago?