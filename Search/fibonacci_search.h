//
//  fibonacci_search.h
//  Search Algorithms
//
//  Created by Lennart Buhl on 1/26/22.
//

#ifndef fibonacci_search_h
#define fibonacci_search_h

#include <vector>

int fibonacciSearch(std::vector<double> input, double x) {
    int f_m2 = 0;
    int f_m1 = 1;
    int f_m = f_m2 + f_m1;
    const int size = (int)input.size()-1;
    while (f_m < size) {
        f_m2 = f_m1;
        f_m1 = f_m;
        f_m = f_m1 + f_m2;
    }
    int offset = -1;
    while (f_m > 1) {
        int index = fmin(offset + f_m2, size);
        if (input[index] < x) {
            f_m = f_m1;
            f_m1 = f_m2;
            f_m2 = f_m - f_m1;
            offset = index;
        } else if (input[index] > x) {
            f_m = f_m2;
            f_m1 = f_m1 - f_m2;
            f_m2 = f_m - f_m1;
        } else {
            return index;
        }
    }
    offset++;
    if (input[offset] == x) {
        return offset;
    } else {
        return -1;
    }
}

#endif /* fibonacci_search_h */
