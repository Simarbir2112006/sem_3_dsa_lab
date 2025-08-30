#include <iostream>

using namespace std;

const int MAX = 100;

void transpose(int A[MAX][3], int T[MAX][3]) {
    int row_terms[MAX] = {0}, starting_pos[MAX] = {0};
    int n = A[0][2], cols = A[0][1];

    T[0][0] = cols;
    T[0][1] = A[0][0];
    T[0][2] = n;

    for (int i = 1; i <= n; i++)
        row_terms[A[i][1]]++;

    starting_pos[0] = 1;
    for(int i = 1; i < cols; i++)
        starting_pos[i] = starting_pos[i-1] + row_terms[i-1];

    for(int i = 1; i <= n; i++) {
        int col = A[i][1];
        int pos = starting_pos[col]++;
        T[pos][0] = A[i][1];
        T[pos][1] = A[i][0];
        T[pos][2] = A[i][2];
    }
}

void printSparse(int A[MAX][3]) {
    cout << "Rows: " << A[0][0] << ", Cols: " << A[0][1] << ", Non-zero: " << A[0][2] << "\n";
    cout << "Row Col Value\n";
    for(int i=0; i<=A[0][2]; i++)
        cout << A[i][0] << "   " << A[i][1] << "   " << A[i][2] << "\n";
    cout << endl;
}

int main() {
    int A[MAX][3] = {
        {3, 4, 4},
        {0, 0, 5},
        {0, 2, 8},
        {1, 1, 3},
        {2, 3, 6}
    };

    int T[MAX][3];
    cout << "Original Matrix A:\n";
    printSparse(A);

    transpose(A, T);
    cout << "Transpose of A:\n";
    printSparse(T);

    return 0;
}
