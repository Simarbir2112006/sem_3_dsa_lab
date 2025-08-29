#include <iostream>
#include <cstring>
using namespace std;

void bubbleSort(char arr[][100], int n) {
    char temp[100];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cout << endl;

    char arr[50][100];
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n+1; i++) {
        cin.getline(arr[i], 100);
    }

    bubbleSort(arr, n+1);

    cout << "\nStrings in alphabetical order:\n";
    for (int i = 0; i < n+1; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
