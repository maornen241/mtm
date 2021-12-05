#include "matamikya_print.h"
#include "matamikya.h"
#include "amount_set.h"
#include "set.h"
#include "matamikya_product.h"
#include "matamikya_order.h"
#include "list.h"
#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


static bool is_amount_compatible(const double amount, const MatamikyaAmountType amountType);
static bool is_int_amount_valid(double amount);
static bool is_half_int_amount_valid(double amount);
static Product getProduct_from_id(AmountSet inventory, unsigned int id);
static Order get_order_from_id(Set orders, unsigned int id);

//according to a given order decreases amount of relevant products in warehouse
//and increases their income accordingly
//if the order contains some product with amount larger then the amount existing in the warehouse, returns MATAMIKYA_INSUFFICENT_AMOUNT
static MatamikyaResult modifying_inventory_according_to_order(Matamikya matamikya, Order order_to_ship);

#define ALLOWED_ERROR 0.001
#define HALF_ERROR 0.5
#define ORDER_ERROR 0


#define ABS(x) ((x) >= 0) ? (x) : (-x)

#define IS_LETTER(mychar)\
        ((((mychar) >= 'A') && (mychar) <= 'Z') || (((mychar) >= 'a') && (mychar) <= 'z'))

 #define IS_DIGIT(mychar)\
         ((mychar) >= '0' && (mychar) <= '9')



struct Matamikya_t
{
    AmountSet inventory;
    Set orders;
};

Matamikya matamikyaCreate()
{
    Matamikya new_warehouse = (Matamikya) malloc(sizeof(*new_warehouse));
    if(new_warehouse == NULL)
    {
        return NULL;
    }

    new_warehouse->inventory = asCreate(ProductCopy, ProductFree, ProductCompare);
    if(new_warehouse->inventory == NULL)
    {
        free(new_warehouse);
        return NULL;
    }
    
    new_warehouse->orders = setCreate(OrderCopy, OrderDestroy, OrderCompare);
    if(new_warehouse->orders == NULL) 
    {
        asDestroy(new_warehouse->inventory);
        free(new_warehouse);
        return NULL;
    }

    return  new_warehouse;
}

void matamikyaDestroy(Matamikya matamikya)
{
    if(matamikya == NULL)
    {
        return;
    }

    asDestroy(matamikya->inventory);
    setDestroy(matamikya->orders);
    free(matamikya);
}





MatamikyaResult mtmNewProduct(Matamikya matamikya, const unsigned int id, const char *name,
                              const double amount, const MatamikyaAmountType amountType,
                              const MtmProductData customData, MtmCopyData copyData,
                              MtmFreeData freeData, MtmGetProductPrice prodPrice)

{
    if(matamikya == NULL || name == NULL || customData == NULL  
        || freeData == NULL || copyData == NULL || prodPrice == NULL)
       {
           return MATAMIKYA_NULL_ARGUMENT;
       }

    bool is_name_not_valid = (strcmp(name, "") == 0 || (!IS_LETTER((name[0])) && !IS_DIGIT((name[0]))));
    if(is_name_not_valid)
    {
        return MATAMIKYA_INVALID_NAME;
    }

    if(amount < 0 || !is_amount_compatible(amount, amountType))
    {
        return MATAMIKYA_INVALID_AMOUNT;
    }

    char* copied_name = malloc((sizeof(char)*strlen(name))+1);
    if(copied_name == NULL)
    {
         return MATAMIKYA_OUT_OF_MEMORY;
    }
    strcpy(copied_name, name);

    Product new_product = ProductCreate(id, copied_name, amountType, customData,
                                 copyData, freeData, prodPrice);
    
    free(copied_name);


    if(new_product == NULL)
    {
        return MATAMIKYA_OUT_OF_MEMORY;
    }

    if(matamikya->inventory == NULL)
    {
        ProductFree(new_product);
        return MATAMIKYA_NULL_ARGUMENT;
    }
    
    AmountSetResult register_result =  asRegister(matamikya->inventory, new_product);
    Product product_in_set = getProduct_from_id(matamikya->inventory, id);
    assert(product_in_set != NULL);

    asChangeAmount(matamikya->inventory, product_in_set, amount);
    //asChangeAmount(matamikya->inventory, new_product, amount);
    ProductFree(new_product);// asRegister copies the new_product, so we need to delete the origin

    if(register_result == AS_ITEM_ALREADY_EXISTS)
    {
         return MATAMIKYA_PRODUCT_ALREADY_EXIST;
    }

    if(register_result ==  AS_SUCCESS)
    {
        return MATAMIKYA_SUCCESS;
    }
    return MATAMIKYA_SUCCESS;
    

}



