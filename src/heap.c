#include "../utils/heap.h"

//========================================HEAP SUPPORTING FUNCS DEFINITION======================
void swap(vertwdist* x, vertwdist* y)
{
    vertwdist tempedge;
    tempedge.a = x->a;
    tempedge.b = x->b;
    tempedge.weight = x->weight;
    tempedge.weight = x->length;

    x->a = y->a;
    x->b = y->b;
    x->weight = y->weight;
    x->length = y->weight;

    y->a = tempedge.a;
    y->b = tempedge.b;
    y->weight = tempedge.weight;
    y->length = tempedge.length;
}
//================================================================================================

//=======================HEAP RELATED FUNCS DEFINITIONS===========================================

//returns true if heap is empty
int isHeapEmpty(heap* hp)
{
    if(hp->numelems == 0){return 1;}
    else{return 0;}
}

//mallocs the heap
heap* createHeap(int size)
{
    heap* p = NULL;
    p = (heap*) malloc(sizeof(heap));
    p->numelems = 0;
    p->capacity = size;
    p->arr = (vertwdist*) malloc(size * sizeof(vertwdist));
    return p;
}

//inserts in heap and adjusts the heap, also take cares about reallocing
void insertInHeap(heap* hp, int a, int b, int weight, int length)
{
    vertwdist e;
    e.a = a;
    e.b = b;
    e.length = length;
    e.weight = weight;
    if((hp->numelems) +2 >= hp->capacity)
    {
        hp->arr = (vertwdist*) realloc(hp->arr, (hp->capacity)*2*sizeof(vertwdist));
        hp->capacity *= 2;
    }
    
    int x = hp->numelems;
    hp->arr[x] = e;
    
    int index = hp->numelems;
    hp->numelems++;

    //now bubbling up
    //this is min heap, chainging into a max heap if reqd try doing here
    while(hp->arr[parent(index)].weight > hp->arr[index].weight && index != 0)
    {
        swap(&(hp->arr[parent(index)]), &(hp->arr[index]));
        index = parent(index);
    }

}

//returns the top element of the heap
vertwdist topOfHeap(heap* hp)
{
    //[DOUBT] should i add an assert() here?
    return hp->arr[0];
}

//pops from the heap and readjusts it
void popFromHeap(heap* hp)
{
    if(isHeapEmpty(hp)){return;}

    hp->arr[0] = hp->arr[(hp->numelems)-1];
    hp->numelems--;
    int maxindex = (hp->numelems)-1;
    int index = 0;
    
    int bestindex;
    
    if(leftchild(index) > maxindex){bestindex = -1;}
    else if(rightchild(index) > maxindex){bestindex = leftchild(index);}
    else
    {
        if(hp->arr[rightchild(index)].weight > hp->arr[leftchild(index)].weight){bestindex = rightchild(index);}
        else{bestindex = leftchild(index);}
    }


    //now sinking down operation
    //change here if making max heap
    while(bestindex != -1 && hp->arr[index].weight > hp->arr[bestindex].weight)
    {
        swap(&(hp->arr[index]), &(hp->arr[bestindex]));
        index = bestindex;
        if(leftchild(index) > maxindex){bestindex = -1;}
        else if(rightchild(index) > maxindex){bestindex = leftchild(index);}
        else
        {
            if(hp->arr[rightchild(index)].weight > hp->arr[leftchild(index)].weight){bestindex = rightchild(index);}
            else{bestindex = leftchild(index);}
        }
    }
    
}