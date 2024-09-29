#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

// Function to perform binary search
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    // Test for different sizes of arrays
    vector<int> sizes = {1000, 10000, 100000, 1000000, 10000000};
    
    for (int size : sizes) {
        // Create a sorted array with 'size' elements
        std::vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = i;
        }

        int target = size - 1;  // Target to search for in the array

        // Measure the time taken by binary search
        auto start =chrono::high_resolution_clock::now();
        int result =binarySearch(arr, target);
        auto end =chrono::high_resolution_clock::now();

        // Calculate duration
        chrono::duration<double> duration = end - start;

        // Print the result
        cout << "Array size: " << size 
                  << ", Time taken: " << duration.count() << " seconds" 
                  << ", Target index: " << result << std::endl;
    }

    return 0;
}
