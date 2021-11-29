#include "amount_set_str.h"
#include "linkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>




struct AmountSet_t{
    asNode head; 
    asNode iterator;
};


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







bool createNewAs()
{
    AmountSet newSet = asCreate();
    if(newSet == NULL)
    {
        return false;
    }

    return true;
}



bool destroyNull()
{
    asDestroy(NULL);
    return true;
}

bool destroyAs()
{
    AmountSet newSet = asCreate();
    newSet->head = createNode("abc", 2);
    newSet->iterator = newSet->head;

    asDestroy(newSet);

    return true;
}

bool copyNull()
{
    if(asCopy(NULL) != NULL)
    {
        return false;
    }
    return true;
}

bool copyASWithNullList()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    set1->head = NULL;

    AmountSet copiedSet = asCopy(set1);

    if(copiedSet->head != NULL)
    {
        return false;
    }

    asDestroy(copiedSet);
    asDestroy(set1);
    
    return true;

}

bool copyGoodListWithNoIterator()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", 1.5);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;
    AmountSet copiedSet = asCopy(set1);

    if(copiedSet == NULL)
    {
        return false;
    }

    asNode copied_list = copiedSet->head;

    if(strcmp(copied_list->name, "MAOR") != 0 || copied_list->amount != 1.5)
    {
        return false;
    }
    copied_list = copied_list->next;

    if(strcmp(copied_list->name, "BENJAMIN") != 0 || copied_list->amount != 2.0)
    {
        return false;
    }
    copied_list = copied_list->next;

    if(strcmp(copied_list->name, "ARI") != 0  || copied_list->amount != 0)
    {
        return false;
    }

    asDestroy(copiedSet);
    asDestroy(set1);
    

    return true;
}

bool Copy_as_and_change_copy()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", 1.5);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;
    AmountSet copiedSet = asCopy(set1);

    if(copiedSet == NULL)
    {
        return false;
    }

    copiedSet->head->amount = 12;
    if(set1->head->amount != 1.5)
    {
        return false;
    }

    char* my_string = "YONEZ";
    *(copiedSet->head->name) = *(my_string);
    if(strcmp(set1->head->name, "MAOR") != 0)
    {
        return false;
    }


    asDestroy(copiedSet);
    asDestroy(set1);

    return true;
}

bool getSize_of_null_as()
{
    if(asGetSize(NULL) != -1)
    {
        return false;
    }

    return true;
}

bool getSize_of_empty_as()
{
    AmountSet myset = asCreate();
    assert(myset !=  NULL);

    if(asGetSize(myset) != 0)
    {
        return false;
    }
    asDestroy(myset);

    return true;
}

bool getSize_of_full_as()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", -6.45);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;

    if (asGetSize(set1) != 3)       
    {
        return false;
    }

    asDestroy(set1);

    return true;
    
}

bool getSize_of_as_and_check_iterator_unchanged()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", -6.45);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;
    set1->iterator = node2;

    if (asGetSize(set1) != 3)       
    {
        return false;
    }

    if(set1->iterator != node2)
    {
        return false;
    }

    asDestroy(set1);

    return true;
}

bool containes_null_set()
{
    bool result=asContains(NULL,"MAOR");
    if(result == false)
    {
        return true;
    }
    
    return false;
}

bool containes_null_element()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", -6.45);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;
    bool result = asContains(set1,NULL);

     if(result == false)
    {
        asDestroy(set1);
        return true;
    }
    
    asDestroy(set1);
    return false;

}

bool contains_empty_set()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    bool result = asContains(set1, "abc");
    asDestroy(set1);

    if(result == false)
    {
        return true;
    }
    return false;
}

bool containes_found_element()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", -6.45);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;
    bool result = asContains(set1,"ARI");

    if(result == true)
    {
        asDestroy(set1);
        return true;
    }
    
    asDestroy(set1);
    return false;
}

bool containes_unfound_element()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", -6.45);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;
    bool result = asContains(set1,"IVGENY");

    if(result == false)
    {
        asDestroy(set1);
        return true;
    }

    asDestroy(set1);
    return false;
}

