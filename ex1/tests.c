#include "amount_set_str.h"
#include "linkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>




struct AmountSet_t{
    asNode head; 
    asNode iterator;
};


bool createNewAs();
asNode createNode(char* name, double amount);
void destroyList(asNode myNode);

bool destroyNull();
bool destroyAs();

bool copyNull();
bool copyASWithNullList();
bool copyGoodListWithNoIterator();
bool Copy_as_and_change_copy();

bool getSize_of_null_as();
bool getSize_of_empty_as();
bool getSize_of_full_as();
bool getSize_of_as_and_check_iterator_unchanged();

//bool try_contains_with_null();
//bool try_contains_with_full_as();




#define  RUN_TEST_CASE(test_fn) \
{\
    if(test_fn())\
    {\
        printf("%s passed\n" ,#test_fn);\
    }\
    else\
    {\
        printf("%s failed\n" ,#test_fn);\
    }\
}


int main()
{
    RUN_TEST_CASE(createNewAs);
    RUN_TEST_CASE(destroyNull);
    RUN_TEST_CASE(destroyAs);
    RUN_TEST_CASE(copyNull);
    RUN_TEST_CASE(copyASWithNullList);
    RUN_TEST_CASE(copyGoodListWithNoIterator);
    RUN_TEST_CASE(Copy_as_and_change_copy);
    RUN_TEST_CASE(getSize_of_null_as);
    RUN_TEST_CASE(getSize_of_empty_as);
    RUN_TEST_CASE(getSize_of_full_as);
    RUN_TEST_CASE(getSize_of_as_and_check_iterator_unchanged);
    
    printf("check\n");
    return 0;
}



bool createNewAs()
{
    AmountSet newSet = asCreate();
    if(newSet == NULL)
    {
        return false;
    }

    return true;
}



bool destroyNull()
{
    asDestroy(NULL);
    return true;
}

bool destroyAs()
{
    AmountSet newSet = asCreate();
    newSet->head = createNode("abc", 2);
    newSet->iterator = newSet->head;

    asDestroy(newSet);

    return true;
}

bool copyNull()
{
    if(asCopy(NULL) != NULL)
    {
        return false;
    }
    return true;
}

bool copyASWithNullList()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    set1->head = NULL;

    AmountSet copiedSet = asCopy(set1);

    if(copiedSet->head != NULL)
    {
        return false;
    }

    asDestroy(copiedSet);
    asDestroy(set1);
    
    return true;

}

bool copyGoodListWithNoIterator()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", 1.5);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;
    AmountSet copiedSet = asCopy(set1);

    if(copiedSet == NULL)
    {
        return false;
    }

    asNode copied_list = copiedSet->head;

    if(strcmp(copied_list->name, "MAOR") != 0 || copied_list->amount != 1.5)
    {
        return false;
    }
    copied_list = copied_list->next;

    if(strcmp(copied_list->name, "BENJAMIN") != 0 || copied_list->amount != 2.0)
    {
        return false;
    }
    copied_list = copied_list->next;

    if(strcmp(copied_list->name, "ARI") != 0  || copied_list->amount != 0)
    {
        return false;
    }

    asDestroy(copiedSet);
    asDestroy(set1);
    

    return true;
}

bool Copy_as_and_change_copy()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", 1.5);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;
    AmountSet copiedSet = asCopy(set1);

    if(copiedSet == NULL)
    {
        return false;
    }

    copiedSet->head->amount = 12;
    if(set1->head->amount != 1.5)
    {
        return false;
    }

    char* my_string = "YONEZ";
    *(copiedSet->head->name) = *(my_string);
    if(strcmp(set1->head->name, "MAOR") != 0)
    {
        return false;
    }


    asDestroy(copiedSet);
    asDestroy(set1);

    return true;
}

bool getSize_of_null_as()
{
    if(asGetSize(NULL) != -1)
    {
        return false;
    }

    return true;
}

bool getSize_of_empty_as()
{
    AmountSet myset = asCreate();
    assert(myset !=  NULL);

    if(asGetSize(myset) != 0)
    {
        return false;
    }
    asDestroy(myset);

    return true;
}

bool getSize_of_full_as()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", -6.45);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;

    if (asGetSize(set1) != 3)       
    {
        return false;
    }

    asDestroy(set1);

    return true;
    
}

bool getSize_of_as_and_check_iterator_unchanged()
{
        AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", -6.45);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;
    set1->iterator = node2;

    if (asGetSize(set1) != 3)       
    {
        return false;
    }

    if(set1->iterator != node2)
    {
        return false;
    }

    asDestroy(set1);

    return true;
}