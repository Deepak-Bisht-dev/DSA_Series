#include<bits/stdc++.h>
using namespace std;

//this func. is for finding the pivot element like peak of a mountain array...
int getPivot(int arr[], int n){

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    while(s < e){
        if(arr[mid] >= arr[0]) s = mid + 1;
        else e = mid;

        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(int arr[], int s, int e, int key){
    
    int start = s, end = e;
    int mid = s + (e-s)/2;

    while(start <= end){
        if(arr[mid] == key) return mid;
    }
    if(arr[mid] > key){
        end = mid - 1;
    }
    else start = mid + 1;

    mid = start + (end-start)/2;

    return -1;
}

// this func is for finding the pos of an element in rotated sorted array i.e using Binary Search
int findPos(int arr[], int n, int k){

    int pivot = getPivot(arr, n);
    if(arr[pivot] == k) return pivot;
    if(k >= arr[pivot] && k <= arr[n-1]){
        // BS on second line
        return binarySearch(arr, pivot, n-1, k);
    }
    else{
        // BS on first line
        return binarySearch(arr, 0, pivot-1, k);
    }
}

int main(){

    int arr[5] = {3, 8, 10, 17, 1};

    // cout << "Pivot is at index" << getPivot(arr, 5) << endl;

    cout << findPos(arr, 5, 10);

    return 0;
}