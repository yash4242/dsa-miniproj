#include "../utils/linkedlist.h"
#include <stdlib.h>

node* createNode(int b, int w, int length)
{
    node* p = (node*) malloc(sizeof(node));
    p->length = length;
    p->b = b;
    p->weight = w;
    p->next = NULL; 
    return p;
}

void pushFront(list* lp, int b, int w, int length)
{
    if(*(lp) == NULL)
    {*lp = createNode(b, w, length); return;}
    node* t = *lp;
    *lp = createNode(b, w, length);
    (*(lp))->next = t;
}