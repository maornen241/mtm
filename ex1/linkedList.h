#ifndef _AMOUNT_NODE_H
#define _AMOUNT_NODE_H

typedef struct amount_node *asNode;
asNode createNode(char* name, double* amount);
void destroyList(asNode myNode);
asNode copyLinkedList(asNode source);




































#endif