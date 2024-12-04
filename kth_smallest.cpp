#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Partition function used in Quickselect
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quickselect algorithm to find the kth smallest element
int quickselect(vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        // If pivot is at the kth position
        if (pi == k) {
            return arr[pi];
        }
        // If k is smaller, search in the left partition
        else if (k < pi) {
            return quickselect(arr, low, pi - 1, k);
        }
        // If k is larger, search in the right partition
        else {
            return quickselect(arr, pi + 1, high, k);
        }
    }
    return -1;  // This should never happen if k is valid
}

int main() {
    vector<int> arr = {12, 3, 5, 7, 19, 8, 11};
    int n = arr.size();
    int k = 4; // Find the 4th smallest element
    
    // Quickselect returns the kth smallest element
    int result = quickselect(arr, 0, n - 1, k - 1);  // k-1 because index is 0-based
    cout << "The " << k << "th smallest element is " << result << endl;

    return 0;
}
