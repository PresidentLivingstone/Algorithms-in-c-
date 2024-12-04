#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(string X, string Y, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    cout << "Length of LCS: " << lcs(X, Y, X.length(), Y.length()) << endl;
    return 0;
}
