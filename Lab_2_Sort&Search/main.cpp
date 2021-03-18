#include <iostream>
#include "Sort&Search.h"

int main() {

    introduction();

    int SIZE = getInteger();
    int arrayToSort[SIZE];

    fillArray(arrayToSort, SIZE);
    displayArray(arrayToSort, SIZE);
    sortArray(arrayToSort, SIZE);
    displayArray(arrayToSort, SIZE);
    searchArray(arrayToSort, SIZE);

    return 0;
}
