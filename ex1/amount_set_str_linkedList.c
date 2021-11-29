#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "amount_set_str_linkedList.h"





asNode createNode(char* name, double amount)
{
    asNode myNode = malloc(sizeof(*myNode));
    if (myNode == NULL)
    {
        return NULL;
    }

    assert(name != NULL);

    int len=strlen(name);
    myNode->name = malloc((sizeof(char)*len)+1);
    if(myNode->name == NULL)
    {
        return NULL;
    }
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
        free(myNode->name);
        free(myNode);
        myNode = nextNode;
    }
    //myNode = NULL;
    
}

asNode copyLinkedList(asNode source)
{
    if(source == NULL)
    {
        return NULL;
    }

    asNode newHead = createNode(source->name,source->amount);
    if(newHead == NULL)
    {
        return NULL;
    }

    source = source->next;
    asNode currentNode = newHead;

    while (source != NULL)
    {   
        currentNode->next = createNode(source->name,source->amount);
        
        if(currentNode->next == NULL)
        {
            return NULL;
        }
        
        source = source->next;
        currentNode = currentNode->next;
    }
    return newHead;
}
