#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(vector<int>& dims, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + dims[i] * dims[k] * dims[j]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> dims = {1, 2, 3, 4};
    int n = dims.size();

    cout << "Minimum number of multiplications: " << matrixChainMultiplication(dims, n) << endl;
    return 0;
}
