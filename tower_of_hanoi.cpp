#include <iostream>
using namespace std;

// Function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);  // Move n-1 disks from source to auxiliary
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, destination, source);  // Move n-1 disks from auxiliary to destination
}

int main() {
    int n = 3;  // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B');  // A -> source, C -> destination, B -> auxiliary
    return 0;
}
