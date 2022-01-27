//
//  heap_sort.h
//  Sorting Algorithms
//
//  Created by Lennart Buhl on 1/26/22.
//

#ifndef heap_sort_h
#define heap_sort_h

#include <vector>

std::vector<double> heaping(std::vector<double> input, int heap, int node) {
    int largest = node;
    int left = 2 * node + 1;
    int right = 2 * node + 2;
    if (left < heap && input[left] > input[largest]) {
        largest = left;
    }
    if (right < heap && input[right] > input[largest]) {
        largest = right;
    }
    if (largest != node) {
        double temp = input[largest];
        input[largest] = input[node];
        input[node] = temp;
        input = heaping(input, heap, largest);
    }
    return input;
}

std::vector<double> heapSort(std::vector<double> input) {
    int size = (int)input.size();
    for (int x = (size / 2)-1; x >= 0; x--) {
        input = heaping(input, size, x);
    }
    for (int x = size-1; x > 0; x--) {
        double temp = input[0];
        input[0] = input[x];
        input[x] = temp;
        input = heaping(input, x, 0);
    }
    return input;
}

#endif /* heap_sort_h */
