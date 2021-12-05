#include "matamikya_order.h"
#include "matamikya_product.h"
#include "amount_set.h"


ASElement ItemIdCopy(ASElement element)
{
    int* id = (int*) element;//casting

    int* new_item_id = malloc(sizeof(*new_item_id));
    if(new_item_id == NULL)
    {
        return NULL;
    }
    *new_item_id = *id;
    return new_item_id;
}

void ItemIdFree(ASElement element)
{
    free(element);
}

int ItemIdCompare(ASElement element1, ASElement element2)
{
    /**
    int* id1 = malloc(sizeof(*id1));
    int* id2 = malloc(sizeof(*id2));
    assert(id1 != NULL && id2 != NULL);

    *id1 = *(int*) element1;
    *id2 = *(int*) element2;

    return (*id1)-(*id2);
    **/
    return (*(int*)(element1)) - (*(int*)(element2));
}





Order OrderCreate()
{
    Order order = malloc(sizeof(*order));
    if(order == NULL)
    {
        return NULL;
    }
    order->order_id =0;

    order->items = asCreate(ItemIdCopy, ItemIdFree, ItemIdCompare);
    if(order->items == NULL)
    {
        free(order);
        return NULL;
    }
    return order;
}

void OrderDestroy(SetElement element)
{
    // Order order = (Order) element; //casting element into order
    // if(order == NULL)
    // {
    //     return;
    // }

    // asDestroy(order->items);
    // free(order);
    if(element == NULL)
     {
         return;
    }

    asDestroy(((Order)element)->items);
    free(element);
}

SetElement OrderCopy(SetElement element)
{
    Order order = (Order) element;//casting element

    Order new_order = (Order) OrderCreate();
    if(new_order == NULL)
    {
        return NULL;
    }

    new_order->order_id = order->order_id;

    asDestroy(new_order->items);
    new_order->items = asCopy(order->items);
    if(new_order->items == NULL)
    {
        OrderDestroy(new_order);
        return NULL;
    }

    return new_order;
}


int OrderCompare(SetElement element1, SetElement element2)
{
    Order order1 = (Order) element1;
    Order order2 = (Order) element2;

    return (order1->order_id) - (order2->order_id);
}

