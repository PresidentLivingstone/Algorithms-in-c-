#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to print a matrix
void print(const string& display, const vector<vector<int>>& matrix) {
    cout << endl << display << " =>" << endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row)
            cout << setw(10) << elem;
        cout << endl;
    }
}

// Function to add two matrices
void add_matrix(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int n = A.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to multiply two matrices using divide and conquer
vector<vector<int>> multiply_matrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n == 1)
        return {{A[0][0] * B[0][0]}};

    int split = n / 2;
    vector<vector<int>> a00(split, vector<int>(split)), a01(split, vector<int>(split));
    vector<vector<int>> a10(split, vector<int>(split)), a11(split, vector<int>(split));
    vector<vector<int>> b00(split, vector<int>(split)), b01(split, vector<int>(split));
    vector<vector<int>> b10(split, vector<int>(split)), b11(split, vector<int>(split));

    for (int i = 0; i < split; ++i) {
        for (int j = 0; j < split; ++j) {
            a00[i][j] = A[i][j];
            a01[i][j] = A[i][j + split];
            a10[i][j] = A[i + split][j];
            a11[i][j] = A[i + split][j + split];
            b00[i][j] = B[i][j];
            b01[i][j] = B[i][j + split];
            b10[i][j] = B[i + split][j];
            b11[i][j] = B[i + split][j + split];
        }
    }

    vector<vector<int>> c00(split, vector<int>(split)), c01(split, vector<int>(split));
    vector<vector<int>> c10(split, vector<int>(split)), c11(split, vector<int>(split));

    add_matrix(multiply_matrix(a00, b00), multiply_matrix(a01, b10), c00);
    add_matrix(multiply_matrix(a00, b01), multiply_matrix(a01, b11), c01);
    add_matrix(multiply_matrix(a10, b00), multiply_matrix(a11, b10), c10);
    add_matrix(multiply_matrix(a10, b01), multiply_matrix(a11, b11), c11);

    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < split; ++i) {
        for (int j = 0; j < split; ++j) {
            result[i][j] = c00[i][j];
            result[i][j + split] = c01[i][j];
            result[i + split][j] = c10[i][j];
            result[i + split][j + split] = c11[i][j];
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix_A = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {2, 2, 2, 2}};
    vector<vector<int>> matrix_B = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {2, 2, 2, 2}};

    print("Matrix A", matrix_A);
    print("Matrix B", matrix_B);

    vector<vector<int>> result_matrix = multiply_matrix(matrix_A, matrix_B);

    print("Result Matrix", result_matrix);

    return 0;
}
