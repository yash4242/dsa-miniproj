//DEPENDENCIES: none
#pragma once

struct node
{
    int b;
    int weight;
    int length;
    struct node* next;
};
typedef struct node node;
typedef node* list;

//=================================FUNC PROTOS==========================================
node* createNode(int, int, int);

void pushFront(list*, int, int, int);