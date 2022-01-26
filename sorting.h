//
//  sorting.h
//  Sorting Algorithms
//
//  Created by Lennart Buhl on 1/23/22.
//

#ifndef sorting_h
#define sorting_h

#include <vector>


class SortAlgorithms {
public:
    
    SortAlgorithms(){}
    
    std::vector<double> selectionSort(std::vector<double> input) {
        for (int x = 0; x < input.size() - 1; x++) {
            int min_idx = x;
            for (int y = x + 1; y < input.size(); y++) {
                if (input[y] < input[min_idx]) {
                    min_idx = y;
                }
            }
            double temp = input[min_idx];
            input[min_idx] = input[x];
            input[x] = temp;
        }
        return input;
    }
    
    std::vector<double> bubbleSort(std::vector<double> input) {
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for (int x = 0; x < input.size()-1; x++) {
                if (input[x] > input[x+1]) {
                    double temp = input[x+1];
                    input[x+1] = input[x];
                    input[x] = temp;
                    sorted = false;
                }
            }
        }
        return input;
    }
    
    
    std::vector<double> recursiveBubbleSort(std::vector<double> input, int num) {
        
        for (int x = 0; x < input.size()-1; x++) {
            if (input[x] > input[x+1]) {
                double temp = input[x+1];
                input[x+1] = input[x];
                input[x] = temp;
            }
        }
        if (num > 1) {
            input = recursiveBubbleSort(input, num-1);
        }
        return input;
    }
    
    
    std::vector<double> insertionSort(std::vector<double> input) {
           for (int x = 1; x < input.size(); x++) {
               double key = input[x];
               int y = x - 1;
               
               while (y >= 0 && input[y] > key) {
                   input[y + 1] = input[y];
                   y--;
               }
               input[y + 1] = key;
           }
        return input;
    }
    
    std::vector<double> recursiveInsertionSort(std::vector<double> input, int num) {
        if (num > 1) {
            input = recursiveInsertionSort(input, num-1);
        }
        double key = input[num-1];
        int y = num-2;
        while (y >= 0 && input[y] > key) {
            input[y + 1] = input[y];
            y--;
        }
        input[y + 1] = key;
        return input;
    }
    
    
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
    
    std::vector<double> quickSort(std::vector<double> input, int left, int right) {
        if (left < right) {
            double spin = input[right];
            int index = left - 1;
            for (int x = left; x < right; x++) {
                if (input[x] < spin) {
                    index++;
                    double temp = input[index];
                    input[index] = input[x];
                    input[x] = temp;
                }
            }
            index++;
            double temp = input[index];
            input[index] = input[right];
            input[right] = temp;
            input = quickSort(input, left, index-1);
            input = quickSort(input, index+1, right);
        }
        return input;
    }
    
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
};

#endif /* sorting_h */
