//DEPENDENCIES: none
#ifndef __HEAP_H
#define __HEAP_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef long long int lli;
#define INF (long long) 1e16


double min(double a, double b){return a<b?a:b;}

struct vertwdist
{
    int a; //starting node of the edge
    int b; //ending node of the edge
    double weight; //is equal to the dangervalue of the edge that it is leading towards
    int length; //as given in the input initially
};
typedef struct vertwdist vertwdist;


struct heap
{
    int capacity;
    int numelems;
    vertwdist* arr;
};
typedef struct heap heap;

//=======================HEAP CORE FUNC PROTOTYPES==============================

//returns true of the heap is indeed empty
int isHeapEmpty(heap*);

//mallocs the heap
heap* createHeap(int size);

//inserts in the heap and adjusts the heap, also takes care about reallocing
void insertInHeap(heap*, int, int, double, int);

//pops from the heap, returns void
void popFromHeap(heap*);

//returns the vertwdist struct, doesnt pop
vertwdist topOfHeap(heap*);


int leftchild(int x) {return 2*x+1;}
int rightchild(int x){return 2*x +2;}
int parent(int x){return (x-1)/2;}

//===========================HEAP SUPPORTING FUNCS================================

//swaps 2 vertwdist structs
void swap(vertwdist* x, vertwdist* y);

//=================================================================================

#endif