MatamikyaResult mtmChangeProductAmount(Matamikya matamikya, const unsigned int id, const double amount)
{
    if(matamikya == NULL || matamikya->inventory == NULL)
    {
        return MATAMIKYA_NULL_ARGUMENT;
    }

    Product product_to_change = getProduct_from_id(matamikya->inventory, id);
    if(product_to_change == NULL)
    {
        return MATAMIKYA_PRODUCT_NOT_EXIST;
    }

    if(!is_amount_compatible(amount, product_to_change->amount_type))
    {
        return MATAMIKYA_INVALID_AMOUNT;
    }

    if(asChangeAmount(matamikya->inventory, product_to_change, amount) ==  AS_INSUFFICIENT_AMOUNT)
    {
        return MATAMIKYA_INSUFFICIENT_AMOUNT;
    }
    return MATAMIKYA_SUCCESS;
    
}




 
MatamikyaResult mtmClearProduct(Matamikya matamikya, const unsigned int id)
{
    if(matamikya == NULL || matamikya->inventory == NULL)
    {
        return MATAMIKYA_NULL_ARGUMENT;
    }

    Product product_to_clear = getProduct_from_id(matamikya->inventory, id);
    if(product_to_clear == NULL)
    {
        return MATAMIKYA_PRODUCT_NOT_EXIST;
    }
    //erasing product from inventory
    asDelete(matamikya->inventory, product_to_clear);

    if(matamikya->orders == NULL )
    {
        return MATAMIKYA_SUCCESS;
    }

    SET_FOREACH(Order,current_order,matamikya->orders)
    {
        unsigned int copied_id = id;
        unsigned int* ptr_copied_id = &copied_id;
        asDelete(current_order->items, ptr_copied_id);
    }

    return MATAMIKYA_SUCCESS;

}


unsigned int mtmCreateNewOrder(Matamikya matamikya)
{
    if(matamikya == NULL || matamikya->orders ==  NULL)
    {
        return ORDER_ERROR;
    }

    unsigned int max_id = 0;
    SET_FOREACH(Order, current_order, matamikya->orders)
    {
        if(current_order->order_id >= max_id)
        {
            max_id = current_order->order_id; 
        }
    }
    unsigned int new_id = (max_id+1);

    Order new_order = OrderCreate();
    if(new_order == NULL)
    {
        return ORDER_ERROR;
    }
    new_order->order_id = new_id;

    SetResult result = setAdd(matamikya->orders,new_order);
    OrderDestroy(new_order);

    if(result != SET_SUCCESS)
    {
        
        return ORDER_ERROR;
    }

    return new_id;

    
}




MatamikyaResult mtmChangeProductAmountInOrder(Matamikya matamikya, const unsigned int orderId,
                                     const unsigned int productId, const double amount)

{
    if(matamikya == NULL || matamikya->orders == NULL)
    {
        return  MATAMIKYA_NULL_ARGUMENT;
    }

   
    Order order_to_change = get_order_from_id(matamikya->orders,  orderId);

    //no such order
    if(order_to_change == NULL)
    {
        return MATAMIKYA_ORDER_NOT_EXIST; 
    }

    Product product_in_inventory = getProduct_from_id(matamikya->inventory, productId);

    //no such product in warehouse
    if(product_in_inventory == NULL)
    {
        return MATAMIKYA_PRODUCT_NOT_EXIST;
    }

    if(!is_amount_compatible(amount, product_in_inventory->amount_type))
    {
        return MATAMIKYA_INVALID_AMOUNT;
    }

    unsigned int copied_productId = productId;
    unsigned int* ptr_copied_productId = &copied_productId; //productId is const so we need to copy it

    double current_item_amount;
    AmountSetResult get_amount_result  = 
                asGetAmount(order_to_change->items, ptr_copied_productId, &current_item_amount);

    //no item in order
    if( get_amount_result == AS_ITEM_DOES_NOT_EXIST )
    {
        if(amount <= 0)
        {
            return MATAMIKYA_SUCCESS;
        }
        
        // if amount positive add item
        AmountSetResult register_result = asRegister(order_to_change->items, ptr_copied_productId);
        AmountSetResult change_result = asChangeAmount(order_to_change->items, ptr_copied_productId, amount);
        if(register_result == AS_SUCCESS && change_result == AS_SUCCESS)
        {
            return MATAMIKYA_SUCCESS;
        }
       
    }
    
        /*
        if we got here item exits in order
        */

        if(current_item_amount + amount <= 0)
        {
            if( AS_SUCCESS == asDelete(order_to_change->items, ptr_copied_productId))
            {
                return MATAMIKYA_SUCCESS;
            }
        }
        
       
        else
        {
           if(AS_SUCCESS ==  asChangeAmount(order_to_change->items, ptr_copied_productId, amount))
           {
           return MATAMIKYA_SUCCESS;
           }
        }
        return AS_SUCCESS;
}


