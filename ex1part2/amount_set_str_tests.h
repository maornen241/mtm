#ifndef _AMOUNT_STR_SET_TESTS_H
#define _AMOUNT_STR_SET_TESTS_H

#include "amount_set_str.h"
#include "amount_set_str_linkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


#define  RUN_TEST_CASE(test_fn)\
{\
    if(test_fn())\
    {\
        printf("%s " ,#test_fn);\
        printf("\033[0;32m");\
        printf("passed\n");\
        printf("\033[0m");\
    }\
    else\
    {\
        printf("%s " ,#test_fn);\
        printf("\033[0;31m");\
        printf("failed\n");\
        printf("\033[0m");\
    }\
}

bool createNewAs();

bool destroyNull();
bool destroyAs();

bool copyNull();
bool copyASWithNullList();
bool copyGoodListWithNoIterator();
bool copyAsAndChangeAmount();

bool getSizeOfNullAs();
bool getSizeOfEmptyAs();
bool getSizeOfFullAs();
bool getSizeOfAsAndCheckIteratorUnchanged();

bool containesNullSet();
bool containesNullElement();
bool containsEmptySet();
bool containesFoundElement();
bool containesUnfoundElement();

bool getAmountNullSet();
bool getAmountNullElement();
bool getAmountNullOutAmount();
bool getAmountFoundElement();
bool getAmountUnfoundElement();

bool registerNullSet();
bool registerNullElement();
bool registerOnlyLowerCase();
bool registerLowerAndUperCase();
bool registerWordsAndNumbers();

bool changeAmountNullSet();
bool changeAmountNullElement();
bool changeAmountWithEmptyList();
bool changeAmountElementDosentExist();
bool changeAmountZero();
bool changeAmountIncrease();
bool changeAmountDecrease();
bool changeAmountDecreaseTooLow();

bool deleteNullSet();
bool deleteNullElement();
bool deleteUnitializedSet();
bool deleteNonExistingElement();
bool deleteExistingElements();

bool clearNullSet();
bool clearUninitializedList();
bool clearFullSet();

bool getFirstNullSet();
bool getFirstUnintializedList();
bool getFirstFullListAndCheckOriginalName();

bool getNextNullSet();
bool getNextEmptyList();
bool getNextMiddleOfList();
bool foreachFullSet();

bool forEachNullSet();
bool forEachEmptyList();

#endif