#include <iostream>

using namespace std;

int missingNumberBinary(int arr[]){
	if(arr[0] != 1){
		return 1;
	}
	int len = 5;
	int i = 0;
	int m = len/2;
	int f = 0;
	int l = len-1;
	for (i; i<len/2; i++){
		if(arr[m+1]-arr[m] == 2){
			return m+2;
		}
		else if(arr[m] - m == 1){
			f = m;
			m = (f+l)/2;
		}
		else{
			l = m;
			m = (f+l)/2;
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
	cout << "Missing number: " << missingNumberBinary(arr) << endl;
}