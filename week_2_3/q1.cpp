#include <iostream>

using namespace std;

int binarySearch(int arr[], int n){
	int len = 5;
	int i = 0;
	int m = len/2;
	int f = 0;
	int l = len-1;
	for (i; i<len/2; i++){
		if(n == arr[m]){
			return m;
		}
		else if(n > arr[m]){
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
	int arr[5];
	int i, j;
	cout << "Elements in ascending order: " << endl;
	for (i = 0; i < 5; i++){
		cin >> arr[i];
	}
	int n;
	cout << "Enter number to find: ";
	cin >> n;
	int ans = binarySearch(arr, n);
	cout << "Answer: " << arr[ans] << " at index: " << ans << endl;
}