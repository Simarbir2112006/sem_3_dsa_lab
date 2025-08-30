#include <iostream>

using namespace std;

const int MAX = 100;

void Transpose(int A[MAX][3], int T[MAX][3]) {
    int row_terms[MAX] = {0}, starting_pos[MAX] = {0};
    int n = A[0][2], cols = A[0][1];

    T[0][0] = cols;
    T[0][1] = A[0][0];
    T[0][2] = n;

    for (int i = 1; i <= n; i++)
        row_terms[A[i][1]]++;

    starting_pos[0] = 1;
    for(int i = 1; i < cols; i++)
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

    for(int i = 1; i <= n; i++) {
        int col = A[i][1];
        int pos = starting_pos[col]++;
        T[pos][0] = A[i][1];
        T[pos][1] = A[i][0];
        T[pos][2] = A[i][2];
    }
}

void multiplySparse(int A[MAX][3], int B[MAX][3], int M[MAX][3]) {
    if(A[0][1] != B[0][0]) {
        cout << "Multiplication not possible: dimension mismatch." << endl;
        M[0][2] = 0;
        return;
    }

    int BT[MAX][3];
    Transpose(B, BT);
    int m_k = 1;
    M[0][0] = A[0][0];
    M[0][1] = B[0][1];

    for(int i = 0; i < A[0][0]; i++) {
        for(int j = 0; j < B[0][1]; j++) {
            int sum = 0;
            for(int a = 1; a <= A[0][2]; a++) {
                if(A[a][0] == i) {
                    for(int b = 1; b <= BT[0][2]; b++) {
                        if(BT[b][0] == j && BT[b][1] == A[a][1]) {
                            sum += A[a][2] * BT[b][2];
                            break;
                        }
                    }
                }
            }
            if(sum != 0) {
                M[m_k][0] = i;
                M[m_k][1] = j;
                M[m_k][2] = sum;
                m_k++;
            }
        }
    }
    M[0][2] = m_k - 1;
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
        {2, 3, 4},
        {0, 0, 1},
        {0, 2, 2},
        {1, 1, 3},
        {1, 2, 4}
    };

    int B[MAX][3] = {
        {3, 2, 5},
        {0, 0, 5},
        {0, 1, 6},
        {2, 0, 1},
        {2, 1, 2}
    };

    int M[MAX][3];

    cout << "Matrix A:\n";
    printSparse(A);

    cout << "Matrix B:\n";
    printSparse(B);

    multiplySparse(A, B, M);

    if(M[0][2] > 0) {
        cout << "Product A * B:\n";
        printSparse(M);
    } else {
        cout << "No non-zero elements in product or multiplication not possible.\n";
    }

    return 0;
}
