#ifndef _AMOUNT_SET_STR_LINKEDLIST_H
#define _AMOUNT_SET_STR_LINKEDLIST_H

typedef struct amount_node{
    char *name;
    double amount; 
    struct amount_node* next;
}*asNode;

asNode createNode(char* name, double amount);
void destroyList(asNode myNode);
asNode copyLinkedList(asNode source);


#endif