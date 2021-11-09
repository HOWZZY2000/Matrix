#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<double> C, int m) {
    for (int i = 0; i < C.size(); i++) {
        if ((i + 1) % m == 0) {
            cout << C[i] << endl;;
        } else {
            cout << C[i] << " ";
        }
    }
}

double row_mutiply(vector<double> A, vector<double> B, int n) { // n is length of the row
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += A[i] * B[i];
    }
    return result;
}

void matrix_mutiply(double *A, double *B, int m, int n, int p) { // A is a m x n matrix, B is a n x p matrix
    vector<double> A_row; 
    vector<double> B_column;
    vector<double> result;
    for (int j = 0; j < m; j ++) {
        for (int i = 0; i < n; i++) {
            A_row.push_back(A[j * n + i]);
        }
        for (int k = 0; k < p; k++) {
            for(int l = 0; l < n; l ++) {
                B_column.push_back(B[k + l * p]);
            }
            result.push_back(row_mutiply(A_row, B_column, n));
            B_column.clear();
        }
        A_row.clear();
    }
    print(result, p); // print result
}

int main() {
    double x[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // matrix A
    double p[12] = {1, 2, 3, 4, 7, 6, 5, 4, 8, 9, 10, 11}; // matrix B
    matrix_mutiply(x, p, 3, 3, 4); // x is 3 x 3 matrix, p is 3 x 4 matrix
}