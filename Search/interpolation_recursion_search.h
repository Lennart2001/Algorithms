//
//  recursive_insertion_search.h
//  Search Algorithms
//
//  Created by Lennart Buhl on 1/26/22.
//

#ifndef recursive_insertion_search_h
#define recursive_insertion_search_h

#include <vector>

int interpolationRecursionSearch(std::vector<double> input, double x, int low, int high) {
    if (low <= high && x >= input[low] && x <= input[high]) {
        int position = low + (((double)(high - low) / (input[high] - input[low]))
                              * (x - input[low]));
        if (input[position] == x) {
            return position;
        }
        if (input[position] < x) {
            return interpolationRecursionSearch(input, x, position + 1, high);
        } else {
            return interpolationRecursionSearch(input, x, low, position - 1);
        }
    }
    return -1;
}


#endif /* recursive_insertion_search_h */
