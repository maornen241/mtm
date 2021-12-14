#include "amount_set_str_tests.h"





struct AmountSet_t{
    asNode head; 
    asNode iterator;
};



bool createNewAs()
{
    AmountSet set = asCreate();
    if(set == NULL)
    {
        return false;
    }
    asDestroy(set);
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

bool copyAsAndChangeAmount()
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

bool getSizeOfNullAs()
{
    if(asGetSize(NULL) != -1)
    {
        return false;
    }

    return true;
}

bool getSizeOfEmptyAs()
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

bool getSizeOfFullAs()
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

bool getSizeOfAsAndCheckIteratorUnchanged()
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

bool containesNullSet()
{
    bool result=asContains(NULL,"MAOR");
    if(result == false)
    {
        return true;
    }
    
    return false;
}

bool containesNullElement()
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

bool containsEmptySet()
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

bool containesFoundElement()
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

bool containesUnfoundElement()
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

bool getAmountNullSet()
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

bool getAmountNullElement()
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


bool getAmountNullOutAmount()
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

bool getAmountFoundElement()
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

bool getAmountUnfoundElement()
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



bool registerNullSet()
{
    AmountSetResult result = asRegister(NULL, "ABC");
    if(result == AS_NULL_ARGUMENT)
    {
        return true;
    }
    return false;
}

bool registerNullElement()
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

bool registerOnlyLowerCase()
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

bool registerLowerAndUperCase()
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

bool registerWordsAndNumbers()
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

bool changeAmountNullSet()
{
    if(asChangeAmount(NULL, "yonez", 2) == AS_NULL_ARGUMENT)
    {
        return true;
    }
    return false;
}

bool changeAmountNullElement()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    bool result = (asChangeAmount(set, NULL, 2) == AS_NULL_ARGUMENT);
    asDestroy(set);
    return result;
}

bool changeAmountWithEmptyList()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    bool result = (asChangeAmount(set, "yonez", 2) == AS_ITEM_DOES_NOT_EXIST);
    asDestroy(set);
    return result;
}

bool changeAmountElementDosentExist()
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

bool changeAmountZero()
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

bool changeAmountIncrease()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    asRegister(set, "benjamin");
    asChangeAmount(set, "benjamin", 2);

    bool result = set->head->amount == 2;
    asDestroy(set);
    return result;
}

bool changeAmountDecrease()
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

bool changeAmountDecreaseTooLow()
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

bool deleteNullSet()
{
    if(asDelete(NULL, "yonez") == AS_NULL_ARGUMENT)
    {
        return true;
    }
    return false;

}



bool deleteNullElement()
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




bool deleteUnitializedSet()
{
    AmountSet set1 = asCreate();
    assert(set1 != NULL);

    bool result = (asDelete(set1, "chiko") == AS_ITEM_DOES_NOT_EXIST);
    asDestroy(set1);

    return result;
}

bool deleteNonExistingElement()
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

bool deleteExistingElements()
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

bool clearNullSet()
{
    if(asClear(NULL) == AS_NULL_ARGUMENT)
    {
        return true;
    }
    return false;
}

bool clearUninitializedList()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    bool result = (asClear(set) == AS_SUCCESS);
    asDestroy(set);

    return result;
}

bool clearFullSet()
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

bool getFirstNullSet()
{
    if(asGetFirst(NULL) == NULL)
    {
        return true;
    }
    return false;
}

bool getFirstUnintializedList()
{
    AmountSet set = asCreate();
    assert(set != NULL);

    bool result = (NULL == asGetFirst(set));
    asDestroy(set);
    return result;
}

bool getFirstFullListAndCheckOriginalName()
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

bool getNextMiddleOfList()
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
        asDestroy(set);
        return true;
    }
    asDestroy(set);
    return false;

}

bool getNextNullSet()
{
    char* result = asGetNext(NULL);
    if(result == NULL)
    {
        return true;
    }
    return false;
}

bool getNextEmptyList()
{
    AmountSet set = asCreate();
    assert(set != NULL);
    
    bool result = (NULL == asGetNext(set));
    asDestroy(set);
    return result;
}

bool getNextUndefinedIterator()
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
    asGetNext(set);
    asRegister(set, "zebra");
    char* should_be_null1 = asGetNext(set);

    asGetFirst(set);
    asGetNext(set);
    asDelete(set, "zebra");
    char* should_be_null2 = asGetNext(set);

    asGetFirst(set);
    asGetNext(set);
    AmountSet copied_set = asCopy(set);
    char* should_be_null3 = asGetNext(set);

    asGetFirst(set);
    asGetNext(set);
    asClear(set);
    char* should_be_null4 = asGetNext(set);

    bool result = (!should_be_null1 && !should_be_null2 && !should_be_null3 && !should_be_null4);
    asDestroy(copied_set);
    asDestroy(set);
    return result;

}


bool forEachNullSet()
{
    AS_FOREACH(char*, current, NULL)
    {
        return false;
    }
    return true;
}

bool forEachEmptyList()
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

bool foreachFullSet()
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

