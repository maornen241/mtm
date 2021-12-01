#include "amount_set_str_tests.h"

int main()
{
    RUN_TEST_CASE(createNewAs);
    printf("\n");

    RUN_TEST_CASE(destroyNull);
    RUN_TEST_CASE(destroyAs);
    printf("\n");

    RUN_TEST_CASE(copyNull);
    RUN_TEST_CASE(copyASWithNullList);
    RUN_TEST_CASE(copyGoodListWithNoIterator);
    RUN_TEST_CASE(Copy_as_and_change_copy);
    printf("\n");

    RUN_TEST_CASE(getSize_of_null_as);
    RUN_TEST_CASE(getSize_of_empty_as);
    RUN_TEST_CASE(getSize_of_full_as);
    RUN_TEST_CASE(getSize_of_as_and_check_iterator_unchanged);
     printf("\n");

    RUN_TEST_CASE(containes_null_set);
    RUN_TEST_CASE(containes_null_element);
    RUN_TEST_CASE(contains_empty_set);
    RUN_TEST_CASE(containes_found_element);
    RUN_TEST_CASE(containes_unfound_element);
    printf("\n");

    RUN_TEST_CASE(getAmount_null_set);
    RUN_TEST_CASE(getAmount_null_element);
    RUN_TEST_CASE(getAmount_null_outAmount);
    RUN_TEST_CASE(getAmount_found_element);
    RUN_TEST_CASE(getAmount_unfound_element); 
    printf("\n");

    RUN_TEST_CASE(register_null_set);
    RUN_TEST_CASE(register_null_element);
    RUN_TEST_CASE(register_only_lower_case);
    RUN_TEST_CASE(register_lower_and_uuper_case);
    RUN_TEST_CASE(register_words_and_numbers);
    printf("\n");

    RUN_TEST_CASE(change_amount_null_set);
    RUN_TEST_CASE(change_amount_null_element);
    RUN_TEST_CASE(change_amount_with_empty_list);
    RUN_TEST_CASE(change_amount_zero);
    RUN_TEST_CASE(change_amount_decrease_too_low);
    RUN_TEST_CASE(change_amount_decrease);
    RUN_TEST_CASE(change_amount_increase);
    printf("\n");

    RUN_TEST_CASE(delete_null_set);
    RUN_TEST_CASE(delete_null_element);
    RUN_TEST_CASE(delete_unitialized_set);
    RUN_TEST_CASE(delete_non_existing_element);
    RUN_TEST_CASE(delete_existing_elements);
    printf("\n");

    RUN_TEST_CASE(clear_null_set);
    RUN_TEST_CASE(clear_uninitialized_list);
    RUN_TEST_CASE(clear_full_set);
    printf("\n");

    RUN_TEST_CASE(get_first_null_set);
    RUN_TEST_CASE(get_first_unintialized_list);
    RUN_TEST_CASE(get_first_full_list_and_check_original_name);
    printf("\n");

    RUN_TEST_CASE(get_next_null_set);
    RUN_TEST_CASE(get_next_empty_list);
    RUN_TEST_CASE(get_next_middle_of_list);
    printf("\n");

    RUN_TEST_CASE(foreach_full_set);
    RUN_TEST_CASE(for_each_empty_list);
    RUN_TEST_CASE(for_each_null_set);
    printf("\n");

    printf("All test have finished\n");
    return 0;
}