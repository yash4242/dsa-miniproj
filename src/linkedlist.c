#include "../utils/linkedlist.h"
#include <stdlib.h>

node* createNode(int b, int w)
{
    node* p = (node*) malloc(sizeof(node));
    
    p->b = b;
    p->weight = w;
    p->next = NULL; 
    return p;
}

void pushFront(list* lp, int b, int w)
{
    if(*(lp) == NULL)
    {*lp = createNode(b, w); return;}
    node* t = *lp;
    *lp = createNode(b, w);
    (*(lp))->next = t;
}