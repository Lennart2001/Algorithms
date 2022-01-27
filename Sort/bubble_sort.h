//
//  bubble_sort.h
//  Sorting Algorithms
//
//  Created by Lennart Buhl on 1/23/22.
//

#ifndef bubble_sort_h
#define bubble_sort_h

#include <vector>


std::vector<double> bubbleSort(std::vector<double> input) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int x = 0; x < input.size()-1; x++) {
            if (input[x] > input[x+1]) {
                double temp = input[x+1];
                input[x+1] = input[x];
                input[x] = temp;
                sorted = false;
            }
        }
    }
    return input;
}




#endif /* bubble_sort_h */
