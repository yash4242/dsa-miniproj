//DEPENDENCIES: 
//#pragma once

#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

struct node
{
    int b;
    double weight;
    int length; //or should it be lli?
    struct node* next;
};
typedef struct node node;
typedef node* list;

//=================================FUNC PROTOS==========================================
node* createNode(int, double, int);

void pushFront(list*, int, double, int);

#endif