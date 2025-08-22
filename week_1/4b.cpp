#include <iostream>

using namespace std;

int main() {
    int m, n, p, q;
    cout << "Enter rows and columns of 1st matrix: ";
    cin >> m >> n;
    cout << "Enter rows and columns of 2nd matrix: ";
    cin >> p >> q;

    if (n != p) {
        cout << "Matrix multiplication not possible (columns of 1st != rows of 2nd)" << endl;
        return 0;
    }

    int a[50][50], b[50][50], c[50][50];

    cout << "Enter elements of 1st matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout << "Enter elements of 2nd matrix:" << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            c[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "Resultant matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}
