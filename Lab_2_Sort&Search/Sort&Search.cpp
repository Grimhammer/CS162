#include "Sort&Search.h"
#include <iostream>
#include <iomanip>
#include <ctime>

void introduction() {

    std::cout << "Please enter a number of integers between 10 and 20. This will be the number of random integers\n"
                 "between 1 and 99 entered into the array.\n";

}

/*
 * getInteger prompts the user for input, validates it, and then returns a valid integer to establish the size
 * of the array.
 */

int getInteger() {

    int input;

    std::cin >> input;

    while (std::cin.fail() || input < arrayMin || input > arrayMax) {
        std::cin.clear();
        std::cin.ignore(LARGE, END_LINE);
        std::cout << "Please enter an integer between 10 and 20.\n";
        std::cin >> input;

    }

    std::cout <<"\nYou chose " << input << " elements for the array.\n\n";

    return input;

}

/*
 * fillArray iterates through a number of elements equal to the size of the array, assigning a random
 * number between 1 and 99 to each element.
 */

void fillArray(int theArray[], int arraySize) {

    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);

    for (int i = 0; i < arraySize; i++) {
        int randArray = std::rand();
        theArray[i] = 1 + (randArray % 99);
    }

}

/*
 * sortArray uses an insertion sort to iterate through the array starting at the 1st element and swap values
 * with the preceding element if the current element is larger. this continues until that element is in its correct
 * location. we repeat this process until the array is totally sorted.
 */

void sortArray (int theArray[], int arraySize) {

    std::cout << "\nSorting array...\n\n";

    for(int i = 1; i < arraySize; i++) {
        // local variables for tracking the value of the current array element, and the position of the
        // previous element
        int value = theArray[i];
        int j = i - 1;
        // as long are at or greater than the 0th element of the array, evaluate the value of the position
        // against the value of the preceding element. if the current element is smaller, swap it with the
        // preceding element. repeat until at the 0 index and the 1st element is larger than the 0th.
        while (j >= 0 && theArray[j] > value) {
            theArray[j+1] = theArray[j];
            j-= 1;
        }

        theArray[j+1] = value;

    }

}

/*
 * displayArray iteratively sycles through the array, dispalying each element in rows of 5 elements.
 * did not refer to arraySize as constant as it is already defined as such in main.
 */

void displayArray(const int theArray[], int arraySize) {

    for (int i = 0; i < arraySize; i++) {
        std::cout << std::setw(charWidth);
        std::cout << theArray[i] << " ";
        if ((i + 1) % rowWidth == 0) {
            std::cout << "\n";
        }
    }

}

/*
 * searchArray prompts the user for 3 inputs, comparing values against those in the array using a binary search.
 */

void searchArray (int theArray[], int arraySize){

    std::cout << "\nPlease enter 3 values to search for.\n";

    for (int i = 0; i < searchCount; i++) {

        std::cout << "\nEnter a value to search for: ";
        int search = validInt();
        if (binSearch(theArray,arraySize,search)) {

            std::cout << "" << search << " is in the array.\n";

        }

        else {

            std::cout << search << " is not in the array.\n";

        }

    }

}

/*
 * binSearch uses a binary search. we partition the array into two halves and compare the value against the middle value.
 * If equals, the loop exits. If greater, it searches the right partition. If lesser, it searches the left. Repeat
 * until the value is found.
 */

bool binSearch(const int theArray[], int arraySize, int searchNum){

    int min = 0;
    int max = arraySize - 1;
    bool found = false;

    while (max >= min && !found) {

        int mid = (min + max) / 2;

        if (theArray[mid] == searchNum) {
            found = true;
            return true;
        }

        else if (theArray[mid] < searchNum) {
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }

    }

    if (!found) {
        return false;
    }

}

/*
 * validInt prompts the user for input, and only return the input if it is a valid integer.
 */

int validInt () {

    int input;

    std::cin >> input;
    // updated to use 1 and 99 as criteria.
    while (std::cin.fail() || input < minVal || input > maxVal) {
        std::cin.clear();
        std::cin.ignore(LARGE, END_LINE);
        std::cout << "Please enter a valid integer.\n";
        std::cin >> input;
    }

    return input;
}