bool getAmount_null_set()
{
    double amount = -1.0;
    double* outAmount = &amount;
    AmountSetResult result = asGetAmount(NULL, "MAOR" , outAmount);

    if(result == AS_NULL_ARGUMENT && amount == -1.0);
    {
        return true;
    }

    return false;
}

bool getAmount_null_element()
{

    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", -6.45);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;

    double amount = -1.0;
    double* outAmount = &amount;
    AmountSetResult result = asGetAmount(set1, NULL , outAmount);

    if(result == AS_NULL_ARGUMENT && amount == -1.0);
    {
        asDestroy(set1);
        return true;
    }

    asDestroy(set1);
    return false;
}


bool getAmount_null_outAmount()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", -6.45);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;

    AmountSetResult result = asGetAmount(set1, "MAOR" , NULL);

    if(result == AS_NULL_ARGUMENT);
    {
        asDestroy(set1);
        return true;
    }

    asDestroy(set1);
    return false;
}

bool getAmount_found_element()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", -6.45);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;

    double amount = -1.0;
    double* outAmount = &amount;
    AmountSetResult result = asGetAmount(set1, "BENJAMIN" , outAmount);

    if(result == AS_SUCCESS && (*outAmount) == 2.0)
    {
        asDestroy(set1);
        return true;
    }

    asDestroy(set1);
    return false;

}

bool getAmount_unfound_element()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", -6.45);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;

    double amount = -1.0;
    double* outAmount = &amount;
    AmountSetResult result = asGetAmount(set1, "IVGENY" , outAmount);

    if(result == AS_ITEM_DOES_NOT_EXIST && (*outAmount) == -1.0)
    {
        asDestroy(set1);
        return true;
    }

    asDestroy(set1);
    return false;
}



bool register_null_set()
{
    AmountSetResult result = asRegister(NULL, "ABC");
    if(result == AS_NULL_ARGUMENT)
    {
        return true;
    }
    return false;
}

bool register_null_element()
{
    AmountSet set = asCreate();
    AmountSetResult result = asRegister(set,NULL);
    asDestroy(set);

    if(result == AS_NULL_ARGUMENT)
    {
        return true;
    }
    return false;
}

bool register_only_lower_case()
{
    AmountSet set =  asCreate();
    assert(set != NULL);

    asRegister(set, "avi");
    asRegister(set, "dani");
    asRegister(set, "beni");
    asRegister(set, "adi");

    char* arr_check[4] = {"adi", "avi", "beni", "dani"};

    asNode current_node = set->head;
    bool result = true;
    for (int i = 0; i < 4; i++)
    {
        if(strcmp(current_node->name, arr_check[i]) != 0)
        {
            result = false;
            break;
        }
        current_node = current_node->next;
    }
    asDestroy(set);
    return result;
    
}

bool register_lower_and_uuper_case()
{
    AmountSet set =  asCreate();
    assert(set != NULL);

    asRegister(set, "avi");
    asRegister(set, "dani");
    asRegister(set, "beni");
    asRegister(set, "adi");
    asRegister(set ,"Avi");
    asRegister(set, "GIL");
    asRegister(set, "");

    char* arr_check[7] = {"", "Avi", "GIL", "adi", "avi", "beni", "dani"};

    asNode current_node = set->head;
    bool result = true;
    for (int i = 0; i < 7; i++)
    {
        if(strcmp(current_node->name, arr_check[i]) != 0)
        {
            result = false;
            break;
        }
        current_node = current_node->next;
    }
    asDestroy(set);
    return result;
}

bool register_words_and_numbers()
{
    AmountSet set =  asCreate();
    assert(set != NULL);

    asRegister(set, "avi");
    asRegister(set, "dani");
    asRegister(set, "beni");
    asRegister(set, "adi");
    asRegister(set ,"2");
    asRegister(set, "GIL");
    asRegister(set, "7");

    char* arr_check[7] = {"2", "7", "GIL", "adi", "avi", "beni", "dani"};

    asNode current_node = set->head;
    bool result = true;
    for (int i = 0; i < 7; i++)
    {
        if(strcmp(current_node->name, arr_check[i]) != 0)
        {
            result = false;
            break;
        }
        current_node = current_node->next;
    }
    asDestroy(set);
    return result;

}

