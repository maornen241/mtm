#ifndef _MATAMIKYA_PRODUCT_H_
#define _MATAMIKYA_PRODUCT_H_

#include "matamikya.h"
#include "amount_set.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct product_t *Product;

Product ProductCreate(unsigned int id, char* name,
                      MatamikyaAmountType amount_type,
                      MtmProductData custom_data );

Product ProductCopy(Product source_product);

void ProductFree(Product product);


/**
 * Type of function used by the set to identify equal set elements.
 * This function should return:
 *     A positive integer if the first element is greater;
 *     0 if they're equal;
 *     A negative integer if the second element is greater.
 */
int ProductCompare(Product product1, Product product2);





#endif