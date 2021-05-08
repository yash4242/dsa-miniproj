#pragma once
#include <stdlib.h>
//DEPENDENCIES: pair
#include "pair.h"
typedef long long int lli;

struct nodePair
{
    lli first;
    int second;
    struct nodePair* next;
    
};
typedef struct nodePair nodePair;

//internal implementation is by using linklists
struct queue
{
    nodePair* front;
    nodePair* back;
    
};
typedef struct queue queue;

//========================================func protos=======================


void initQueue(queue* qp);
// {
//     qp->front= NULL;
//     qp->back= NULL;
// }


//inserts at the back into queue
void queuePushBack(queue* qp, lli first, int second);
// {
//     if(qp->front == NULL && qp->back == NULL)
//     {
//         qp->front = (nodePair*) malloc(sizeof(nodePair));
//         qp->front->first = first;
//         qp->front->second = second;
//         qp->front->next = NULL;
//         qp->back = qp->front;
//         return;
//     }

//     nodePair* npp = NULL;
//     npp = (nodePair*) malloc(sizeof(nodePair));
//     npp->first = first;
//     npp->second = second;
//     npp->next = NULL;
//     qp->back->next = npp;
//     qp->back = npp;
// }

//pops the front pair from the queue
void queuePopFront(queue* qp);
// {
//     if(qp->front== NULL && qp->back == NULL)
//     {
//         return;
//     }
//     if(qp->front == qp->back && qp->back != NULL)
//     {
//         free(qp->back);
//         qp->back = NULL;
//         qp->front = NULL;
//         return;
//     }
//     nodePair* t = qp->front->next;
//     free(qp->front);
//     qp->front = t;
// }

//tells what is at the front of the queue of pairs, needs pair* as arg, in which it writes
pair queueFront(queue* qp);
// {
//     pp->first = qp->front->first;
//     pp->second = qp->front->second;
// }
pair queueBack(queue* qp);

