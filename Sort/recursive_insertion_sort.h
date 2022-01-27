//
//  recursive_insertion_sort.h
//  Sorting Algorithms
//
//  Created by Lennart Buhl on 1/26/22.
//

#ifndef recursive_insertion_sort_h
#define recursive_insertion_sort_h

#include <vector>

std::vector<double> recursiveInsertionSort(std::vector<double> input, int num) {
    if (num > 1) {
        input = recursiveInsertionSort(input, num-1);
    }
    double key = input[num-1];
    int y = num-2;
    while (y >= 0 && input[y] > key) {
        input[y + 1] = input[y];
        y--;
    }
    input[y + 1] = key;
    return input;
}

#endif /* recursive_insertion_sort_h */
