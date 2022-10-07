#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortZeroOne(int arr[], int n){

    int left = 0, right = n-1;
    int step = 0;
    while(left < right){
        
        // we're doing this to know where our code got stuck OR code kha phta 
        // cout << "Step " << step++ << endl;
        // printArray(arr, n);

        while(arr[left] == 0 && left < right) left++;
        while(arr[right] == 1 && left < right) right--;

        // if we have reached here means arr[left] == 1 && arr[right] == 0
        if(left < right){
            swap(arr[left], arr[right]);
            left++; right--;
        }
    }
    printArray(arr, n);

}

int main(){

    int arr[8] = {1, 1, 0, 0, 0, 0, 1, 0};

    sortZeroOne(arr, 8);

    return 0;
}