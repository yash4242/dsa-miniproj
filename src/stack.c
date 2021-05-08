#pragma once
#include <stdlib.h>
#include "../utils/stack.h"



stack* createStack(int size)
{
    stack* p = NULL;
    p = (stack*) malloc(sizeof(stack));
    p->topindex = -1;
    p->capacity = size;
    p->arr = (int*) malloc (size* sizeof(int));
    return p;
}

int topOfStack(stack* p)
{
    if(p->topindex == -1){return -1;}
    return p->arr[p->topindex];
}

void pushToStack(stack* p, int x)
{
    if(p->topindex +2 >= p->capacity)
    {p->arr = (int*) realloc(p->arr, 2*sizeof(int)*p->capacity); p->capacity*= 2;}
    
    p->topindex++;
    p->arr[p->topindex] = x;
}

void popFromStack(stack* p)
{
    p->topindex--;
}

int isStackEmpty(stack* p)
{
    if(p->topindex == -1){return 1;}
    else{return 0;}
}