//
//  exponential_search.h
//  Search Algorithms
//
//  Created by Lennart Buhl on 1/26/22.
//

#ifndef exponential_search_h
#define exponential_search_h

#include <vector>

int exponentialSearch(std::vector<double> input, double x) {
    if (input[0] == x) {
        return 0;
    }
    int position = 1;
    while (position < input.size() && input[position] <= x) {
        position *= 2;
    }
    return binarySearch(input, x, position/2, fmin(position, input.size()-1));
}

#endif /* exponential_search_h */
