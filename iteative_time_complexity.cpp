#include <iostream>
#include <vector>
using namespace std;

int sumArray(const vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {  // Iteration over n elements
        sum += arr[i];
    }
    return sum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};  // Array of size n=5
    cout << "Sum of array elements: " << sumArray(arr) << endl;

    return 0;
}
