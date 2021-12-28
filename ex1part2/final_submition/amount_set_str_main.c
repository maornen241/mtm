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
    RUN_TEST_CASE(copyAsAndChangeAmount);
    printf("\n");

    RUN_TEST_CASE(getSizeOfNullAs);
    RUN_TEST_CASE(getSizeOfEmptyAs);
    RUN_TEST_CASE(getSizeOfFullAs);
    RUN_TEST_CASE(getSizeOfAsAndCheckIteratorUnchanged);
    printf("\n");

    RUN_TEST_CASE(containesNullSet);
    RUN_TEST_CASE(containesNullElement);
    RUN_TEST_CASE(containsEmptySet);
    RUN_TEST_CASE(containesFoundElement);
    RUN_TEST_CASE(containesUnfoundElement);
    printf("\n");

    RUN_TEST_CASE(getAmountNullSet);
    RUN_TEST_CASE(getAmountNullElement);
    RUN_TEST_CASE(getAmountNullOutAmount);
    RUN_TEST_CASE(getAmountFoundElement);
    RUN_TEST_CASE(getAmountUnfoundElement); 
    printf("\n");

    RUN_TEST_CASE(registerNullSet);
    RUN_TEST_CASE(registerNullElement);
    RUN_TEST_CASE(registerOnlyLowerCase);
    RUN_TEST_CASE(registerLowerAndUperCase);
    RUN_TEST_CASE(registerWordsAndNumbers);
    printf("\n");

    RUN_TEST_CASE(changeAmountNullSet);
    RUN_TEST_CASE(changeAmountNullElement);
    RUN_TEST_CASE(changeAmountWithEmptyList);
    RUN_TEST_CASE(changeAmountZero);
    RUN_TEST_CASE(changeAmountDecreaseTooLow);
    RUN_TEST_CASE(changeAmountDecrease);
    RUN_TEST_CASE(changeAmountIncrease);
    printf("\n");

    RUN_TEST_CASE(deleteNullSet);
    RUN_TEST_CASE(deleteNullElement);
    RUN_TEST_CASE(deleteUnitializedSet);
    RUN_TEST_CASE(deleteNonExistingElement);
    RUN_TEST_CASE(deleteExistingElements);
    printf("\n");

    RUN_TEST_CASE(clearNullSet);
    RUN_TEST_CASE(clearUninitializedList);
    RUN_TEST_CASE(clearFullSet);
    printf("\n");

    RUN_TEST_CASE(getFirstNullSet);
    RUN_TEST_CASE(getFirstUnintializedList);
    RUN_TEST_CASE(getFirstFullListAndCheckOriginalName);
    printf("\n");

    RUN_TEST_CASE(getNextNullSet);
    RUN_TEST_CASE(getNextEmptyList);
    RUN_TEST_CASE(getNextUndefinedIterator);
    RUN_TEST_CASE(getNextMiddleOfList);
    printf("\n");

    RUN_TEST_CASE(foreachFullSet);
    RUN_TEST_CASE(forEachEmptyList);
    RUN_TEST_CASE(forEachNullSet);
    printf("\n");

    printf("All test have finished\n");
    return 0;
}