bool change_amount_null_set()
{
    if(asChangeAmount(NULL, "yonez", 2) == AS_NULL_ARGUMENT)
    {
        return true;
    }
    return false;
}

bool change_amount_null_element()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    bool result = (asChangeAmount(set, NULL, 2) == AS_NULL_ARGUMENT);
    asDestroy(set);
    return result;
}

bool change_amount_with_empty_list()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    bool result = (asChangeAmount(set, "yonez", 2) == AS_ITEM_DOES_NOT_EXIST);
    asDestroy(set);
    return result;
}

bool change_amount_element_dosent_exist()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    asRegister(set, "benji");
    asRegister(set, "maor");
    set->head->amount = 22.1;

    bool result = (asChangeAmount(set, "yonez", -1) == AS_ITEM_DOES_NOT_EXIST);
    asDestroy(set);
    return result;
}

bool change_amount_zero()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    asRegister(set, "zrobavel");
    set->head->amount = 1.5;

    bool result = asChangeAmount(set, "zrobavel", 0);
    if(result == AS_SUCCESS && set->head->amount == 1.5)
    {
    asDestroy(set);
    return true;
    }

    asDestroy(set);
    return false;
}

bool change_amount_increase()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    asRegister(set, "benjamin");
    asChangeAmount(set, "benjamin", 2);

    bool result = set->head->amount == 2;
    asDestroy(set);
    return result;
}

bool change_amount_decrease()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    asRegister(set, "gomigam");
    asRegister(set, "shokobo");

    set->head->amount = 12;
    set->head->next->amount = 2.4;

    bool is_succes1 = (AS_SUCCESS == asChangeAmount(set, "gomigam", -2));
    bool is_succes2 = (AS_SUCCESS == asChangeAmount(set, "shokobo", -2.4));

    bool did_val1_changed = (set->head->amount == 10);
    bool did_val2_changed = (set->head->next->amount == 0);    

    asDestroy(set);
    return (is_succes1 && is_succes2 && did_val1_changed && did_val2_changed);
}

bool change_amount_decrease_too_low()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    asRegister(set, "gomigam");
    asRegister(set, "shokobo");

    set->head->amount = 12;
    set->head->next->amount = 2.4;

    if(AS_INSUFFICIENT_AMOUNT == asChangeAmount(set, "shokobo", -10))
    {
        asDestroy(set);
        return true;
    }
    
    asDestroy(set);
    return false;
}

bool delete_null_set()
{
    if(asDelete(NULL, "yonez") == AS_NULL_ARGUMENT)
    {
        return true;
    }
    return false;

}



bool delete_null_element()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    asNode node1 = createNode("MAOR", -6.45);
    asNode node2 = createNode("BENJAMIN", 2.0);
    asNode node3 = createNode("ARI", 0);
    node1->next = node2;
    node2->next = node3;

    set1->head = node1;

    bool result = (asDelete(set1, NULL) == AS_NULL_ARGUMENT);
    asDestroy(set1);

    return result;
}




bool delete_unitialized_set()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    bool result = (asDelete(set1, "chiko") == AS_ITEM_DOES_NOT_EXIST);
    asDestroy(set1);

    return result;
}

bool delete_non_existing_element()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    asRegister(set, "gomigam");
    asRegister(set, "shokobo");
    asChangeAmount(set, "gomigam", 2.11);
    asChangeAmount(set, "shokobo", 13);

    bool result = (asDelete(set, "Shokobo") == AS_ITEM_DOES_NOT_EXIST);

    asDestroy(set);
    return result;


}

bool delete_existing_elements()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    asRegister(set, "gomigam");
    asRegister(set, "shokobo");
    asRegister(set, "tenTaklep");
    asChangeAmount(set, "gomigam", 2.11);
    asChangeAmount(set, "shokobo", 13);

    bool result1 = (asDelete(set, "shokobo") == AS_SUCCESS);
    bool result2 = (asDelete(set, "gomigam") == AS_SUCCESS);

    asNode ptr = set->head;

    while(ptr != NULL)
    {
        bool check1 = (strcmp(ptr->name, "shokobo") == 0); 
        bool check2 = (strcmp(ptr->name , "gomigam") == 0);

        if( check1 || check2)
        {
            asDestroy(set);
            return false;
        }
        ptr = ptr->next;
    }

    asDestroy(set);
    return (result1 && result2);
}

