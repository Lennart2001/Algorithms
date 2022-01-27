//
//  quick_sort.h
//  Sorting Algorithms
//
//  Created by hacker on 1/26/22.
//

#ifndef quick_sort_h
#define quick_sort_h

#include <vector>

std::vector<double> quickSort(std::vector<double> input, int left, int right) {
    if (left < right) {
        double spin = input[right];
        int index = left - 1;
        for (int x = left; x < right; x++) {
            if (input[x] < spin) {
                index++;
                double temp = input[index];
                input[index] = input[x];
                input[x] = temp;
            }
        }
        index++;
        double temp = input[index];
        input[index] = input[right];
        input[right] = temp;
        input = quickSort(input, left, index-1);
        input = quickSort(input, index+1, right);
    }
    return input;
}

#endif /* quick_sort_h */
