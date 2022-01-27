//
//  jump_sort.h
//  Search Algorithms
//
//  Created by Lennart Buhl on 1/26/22.
//

#ifndef jump_sort_h
#define jump_sort_h

#include <vector>

int jumpSearch(std::vector<double> input, int size, double x) {
    int step = sqrt(size);
    int previous = 0;
    while (x > input[fmin(step, size)-1]) {
        previous = step;
        step += sqrt(size);
        if (previous >= size) {
            return -1;
        }
    }
    while (x > input[previous]) {
        previous++;
        if (previous == fmin(step, size)) {
            return -1;
        }
    }
    if (input[previous] == x)
        return previous;
    return -1;
}

#endif /* jump_sort_h */
