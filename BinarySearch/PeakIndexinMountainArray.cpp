#include<bits/stdc++.h>
using namespace std;

int peakIndexMountainArray(int arr[], int n){

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    while(s < e){
        if(arr[mid] < arr[mid+1]){
            s = mid + 1;
        }
        else{
            e = mid; // not mid - 1 here coz our ans also lies in this condn. only 
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main(){

    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << peakIndexMountainArray(arr, n) << endl;

    return 0;
}