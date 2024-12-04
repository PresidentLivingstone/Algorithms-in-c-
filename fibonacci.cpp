#include <iostream>
#include <vector>
using namespace std;

// Using Recursion
int fibonacciRec(int n) {
    if (n <= 1) return n;
    return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}

// Using Dynamic Programming
int fibonacciDP(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0; dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 10;

    cout << "Fibonacci number (recursion): " << fibonacciRec(n) << endl;
    cout << "Fibonacci number (DP): " << fibonacciDP(n) << endl;

    return 0;
}
