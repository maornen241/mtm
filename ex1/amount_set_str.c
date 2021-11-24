#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "amount_set_str.h"

typedef struct amount_node{
    char *name;
    int amount;
    struct amount_node* next;
}*asNode;

asNode createNode(char* name, int amount);
void destroyList(asNode myNode);
    



struct AmountSet_t{
    asNode head; 
    asNode iterator;
};

AmountSet asCreate()
{
    AmountSet newAs = malloc(sizeof(*newAs));
    if(newAs == NULL)
    {
        return NULL;
    }

    newAs->head = NULL;
    newAs->iterator = NULL;
    return newAs;
}

void asDestroy(AmountSet set)
{
    if(set == NULL)
    {
        return;
    }

       destroyList(set->head);
       free(set->iterator);
       free(set);
}


AmountSet asCopy(AmountSet set)
{
    if(set == NULL)
    {
        return NULL;
    }
    AmountSet newAs= malloc(sizeof(*newAs));
    if (newAs == NULL)
    {
        return NULL;
    }
    newAs->head = set->head;
    newAs->iterator = set->iterator;
    return newAs;
}


































asNode createNode(char* name, int amount)
{
    asNode myNode = malloc(sizeof(*myNode));
    if (myNode == NULL)
    {
        return NULL;
    }

    assert(name != NULL);

    int len=strlen(name);
    myNode->name = malloc((sizeof(char)*len)+1);
    strcpy(myNode->name,name);
    myNode->amount=amount;
    myNode->next = NULL;

    return myNode;
}

void destroyList(asNode myNode)
{
    while (myNode != NULL)
    {
        asNode nextNode = myNode->next;
        free(myNode);
        myNode = nextNode;
    }
    
}
