#include<bits/stdc++.h>
using namespace std;

int main(){

	// taking the no of row elements
	int n; cin >> n;
	// taking the no of col elements
	int m; cin >> m;

	// Allocation of 2D array
	int **arr = new int*[n];

	// Allocating the row elements to the col
	for(int i = 0; i < n; i++) arr[i] = new int[m];

	// Taking the input of the 2D array
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}

	// Printing the array elements
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}