MatamikyaResult mtmShipOrder(Matamikya matamikya, const unsigned int orderId)
{
    if(matamikya == NULL || matamikya->orders == NULL || matamikya->inventory == NULL)
    {
        return MATAMIKYA_NULL_ARGUMENT;
    }

    Order order_to_ship = get_order_from_id(matamikya->orders,  orderId);
    //no such order
    if(order_to_ship == NULL)
    {
        return MATAMIKYA_ORDER_NOT_EXIST; 
    }

    //changing amount of all products containd in order and increase profit
    MatamikyaResult ship_result = modifying_inventory_according_to_order(matamikya, order_to_ship);
    if(ship_result != MATAMIKYA_SUCCESS)
    {
        return ship_result;
    }

    
    return mtmCancelOrder(matamikya ,orderId);
}



MatamikyaResult mtmCancelOrder(Matamikya matamikya, const unsigned int orderId)
{
    if(matamikya == NULL)
    {
        return MATAMIKYA_NULL_ARGUMENT;
    }

    if(matamikya->orders == NULL)
    {
        return MATAMIKYA_ORDER_NOT_EXIST;
    }

    Order order_to_cancel =  get_order_from_id(matamikya->orders, orderId);
    if(order_to_cancel == NULL)
    {
        return MATAMIKYA_ORDER_NOT_EXIST;
    }

    setRemove(matamikya->orders, order_to_cancel);
    return MATAMIKYA_SUCCESS;

}


MatamikyaResult mtmPrintInventory(Matamikya matamikya, FILE *output)
{
    if(matamikya == NULL || matamikya->inventory == NULL || output == NULL)
    {
        return MATAMIKYA_NULL_ARGUMENT;
    }

    fprintf(output, "Inventory Status:\n");
    
    AS_FOREACH(Product, current_product, matamikya->inventory)
    { 
        double product_amount = 0;

       AmountSetResult result = asGetAmount(matamikya->inventory, current_product, &product_amount);
       result++;

        double product_price_per_unit = (current_product->get_product_price)(current_product->custom_data, 1);

        mtmPrintProductDetails(current_product->name, current_product->product_id, product_amount, product_price_per_unit, output);
    }
    return MATAMIKYA_SUCCESS;

}


/**
 * matamikyaPrintOrder: print a summary of an order from a Matamikya warehouse,
 * as explained in the *.pdf
 *
 * The printout includes the total price of the order.
 *
 * @param matamikya - the Matamikya warehouse containing the order.
 * @param orderId - id of the order in matamikya.
 * @param output - an open, writable output stream, to which the order is printed.
 * @return
 *     MATAMIKYA_NULL_ARGUMENT - if a NULL argument is passed.
 *     MATAMIKYA_ORDER_NOT_EXIST - if matamikya does not contain an order with
 *         the given orderId.
 *     MATAMIKYA_SUCCESS - if printed successfully.
 */
MatamikyaResult mtmPrintOrder(Matamikya matamikya, const unsigned int orderId, FILE *output)
{
    if(matamikya == NULL || matamikya->orders == NULL || output == NULL)
    {
        return MATAMIKYA_NULL_ARGUMENT;       
    }

    Order order_to_print = get_order_from_id(matamikya->orders, orderId);
    if(order_to_print == NULL)
    {
        return MATAMIKYA_ORDER_NOT_EXIST;
    }

    mtmPrintOrderHeading(orderId, output);

    double total_price = 0;
    AS_FOREACH(int* , current_item_id ,order_to_print->items)
    { 
        double item_amount = 0;
        asGetAmount( order_to_print->items, current_item_id, &item_amount);

        Product current_product = getProduct_from_id(matamikya->inventory, *current_item_id);
        assert(current_product != NULL);

        double product_price = (current_product->get_product_price)(current_product->custom_data, item_amount);
        total_price += product_price;

        mtmPrintProductDetails(current_product->name, *current_item_id , item_amount, product_price, output);
    }

    mtmPrintOrderSummary(total_price, output);
    return MATAMIKYA_SUCCESS;

}


