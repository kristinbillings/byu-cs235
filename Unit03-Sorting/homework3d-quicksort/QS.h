#pragma once

#include <vector>
using namespace std;

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    // implement medianOfThree here
    int middle = (left+right)/2;

    if (array[left] > array[middle]) {
        swap(array[left], array[middle]);
    }
    if (array[left] > array[right]) {
        swap(array[left], array[right]);
    }
    if (array[middle] > array[right]) {
        swap(array[middle], array[right]);
    }
    return middle;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    // implement partition here
    int middle = medianOfThree(array, left, right);


    swap(array[left], array[middle]);

    int up = left + 1;
    int down = right;

    while (true) {
        while ((array[up] <= array[left]) && (up < right)) { // because pivot is no longer in the middle
            up += 1;
        }

        while ((array[down] > array[left]) && (down > left)) {
            down -= 1;
        }

        if (up < down) {
            swap(array[up], array[down]);
        } else {
            break;
        }
    }

    swap(array[left],array[down]);

    return down;
}

template<class T>
void sort_helper(std::vector<T>& array, int left, int right) {
    //if (left >= right) {
      //  cont;
    //}
    if (left < right) {
        // pi is the partition return index of pivot

        int par=partition(array,left,right);

        //Recursion Call
        //smaller element than pivot goes left and
        //higher element goes right
        sort_helper(array,left,par-1);
        sort_helper(array,par+1,right);
    }

}

template<class T>
void sort(std::vector<T>& array) {
    // implement sort here
    // hint: you'll probably want to make a recursive sort_helper function
    int left  = 0;
    int right = array.size() - 1;

    sort_helper(array, left, right);

}


