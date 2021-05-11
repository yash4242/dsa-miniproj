#pragma once
#include "../utils/queue.h"
typedef long long int lli;

void initQueue(queue* qp)
{
    qp->front= NULL;
    qp->back= NULL;
}

//inserts at the back into queue
void queuePushBack(queue* qp, double first, int second)
{
    if(qp->front == NULL && qp->back == NULL)
    {
        qp->front = (nodePair*) malloc(sizeof(nodePair));
        qp->front->first = first;
        qp->front->second = second;
        qp->front->next = NULL;
        qp->back = qp->front;
        return;
    }

    nodePair* npp = NULL;
    npp = (nodePair*) malloc(sizeof(nodePair));
    npp->first = first;
    npp->second = second;
    npp->next = NULL;
    qp->back->next = npp;
    qp->back = npp;
}

//pops the front pair from the queue
void queuePopFront(queue* qp)
{
    if(qp->front== NULL && qp->back == NULL)
    {
        return;
    }
    if(qp->front == qp->back && qp->back != NULL)
    {
        free(qp->back);
        qp->back = NULL;
        qp->front = NULL;
        return;
    }
    nodePair* t = qp->front->next;
    free(qp->front);
    qp->front = t;
}

void queuePopBack(queue* qp)
{
    if(qp->front== NULL && qp->back == NULL)
    {
        return;
    }
    if(qp->front == qp->back && qp->back != NULL)
    {
        free(qp->back);
        qp->back = NULL;
        qp->front = NULL;
        return;
    }
    nodePair* t = qp->front;

    while(t->next->next!=NULL)
    {
        t = t->next;
    }
    free(t->next);
    qp->back = t;    
}

//tells what is at the front of the queue of pairs, needs pair* as arg, in which it writes
pairForQ queueFront(queue* qp)
{
    pairForQ p;
    p.first = qp->front->first;
    p.second = qp->front->second;
    return p;
}

pairForQ queueBack(queue* qp)
{
    pairForQ p;
    p.first = qp->back->first;
    p.second = qp->back->second;
    return p;
}


int queueSize(queue* qp)
{
    if(qp->back== NULL && qp->front == NULL){return 0;}
    if(qp->back == qp->front && qp->front != NULL){return 1;}
    nodePair* trav = qp->front;
    int len = 1;
    while(trav!= qp->back)
    {
        trav = trav->next;
        len++;
    }
    return len;
}

int isQueueEmpty(queue* qp)
{
    if(qp->front == qp->back && qp->back == NULL)
    {return 1;}
    else
    return 0;
}