#ifndef _MATAMIKYA_ORDER_H_
#define _MATAMIKYA_ORDER_H_
#include "amount_set.h"
#include "set.h"

/** Type for representing  Matamikya orders */
struct order_t 
{
    unsigned int order_id;
    AmountSet items;
};

/** Type for representing a singel order */
typedef struct order_t *Order;

/**
 * ItemIdCopy: Creates a copy of target itemId.
 *
 *
 * @param element - Target itemId.
 * @return
 *     NULL if a NULL was sent or a memory allocation failed.
 *     A pointer to int containing the same itemId, otherwise.
 */
ASElement ItemIdCopy(ASElement element);

/**
 * ItemIdFree: Deallocates an existing itemId.
 *
 * @param element - Target itemId to be deallocated. If element is NULL nothing will be done.
 */
void ItemIdFree(ASElement element);

/**
 * ItemIdCompare: identify equal itemId's.
 * compares the two itemIds by their value.
 * 
 * @param element1 - the first itemid to compare
 * @param element2 - the second itemid to compare
 * 
 * @return 
 *     A positive integer if the first element is greater;
 *     0 if they're equal;
 *     A negative integer if the second element is greater.
 */
int ItemIdCompare(ASElement element1, ASElement element2);



/**
 * OrderCreate: Allocates a new empty order.
 *
 * @return
 *     NULL - NULL if allocations failed.
 *     A new order in case of success.
 */
Order OrderCreate();

/**
 * OrderCopy: Creates a copy of target order.
 * copies all items stored in target order, and it's order id.
 *
 *
 * @param element - Target order.
 * 
 * @return
 *     NULL if a NULL was sent or a memory allocation failed.
 *     The copied order, otherwise.
 */
SetElement OrderCopy(SetElement element);

/**
 * OrderDestroy: Deallocates an existing order.
 * dellocating all items in order, and the order itself.
 *
 * @param element - Target order to be deallocated. If element is NULL nothing will be done.
 */
void OrderDestroy(SetElement element);

/**
 * OrderCompare: identify equal orders.
 *  compares the orders id.
 * 
 * @param element1 - the first order to compare
 * @param element2 - the second order to compare
 * 
 * @return 
 *     A positive integer if the first element is greater;
 *     0 if they're equal;
 *     A negative integer if the second element is greater.
 */
int OrderCompare(SetElement element1, SetElement element2);







#endif