#include <iostream>

using namespace std;

int missingNumberLinear(int arr[]){
	if(arr[0] != 1){
		return 1;
	}
	int i=0;
	for(i; i < 4; i++){
		if (arr[i+1]-arr[i] != 1){
			break;
		}
	}
	return i+2;
}

int main(){
	int n = 5;
	int arr[n];
	int i;
	cout << "Elements: " << endl;
	for (i = 0; i < 5; i++){
		cin >> arr[i];
	}
	cout << "Missing number: " << missingNumberLinear(arr) << endl;
}