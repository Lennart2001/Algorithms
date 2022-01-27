//
//  binary_search.h
//  Search Algorithms
//
//  Created by Lennart Buhl on 1/26/22.
//

#ifndef binary_search_h
#define binary_search_h

#include <vector>

int binarySearch(std::vector<double> input, double x, int left, int right) {
    if (right >= 1) {
        int middle = left + ((right - left) / 2);
        if (input[middle] == x) {
            return binarySearch(input, x, left, middle-1);
        }
        return binarySearch(input, x, middle+1, right);
    } else {
        return -1;
    }
}

#endif /* binary_search_h */
