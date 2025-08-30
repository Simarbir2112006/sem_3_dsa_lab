#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "enter n : ";
    cin >> n;
    int arr[n];
    cout << "enter values of array : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int c = 0;
    for(int i = 0; i < n; i++){
        bool isDuplicate = false;
        for(int j = 0; j < i; j++){
            if(arr[i] == arr[j]){
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate){
            c++;
        }
    }

    cout << "the number of distinct elements in array are : " << c << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
