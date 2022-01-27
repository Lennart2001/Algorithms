//
//  merge_sort.h
//  Sorting Algorithms
//
//  Created by Lennart Buhl on 1/26/22.
//

#ifndef merge_sort_h
#define merge_sort_h

#include <vector>

std::vector<double> mergeSort(std::vector<double> input) {
    std::vector<double> left_vec;
    std::vector<double> right_vec;
    int length = int(input.size());
    if (length > 1) {
        for (int x = 0; x < length; x++) {
            if (x < (length/2)) {
                left_vec.push_back(input[x]);
            } else {
                right_vec.push_back(input[x]);
            }
        }
    } else {
        return input;
    }
    left_vec = mergeSort(left_vec);
    right_vec = mergeSort(right_vec);
    
    int left = 0, right = 0, total = 0;
    while (left < left_vec.size() && right < right_vec.size()) {
        if (left_vec[left] <= right_vec[right]) {
            input[total] = left_vec[left];
            left++;
        } else {
            input[total] = right_vec[right];
            right++;
        }
        total++;
    }
    while (left < left_vec.size()) {
        input[total] = left_vec[left];
        left++;
        total++;
    }
    while (right < right_vec.size()) {
        input[total] = right_vec[right];
        right++;
        total++;
    }
    return input;
}

#endif /* merge_sort_h */
