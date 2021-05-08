#pragma once
#include "../utils/queue.h"
typedef long long int lli;
void initQueue(queue* qp)
{
    qp->front= NULL;
    qp->back= NULL;
}

//inserts at the back into queue
void queuePushBack(queue* qp, lli first, int second)
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

//tells what is at the front of the queue of pairs, needs pair* as arg, in which it writes
pair queueFront(queue* qp)
{
    pair p;
    p.first = qp->front->first;
    p.second = qp->front->second;
    return p;
}

pair queueBack(queue* qp)
{
    pair p;
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
    while(trav!= NULL)
    {
        trav = trav->next;
        len++;
    }
    return len;
}

