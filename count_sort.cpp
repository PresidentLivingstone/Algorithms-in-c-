#include <iostream>
#include <vector>
#include <algorithm> // for `max`
using namespace std;

void countingSort(vector<int>& arr, int n) {
    if (n <= 1) return;  // No need to sort if 1 or fewer elements

    // Find the maximum element to know the range of the input array
    int maxElem = *max_element(arr.begin(), arr.end());

    // Create a counting array to store frequency of each element
    vector<int> count(maxElem + 1, 0);  // size of maxElem + 1

    // Count the frequency of each element
    for (int num : arr) {
        count[num]++;
    }

    // Reconstruct the sorted array
    int idx = 0;
    for (int i = 0; i <= maxElem; ++i) {
        while (count[i]--) {
            arr[idx++] = i;
        }
    }

    // Print the sorted array
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    vector<int> arr = { 1, 4, 3, 5, 1 };
    int n = arr.size();

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    countingSort(arr, n);

    cout << "\nSorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
