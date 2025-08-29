#include <iostream>

using namespace std;

void bubbleSort(int arr[]){
	int i, j;
	bool flag;
	for(i = 1; i < 5; i++){
		flag = true;
		for(j = 0; j < 5-i; j++){
			if (arr[j] > arr[j+1]){
				flag = false;
				int temp = arr[j + 1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
		if (flag){
			break;
		}
	}
}

int main(){
	int n = 5;
	int arr[n];
	int i;
	cout << "Elements: " << endl;
	for (i = 0; i < 5; i++){
		cin >> arr[i];
	}
	cout << endl << "Elements: ";
	for (i = 0; i < 5; i++){
		cout << arr[i] <<" ";
	}
	bubbleSort(arr);
	cout << endl << "Elements: ";
	for (i = 0; i < 5; i++){
		cout << arr[i] <<" ";
	}
	
}