bool clear_null_set()
{
    if(asClear(NULL) == AS_NULL_ARGUMENT)
    {
        return true;
    }
    return false;
}

bool clear_uninitialized_list()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    bool result = (asClear(set) == AS_SUCCESS);
    asDestroy(set);

    return result;
}

bool clear_full_set()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    asRegister(set, "Ma?");
    asRegister(set, "yonez!");
    asRegister(set, "turning");
    asRegister(set, "tables");

    asChangeAmount(set, "Ma?", 2.3);
    asChangeAmount(set, "yonez!", 1);
    asChangeAmount(set, "turning", 0);
    asChangeAmount(set, "tables", 16);

    bool is_succes = (AS_SUCCESS == asClear(set));
    bool is_cleared = (set->head == NULL);

    asDestroy(set);
    return (is_cleared && is_succes);
}

bool get_first_null_set()
{
    if(asGetFirst(NULL) == NULL)
    {
        return true;
    }
    return false;
}

bool get_first_unintialized_list()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    bool result = (NULL == asGetFirst(set));
    asDestroy(set);
    return result;
}

bool get_first_full_list_and_check_original_name()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    asRegister(set, "Ma?");
    asRegister(set, "yonez!");

    asChangeAmount(set, "Ma?", 2.3);
    asChangeAmount(set, "yonez!", 1);

    char* first_element = asGetFirst(set);

    bool is_first_element = (strcmp("Ma?",first_element ) == 0);
    bool is_original_copy;

    first_element[0] = 'D';
    is_original_copy = (strcmp(set->head->name,"Da?") == 0);

    asDestroy(set);
    return (is_first_element && is_original_copy);
}

bool get_next_middle_of_list()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    asRegister(set, "Ma?");
    asRegister(set, "yonez!");
    asRegister(set, "turning");
    asRegister(set, "tables");

    asChangeAmount(set, "Ma?", 2.3);
    asChangeAmount(set, "yonez!", 1);
    asChangeAmount(set, "turning", 0);
    asChangeAmount(set, "tables", 16);

    asGetFirst(set);
    char* result = asGetNext(set);
    if(strcmp(result , "tables") == 0)
    {
        return true;
    }
    return false;

}


bool for_each_null_set()
{
    AS_FOREACH(char*, current, NULL)
    {
        return false;
    }
    return true;
}

bool for_each_empty_list()
{
    AmountSet set = asCreate();
    assert(set != NULL);
    
    AS_FOREACH(char*, current, set)
    {
        asDestroy(set);
        return false;
    }
    asDestroy(set);
    return true;
}

bool foreach_full_set()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    asRegister(set, "Ma?");
    asRegister(set, "yonez!");
    asRegister(set, "turning");
    asRegister(set, "tables");

    asChangeAmount(set, "Ma?", 2.3);
    asChangeAmount(set, "yonez!", 1);
    asChangeAmount(set, "turning", 0);
    asChangeAmount(set, "tables", 16);

    char* check_arr[4] = {"Ma?", "tables", "turning", "yonez!" };
    int i = 0;

    AS_FOREACH(char*, current_name, set)
    {
        if(strcmp(check_arr[i], current_name) != 0)
        {
            asDestroy(set);
            return false;
        }
        i++;
    }

    if(asGetNext(set) != NULL)
    {
        asDestroy(set);
        return false;        
    }

    asDestroy(set);
    return true;
}

bool get_next_null_set()
{
    char* result = asGetNext(NULL);
    if(result == NULL)
    {
        return true;
    }
    return false;
}

bool get_next_empty_list()
{
    AmountSet set = asCreate();
    assert(set != NULL);
    
    bool result = (NULL == asGetNext(set));
    asDestroy(set);
    return result;
}