/**
 * mtmPrintBestSelling: print the best selling products of a Matamikya
 * warehouse, as explained in the *.pdf.
 *
 * @param matamikya - a Matamikya warehouse.
 * @param output - an open, writable output stream, to which the order is printed.
 * @return
 *     MATAMIKYA_NULL_ARGUMENT - if a NULL argument is passed.
 *     MATAMIKYA_SUCCESS - if printed successfully.
 */
MatamikyaResult mtmPrintBestSelling(Matamikya matamikya, FILE *output)
{
    if(matamikya == NULL || matamikya->inventory == NULL || output == NULL)
    {
        return MATAMIKYA_NULL_ARGUMENT;
    }

    fprintf(output,"Best Selling Product:\n");
    
    double max_profit = 0;    

    AS_FOREACH(Product, current_product, matamikya->inventory)
    {   
        if(current_product->income >= max_profit)
        {
            max_profit = current_product->income;
        }
    }

    //the warehouse has no profits
    if(max_profit == 0)
    {
        fprintf(output, "none\n");
        return MATAMIKYA_SUCCESS;
    }

    AS_FOREACH(Product, current_product, matamikya->inventory)
    {   
        if(current_product->income == max_profit)
        {
            mtmPrintIncomeLine(current_product->name, current_product->product_id, max_profit, output);
        }
    }
    return MATAMIKYA_SUCCESS;
    

}









































































static bool is_amount_compatible(const double amount, const MatamikyaAmountType amountType)
{
    if(amountType == MATAMIKYA_INTEGER_AMOUNT)
    {
        return is_int_amount_valid(amount);
    }

    if(amountType == MATAMIKYA_HALF_INTEGER_AMOUNT)
    {
        return is_half_int_amount_valid(amount);
    }

    return true;
}


static bool is_int_amount_valid(double amount)
{
    int rounded_amount = round(amount);
    double diff = rounded_amount - amount;
    double abs_diff = ABS((diff));

    return (abs_diff <= ALLOWED_ERROR);
}
    

static bool is_half_int_amount_valid(double amount)
{
    return (is_int_amount_valid(amount) || is_int_amount_valid(amount+0.5));

    
}


//returns pointer (not a copy) to a product with a given id from a given inventory
//if inventory has no such product, returns NULL
//if NULL was given in the parameter inventory or inventory is NULL returns NULL
static Product getProduct_from_id(AmountSet inventory, unsigned int id)
{
    if(inventory == NULL)
    {
        return NULL;
    }

    Product product = NULL;
    AS_FOREACH(Product, current_product, inventory)
    {
        if(current_product->product_id == id)
        {
           product = current_product;
           break;
        }
    }
    return product;
}


//returns pointer (not a copy) to order with a given id from a given orders set
//if orders has no such order, returns NULL
//if NULL was given in the parameter orders  returns NULL
static Order get_order_from_id(Set orders, unsigned int id)
{
    if(orders == NULL)
    {
        return NULL;
    }

    Order order = NULL;
    SET_FOREACH(Order, current_order, orders)
    {
        if(current_order->order_id == id)
        {
           order = current_order;
           break;
        }
    }
    return order;
}



static MatamikyaResult modifying_inventory_according_to_order(Matamikya matamikya, Order order_to_ship )
{
    if(matamikya == NULL || order_to_ship == NULL)
    {
        return MATAMIKYA_NULL_ARGUMENT;
    }
    
    AS_FOREACH(int*, ptr_current_item_id, order_to_ship->items)
    {
        /*
        changing product's amount in inventory
        */
        Product current_product  = getProduct_from_id(matamikya->inventory,  *ptr_current_item_id);
        if(current_product == NULL)
        {
            return MATAMIKYA_PRODUCT_NOT_EXIST;
        }

        double  product_amount_in_order = 0;
        asGetAmount(order_to_ship->items , ptr_current_item_id, &product_amount_in_order);

        if(asChangeAmount(matamikya->inventory, current_product, product_amount_in_order) == AS_INSUFFICIENT_AMOUNT)
        {
            return MATAMIKYA_INSUFFICIENT_AMOUNT;
        }

        /*
        changing product's income
        */

        double price_for_amount = (current_product->get_product_price)(current_product->custom_data, product_amount_in_order);
        current_product->income += price_for_amount;

    }
    return MATAMIKYA_SUCCESS;

}

    

