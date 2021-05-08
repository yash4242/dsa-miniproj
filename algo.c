//#pragma once
#include "src/person.c"
#include "src/city.c"
#include "src/heap.c"
#include "src/linkedlist.c"
#include "src/vector.c"
#include "src/queue.c"
#include "src/stack.c"
#include <stdio.h>
#include <stdlib.h>
typedef long long int lli;

struct journey
{
    lli weight;
    lli length;
    int whichIndexStackIsThePath;
};
typedef struct journey journey;


int cmpfunc(const void* a, const void* b)
{
    journey* x = (journey*) a;
    journey* y = (journey*) b;
    if(x->weight == y->weight)
    {return x->length - y->length;}
    else
    {
        return x->weight - y->weight;
    }
}






//finds the routes, prints the routes, waits for route choice, updates contact lists of traveler and people of intermidiate cities
void algo(int personIndex, int sourceCity, int destCity, int noOfCity, list graph[], city cityArray[], person personArray[])
{
    heap* pq = createHeap(100);
    
    queue queueOfCities[noOfCity+1];
    
    lli cumulativeWeight;
    


    for(int i = 0; i<= noOfCity; i++) initQueue( &(queueOfCities[i]) );

    insertInHeap(pq, sourceCity, sourceCity,0,0);
    
    //DIS DA SHIT 

    while(queueSize(&(queueOfCities[destCity])) < 3)
    {
        vertwdist top = topOfHeap(pq);
        popFromHeap(pq);
        
        //now for all neighbours of that vertext whose inward edge comesout at top, insert them in the heap and
        //insert the weight of the journney till now in the respectve destination cities 
        
        node* trav = graph[top.b];
        while(trav!= NULL)
        {
            cumulativeWeight = top.weight + trav->weight;
            insertInHeap(pq, top.b, trav->b,  cumulativeWeight, trav->length);
            queuePushBack(&(queueOfCities[trav->b]), cumulativeWeight, top.b);
            trav = trav->next;
        }
    }

    //yea now we have dists and and parent cities stored in the queueOfCities array

    journey paths[3];


    stack* sp[3];
    
    //gathering info about 1st shortest path
    sp[0] = createStack(20);
    int currCity = destCity; //the vairable used for backtracking the route
    lli weight1 = queueFront(&(queueOfCities[destCity])).first;
    lli length1=0;
    int parentCity;

    while(currCity != sourceCity)
    {
        pushToStack(sp[0], currCity);
        node* trav = graph[currCity];
        while(trav!=NULL && trav->b != queueFront(&(queueOfCities[currCity])).second)
        {
            trav = trav->next;
        }
        length1 += trav->length;
        parentCity = queueFront(&(queueOfCities[currCity])).second;
        queuePopFront(&(queueOfCities[currCity]));
        currCity = parentCity;
    
    }
    pushToStack(sp[0], sourceCity);
    paths[0].length = length1;
    paths[0].weight = weight1;
    paths[0].whichIndexStackIsThePath = 0;
    //now length1 has the length of 1st shortest path (weightwise)
    //now weight1 has the total weight of the shortest path


    //now doing this for 2nd shortest path (weightwise)
    sp[1] = createStack(20);
    int currCity = destCity; //the vairable used for backtracking the route
    lli weight2 = queueFront(&(queueOfCities[destCity])).first;
    lli length2=0;
    int parentCity;

    while(currCity != sourceCity)
    {
        pushToStack(sp[1], currCity);
        node* trav = graph[currCity];
        while(trav!=NULL && trav->b != queueFront(&(queueOfCities[currCity])).second)
        {
            trav = trav->next;
        }
        length2 += trav->length;
        parentCity = queueFront(&(queueOfCities[currCity])).second;
        queuePopFront(&(queueOfCities[currCity]));
        currCity = parentCity;
    
    }
    pushToStack(sp[1], sourceCity);
    paths[1].length = length2;
    paths[1].weight = weight2;
    paths[1].whichIndexStackIsThePath = 1;
    //now length2 has the length of 2nd shortest path (weightwise)
    //now weight2 has the total weight of the 2nd shortest path (weightwise)

    //now doing this for 3rd shortest path (weightwise)
    sp[2] = createStack(20);
    int currCity = destCity; //the vairable used for backtracking the route
    lli weight3 = queueFront(&(queueOfCities[destCity])).first;
    lli length3=0;
    int parentCity;

    while(currCity != sourceCity)
    {
        pushToStack(sp[2], currCity);
        node* trav = graph[currCity];
        while(trav!=NULL && trav->b != queueFront(&(queueOfCities[currCity])).second)
        {
            trav = trav->next;
        }
        length3 += trav->length;
        parentCity = queueFront(&(queueOfCities[currCity])).second;
        queuePopFront(&(queueOfCities[currCity]));
        currCity = parentCity;
    
    }
    pushToStack(sp[2], sourceCity);
    paths[2].length = length3;
    paths[2].weight = weight3;
    paths[2].whichIndexStackIsThePath = 2;
    //now length2 has the length of 2nd shortest path (weightwise)
    //now weight2 has the total weight of the 2nd shortest path (weightwise)

    //now qsort()
    qsort(paths, 3, sizeof(journey), cmpfunc);

    //paths have been sorted

    printf("here are the paths:\n");
    for(int y = 0; y<3; y++)
    {
        printf("%d. ", y+1);
        int idx = paths[y].whichIndexStackIsThePath;
        for(int i = sp[idx]->topindex; i<=0; i--)
            printf("%d ", sp[idx]->arr[i]);
        
        printf(" Sum of Danger values is %lld and path length is %lld", paths[y].weight, paths[y].length);
        printf("\n");
    }

    int input;
    printf("which one do you choose, enter -1 to quit journey\n");
    scanf("%d", &input);

    if(input == -1){return;}

    




    



    

    
    

}