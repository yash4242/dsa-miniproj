//DEPENDENCIES: none
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef long long int lli;
#define INF (long long) 1e16


lli min(lli a, lli b){return a<b?a:b;}

struct vertwdist
{
    int a;
    int b;
    int weight;
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
void insertInHeap(heap*, int, int, int);

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