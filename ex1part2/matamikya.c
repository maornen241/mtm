#include "amount_set.h"
#include "matamikya.h"
#include "matamikya_product.h"
#include "list.h"
#include "set.h"
#include "matamikya_print.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALLOWED_ERROR 0.001

#define IS_LETTER(char mychar)\
        ((mychar >= 'A' && mychar <= 'Z') || (mychar >= 'a' && mychar <= 'z'))

 #define IS_DIGIT(char mychar)\
         ((mychar >= '0' && mychar <= '9')



struct Matamikya_t
{
    AmountSet inventory;
    Set deliveries;
};

Matamikya matamikyaCreate()
{
    Matamikya new_warehouse = (Matamikya) malloc(sizeof(*new_warehouse));
    if(new_warehouse == NULL)
    {
        return NULL;
    }

    new_warehouse->inventory = NULL;
    new_warehouse->deliveries = NULL;
    return  new_warehouse;
}

void matamikyaDestroy(Matamikya matamikya)
{
    if(matamikya == NULL)
    {
        return;
    }

    asDestroy(matamikya->inventory);
    setDestroy(matamikya->deliveries);
    free(matamikya);
}




/**
 * mtmNewProduct: add a new product to a Matamikya warehouse.
 *
 * @param matamikya - warehouse to add the product to. Must be non-NULL.
 * @param id - new product id. Must be non-negative, and unique.
 * @param name - name of the product, e.g. "apple". Must be non-empty.
 * @param amount - the initial amount of the product when added to the warehouse.
 * @param amountType - defines what are valid amounts for this product.
 * @param customData - pointer to product's additional data
 * @param copyData - function pointer to be used for copying product's additional 
 *      data.
 * @param freeData - function pointer to be used for free product data.
 * @param prodPrice - function pointer to be used for getting the price of some 
 *      product.
 * @return
 *     MATAMIKYA_NULL_ARGUMENT - if matamikya/name/customData/copyData/freeData
 *      /prodPrice are NULL.
 *     MATAMIKYA_INVALID_NAME - if name is empty, or doesn't start with a
 *         letter (a -z, A -Z) or a digit (0 -9).
 *     MATAMIKYA_INVALID_AMOUNT - if amount < 0, or is not consistent with amountType
 *         (@see MatamikyaAmountType documentation above)
 *     MATAMIKYA_PRODUCT_ALREADY_EXIST - if a product with the given id already exist.
 *     MATAMIKYA_SUCCESS - if product was added successfully.
**/
MATAMIKYA_INVALID_NAME
MatamikyaResult mtmNewProduct(Matamikya matamikya, const unsigned int id, const char *name,
                              const double amount, const MatamikyaAmountType amountType,
                              const MtmProductData customData, MtmCopyData copyData,
                              MtmFreeData freeData, MtmGetProductPrice prodPrice)

{
    if(matamikya == NULL || name == NULL || customData == NULL || 
       freeData == NULL || copyData == NULL || prodPrice == NULL)
       {
           return MATAMIKYA_NULL_ARGUMENT;
       }

    if(strcmp(name, "") == 0 || !IS_LETTER(name[0]) || !IS_DIGIT(name[0]))
    {
        return MATAMIKYA_INVALID_NAME;
    }

    if(amount < 0 || !is_amount_compatible(amount, amountType))
    {

    }
}



static bool is_amount_compatible(const double amount, const MatamikyaAmountType amountType)
{
    int casted_amount = (int) amount;
    if(amountType == MATAMIKYA_INTEGER_AMOUNT)
    {
        if(casted_amount <= amount)
        {
            casted_amount++;
            double diff = casted_amount-amount;
        }
        else
        {
            double diff = amount-casted_amount; 
        }

        return (diff <= ALLOWED_ERROR);
    }

    if(amountType == MATAMIKYA_HALF_INTEGER_AMOUNT)
    {
        if(casted_amount <= amount)
        {
            casted_amount++;
            double diff = casted_amount-amount;
        }
        else
        {
            double diff = amount-casted_amount; 
        }
        return (diff <= ALLOWED_ERROR || (diff <= (ALLOWED_ERROR+0.5) && diff >= 0.5-ALLOWED_ERROR);
    }
    
    if(amountType == MATAMIKYA_ANY_AMOUNT)
    {
        return true;
    }
}