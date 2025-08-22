#include <iostream>

using namespace std;

int main(){
    int arr[10] = {1,1,1,2,1,1, 2, 1, 1, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < len; i++){
        int ind;
        for (int j = i+1; j < len;){
            if (arr[i] == arr[j]){
                for (int k = j; k < len - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                len--;
            }
            else{
                j++;
            }
        }
    }
    int k;
    cout << "Final Elements:\n";
    for(k = 0; k < len; k+=1){
        cout << arr[k] << " ";
    }
    cout << endl;

}