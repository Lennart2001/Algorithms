//
//  recursive_bubble_sort.h
//  Sorting Algorithms
//
//  Created by Lennart Buhl on 1/26/22.
//

#ifndef insertion_sort_h
#define insertion_sort_h

#include <vector>

std::vector<double> recursiveBubbleSort(std::vector<double> input, int num) {
    
    for (int x = 0; x < input.size()-1; x++) {
        if (input[x] > input[x+1]) {
            double temp = input[x+1];
            input[x+1] = input[x];
            input[x] = temp;
        }
    }
    if (num > 1) {
        input = recursiveBubbleSort(input, num-1);
    }
    return input;
}

#endif /* insertion_sort_h */
