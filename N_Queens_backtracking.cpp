#include <iostream>
#include <vector>
using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check this column on all rows
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row, int n) {
    if (row >= n)
        return true;  // All queens are placed

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solveNQueensUtil(board, row + 1, n))
                return true;
            board[row][col] = 0;  // Backtrack
        }
    }

    return false;
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (solveNQueensUtil(board, 0, n)) {
        for (auto row : board) {
            for (auto cell : row) {
                cout << (cell ? "Q" : ".") << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Solution does not exist" << endl;
    }
}

int main() {
    int n = 4;
    solveNQueens(n);
    return 0;
}
