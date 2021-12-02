#ifndef _MATAMIKYA_ORDER_H_
#define _MATAMIKYA_ORDER_H_
#include "amount_set.h"
#include "set.h"

struct order_t 
{
    unsigned int order_id;
    AmountSet items;//maybe change to be only the id of the products
};

typedef struct order_t *Order;

ASElement ItemIdCopy(ASElement element);
void ItemIdFree(ASElement element);
int ItemIdCompare(ASElement element1, ASElement element2);


Order OrderCreate();
void OrderDestroy(SetElement element);
SetElement OrderCopy(SetElement element);
int OrderCompare(SetElement element1, SetElement element2);






#endif