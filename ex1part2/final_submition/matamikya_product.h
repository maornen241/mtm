#ifndef _MATAMIKYA_PRODUCT_H_
#define _MATAMIKYA_PRODUCT_H_

#include "matamikya.h"
#include "amount_set.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/** Type for representing  Matamikya products*/
struct product_t
{
    unsigned int product_id;
    double income;
    char* name;
    MatamikyaAmountType amount_type;
    MtmProductData custom_data;
    MtmCopyData copy_custom_data;
    MtmFreeData free_custom_data;
    MtmGetProductPrice get_product_price;
};



typedef struct product_t *Product;

/**
 * ProductCreate: Allocates a new empty product.
 * 
 * allocating: product's name, custom data, and product itself.
 * 
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
 *
 * @return
 *     NULL - NULL if allocations failed.
 *     A new product in case of success.
 */
Product ProductCreate(unsigned int id, char* name,
                      MatamikyaAmountType amount_type,
                      MtmProductData custom_data,
                      MtmCopyData copy_custom_data, MtmFreeData free_custom_data,
                      MtmGetProductPrice get_product_price );


/**
 * ProductCopy: Creates a copy of target product.
 * copies all products fields.
 *
 *
 * @param element - Target product.
 * 
 * @return
 *     NULL if a NULL was sent or a memory allocation failed.
 *     The copied product, otherwise.
 */
ASElement ProductCopy(ASElement element);

/**
 * ProductFree: Deallocates an existing product.
 * dellocating: product's name, product's custom data, product itself.
 *
 * @param element - Target product to be deallocated. If element is NULL nothing will be done.
 */
void ProductFree(ASElement element);

/**
 * ProductCompare: identify equal products.
 * compares the products id.
 * 
 * @param element1 - the first product to compare
 * @param element2 - the second product  to compare
 * 
 * @return 
 *     A positive integer if the first element is greater;
 *     0 if they're equal;
 *     A negative integer if the second element is greater.
 */
int ProductCompare(ASElement elemen1, ASElement element2);




#endif