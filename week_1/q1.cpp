#include <iostream>

using namespace std;

int main(){
    int status = 0;
    int n;
    int j;
    int arr[100];
    int len;
    while (status == 0) {
        cout << "\nMenu\n\n1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. Exit\nEnter number from menu to operate: ";
        cin >> n;
        switch (n){
            case 1:{
                cout << "Enter no of elements in array: ";
                cin >> len;
                int i = 0;
                for(i; i < len; i+=1){
                    cin >> arr[i];
                }
                break;
            }
            case 2:{
                int i;
                cout << "Elements: ";
                for(i = 0; i < len; i+=1){
                    cout << arr[i] << endl;
                }
                break;
            }
            case 3:{
                if (len == 0){
                    cout << "Array is empty create an array first\n";
                    break;
                }
                else{
                    len++;
                    int num;
                    int i, j;
                    cout << "Enter index to insert at: ";
                    cin >> j;
                    cout << "Enter no to be inserted: ";
                    cin >> num;
                    i = len;
                    for (i; i > j; i--){
                        arr[i] = arr[i-1];
                    }
                    arr[j] = num;
                    break;
                }
            }
            case 4:{
                if (len == 0){
                    cout <<"Array is empty create an array first\n";
                    break;
                }
                else{
                    int j;
                    cout <<"Enter index to delete element from: ";
                    cin >> j;
                    for (j; j < len; j++){
                        arr[j] = arr[j+1];
                    }
                    len--;
                    break;
                }
            }
            case 5:{
                if (len == 0){
                    cout <<"Array is empty create an array first\n";
                    break;
                }
                else{
                    int i, j;
                    cout <<"Enter number to search: ";
                    cin >> j;
                    i = 0;
                    for(i; i < len; i++){
                        if (j == arr[i]) {
                            cout << j <<" found on index " << i;
                        }
                    }
                    break;
                }
            }
            case 6:
                cout <<"Thank You!"<< endl;
                status = 1;
                break;
        }
    }
}