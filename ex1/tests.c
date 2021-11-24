#include "amount_set_str.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct amount_node{
    char *name;
    int amount;
    struct amount_node* next;
}*asNode;


struct AmountSet_t{
    asNode head; 
    asNode iterator;
};

bool destroyNull();
bool createNewAs();
asNode createNode(char* name, int amount);
void destroyList(asNode myNode);
bool destroyAs();


bool createNewAs();

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
    RUN_TEST_CASE(destroyNull);
    printf("check");
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