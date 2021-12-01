#include "matamikya_order.h"
#include "matamikya_product.h"
#include "amount_set.h"

struct order_t 
{
    unsigned int order_id;
    AmountSet products;
};