#include <iostream>
using namespace std;

/* Function to sort array using insertion sort */
void insertionSort(int arr[], int n, int& comparisons) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than the key to one position ahead
        while (j >= 0 && arr[j] > key) {
            ++comparisons; // Increment comparison count
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // Count the final comparison when the loop condition fails
        if (j >= 0) ++comparisons;
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver method
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0; // Initialize comparison count

    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n, comparisons);

    cout << "Sorted array: ";
    printArray(arr, n);

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
