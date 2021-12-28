#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "amount_set_str.h"
#include "amount_set_str_linkedList.h"

#define UNDEFINED_STATE NULL


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
       free(set);
}


AmountSet asCopy(AmountSet set)
{
    if(set == NULL)
    {
        return NULL;
    }

    AmountSet new_as = asCreate();
    if (new_as == NULL)
    {
        return NULL;
    }

    new_as->head = copyLinkedList(set->head);
    new_as->iterator = UNDEFINED_STATE;
    set->iterator = UNDEFINED_STATE;

    
    return new_as;
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

    asNode internal_iterator = set->head;

    while (internal_iterator != NULL)
    {
        char* current_name = internal_iterator->name;
        assert(current_name != NULL);

        if(strcmp(current_name,element) == 0)
        {
            return true;
        }

        internal_iterator = internal_iterator->next;
    }

    return false;
}

AmountSetResult asGetAmount(AmountSet set, const char* element, double* outAmount)
{
    if(set == NULL || element == NULL || outAmount == NULL)
    {
        return AS_NULL_ARGUMENT;
    }

    if((asContains(set, element)) == false)
    {
        return AS_ITEM_DOES_NOT_EXIST;
    }

    asNode internal_iterator = set->head;
    while(strcmp(internal_iterator->name, element) != 0)
    {
        internal_iterator = internal_iterator->next;
    }

    *outAmount = internal_iterator->amount;

    
    return  AS_SUCCESS;

}

AmountSetResult asRegister(AmountSet set, const char* element)
{
    if(set == NULL || element == NULL)
    {
        return AS_NULL_ARGUMENT;
    }
    set->iterator = UNDEFINED_STATE;

    if(asContains(set,element) == true)
    {
        return AS_ITEM_ALREADY_EXISTS;
    }


    char* copied_element = (char*) malloc((strlen(element)*sizeof(char))+1);
    if(copied_element == NULL)
    {
        return AS_OUT_OF_MEMORY;
    }

    strcpy(copied_element, element); 
    asNode between = createNode(copied_element, 0);
    free(copied_element);
    if(between == NULL)
    {
        free(copied_element);
        return AS_OUT_OF_MEMORY;
    }

    //if the linked list is empty
    if(set->head == NULL)
    {
        set->head = between;
        return AS_SUCCESS;
    }

    //if element is the smallest one
    if((strcmp(element,set->head->name) < 0))
    {
        between->next = set->head;
        set->head = between;
        return AS_SUCCESS;
    }


    //otherwise element should be somewhere in th middle/last
    asNode previous = set->head;
    asNode after = previous->next;

    while(after != NULL && strcmp(element,after->name) > 0)
    {
        previous = after;
        after = previous->next;
    }

    previous->next = between;
    between->next = after;
    return AS_SUCCESS;
    
}


AmountSetResult asChangeAmount(AmountSet set, const char* element, double amount)
{
    if(set == NULL || element == NULL)
    {
        return AS_NULL_ARGUMENT;
    }

    if(asContains(set, element) == false)
    {
        return AS_ITEM_DOES_NOT_EXIST;
    }

    asNode current_node = set->head;
    while (strcmp(current_node->name, element) != 0)
    {
        current_node = current_node->next;
    }

    if((current_node->amount) + amount < 0)
    {
        return AS_INSUFFICIENT_AMOUNT;
    }

    (current_node->amount) += amount;
    return  AS_SUCCESS;
    
}


 
AmountSetResult asDelete(AmountSet set, const char* element)
{
    if(set == NULL || element == NULL)
    {
        return AS_NULL_ARGUMENT;
    }
    set->iterator = UNDEFINED_STATE;
    
    if(asContains(set, element) == false)
    {
        return AS_ITEM_DOES_NOT_EXIST;
    }

    if (strcmp(set->head->name, element) == 0)
    {
        asNode temp = set->head;
        set->head = set->head->next;
        free(temp->name);
        free(temp);
        return AS_SUCCESS;
    }
    

    asNode current_node = set->head;
    asNode previous_node;
    do 
    {
        previous_node = current_node; 
        current_node = current_node->next;
    }while(current_node != NULL && (strcmp(current_node->name, element) != 0));

    previous_node->next = current_node->next;
    free(current_node->name);
    free(current_node);
    return AS_SUCCESS;
    
}





AmountSetResult asClear(AmountSet set)
{
    if(set == NULL)
    {
        return AS_NULL_ARGUMENT;
    }
    set->iterator = UNDEFINED_STATE;

    destroyList(set->head);
    set->head = NULL;
    return AS_SUCCESS; 
}


char* asGetFirst(AmountSet set)
{
    if(set == NULL || set->head == NULL)
    {
        return NULL;
    }

    set->iterator = set->head;
    return set->iterator->name; 
}

char* asGetNext(AmountSet set)
{
    if(set == NULL || set->head == NULL
        || set->iterator == UNDEFINED_STATE || set->iterator->next == NULL)
    {
        return NULL;
    }

    set->iterator = set->iterator->next;
    return set->iterator->name; 
}



















