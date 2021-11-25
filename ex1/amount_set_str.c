#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "amount_set_str.h"
#include "linkedList.h"



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
       //free(set->iterator);
       free(set);
}


AmountSet asCopy(AmountSet set)
{
    if(set == NULL)
    {
        return NULL;
    }

    AmountSet newAs = asCreate();
    if (newAs == NULL)
    {
        return NULL;
    }

    newAs->head = copyLinkedList(set->head);
    if(newAs->head == NULL)
    {
        return NULL;
    }
    
    return newAs;
}





































//לעשות קובץ האדר וקובץ סי לנוד ולסט בנפרד??