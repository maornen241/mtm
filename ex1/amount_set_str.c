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

    //im pretty sure this is unnecessary
    //I think we should just return As with NULL as head
    /**
    if(newAs->head == NULL)
    {
        return NULL;
    }
    **/
    
    return newAs;
}


int asGetSize(AmountSet set)
{
    if(set == NULL)
    {
        return -1;
    }

    asNode initial_iterator_value = set->iterator;

    set->iterator = set->head;
    asNode iterator = set->iterator;

    int counter = 0;
    while (iterator != NULL)
    {
        counter++;
        iterator = iterator->next;
    }
    
    set->iterator = initial_iterator_value;

    
    return counter;
}


bool asContains(AmountSet set, const char* element)
{
    if(set == NULL || element == NULL)
    {
        return false;
    }

    asNode initial_iterator_value = set->iterator;

    set->iterator = set->head;
    asNode iterator = set->iterator;

    while (iterator != NULL)
    {
        char* current_name = iterator->name;
        assert(current_name != NULL);

        if(strcmp(current_name,element) == 0)
        {
            return true;
        }

        iterator = iterator->next;
    }
    
    set->iterator = initial_iterator_value;
    return false;
}




































//לעשות קובץ האדר וקובץ סי לנוד ולסט בנפרד??