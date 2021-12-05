#ifndef _MATAMIKYA_PRODUCT_H_
#define _MATAMIKYA_PRODUCT_H_

#include "matamikya.h"
#include "amount_set.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

Product ProductCreate(unsigned int id, char* name,
                      MatamikyaAmountType amount_type,
                      MtmProductData custom_data,
                      MtmCopyData copy_custom_data, MtmFreeData free_custom_data,
                      MtmGetProductPrice get_product_price );

ASElement ProductCopy(ASElement element);
void ProductFree(ASElement element);
int ProductCompare(ASElement elemen1, ASElement element2);


/**
Product ProductCopy(Product source_product);

void ProductFree(Product product);


int ProductCompare(Product product1, Product product2);
**/



#endif