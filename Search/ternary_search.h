//
//  ternary_search.h
//  Search Algorithms
//
//  Created by Lennart Buhl on 1/26/22.
//

#ifndef ternary_search_h
#define ternary_search_h

#include <vector>

int ternarySearch(std::vector<double> input, double x, int left, int right) {
    if (right >= 1) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if (input[mid1] == x) {
            return mid1;
        }
        if (input[mid2] == x) {
            return mid2;
        }
        if (x < input[mid1]) {
            return ternarySearch(input, x, left, mid1-1);
        } else if (x > input[mid2]) {
            return ternarySearch(input, x, mid2+1, right);
        } else {
            return ternarySearch(input, x, mid1+1, mid2-1);
        }
    }
    return -1;
}

#endif /* ternary_search_h */
