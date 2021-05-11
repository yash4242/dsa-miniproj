#pragma once
//#include "src/person.c"
#include "src/comb.c"
#include "src/heap.c"
#include "src/linkedlist.c"
#include "src/vector.c"
#include "src/queue.c"
#include "src/stack.c"
#include <stdio.h>
#include <stdlib.h>
typedef long long int lli;
#define EPS (double) 1e-4
struct journey
{
    double weight;
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

//finds the routes, prints the routes, waits for route choice, transefers traveler and updates contact lists of traveler and people of intermidiate cities
void algo(int personIndex, int sourceCity, int destCity, int noOfCity, list graph[], city cityArray[], person personArray[], int noOfPerson)
{
    heap* pq = createHeap(100);
    
    queue queueOfCities[noOfCity+1];
    
    double cumulativeWeight;
    


    for(int i = 0; i<= noOfCity; i++) initQueue( &(queueOfCities[i]) );

    insertInHeap(pq, sourceCity, sourceCity,0.0,0);
    
    //actual algo

    do
    {
        vertwdist top = topOfHeap(pq);
        printf("\n\ncontents of heap\n");
        for(int i = 0; i< pq->numelems; i++)
        {
            printf("%lf  %d  %d\n", pq->arr[i].weight, pq->arr[i].a, pq->arr[i].b);
        }
        printf("\n\n");
        printf("now examining vertex %lf  %d  %d\n", top.weight, top.a, top.b);
        popFromHeap(pq);


        
        //now for all neighbours of that vertext whose inward edge comesout at top, insert them in the heap and
        //insert the weight of the journney till now in the respectve destination cities 
        
        node* trav = graph[top.b];
        while(trav!= NULL)
        {
            if(top.a == trav->b){/*printf("was on %d, saw %d. rejecting edge from %d to %d\n", top.b, trav->b, trav->b, top.b);*/ trav = trav->next;  continue;}
            cumulativeWeight = top.weight + (cityArray[trav->b]).dangerValue;
            printf("inserted in heap: %lf %d %d\n", cumulativeWeight, top.b, trav->b);
            insertInHeap(pq, top.b, trav->b,  cumulativeWeight, trav->length);
            
            queuePushBack(&(queueOfCities[trav->b]), cumulativeWeight, top.b);
            trav = trav->next;
            //printf("cumulativeWeight is %lf\n", cumulativeWeight);
            cumulativeWeight = 0;
        }
        //printf("inserting from %d done, ab toppop ki bari\n", top.b);
    }while(queueSize(&(queueOfCities[destCity])) <= 3);

    //yea now we have dists and and parent cities stored in the queueOfCities array

    journey paths[3];

    paths[0].weight = 100000000;
    paths[1].weight = 100000000;
    paths[2].weight = 100000000;

    paths[0].length = 100000000;
    paths[1].length = 100000000;
    paths[2].length = 100000000;

    paths[0].whichIndexStackIsThePath =0;
    paths[1].whichIndexStackIsThePath = 1;
    paths[2].whichIndexStackIsThePath = 2;

    stack* sp[3];
    
    //gathering info about 1st shortest path
    sp[0] = createStack(20);
    sp[1] = createStack(20);
    sp[2] = createStack(20);
int flag = 1;//new
int pathsCovered = 0;
while(isQueueEmpty(&queueOfCities[destCity]) != 1 && pathsCovered < 3)
{
    int currCity = destCity; //the vairable used for backtracking the route
    paths[pathsCovered].weight = queueFront(&(queueOfCities[destCity])).first;
    paths[pathsCovered].length = 0;
    int parentCity;
//////////////
    while(1)//no we need other breaking condition maybe?
    {
        pushToStack(sp[pathsCovered], currCity);
        //node* trav = graph[currCity];

                    // //edgelength finding
                    // if(isQueueEmpty(&(queueOfCities[currCity]))==1){printf("path could not be found\n"); return;}
                    // while(trav!=NULL && trav->b != queueFront(&(queueOfCities[currCity])).second)
                    // {
                    //     trav = trav->next;
                    // }
                    // if(trav == NULL)
                    // {printf("error at line %d of algo.c, quitting func\n", __LINE__);return;}
                    // paths[pathsCovered].length += (lli) trav->length;

        if(isQueueEmpty(&queueOfCities[currCity]) == 1){printf("wouldve segfaulted on %d in algo.c\n", __LINE__); return;}
        parentCity = queueFront(&(queueOfCities[currCity])).second;
        double aim = queueFront(&queueOfCities[currCity]).first - cityArray[currCity].dangerValue;
       

       // printf("reached line %d in algo.c\n", __LINE__);

        
        if(abs(aim - 0) <EPS) {queuePopFront(&queueOfCities[currCity]); break;} 
        
        if(isQueueEmpty(&queueOfCities[parentCity]) == 1){printf("wouldve segfaulted on %d in algo.c\n", __LINE__); return;}
        if(queueFront(&queueOfCities[parentCity]).first != aim)
        {   
            queuePopFront(&queueOfCities[currCity]);
            printf("This path covered came back to city %d while already covering it earlier, so not much use.\n", parentCity);
            paths[pathsCovered].weight = 0; 
            paths[pathsCovered].length = 0;
            clearStack(sp[pathsCovered]);
            currCity = destCity;
            pathsCovered--; //new
            
            flag = 0;//new
            break;//new
            // if(isQueueEmpty(&queueOfCities[destCity]) == 1){printf("wouldve segfaulted on line %d of algo.c\n", __LINE__); return;}
            // paths[pathsCovered].weight = queueFront(&(queueOfCities[destCity])).first;
            //continue;
        }

          queuePopFront(&(queueOfCities[currCity]));


        currCity = parentCity;

        //printf("is this inf loop on line %d of algo.c?\n", __LINE__);
    }
    

    ////////
    if(flag != 0)//new
        pushToStack(sp[pathsCovered], sourceCity);
    pathsCovered++;
    flag = 1;//new
    //now length1 has the length of 1st shortest path (weightwise)
    //now weight1 has the total weight of the shortest path
}

    qsort(paths, 3, sizeof(journey), cmpfunc);

    //paths have been sorted

    if(isStackEmpty(sp[0]) == 1){printf("stack is empty line %d in algo.c nothing would print", __LINE__);}
    printf("here are the paths:\n");
    for(int y = 0; y<3; y++)
    {
        printf("%d. ", y+1);
        int idx = paths[y].whichIndexStackIsThePath;
        //printf("at line %d in algo.c, idx is %d\n", __LINE__ , idx);
        //printf("sp[idx]->topindex = %d\n", sp[idx]->topindex);
        for(int i = sp[idx]->topindex; i>=0; i--)
        {   //printf("path print kiya? line %d in algo.c", __LINE__);
            printf(" go to %d ->   ", sp[idx]->arr[i]);
        
        }
        
        printf("\nSum of Danger values is %lf and path length is %lld", paths[y].weight, paths[y].length);
        printf("\n");
    }

    int input;
    printf("which one do you choose, enter -1 to quit journey\n");
    scanf("%d", &input);

    if(input == -1){return;}

    int curr, nxt;
    curr = sourceCity;
    stack* s = sp[paths[input-1].whichIndexStackIsThePath];
    popFromStack(s);

    while(isStackEmpty(s) != 1)
    {
        nxt = topOfStack(s);
        popFromStack(s);
        transferPerson(personIndex, curr, nxt, personArray, cityArray, graph, noOfPerson);
        curr = nxt;
    }

    //printf("person %d transferred from city %d to %d\n", personIndex, sourceCity, destCity);    

}