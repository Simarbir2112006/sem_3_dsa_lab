#include <iostream>

using namespace std;

const int MAX = 100;

bool addSparse(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Addition not possible: dimension mismatch." << endl;
        return false;
    }

    int i=1,j=1,k=1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while(i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1])) {
            C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2];
            i++; k++;
        }
        else if (B[j][0]<A[i][0] || (B[j][0]==A[i][0] && B[j][1]<A[i][1])) {
            C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2];
            j++; k++;
        }
        else {
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=sum;
                k++;
            }
            i++; j++;
        }
    }
    while(i <= A[0][2]) {
        C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2];
        i++; k++;
    }
    while(j <= B[0][2]) {
        C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2];
        j++; k++;
    }
    C[0][2] = k-1;
    return true;
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
        {3, 3, 4},
        {0, 0, 5},
        {0, 2, 8},
        {1, 1, 3},
        {2, 2, 6}
    };

    int B[MAX][3] = {
        {3, 3, 3},
        {0, 0, 6},
        {0, 1, 9},
        {1, 1, 7}
    };

    int C[MAX][3];

    cout << "Matrix A:\n";
    printSparse(A);

    cout << "Matrix B:\n";
    printSparse(B);

    if(addSparse(A, B, C)) {
        cout << "A + B:\n";
        printSparse(C);
    }

    return 0;
}
