//
//  interpolation_search.h
//  Search Algorithms
//
//  Created by Lennart Buhl on 1/26/22.
//

#ifndef interpolation_search_h
#define interpolation_search_h

#include <vector>

int interpolationSearch(std::vector<double> input, double x) {
    int low = 0;
    int high = (int)input.size() - 1;
    while (low <= high && x >= input[low] && x <= input[high]) {
        if (low == high) {
            if (x == input[low]) {
                return low;
            } else {
                return -1;
            }
        }
        int position = low + (((double)(high - low) / (input[high] - input[low]))
                              * (x - input[low]));
        if (input[position] == x) {
            return position;
        }
        if (input[position] < x) {
            low = position + 1;
        } else {
            high = position - 1;
        }
    }
    return -1;
}

#endif /* interpolation_search_h */
