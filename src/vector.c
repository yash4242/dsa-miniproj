#include "../utils/vector.h"

//===========================VECTORINT FUC DEFINITONS==========================
//mallocs a new vectorInt
vectorInt* createVectorInt(int size)
{
    vectorInt *p = NULL;
    p = (vectorInt*) malloc(sizeof(vectorInt));
    p->numelems = 0;
    p->capacity = size;
    p->arr = (int*) malloc(size * sizeof(int));
    return p;
}

//pushes ints into vectorInt
void vectorIntPushBack(vectorInt* vip, int x)
{
    if((vip->numelems) +2 >= vip->capacity)
    {
        vip->arr = (int*) realloc(vip->arr, (vip->capacity)*2*sizeof(int));
        vip->capacity *= 2;
    }
    int n = vip->numelems;
    vip->arr[n] = x;
    vip->numelems++;
}


//===========================VECTORPAIR FUNC PROTOS================================

//mallocs a new vectorPair
vectorPair* createVectorPair(int size)
{
    vectorPair *p = NULL;
    p = (vectorPair*) malloc(sizeof(vectorPair));
    p->numelems = 0;
    p->capacity = size;
    p->arr = (pair*) malloc(size * sizeof(pair));
    return p;
}

//makes a pair of 2 ints and pushes it into vectorPair
void vectorPairPushBack(vectorPair* vpp, int a, int b)
{
    if((vpp->numelems) +2 >= vpp->capacity)
    {
        vpp->arr = (pair*) realloc(vpp->arr, (vpp->capacity)*2*sizeof(pair));
        vpp->capacity *= 2;
    }
    
    pair temp;
    temp.first = a;
    temp.second = b;
    int n = vpp->numelems;
    vpp->arr[n] = temp;
    vpp->numelems++;
}