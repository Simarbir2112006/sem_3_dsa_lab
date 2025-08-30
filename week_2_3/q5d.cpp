#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int A[n*(n+1)/2];

    cout << "Enter elements for Symmetric Matrix (lower triangle):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << "Enter A[" << i << "," << j << "]: ";
            cin >> A[i*(i+1)/2 + j];
        }
    }

    cout << "Symmetric Matrix\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j)
                cout << A[i*(i+1)/2 + j] << " ";
            else
                cout << A[j*(j+1)/2 + i] << " ";
        }
        cout << endl;
    }
}
