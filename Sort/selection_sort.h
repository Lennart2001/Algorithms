//
//  selection_sort.h
//  Sorting Algorithms
//
//  Created by Lennart Buhl on 1/23/22.
//

#ifndef selection_sort_h
#define selection_sort_h

#include <vector>


std::vector<double> selectionSort(std::vector<double> input) {
    for (int x = 0; x < input.size() - 1; x++) {
        int min_idx = x;
        for (int y = x + 1; y < input.size(); y++) {
            if (input[y] < input[min_idx]) {
                min_idx = y;
            }
        }
        double temp = input[min_idx];
        input[min_idx] = input[x];
        input[x] = temp;
    }
    return input;
}


#endif /* selection_sort_h */
