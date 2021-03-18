//
// Created by lucas on 1/17/2021.
//

#ifndef LAB_2_SORT_SEARCH_SORT_SEARCH_H
#define LAB_2_SORT_SEARCH_SORT_SEARCH_H

#include <limits>
#include <iostream>

const unsigned long long LARGE = std::numeric_limits<std::streamsize>::max();
const char END_LINE = '\n';

const int arrayMin = 10;
const int arrayMax = 20;
const int charWidth = 3;
const int rowWidth = 5;
const int minVal = 1;
const int maxVal = 99;
const int searchCount = 3;

void introduction();
int getInteger();
void fillArray(int theArray[], int arraySize);
void sortArray(int theArray[], int arraySize);
void displayArray(const int theArray[], int arraySize);
void searchArray (int theArray[], int arraySize);
bool binSearch(const int theArray[], int arraySize, int searchNum);
int validInt ();

#endif //LAB_2_SORT_SEARCH_SORT_SEARCH_H
