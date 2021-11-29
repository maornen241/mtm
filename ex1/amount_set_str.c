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

    asNode iterator = set->head;

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

    asNode iterator = set->head;
    while(strcmp(iterator->name, element) != 0)
    {
        iterator = iterator->next;
    }

    *outAmount = iterator->amount;

    
    return  AS_SUCCESS;

}

AmountSetResult asRegister(AmountSet set, const char* element)
{
    if(set == NULL || element == NULL)
    {
        return AS_NULL_ARGUMENT;
    }

    if(asContains(set,element) == true)
    {
        return AS_ITEM_ALREADY_EXISTS;
    }


    char* copied_element = malloc(strlen(element)*sizeof(char));
    strcpy(copied_element, element); 
    asNode between = createNode(copied_element, 0);
    if(between == NULL)
    {
        return AS_NULL_ARGUMENT;
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





/**AmountSetResult asClear(AmountSet set)
{
    if(set == NULL)
    {
        return AS_NULL_ARGUMENT;
    }
    destroyList(set->head);
    //if((set->head) == NULL) // didnt decide if the check is needed.
    //{
        return AS_SUCCESS;
    //}
    //return AS_OUT_OF_MEMORY; 
}



char* asGetFirst(AmountSet set)
{
    
}*/


















