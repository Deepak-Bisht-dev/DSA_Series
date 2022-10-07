#include<bits/stdc++.h>
using namespace std;

// this is normal func. to print the array
void printArray(int arr[], int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// this is func. to swap the alternate elements till less than size of array elements
void swapAlternate(int arr[], int size){

    for(int i = 0; i < size; i +=2){
        if(i+1 < size){
            swap(arr[i], arr[i+1]);
        }
    }
}

// this func. is for finding the unique element present in the aray
// Always remember xor property for this use
int findUniqueEle(int arr[], int n){

    int ans = 0;
    for(int i = 0; i < n; i ++){
        ans = ans ^ arr[i];
    }

    return ans;
}

// this func. is to find occurences of each element is unique or not
bool uniqueOccurence(int arr[], int n){

}

// find duplicates in an array means for a array of size N elements present are form 1 -> N-1 and 1 element is repeated twice...
int findDuplicates(int arr[], int n){

    int ans = 0;
    // XOR ing all array elements 
    for(int i = 0; i < n; i++){
        ans = ans ^ arr[i];
    }
    // XOR [1, n-1 ]
    for(int i = 1; i < n; i++){
        ans = ans ^ i;
    }
    return ans;

}

int main(){

    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    // swapAlternate(arr, n);

    // cout << findUniqueEle(arr, n) << endl;
   
    // printArray(arr, n);

    cout << findDuplicates(arr, n) << endl;

    return 0;
}