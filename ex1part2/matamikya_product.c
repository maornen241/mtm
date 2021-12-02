#include "matamikya_product.h"






Product ProductCreate(unsigned int id, char* name,
                      MatamikyaAmountType amount_type, MtmProductData custom_data,
                       MtmCopyData copy_custom_data, MtmFreeData free_custom_data,
                        MtmGetProductPrice get_product_price )

{

  Product new_product = malloc(sizeof(*new_product));

  if(new_product == NULL || name == NULL || custom_data == NULL ||
        copy_custom_data == NULL || free_custom_data == NULL || 
        get_product_price == NULL)
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
  new_product->custom_data = copy_custom_data(custom_data);

  new_product->copy_custom_data = copy_custom_data;
  new_product->free_custom_data = free_custom_data;
  new_product->get_product_price = get_product_price;

  return new_product;
  
}



ASElement ProductCopy(ASElement element)
{
    if(element == NULL)
    {
        return NULL;
    }
    Product product = (Product) element;//casting element into Prouduct
    Product copied_product = ProductCreate(product->product_id,
                                           product->name,
                                           product->amount_type,
                                           product->custom_data,
                                           product->copy_custom_data,
                                           product->free_custom_data,
                                           product->get_product_price);

    if(copied_product == NULL)
    {
        return NULL;
    }

    copied_product->income = product->income;

    return copied_product; 
}




void ProductFree(ASElement element)
{
    Product product = (Product) element;
    free(product->name);
    (product->free_custom_data)(product->custom_data);
    free(product);
}





int ProductCompare(ASElement element1, ASElement element2)
{
    Product product1 = (Product) element1;
    Product product2 = (Product) element2;
    
    assert(product1 != NULL || product2 != NULL);
    return (product1->product_id) - (product2->product_id);
}



/**
Product ProductCreate(unsigned int id, char* name,
                      MatamikyaAmountType amount_type, MtmProductData custom_data,
                       MtmCopyData copy_custom_data, MtmFreeData free_custom_data,
                        MtmGetProductPrice get_product_price )

{

  Product new_product = malloc(sizeof(*new_product));

  if(new_product == NULL || name == NULL || custom_data == NULL ||
        copy_custom_data == NULL || free_custom_data == NULL || 
        get_product_price == NULL)
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
  new_product->custom_data = copy_custom_data(custom_data);

  new_product->copy_custom_data = copy_custom_data;
  new_product->free_custom_data = free_custom_data;
  new_product->get_product_price = get_product_price;

  return new_product;
  
}




Product ProductCopy(Product product)
{
    Product copied_product = ProductCreate(product->product_id,
                                           product->name,
                                           product->amount_type,
                                           product->custom_data,
                                           product->copy_custom_data,
                                           product->free_custom_data,
                                           product->get_product_price);

    if(copied_product == NULL)
    {
        return NULL;
    }

    copied_product->income = product->income;

    return copied_product; 
}




void ProductFree(Product product)
{
    free(product->name);
    (product->free_custom_data)(product->custom_data);
    free(product);
}





int ProductCompare(Product product1, Product product2)
{
    assert(product1 != NULL || product2 != NULL);
    return (product1->product_id) - (product2->product_id);
}

**/





