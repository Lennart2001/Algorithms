//
//  linear_search.h
//  Search Algorithms
//
//  Created by Lennart Buhl on 1/26/22.
//

#ifndef linear_search_h
#define linear_search_h

#include <vector>

int linearSearch(std::vector<double> input, double x) {
    for (int x = 0; x < input.size(); x++) {
        if (input[x] == x) {
            return x;
        }
    }
    return -1;
}

#endif /* linear_search_h */
