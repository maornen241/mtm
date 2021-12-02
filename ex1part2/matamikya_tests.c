#include "matamikya_tests.h"
#include "matamikya.h"
#include "test_utilities.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#define INVENTORY_OUT_FILE "tests/printed_inventory.txt"
#define INVENTORY_TEST_FILE "tests/expected_inventory.txt"
#define ORDER_OUT_FILE "tests/printed_order.txt"
#define ORDER_TEST_FILE "tests/expected_order.txt"
#define BEST_SELLING_OUT_FILE "tests/printed_best_selling.txt"
#define BEST_SELLING_TEST_FILE "tests/expected_best_selling.txt"
#define NO_SELLING_OUT_FILE "tests/printed_no_selling.txt"
#define NO_SELLING_TEST_FILE "tests/expected_no_selling.txt"

#define ASSERT_OR_DESTROY(expr) ASSERT_TEST_WITH_FREE((expr), matamikyaDestroy(mtm))

bool testCreate() {
    Matamikya mtm = matamikyaCreate();
    ASSERT_TEST(mtm != NULL);
    matamikyaDestroy(mtm);
    return true;
}

bool testDestroy() {
    Matamikya mtm = matamikyaCreate();
    matamikyaDestroy(mtm);
    /* try to elicit undefined behavior in case matamikyaDestroy has bugs */
    Matamikya mtm2 = matamikyaCreate();
    ASSERT_TEST(mtm2 != NULL);
    matamikyaDestroy(mtm2);
    return true;
}

static MtmProductData copyDouble(MtmProductData number) {
    double *copy = malloc(sizeof(*copy));
    if (copy) {
        *copy = *(double*)number;
    }
    return copy;
}

static void freeDouble(MtmProductData number) {
    free(number);
}

static double simplePrice(MtmProductData basePrice, const double amount) {
    return (*(double*)basePrice) * amount;
}

static double buy10Get10ForFree(MtmProductData basePrice, const double amount) {
    double realAmount = amount;
    if (amount >= 20) {
        realAmount -= 10;
    } else if (amount >= 10) {
        realAmount = 10;
    }
    return simplePrice(basePrice, realAmount);
}

bool testModifyProducts() {
    Matamikya mtm = matamikyaCreate();
    double basePrice = 8.9;
    ASSERT_OR_DESTROY(MATAMIKYA_SUCCESS ==
                      mtmNewProduct(mtm, 4, "Tomato", 2019.11, MATAMIKYA_ANY_AMOUNT,
                                    &basePrice, copyDouble, freeDouble, simplePrice));
    basePrice = 5.8;
    ASSERT_OR_DESTROY(MATAMIKYA_SUCCESS ==
                      mtmNewProduct(mtm, 6, "Onion", 1789.75, MATAMIKYA_ANY_AMOUNT,
                                    &basePrice, copyDouble, freeDouble, buy10Get10ForFree));
    basePrice = 2000;
    ASSERT_OR_DESTROY(MATAMIKYA_SUCCESS ==
                      mtmNewProduct(mtm, 10, "Television", 15, MATAMIKYA_INTEGER_AMOUNT,
                                    &basePrice, copyDouble, freeDouble, simplePrice));
    basePrice = 5000;
    ASSERT_OR_DESTROY(MATAMIKYA_SUCCESS ==
                      mtmNewProduct(mtm, 11, "Television", 4, MATAMIKYA_INTEGER_AMOUNT,
                                    &basePrice, copyDouble, freeDouble, simplePrice));

    ASSERT_OR_DESTROY(MATAMIKYA_SUCCESS == mtmClearProduct(mtm, 6));
    ASSERT_OR_DESTROY(MATAMIKYA_SUCCESS == mtmChangeProductAmount(mtm, 4, 30.5));
    ASSERT_OR_DESTROY(MATAMIKYA_SUCCESS == mtmChangeProductAmount(mtm, 4, -12.85));
    ASSERT_OR_DESTROY(MATAMIKYA_INVALID_AMOUNT == mtmChangeProductAmount(mtm, 10, 2.25));
    ASSERT_OR_DESTROY(MATAMIKYA_INSUFFICIENT_AMOUNT == mtmChangeProductAmount(mtm, 10, -1000));

    basePrice = 18.5;
    ASSERT_OR_DESTROY(MATAMIKYA_INVALID_AMOUNT ==
                      mtmNewProduct(mtm, 7, "Watermelon", 24.54,
                                    MATAMIKYA_HALF_INTEGER_AMOUNT, &basePrice, copyDouble,
                                    freeDouble, simplePrice));
    ASSERT_OR_DESTROY(MATAMIKYA_SUCCESS ==
                      mtmNewProduct(mtm, 7, "Watermelon", 24.5,
                                    MATAMIKYA_HALF_INTEGER_AMOUNT,
                                    &basePrice, copyDouble,
                                    freeDouble, simplePrice));

    matamikyaDestroy(mtm);
    return true;
}



