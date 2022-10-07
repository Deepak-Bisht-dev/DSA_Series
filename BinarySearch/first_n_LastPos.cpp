#include<bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int n, int key){

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s <= e){
        if(arr[mid] == key){
            ans = mid;
            e = mid - 1; // the only change is this line from binary search code
        }
        else if(key > arr[mid]){ // Go towards right
            s = mid + 1;
        }
        else{ // Go towards left
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans; 
}

int lastOcc(int arr[], int n, int key){

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s <= e){
        if(arr[mid] == key){
            ans = mid;
            s = mid + 1; // the only change is this line from binary search code
        }
        else if(key > arr[mid]){ // Go towards right
            s = mid + 1;
        }
        else{ // Go towards left
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans; 
}

int main(){

    int n, k; cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << "First occurence is at index" << firstOcc(arr, n, k) << endl;
    cout << "Last occurence is at index" << lastOcc(arr, n, k) << endl;

    return 0; 
}