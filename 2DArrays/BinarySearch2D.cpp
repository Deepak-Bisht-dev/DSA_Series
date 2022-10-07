#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

bool searchMatrix(int n, int m, int arr[R][C], int target){

    int start = 0; int end = n*m - 1;
    int mid = start + (end-start)/2;

    while(start <= end){
        int element = arr[mid/m][mid%m]; // in case of 2D matrix way of searching the element

        if(element == target) return true;

        if(element < target) start = mid - 1;
        else end = mid + 1;

        mid = start + (end - start)/2;
    }
    return false;
}

// this func is for searching an element is row and col wise sorted matrix
bool SortedMatrix(int n, int m, int arr[R][C], int target){
    int rowIndex = 0;
    int colIndex = m-1;

    while(rowIndex < n && colIndex >= 0){
        int element = arr[rowIndex][colIndex];

        if(element == target ) return true;
        if(element < target) rowIndex++;
        else colIndex--;
    }
    return false;
}
    
int main()
{   
    int target; cin >> target;
	int arr[R][C] = {{1, 2, 3, 4},
					{5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16}};

    // this is for row and col wise sorted matrix
	int arr1[R][C] = {{1, 4, 7, 11},
                    {2, 5, 8, 12}, 
                    {3, 6, 9, 16}, 
                    {10, 13, 14, 17}};
                
	cout << searchMatrix(R, C, arr, target) << endl;
    cout << SortedMatrix(R, C, arr1, target) << endl;

	return 0;
}