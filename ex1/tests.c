#include "amount_set_str.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct amount_node{
    char *name;
    double amount;
    struct amount_node* next;
}*asNode;


struct AmountSet_t{
    asNode head; 
    asNode iterator;
};

bool destroyNull();
bool createNewAs();
asNode createNode(char* name, double* amount);
void destroyList(asNode myNode);
bool destroyAs();
bool copyNull();
bool copyGoodList();


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
    RUN_TEST_CASE(copyGoodList);
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
    double y = 2.0;
    AmountSet newSet = asCreate();
    newSet->head = createNode("abc",&y );
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

bool copyGoodList()
{
    double x=1.5, y=2.5, z= 3.5;
    asNode node1 = createNode("MAOR", &x);
    asNode node2 = createNode("benyamin",&y);
    asNode node3 = createNode("ari",&z);
    node1->next = node2;
    node2->next = node3;
    
    AmountSet set1 = asCreate();
    set1->head = node1;
    assert(set1 != NULL);

    /**set1->head = createNode("MAOR", 1.5);
    asNode listi = set1->head;
    listi->next = createNode("benyamin",2.5);
    listi = listi->next;
    listi->next = createNode("ari",3.5);*/

    AmountSet copiedSet=asCopy(set1);
    asNode list2 = copiedSet->head;
    while(list2 != NULL)
    {
        printf("node name is: %s, node amount is %lf.\n",list2->name,list2->amount);
        list2 = list2->next;
    }
    return  true;
     


}