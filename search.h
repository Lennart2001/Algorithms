//
//  search.h
//  Search Algorithms
//
//  Created by Lennart Buhl on 1/23/22.
//

#ifndef search_h
#define search_h

#include <vector>
#include <cmath>


class SearchAlgorithms {
public:
    
    SearchAlgorithms(){}
    
    int linearSearch(std::vector<double> input, double x) {
        for (int x = 0; x < input.size(); x++) {
            if (input[x] == x) {
                return x;
            }
        }
        return -1;
    }
    
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
    
    int interpolationRecursionSearch(std::vector<double> input, double x, int low, int high) {
        if (low <= high && x >= input[low] && x <= input[high]) {
            int position = low + (((double)(high - low) / (input[high] - input[low]))
                                  * (x - input[low]));
            if (input[position] == x) {
                return position;
            }
            if (input[position] < x) {
                return interpolationRecursionSearch(input, x, position + 1, high);
            } else {
                return interpolationRecursionSearch(input, x, low, position - 1);
            }
        }
        return -1;
    }
    
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
};

#endif /* search_h */
