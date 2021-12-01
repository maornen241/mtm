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
bool Copy_as_and_change_copy();

bool getSize_of_null_as();
bool getSize_of_empty_as();
bool getSize_of_full_as();
bool getSize_of_as_and_check_iterator_unchanged();

bool containes_null_set();
bool containes_null_element();
bool contains_empty_set();
bool containes_found_element();
bool containes_unfound_element();

bool getAmount_null_set();
bool getAmount_null_element();
bool getAmount_null_outAmount();
bool getAmount_found_element();
bool getAmount_unfound_element();

bool register_null_set();
bool register_null_element();
bool register_only_lower_case();
bool register_lower_and_uuper_case();
bool register_words_and_numbers();

bool change_amount_null_set();
bool change_amount_null_element();
bool change_amount_with_empty_list();
bool change_amount_element_dosent_exist();
bool change_amount_zero();
bool change_amount_increase();
bool change_amount_decrease();
bool change_amount_decrease_too_low();

bool delete_null_set();
bool delete_null_element();
bool delete_unitialized_set();
bool delete_non_existing_element();
bool delete_existing_elements();

bool clear_null_set();
bool clear_uninitialized_list();
bool clear_full_set();

bool get_first_null_set();
bool get_first_unintialized_list();
bool get_first_full_list_and_check_original_name();

bool get_next_null_set();
bool get_next_empty_list();
bool get_next_middle_of_list();
bool foreach_full_set();

bool for_each_null_set();
bool for_each_empty_list();

#endif