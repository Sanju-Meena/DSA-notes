#include <iostream>
#include <string> // For using std::string in the print title

using namespace std;

// The size of our matrices is 3x3
#define N 3

// Helper function to print a matrix
void printMatrix(int matrix[N][N], string title) {
    cout << "--- " << title << " ---" << endl;
    for (int i = 0; i < N; i++) {
        cout << "[ ";
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << "\t"; // \t for better spacing
        }
        cout << "]" << endl;
    }
}

int main() {
    // 1. Define the two 3x3 matrices
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[N][N] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    // 2. Define the result matrix.
    // It's crucial to initialize it to all zeros.
    int C[3][3] ={0};

    // 3. --- Core Multiplication Logic ---
    // Loop for each row of the result matrix (i)
    for (int i = 0; i < N; i++) {
        
        // Loop for each column of the result matrix (j)
        for (int j = 0; j < N; j++) {
            
            // This cell C[i][j] is the dot product of A's row i and B's col j.
            // C[i][j] = (A[i][0]*B[0][j]) + (A[i][1]*B[1][j]) + ...
            
            // Inner loop for the dot product (k)
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // 4. Print all the matrices
    printMatrix(A, "Matrix A");
    cout << endl;
    printMatrix(B, "Matrix B");
    cout << endl;
    printMatrix(C, "Result (A * B)");

    return 0;
}