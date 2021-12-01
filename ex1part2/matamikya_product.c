#include "matamikya_product.h"



struct product_t
{
    unsigned int product_id;
    unsigned int income;
    char* name;
    MatamikyaAmountType amount_type;
    MtmProductData custom_data;
};




Product ProductCreate(unsigned int id, char* name,
                      MatamikyaAmountType amount_type,
                      MtmProductData custom_data )

{

  Product new_product = malloc(sizeof(*new_product));
  if(new_product == NULL || name == NULL || custom_data == NULL)
  {
      return NULL;
  }

  new_product->product_id = id;
  new_product->amount_type = amount_type;
  new_product->income = 0;

  new_product->name = malloc(sizeof(char)*strlen(name));
  if(new_product->name == NULL)
  {
      free(new_product);
      return NULL;
  }

  strcpy(new_product->name, name);
  new_product->custom_data = MtmCopyData(custom_data);
  
  return new_product;
  
}




Product ProductCopy(Product source_product)
{
    Product copied_product = ProductCreate(source_product->product_id,
                                            source_product->name,
                                            source_product->amount_type,
                                             source_product->custom_data);

    if(copied_product == NULL)
    {
        return NULL;
    }

    copied_product->income = source_product->income;

    return copied_product; 
}




void ProductFree(Product product)
{
    free(product->name);
    MtmFreeData(product->custom_data);
    free(product);
}





int ProductCompare(Product product1, Product product2)
{
    assert(product1 != NULL || product2 != NULL);
    return (product1->product_id) - (product2->product_id);
}







