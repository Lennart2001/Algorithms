//
//  insertion_sort.h
//  Sorting Algorithms
//
//  Created by hacker on 1/26/22.
//

#ifndef insertion_sort_h
#define insertion_sort_h

#include <vector>

std::vector<double> insertionSort(std::vector<double> input) {
       for (int x = 1; x < input.size(); x++) {
           double key = input[x];
           int y = x - 1;
           
           while (y >= 0 && input[y] > key) {
               input[y + 1] = input[y];
               y--;
           }
           input[y + 1] = key;
       }
    return input;
}

#endif /* insertion_sort_h */
